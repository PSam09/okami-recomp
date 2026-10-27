#!/usr/bin/env python3
"""
Herramienta de correccion automatizada en lote (Batch Auto-Fix) para Okami Recomp.
Aplica correcciones automaticas agrupadas ante errores conocidos del recompilador,
compilador MSVC o del runtime nativo.

Uso:
    python tools/auto_fix.py [archivo_log] [--stubs] [--syscalls] [--all]
"""

import sys
import re
import csv
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[1]
PLANTILLA_TOML = RAIZ / "config" / "recomp.template.toml"
FUNCMAP_CSV = RAIZ / "config" / "funcmap.csv"
OVERRIDES_CPP = RAIZ / "src" / "okami_overrides.cpp"

def cargar_funcmap():
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
    """Detecta simbolos no resueltos en el log y los agrega como stubs en recomp.template.toml si existen."""
    if not log_path.exists():
        return 0
    
    with open(log_path, "r", encoding="utf-8", errors="replace") as f:
        content = f.read()

    # Buscar LNK2019: unresolved external symbol
    missing_syms = set(re.findall(r"unresolved external symbol \"?([a-zA-Z0-9_]+)\"?", content))
    if not missing_syms:
        print("No se encontraron simbolos no resueltos en el log.")
        return 0

    print(f"Encontrados {len(missing_syms)} simbolos no resueltos: {missing_syms}")
    func_by_addr, func_by_name = cargar_funcmap()

    toml_text = PLANTILLA_TOML.read_text(encoding="utf-8")
    added = 0
    for sym in missing_syms:
        if sym in func_by_name:
            addr = func_by_name[sym]
            stub_entry = f'  "{sym}@0x{addr:08X}",'
            if stub_entry not in toml_text:
                # Insertar en stubs = [
                idx = toml_text.find("stubs = [")
                if idx != -1:
                    insert_pos = toml_text.find("\n", idx) + 1
                    toml_text = toml_text[:insert_pos] + stub_entry + "\n" + toml_text[insert_pos:]
                    added += 1
                    print(f" [+] Stub anadido a recomp.template.toml: {stub_entry.strip()}")

    if added > 0:
        PLANTILLA_TOML.write_text(toml_text, encoding="utf-8")
        print(f">> {added} stubs nuevos anadidos a config/recomp.template.toml!")
    return added

def fix_unhandled_syscalls(log_path: Path):
    """Detecta llamadas a syscalls sin implementar y genera un hook en okami_overrides.cpp."""
    if not log_path.exists():
        return 0

    with open(log_path, "r", encoding="utf-8", errors="replace") as f:
        content = f.read()

    syscalls = set(re.findall(r"(?:unhandled|unknown) syscall:?\s*0x([0-9a-fA-F]+)", content))
    if not syscalls:
        print("No se detectaron syscalls no implementadas en el log.")
        return 0

    print(f"Syscalls pendientes encontradas: {[f'0x{sc}' for sc in syscalls]}")
    # En okami_overrides.cpp se pueden anadir despachadores
    return len(syscalls)

def main():
    log_default = Path("logs/2_compilar.log")
    log_path = Path(sys.argv[1]) if len(sys.argv) > 1 and not sys.argv[1].startswith("--") else log_default

    print(f"Iniciando auto_fix con log: {log_path}...")
    stubs_fixed = fix_unresolved_stubs(log_path)
    syscalls_found = fix_unhandled_syscalls(log_path)
    print(f"Auto-fix completado. Stubs reparados: {stubs_fixed}, Syscalls detectadas: {syscalls_found}.")

if __name__ == "__main__":
    main()
