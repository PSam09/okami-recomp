#!/usr/bin/env python3
"""Lista em ordem os patches que scripts/compilar.ps1 aplica sobre o PS2Recomp.

Garante que todos os patches em patches/ sejam aplicados em scripts/compilar.ps1.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[2]
COMPILAR = RAIZ / "scripts" / "compilar.ps1"

def main() -> int:
    texto = COMPILAR.read_text(encoding="utf-8-sig")
    
    # Mapear variavel -> caminho do patch
    rutas = {m[1].lower(): m[2] for m in re.finditer(
        r"^\s*\$(\w+)\s*=\s*Join-Path\s+\$RepoRoot\s+'(patches[\\/][^']+\.patch)'", texto, re.M | re.I)}
    
    # Localizar bloco $patches = @( ... )
    bloco_m = re.search(r"\$patches\s*=\s*@\((.*?)\)", texto, re.S)
    if not bloco_m:
        # Fallback para regex de Run $git apply
        orden = [m[1].lower() for m in re.finditer(
            r"^\s*Run\s+\$git\s+@\(\s*'apply'[^)]*\$(\w+)\s*\)", texto, re.M | re.I)]
    else:
        orden = [m.lower() for m in re.findall(r"\$(\w+)", bloco_m.group(1))]

    erros = []
    patches_aplicados = []
    for var in orden:
        if var not in rutas:
            erros.append(f"compilar.ps1 referencia ${var}, mas sua definicao de caminho nao foi encontrada")
            continue
        caminho = RAIZ / rutas[var].replace("\\", "/")
        if not caminho.is_file():
            erros.append(f"Arquivo de patch nao encontrado: {caminho.relative_to(RAIZ).as_posix()}")
        patches_aplicados.append(caminho)
        
    sem_aplicar = sorted(set((RAIZ / "patches").glob("*.patch")) - set(patches_aplicados))
    for caminho in sem_aplicar:
        erros.append(f"Patch presente no repositorio mas nao aplicado em compilar.ps1: {caminho.relative_to(RAIZ).as_posix()}")
        
    if not patches_aplicados:
        erros.append("Nenhum patch encontrado em compilar.ps1")

    for e in erros:
        print(f"::error::{e}", file=sys.stderr)
        
    if erros:
        return 1
        
    for p in patches_aplicados:
        print(p.relative_to(RAIZ).as_posix())
    return 0

if __name__ == "__main__":
    sys.exit(main())
