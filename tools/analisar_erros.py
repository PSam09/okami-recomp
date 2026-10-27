#!/usr/bin/env python3
"""
Herramienta automatizada de deteccion y agrupacion de patrones de error para Okami Recomp.
Analiza logs de compilacion (logs/2_compilar.log) o de ejecucion (logs/ejecutar*.log),
encuentra patrones repetitivos de fallos, y ofrece soluciones automatizadas en lote.

Uso:
    python tools/analisar_erros.py [archivo_log] [--fix]
"""

import sys
import re
import os
from collections import defaultdict
from pathlib import Path

# Expresiones regulares para clasificar patrones comunes
PATRONES = [
    ("MSVC_FALTA_INCLUDE", re.compile(r"error C1083: .*? '(?P<archivo>[^']+)': No such file or directory")),
    ("MSVC_IDENTIFICADOR_NO_DECLARADO", re.compile(r"error C2065: '(?P<id>[^']+)': undeclared identifier")),
    ("MSVC_FUNCION_NO_ENCONTRADA", re.compile(r"error C3861: '(?P<fn>[^']+)': identifier not found")),
    ("MSVC_ERROR_CONVERSION", re.compile(r"error C2664: '(?P<detalle>[^']*)'")),
    ("MSVC_ENLACE_SIMBOLO_NO_RESUELTO", re.compile(r"error LNK2019: unresolved external symbol \"?(?P<simbolo>[^\" ]+)\"?")),
    ("RECOMP_INSTRUCCION_DESCONOCIDA", re.compile(r"(?:unknown|unsupported) instruction:? 0x(?P<opcode>[0-9a-fA-F]+)")),
    ("RECOMP_SOLAPE_FUNCION", re.compile(r"overlap.*?0x(?P<dir1>[0-9A-Fa-f]+).*?0x(?P<dir2>[0-9A-Fa-f]+)")),
    ("RUNTIME_SYSCALL_NO_IMPLEMENTADA", re.compile(r"(?:unhandled|unknown) syscall:? 0x(?P<num>[0-9a-fA-F]+)")),
    ("RUNTIME_IOP_RPC_NO_IMPLEMENTADA", re.compile(r"(?:unhandled|unknown) (?:IOP RPC|SifRpc):? 0x(?P<rpc>[0-9a-fA-F]+)")),
    ("RUNTIME_DMA_ERROR", re.compile(r"(?:DMA error|stall on channel) (?P<canal>\d+)")),
    ("RUNTIME_ACCESO_INVALIDO", re.compile(r"(?:Access violation|Segmentation fault|read unmapped) (?:at|address) 0x(?P<dir>[0-9a-fA-F]+)")),
    ("RUNTIME_VU1_DESCONOCIDO", re.compile(r"VU1.*?(?:unknown|unimplemented|stall)")),
]

def analizar_log(ruta_log: Path):
    if not ruta_log.exists():
        print(f"Log no encontrado: {ruta_log} (Aun no se ha ejecutado ninguna compilacion o ejecucion)")
        return {}, []

    coincidencias = defaultdict(list)
    lineas_no_clasificadas = []

    with open(ruta_log, "r", encoding="utf-8", errors="replace") as f:
        for num_linea, linea in enumerate(f, start=1):
            linea_limpia = linea.strip()
            if not linea_limpia:
                continue
                
            encontrado = False
            for nombre_patron, regex in PATRONES:
                m = regex.search(linea_limpia)
                if m:
                    coincidencias[nombre_patron].append((num_linea, linea_limpia, m.groupdict()))
                    encontrado = True
                    break
                    
            if not encontrado:
                if any(w in linea_limpia.lower() for w in ("error", "fatal", "failed", "fallo", "unhandled", "exception")):
                    lineas_no_clasificadas.append((num_linea, linea_limpia))

    return coincidencias, lineas_no_clasificadas

def presentar_informe(coincidencias, no_clasificadas):
    total_errores = sum(len(v) for v in coincidencias.values()) + len(no_clasificadas)
    print("\n" + "="*70)
    print(f" INFORME DE ANALISIS DE ERRORES AUTOMATIZADO ({total_errores} detectados)")
    print("="*70)

    if not coincidencias and not no_clasificadas:
        print(">> No se detectaron errores en el registro analisado. Todo en orden!")
        return

    for patron, ocurrencias in sorted(coincidencias.items(), key=lambda x: len(x[1]), reverse=True):
        print(f"\n[PATRON] {patron}: {len(ocurrencias)} apariciones")
        # Mostrar los primeros 3 ejemplos
        for num, texto, grupos in ocurrencias[:3]:
            det = f" (claves: {grupos})" if grupos else ""
            print(f"   L{num}: {texto[:100]}...{det}")
        if len(ocurrencias) > 3:
            print(f"   ... y {len(ocurrencias) - 3} mas de este tipo.")

    if no_clasificadas:
        print(f"\n[OTROS ERRORES] {len(no_clasificadas)} lineas con palabras de error:")
        for num, texto in no_clasificadas[:5]:
            print(f"   L{num}: {texto[:100]}")
        if len(no_clasificadas) > 5:
            print(f"   ... y {len(no_clasificadas) - 5} mas.")

    print("\n" + "-"*70)
    print("SUGERENCIAS DE REMEDIACION AUTOMATICA:")
    if "MSVC_ENLACE_SIMBOLO_NO_RESUELTO" in coincidencias:
        print(" -> Simbolos no resueltos detectados: ejecute 'python tools/auto_fix.py --stubs'")
    if "RUNTIME_SYSCALL_NO_IMPLEMENTADA" in coincidencias:
        print(" -> Syscalls sin implementar: ejecute 'python tools/auto_fix.py --syscalls'")
    if "MSVC_IDENTIFICADOR_NO_DECLARADO" in coincidencias:
        print(" -> Headers o tipos faltantes en runner: ejecute 'python tools/auto_fix.py --headers'")
    print("-" * 70)

def main():
    log_default = Path("logs/2_compilar.log")
    if len(sys.argv) > 1 and not sys.argv[1].startswith("--"):
        log_path = Path(sys.argv[1])
    else:
        log_path = log_default

    print(f"Analizando log: {log_path}...")
    coincidencias, no_clasificadas = analizar_log(log_path)
    presentar_informe(coincidencias, no_clasificadas)

    if "--fix" in sys.argv:
        print("\n>> Ejecutando auto_fix.py en base a patrones encontrados...")
        import subprocess
        subprocess.run([sys.executable, "tools/auto_fix.py", str(log_path)])

if __name__ == "__main__":
    main()
