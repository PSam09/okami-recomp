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
    if not FUNCMAP_CSV.exists():
        return func_by_addr, func_by_name
    with open(FUNCMAP_CSV, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        header = next(reader, None)
        for row in reader:
            if len(row) >= 4:
                name, start, end, size = row
                addr = int(start, 16)
                func_by_addr[addr] = name
                func_by_name[name] = addr
    return func_by_addr, func_by_name

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
    func_by_addr, func_by_name = carregar_funcmap()

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

    syscalls = set(re.findall(r"(?:unhandled|unknown) syscall:?\s*0x([0-9a-fA-F]+)", content))
    if not syscalls:
        print("Nenhuma syscall não implementada foi detectada no log.")
        return 0

    print(f"Syscalls pendentes encontradas: {[f'0x{sc}' for sc in syscalls]}")
    return len(syscalls)

def fix_missing_targets(log_path: Path):
    """Detecta alvos indiretos faltantes (guest-branch:missing-target) e sugere/gera stubs."""
    if not log_path.exists():
        return 0

    with open(log_path, "r", encoding="utf-8", errors="replace") as f:
        content = f.read()

    targets = set(re.findall(r"\[guest-branch:missing-target\].*?target=0x([0-9a-fA-F]+)", content))
    if not targets:
        print("Nenhum alvo de branch faltante foi detectado no log.")
        return 0

    print(f"Alvos de branch indireto detectados: {[f'0x{t}' for t in targets]}")
    return len(targets)

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
