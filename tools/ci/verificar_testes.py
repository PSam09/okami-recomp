#!/usr/bin/env python3
"""Compara a saida da suite ps2x_tests com a lista de falhas conhecidas.

Uso:
    (cd PS2Recomp && ./build/ps2xTest/ps2x_tests) | python3 tools/ci/verificar_testes.py [fallos_conocidos.txt]
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

def main() -> int:
    arquivo_conhecidos = Path(sys.argv[1]) if len(sys.argv) > 1 else None
    conhecidos: set[str] = set()
    if arquivo_conhecidos and arquivo_conhecidos.is_file():
        conhecidos = {
            linha.strip()
            for linha in arquivo_conhecidos.read_text(encoding="utf-8").splitlines()
            if linha.strip() and not linha.startswith("#")
        }

    texto = sys.stdin.read()
    # Capturar falhas reportadas pelo framework de teste
    falhas_detectadas = set(re.findall(r"^\[\s*FAILED\s*\]\s*(\S+)", texto, re.M))

    novas_falhas = sorted(falhas_detectadas - conhecidos)
    corrigidos = sorted(conhecidos - falhas_detectadas)

    for f in novas_falhas:
        print(f"::error::Regressao ou nova falha de teste: {f}")
    for c in corrigidos:
        print(f"::notice::Teste previamente em falha agora esta passando: {c}")

    print(f"Total de testes com falha: {len(falhas_detectadas)} (conhecidos: {len(conhecidos)})")
    return 1 if novas_falhas else 0

if __name__ == "__main__":
    sys.exit(main())
