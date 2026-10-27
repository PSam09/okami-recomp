#!/usr/bin/env python3
"""
Ferramenta de correção automatizada em lote (Batch Auto-Fix) para Okami Recomp.
Aplica correções automáticas agrupadas diante de erros conhecidos do recompilador,
compilador MSVC ou do runtime nativo.

Uso:
    python tools/auto_fix.py [arquivo_log] [--stubs] [--syscalls] [--all]
"""

import sys
import re
import csv
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[1]
PLANTILLA_TOML = RAIZ / "config" / "recomp.template.toml"
FUNCMAP_CSV = RAIZ / "config" / "funcmap.csv"
OVERRIDES_CPP = RAIZ / "src" / "okami_overrides.cpp"

def carregar_funcmap():
    func_by_addr = {}
    func_by_name = {}
    intervals = []
    if not FUNCMAP_CSV.exists():
        return func_by_addr, func_by_name, intervals
    with open(FUNCMAP_CSV, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        header = next(reader, None)
        for row in reader:
            if len(row) >= 4:
                name, start, end, size = row
                addr_start = int(start, 16)
                addr_end = int(end, 16)
                func_by_addr[addr_start] = name
                func_by_name[name] = addr_start
                intervals.append((addr_start, addr_end, name))
    intervals.sort()
    return func_by_addr, func_by_name, intervals

def obter_offset_elf(addr: int, elf_path: Path):
    if not elf_path.exists():
        return None
    with open(elf_path, "rb") as f:
        elf = f.read()
    if len(elf) < 0x34:
        return None
    e_phoff = int.from_bytes(elf[0x1C:0x20], "little")
    e_phnum = int.from_bytes(elf[0x2C:0x2E], "little")
    e_phentsize = int.from_bytes(elf[0x2A:0x2C], "little")
    for i in range(e_phnum):
        ph = elf[e_phoff + i * e_phentsize : e_phoff + (i + 1) * e_phentsize]
        p_offset = int.from_bytes(ph[4:8], "little")
        p_vaddr = int.from_bytes(ph[8:12], "little")
        p_filesz = int.from_bytes(ph[16:20], "little")
        if p_vaddr <= addr < p_vaddr + p_filesz:
            return p_offset + (addr - p_vaddr)
    return None

def desensamblar_mips(inst: int) -> str:
    op = (inst >> 26) & 0x3F
    rs = (inst >> 21) & 0x1F
    rt = (inst >> 16) & 0x1F
    rd = (inst >> 11) & 0x1F
    funct = inst & 0x3F
    imm = inst & 0xFFFF
    simm = imm if imm < 0x8000 else imm - 0x10000
    reg = ["zero","at","v0","v1","a0","a1","a2","a3","t0","t1","t2","t3","t4","t5","t6","t7",
           "s0","s1","s2","s3","s4","s5","s6","s7","t8","t9","k0","k1","gp","sp","fp","ra"]

    if inst == 0:
        return "nop"
    if op == 0x00:
        if funct == 0x08:
            return f"jr ${reg[rs]}"
        if funct == 0x09:
            return f"jalr ${reg[rs]}"
        if funct == 0x2D:
            return f"daddu ${reg[rd]}, ${reg[rs]}, ${reg[rt]}"
        if funct == 0x21:
            return f"addu ${reg[rd]}, ${reg[rs]}, ${reg[rt]}"
    elif op == 0x0F:
        return f"lui ${reg[rt]}, 0x{imm:04X}"
    elif op == 0x09:
        return f"addiu ${reg[rt]}, ${reg[rs]}, {simm} (0x{imm:04X})"
    elif op == 0x23:
        return f"lw ${reg[rt]}, {simm}(${reg[rs]})"
    elif op == 0x2B:
        return f"sw ${reg[rt]}, {simm}(${reg[rs]})"
    elif op == 0x04:
        return f"beq ${reg[rs]}, ${reg[rt]}, +{simm*4}"
    elif op == 0x05:
        return f"bne ${reg[rs]}, ${reg[rt]}, +{simm*4}"
    elif op == 0x02:
        return f"j 0x{(inst & 0x3FFFFFF) * 4:08X}"
    elif op == 0x03:
        return f"jal 0x{(inst & 0x3FFFFFF) * 4:08X}"
    return f"raw 0x{inst:08X}"

def fix_unresolved_stubs(log_path: Path):
    """Detecta símbolos não resolvidos no log e os adiciona como stubs em recomp.template.toml se existirem."""
    if not log_path.exists():
        return 0
    
    with open(log_path, "r", encoding="utf-8", errors="replace") as f:
        content = f.read()

    # Buscar LNK2019: unresolved external symbol
    missing_syms = set(re.findall(r"unresolved external symbol \"?([a-zA-Z0-9_]+)\"?", content))
    if not missing_syms:
        print("Nenhum símbolo não resolvido foi detectado no log.")
        return 0

    print(f"Detectados {len(missing_syms)} símbolos não resolvidos: {missing_syms}")
    func_by_addr, func_by_name, _ = carregar_funcmap()

    toml_text = PLANTILLA_TOML.read_text(encoding="utf-8")
    added = 0
    for sym in missing_syms:
        if sym in func_by_name:
            addr = func_by_name[sym]
            stub_entry = f'  "{sym}@0x{addr:08X}",'
            if stub_entry not in toml_text:
                # Inserir em stubs = [
                idx = toml_text.find("stubs = [")
                if idx != -1:
                    insert_pos = toml_text.find("\n", idx) + 1
                    toml_text = toml_text[:insert_pos] + stub_entry + "\n" + toml_text[insert_pos:]
                    added += 1
                    print(f" [+] Stub adicionado a recomp.template.toml: {stub_entry.strip()}")

    if added > 0:
        PLANTILLA_TOML.write_text(toml_text, encoding="utf-8")
        print(f">> {added} novos stubs adicionados a config/recomp.template.toml!")
    return added

def fix_unhandled_syscalls(log_path: Path):
    """Detecta chamadas a syscalls não implementadas e relata para criação de hook."""
    if not log_path.exists():
        return 0

    with open(log_path, "r", encoding="utf-8", errors="replace") as f:
        content = f.read()

    matches = re.findall(r"(?:Chosen=0x([0-9a-fA-F]+)|\[Syscall TODO\].*?v1=0x([0-9a-fA-F]+)|(?:unhandled|unknown)\s+syscall:?\s*0x([0-9a-fA-F]+))", content, re.IGNORECASE)
    syscalls = {m[0] or m[1] or m[2] for m in matches if any(m)}
    if not syscalls:
        print("Nenhuma syscall não implementada foi detectada no log.")
        return 0

    print(f"Syscalls pendentes encontradas: {[f'0x{sc.lower()}' for sc in sorted(syscalls)]}")
    return len(syscalls)

def fix_missing_targets(log_path: Path):
    """Detecta alvos indiretos faltantes (guest-branch:missing-target) e sugere/gera stubs."""
    if not log_path.exists():
        return 0

    with open(log_path, "r", encoding="utf-8", errors="replace") as f:
        content = f.read()

    targets_str = set(re.findall(r"\[guest-branch:missing-target\].*?target=0x([0-9a-fA-F]+)", content))
    if not targets_str:
        print("Nenhum alvo de branch faltante foi detectado no log.")
        return 0

    print(f"\nDetectados {len(targets_str)} alvos de branch indireto não mapeados:")
    _, _, intervals = carregar_funcmap()
    elf_path = RAIZ / "game" / "SLUS_211.15"

    for t_str in sorted(targets_str):
        target = int(t_str, 16)
        containing = None
        for start, end, name in intervals:
            if start <= target < end:
                containing = (start, end, name)
                break

        print(f"\n[*] Alvo: 0x{target:08X}")
        if containing:
            start, end, name = containing
            offset = target - start
            print(f"    Função contêiner em funcmap.csv: {name} (0x{start:08X}..0x{end:08X}, offset +0x{offset:X})")
        else:
            print(f"    Alvo fora de qualquer intervalo em funcmap.csv!")

        if elf_path.exists():
            file_off = obter_offset_elf(target, elf_path)
            if file_off is not None:
                print(f"    Desmontagem MIPS a partir de 0x{target:08X}:")
                with open(elf_path, "rb") as ef:
                    ef.seek(file_off)
                    code_bytes = ef.read(64)
                for j in range(0, len(code_bytes), 4):
                    cur_addr = target + j
                    inst = int.from_bytes(code_bytes[j:j+4], "little")
                    dis = desensamblar_mips(inst)
                    print(f"      0x{cur_addr:08X}: {dis}")
                    if "jr $ra" in dis or "j 0x" in dis:
                        # Print delay slot too
                        if j + 4 < len(code_bytes):
                            d_inst = int.from_bytes(code_bytes[j+4:j+8], "little")
                            print(f"      0x{cur_addr+4:08X}: {desensamblar_mips(d_inst)} (delay slot)")
                        break

        print(f"    Sugestão para src/okami_overrides.cpp:")
        print(f"      void okamiOverride_Sub_{target:08x}(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)")
        print(f"      {{")
        print(f"          (void)rdram; (void)runtime;")
        print(f"          const uint32_t ra = getRegU32(ctx, 31);")
        print(f"          ctx->pc = ra;")
        print(f"      }}")
        print(f"      replaceFunctionRange(runtime, 0x{target:08X}u, 0x{target+0x20:08X}u, okamiOverride_Sub_{target:08x});")

    return len(targets_str)

def main():
    log_default = Path("logs/2_compilar.log")
    log_path = Path(sys.argv[1]) if len(sys.argv) > 1 and not sys.argv[1].startswith("--") else log_default

    print(f"Iniciando auto_fix com log: {log_path}...")
    stubs_fixed = fix_unresolved_stubs(log_path)
    syscalls_found = fix_unhandled_syscalls(log_path)
    targets_found = fix_missing_targets(log_path)
    print(f"Auto-fix concluído. Stubs: {stubs_fixed}, Syscalls: {syscalls_found}, Missing targets: {targets_found}.")

if __name__ == "__main__":
    main()
