#!/usr/bin/env python3
"""
Ferramenta automatizada de detecção e agrupamento de padrões de erro para Okami Recomp.
Analisa logs de compilação (logs/2_compilar.log) ou de execução (logs/executar*.log),
encontra padrões repetitivos de falhas e sugere correções automatizadas em lote.

Uso:
    python tools/analisar_erros.py [arquivo_log] [--fix]
"""

import sys
import re
import os
from collections import defaultdict
from pathlib import Path

# Expressões regulares para classificar padrões recorrentes
PATRONES = [
    ("MSVC_FALTA_INCLUDE", re.compile(r"error C1083: .*? '(?P<arquivo>[^']+)': No such file or directory")),
    ("MSVC_IDENTIFICADOR_NAO_DECLARADO", re.compile(r"error C2065: '(?P<id>[^']+)': undeclared identifier")),
    ("MSVC_FUNCAO_NAO_ENCONTRADA", re.compile(r"error C3861: '(?P<fn>[^']+)': identifier not found")),
    ("MSVC_ERRO_CONVERSAO", re.compile(r"error C2664: '(?P<detalhe>[^']*)'")),
    ("MSVC_SIMBOLO_NAO_RESOLVIDO", re.compile(r"error LNK2019: unresolved external symbol \"?(?P<simbolo>[^\" ]+)\"?")),
    ("RECOMP_INSTRUCAO_DESCONHECIDA", re.compile(r"(?:unknown|unsupported) instruction:? 0x(?P<opcode>[0-9a-fA-F]+)")),
    ("RECOMP_SOBREPOSICAO_FUNCAO", re.compile(r"overlap.*?0x(?P<dir1>[0-9A-Fa-f]+).*?0x(?P<dir2>[0-9A-Fa-f]+)")),
    ("RUNTIME_BRANCH_MISSING_TARGET", re.compile(r"\[guest-branch:missing-target\].*?source=0x(?P<src>[0-9a-fA-F]+)\s+target=0x(?P<dst>[0-9a-fA-F]+)")),
    ("RUNTIME_THREAD_DORMANT", re.compile(r"\[(?:gow|okami)-trace\]\s+(?P<detalhe>main thread dormant)")),
    ("RUNTIME_SYSCALL_NAO_IMPLEMENTADA", re.compile(r"(?:(?:unhandled|unknown|unimplemented)\s+(?:ps2\s+)?syscall|\[Syscall TODO\]).*?(?:Chosen=0x(?P<num>[0-9a-fA-F]+)|v1=0x(?P<num2>[0-9a-fA-F]+)|syscall:?\s*0x(?P<num3>[0-9a-fA-F]+))", re.IGNORECASE)),
    ("RUNTIME_IOP_RPC_NAO_IMPLEMENTADA", re.compile(r"(?:unhandled|unknown) (?:IOP RPC|SifRpc):? 0x(?P<rpc>[0-9a-fA-F]+)")),
    ("RUNTIME_ERRO_DMA", re.compile(r"(?:DMA error|stall on channel) (?P<canal>\d+)")),
    ("RUNTIME_ACESSO_INVALIDO", re.compile(r"(?:Access violation|Segmentation fault|read unmapped) (?:at|address) 0x(?P<dir>[0-9a-fA-F]+)")),
    ("RUNTIME_STALL_LEITURA_PARTICAO", re.compile(r"\[okami-ptstat\].*?stat=(?P<stat>[^4\s]+).*?v0=(?P<v0>[^4\s]+)")),
    ("RUNTIME_VU1_DESCONHECIDO", re.compile(r"VU1.*?(?:unknown|unimplemented|stall)")),
]

def analisar_log(ruta_log: Path):
    if not ruta_log.exists():
        print(f"Log não encontrado: {ruta_log} (Ainda não foi executada nenhuma compilação ou execução)")
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
                if any(w in linea_limpia.lower() for w in ("error", "fatal", "failed", "falha", "unhandled", "exception")):
                    lineas_no_clasificadas.append((num_linea, linea_limpia))

    return coincidencias, lineas_no_clasificadas

def apresentar_informe(coincidencias, no_clasificadas):
    total_errores = sum(len(v) for v in coincidencias.values()) + len(no_clasificadas)
    print("\n" + "="*70)
    print(f" RELATÓRIO DE ANÁLISE AUTOMATIZADA DE ERROS ({total_errores} detectados)")
    print("="*70)

    if not coincidencias and not no_clasificadas:
        print(">> Nenhum erro detectado no registro analisado. Tudo funcionando normalmente!")
        return

    for patron, ocurrencias in sorted(coincidencias.items(), key=lambda x: len(x[1]), reverse=True):
        print(f"\n[PADRÃO] {patron}: {len(ocurrencias)} ocorrências")
        for num, texto, grupos in ocurrencias[:3]:
            det = f" (chaves: {grupos})" if grupos else ""
            print(f"   L{num}: {texto[:100]}...{det}")
        if len(ocurrencias) > 3:
            print(f"   ... e mais {len(ocurrencias) - 3} ocorrências deste tipo.")

    if no_clasificadas:
        print(f"\n[OUTROS ERROS] {len(no_clasificadas)} linhas com indicação de erro:")
        for num, texto in no_clasificadas[:5]:
            print(f"   L{num}: {texto[:100]}")
        if len(no_clasificadas) > 5:
            print(f"   ... e mais {len(no_clasificadas) - 5} linhas.")

    print("\n" + "-"*70)
    print("SUGESTÕES DE CORREÇÃO AUTOMATIZADA:")
    if "MSVC_SIMBOLO_NAO_RESOLVIDO" in coincidencias:
        print(" -> Símbolos não resolvidos detectados: execute 'python tools/auto_fix.py --stubs'")
    if "RUNTIME_SYSCALL_NAO_IMPLEMENTADA" in coincidencias:
        print(" -> Syscalls pendentes: execute 'python tools/auto_fix.py --syscalls'")
    if "MSVC_IDENTIFICADOR_NAO_DECLARADO" in coincidencias:
        print(" -> Headers ou tipos ausentes no runner: execute 'python tools/auto_fix.py --headers'")
    if "RUNTIME_BRANCH_MISSING_TARGET" in coincidencias:
        print(" -> Alvos de branch indireto ausentes: execute 'python tools/auto_fix.py <log> --targets'")
    print("-" * 70)

def main():
    log_default = Path("logs/2_compilar.log")
    if len(sys.argv) > 1 and not sys.argv[1].startswith("--"):
        log_path = Path(sys.argv[1])
    else:
        log_path = log_default

    print(f"Analisando log: {log_path}...")
    coincidencias, no_clasificadas = analisar_log(log_path)
    apresentar_informe(coincidencias, no_clasificadas)

    if "--fix" in sys.argv:
        print("\n>> Executando auto_fix.py com base nos padrões encontrados...")
        import subprocess
        subprocess.run([sys.executable, "tools/auto_fix.py", str(log_path)])

if __name__ == "__main__":
    main()
