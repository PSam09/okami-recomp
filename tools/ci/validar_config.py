#!/usr/bin/env python3
"""Valida config/funcmap.csv e config/recomp.template.toml sem necessidade dos arquivos do jogo.

Uso:  python tools/ci/validar_config.py [--runtime CAMINHO_PS2RECOMP]
"""
from __future__ import annotations

import argparse
import bisect
import csv
import re
import sys
import tomllib
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[2]
FUNCMAP = RAIZ / "config" / "funcmap.csv"
PLANTILLA = RAIZ / "config" / "recomp.template.toml"
SELECTOR = re.compile(r"^(?P<nome>[A-Za-z_$][\w$.]*)@0x(?P<dir>[0-9A-Fa-f]{1,8})$")

erros: list[str] = []
avisos: list[str] = []

def ler_funcmap() -> list[tuple[str, int, int]]:
    with FUNCMAP.open(newline="", encoding="utf-8") as f:
        leitor = csv.reader(f)
        cabecalho = next(leitor, None)
        if cabecalho != ["Name", "Start", "End", "Size"]:
            erros.append(f"funcmap.csv: cabeçalho {cabecalho}, esperado Name,Start,End,Size")
            return []
        funcoes = []
        for n, linha in enumerate(leitor, start=2):
            try:
                nome, ini, fin, tam = linha
                ini_i, fin_i, tam_i = int(ini, 16), int(fin, 16), int(tam)
            except ValueError:
                erros.append(f"funcmap.csv:{n}: linha mal formatada: {linha}")
                continue
            if fin_i - ini_i != tam_i:
                erros.append(f"funcmap.csv:{n}: {nome}: Size {tam_i} != End - Start ({fin_i - ini_i})")
            if fin_i <= ini_i:
                erros.append(f"funcmap.csv:{n}: {nome}: End <= Start")
            funcoes.append((nome, ini_i, fin_i))

    vistos: dict[str, int] = {}
    for i, (nome, ini, fin) in enumerate(funcoes):
        if nome in vistos:
            erros.append(f"funcmap.csv: nome repetido {nome}")
        vistos[nome] = ini
        if i and ini < funcoes[i - 1][1]:
            erros.append(f"funcmap.csv: {nome} (0x{ini:08X}) não está ordenada por endereço")
        elif i and ini < funcoes[i - 1][2]:
            erros.append(f"funcmap.csv: {nome} (0x{ini:08X}) sobrepõe-se a {funcoes[i - 1][0]}")
    return funcoes

def seletores(config: dict, chave: str) -> list[tuple[str, int]]:
    valores = config.get("general", {}).get(chave, [])
    saida = []
    for v in valores:
        m = SELECTOR.match(v) if isinstance(v, str) else None
        if not m:
            erros.append(f"recomp.template.toml: {chave}: '{v}' não possui o formato nome@0xENDERECO")
            continue
        saida.append((m["nome"], int(m["dir"], 16)))
    return saida

def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--runtime", type=Path, help="Caminho para o checkout do PS2Recomp (com patches aplicados)")
    args = ap.parse_args()

    funcoes = ler_funcmap()
    inicios = [f[1] for f in funcoes]

    texto = PLANTILLA.read_text(encoding="utf-8")
    for marca in ("@ELF@", "@MAP@", "@OUT@"):
        if marca not in texto:
            erros.append(f"recomp.template.toml: marcador ausente {marca}")
    try:
        config = tomllib.loads(texto)
    except tomllib.TOMLDecodeError as e:
        erros.append(f"recomp.template.toml: TOML inválido: {e}")
        config = {}

    stubs = seletores(config, "stubs")
    entradas = seletores(config, "entry_points")

    for chave, lista in (("stubs", stubs), ("entry_points", entradas)):
        for nome, addr in lista:
            idx = bisect.bisect_right(inicios, addr) - 1
            if idx < 0 or not (funcoes[idx][1] <= addr < funcoes[idx][2]):
                erros.append(f"recomp.template.toml: {chave}: {nome}@0x{addr:08X} está fora de qualquer função do funcmap.csv")

    for e in erros:
        print(f"::error::{e}")
    for a in avisos:
        print(f"::warning::{a}")

    print(
        f"funcmap.csv: {len(funcoes)} funções; stubs: {len(stubs)}; "
        f"entry_points: {len(entradas)}; erros: {len(erros)}; avisos: {len(avisos)}"
    )
    return 1 if erros else 0

if __name__ == "__main__":
    sys.exit(main())
