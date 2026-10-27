#!/usr/bin/env python3
"""Gera o mapa visual de status do port (treemap SVG) e suas tabelas de detalhamento.

Entradas:  docs/estado/dados.toml, config/funcmap.csv
Saídas:    docs/estado/mapa.<idioma>.svg, docs/estado/detalhes.<idioma>.md   (idiomas: en, pt-BR)

Uso:
    python tools/estado/gerar.py             (regenera os arquivos)
    python tools/estado/gerar.py --comprobar (verifica se os arquivos estão atualizados)

Requer apenas a biblioteca padrão (Python 3.11+ por tomllib).
"""
from __future__ import annotations

import argparse
import bisect
import csv
import math
import sys
import tomllib
from dataclasses import dataclass
from html import escape
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[2]
DATOS = RAIZ / "docs" / "estado" / "dados.toml"
FUNCMAP = RAIZ / "config" / "funcmap.csv"
SALIDA = RAIZ / "docs" / "estado"

ESTADOS = ("ok", "parcial", "pendiente")

# chave interna -> (sufixo do arquivo, chave em dados.toml)
IDIOMAS = {
    "pt-BR": ("pt-BR", "pt"),
    "en": ("en", "en")
}

TEXTOS = {
    "pt-BR": {
        "titulo": "Status",
        "librerias": "bibliotecas*",
        "hardware": "hardware",
        "panel_lib": "Bibliotecas do SDK da Sony*",
        "panel_hw": "Hardware do PS2",
        "ok": "Funciona",
        "parcial": "Parcial",
        "pendiente": "Pendente",
        "pie": "* Funções das bibliotecas estáticas da Sony ligadas no executável SLUS_211.15 (config/funcmap.csv). "
               "Hardware: ponderado por componente.",
        "detalle_titulo": "Status do port: detalhes",
        "detalle_intro": "Gerado automaticamente por `tools/estado/gerar.py` a partir de `docs/estado/dados.toml` e "
                         "`config/funcmap.csv`. Não edite diretamente este arquivo.",
        "col_lib": "Biblioteca", "col_func": "Funções", "col_estado": "Status", "col_nota": "Nota",
        "col_comp": "Componente", "col_grupo": "Grupo", "col_peso": "Peso",
        "total": "Total",
    },
    "en": {
        "titulo": "Status",
        "librerias": "libraries*",
        "hardware": "hardware",
        "panel_lib": "Sony SDK libraries*",
        "panel_hw": "PS2 hardware",
        "ok": "Working",
        "parcial": "Partial",
        "pendiente": "Pending",
        "pie": "* Functions of the static Sony libraries linked into SLUS_211.15 (config/funcmap.csv). "
               "Hardware: weighted per component.",
        "detalle_titulo": "Port status: details",
        "detalle_intro": "Generated automatically by `tools/estado/gerar.py` from `docs/estado/dados.toml` and "
                         "`config/funcmap.csv`. Do not edit by hand.",
        "col_lib": "Library", "col_func": "Functions", "col_estado": "Status", "col_nota": "Note",
        "col_comp": "Component", "col_grupo": "Group", "col_peso": "Weight",
        "total": "Total",
    }
}

ICONO = {"ok": "✅", "parcial": "🔧", "pendiente": "⏳"}

@dataclass
class Celda:
    etiqueta: str
    estado: str

@dataclass
class Grupo:
    nombre: str
    celdas: list[Celda]
    pesos: list[float]
    rotular_celdas: bool
    cortos: list[str]

def obter_texto(valor, idioma: str) -> str:
    if valor is None:
        return ""
    if isinstance(valor, str):
        return valor
    chave_idioma = IDIOMAS[idioma][1]
    return valor.get(chave_idioma) or valor.get("pt") or valor.get("en", "")

def validar_estado(estado: str, onde: str) -> str:
    if estado not in ESTADOS:
        sys.exit(f"dados.toml: estado desconhecido '{estado}' em {onde} (use {', '.join(ESTADOS)})")
    return estado

def carregar_funcoes() -> list[tuple[int, int]]:
    with FUNCMAP.open(newline="", encoding="utf-8") as f:
        return sorted((int(r["Start"], 16), int(r["Size"])) for r in csv.DictReader(f))

def processar_librerias(dados: dict, idioma: str) -> tuple[list[Grupo], list[dict]]:
    lib = dados["librerias"]
    entradas = sorted(lib["grupo"], key=lambda g: g["inicio"])
    inicios = [g["inicio"] for g in entradas]
    if inicios[0] > lib["desde"]:
        sys.exit("dados.toml: a primeira biblioteca deve iniciar em `desde` ou antes")
    
    por_nombre: dict[str, list[tuple[int, int]]] = {}
    orden: list[str] = []
    for direccion, tamano in carregar_funcoes():
        if not lib["desde"] <= direccion < lib["hasta"]:
            continue
        g = entradas[bisect.bisect_right(inicios, direccion) - 1]
        if g["nombre"] not in por_nombre:
            por_nombre[g["nombre"]] = []
            orden.append(g["nombre"])
        por_nombre[g["nombre"]].append((direccion, tamano))

    info = {}
    for g in entradas:
        estado = validar_estado(g["estado"], g["nombre"])
        previo = info.get(g["nombre"])
        if previo and previo["estado"] != estado:
            sys.exit(f"dados.toml: '{g['nombre']}' possui estados conflitantes")
        info[g["nombre"]] = {"estado": estado, "nota": obter_texto(g.get("nota"), idioma) or (previo or {}).get("nota", "")}

    grupos, filas = [], []
    for nombre in orden:
        funcs = por_nombre[nombre]
        estado = info[nombre]["estado"]
        celdas = [Celda(f"{nombre} · sub_{d:08X} ({t} B)", estado) for d, t in funcs]
        grupos.append(Grupo(nombre, celdas, [1.0] * len(celdas), False, []))
        filas.append({"nombre": nombre, "n": len(funcs), "estado": estado, "nota": info[nombre]["nota"],
                      "desde": funcs[0][0], "hasta": funcs[-1][0] + funcs[-1][1]})
    return grupos, filas

def processar_hardware(dados: dict, idioma: str) -> tuple[list[Grupo], list[dict]]:
    grupos, filas = [], []
    for g in dados["hardware"]["grupo"]:
        celdas, pesos, cortos = [], [], []
        for c in g["componente"]:
            estado = validar_estado(c["estado"], c["corto"])
            nombre = obter_texto(c["nombre"], idioma)
            nota = obter_texto(c.get("nota"), idioma)
            celdas.append(Celda(nombre + (f" — {nota}" if nota else ""), estado))
            pesos.append(float(c.get("peso", 1)))
            cortos.append(c["corto"])
            filas.append({"grupo": g["nombre"], "nombre": nombre, "estado": estado, "nota": nota,
                          "peso": c.get("peso", 1)})
        grupos.append(Grupo(g["nombre"], celdas, pesos, True, cortos))
    return grupos, filas

def calcular_porcentagem(grupos: list[Grupo]) -> tuple[float, float, float]:
    ok = total = 0.0
    for g in grupos:
        for c, p in zip(g.celdas, g.pesos):
            total += p
            ok += p if c.estado == "ok" else 0.0
    return (100.0 * ok / total if total else 0.0), ok, total

Rect = tuple[float, float, float, float]

def squarify(valores: list[float], x: float, y: float, w: float, h: float) -> list[Rect]:
    total = sum(valores)
    if total <= 0 or not valores:
        return [(x, y, 0.0, 0.0)] * len(valores)
    areas = [v * w * h / total for v in valores]
    rects: list[Rect] = []
    i = 0
    while i < len(areas):
        lado = min(w, h)
        fila = [areas[i]]
        j = i + 1

        def pior(f: list[float]) -> float:
            s = sum(f)
            return max(max(lado * lado * a / (s * s), (s * s) / (lado * lado * a)) for a in f)

        while j < len(areas) and pior(fila + [areas[j]]) <= pior(fila):
            fila.append(areas[j])
            j += 1
        s = sum(fila)
        if w >= h:
            ancho = s / h
            yy = y
            for a in fila:
                rects.append((x, yy, ancho, a / ancho))
                yy += a / ancho
            x, w = x + ancho, w - ancho
        else:
            alto = s / w
            xx = x
            for a in fila:
                rects.append((xx, y, a / alto, alto))
                xx += a / alto
            y, h = y + alto, h - alto
        i = j
    return rects

def calcular_grade(n: int, w: float, h: float) -> tuple[int, int]:
    melhor = (1, n)
    melhor_custo = math.inf
    for cols in range(1, n + 1):
        filas = math.ceil(n / cols)
        cw, ch = w / cols, h / filas
        custo = max(cw / ch, ch / cw) + 0.02 * (cols * filas - n)
        if custo < melhor_custo:
            melhor, melhor_custo = (cols, filas), custo
    return melhor

ANCHO = 900
MARGEN = 16
SEP_PANELES = 20
ALTO_MAPA = 260
HUECO_GRUPO = 2.0
HUECO_CELDA = 1.0

ESTILO = """
  .fondo { fill: #ffffff; }
  .borde { stroke: #d0d7de; }
  .t1 { fill: #1f2328; }
  .t2 { fill: #59636e; }
  .ok { fill: #0ca30c; }
  .parcial { fill: #fab219; }
  .pendiente { fill: #c4c8ce; }
  .rayado { stroke: #8a5a00; }
  .chip { fill: #ffffff; fill-opacity: .85; }
  .badge-k { fill: #59636e; }
  .badge-t { fill: #ffffff; }
  .badge-v-oscuro { fill: #1f2328; }
  .txt-pendiente { fill: #1f2328; }
  .grupo { fill: #ffffff; }
  @media (prefers-color-scheme: dark) {
    .fondo { fill: #0d1117; }
    .borde { stroke: #30363d; }
    .t1 { fill: #e6edf3; }
    .t2 { fill: #9198a1; }
    .pendiente { fill: #4b525c; }
    .chip { fill: #0d1117; fill-opacity: .8; }
    .badge-k { fill: #3d444d; }
    .txt-pendiente { fill: #e6edf3; }
    .grupo { fill: #0d1117; }
  }
"""

FUENTE = "font-family=\"-apple-system,BlinkMacSystemFont,'Segoe UI',Helvetica,Arial,sans-serif\""

def largura_texto(s: str, tam: float) -> float:
    return len(s) * tam * 0.6

def num(v: float) -> str:
    return f"{v:.1f}".rstrip("0").rstrip(".")

def fmt_pct(p: float) -> str:
    return f"{p:.1f}%"

def classe_badge(p: float) -> str:
    return "ok" if p >= 75 else ("parcial" if p >= 40 else "pendiente")

def render_badge(x: float, y: float, chave: str, valor: str, classe: str) -> tuple[list[str], float]:
    tam, alto, pad = 12, 22, 8
    wk = largura_texto(chave, tam) + 2 * pad
    wv = largura_texto(valor, tam) + 2 * pad
    texto_valor = "badge-v-oscuro" if classe == "parcial" else "badge-t"
    partes = [
        f'<rect class="badge-k" x="{num(x)}" y="{num(y)}" width="{num(wk)}" height="{alto}" rx="3"/>',
        f'<rect class="{classe}" x="{num(x + wk)}" y="{num(y)}" width="{num(wv)}" height="{alto}" rx="3"/>',
        f'<rect class="{classe}" x="{num(x + wk)}" y="{num(y)}" width="4" height="{alto}"/>',
        f'<text class="badge-t" x="{num(x + wk / 2)}" y="{num(y + 15)}" font-size="{tam}" text-anchor="middle">{escape(chave)}</text>',
        f'<text class="{texto_valor}" x="{num(x + wk + wv / 2)}" y="{num(y + 15)}" font-size="{tam}" '
        f'font-weight="600" text-anchor="middle">{escape(valor)}</text>',
    ]
    return partes, wk + wv

def desenhar_painel(grupos: list[Grupo], x: float, y: float, w: float, h: float) -> list[str]:
    out = [f'<rect class="grupo" x="{num(x)}" y="{num(y)}" width="{num(w)}" height="{num(h)}"/>']
    grupos = sorted(grupos, key=lambda g: -sum(g.pesos))
    rects = squarify([sum(g.pesos) for g in grupos], x, y, w, h)
    etiquetas: list[str] = []
    for g, (gx, gy, gw, gh) in zip(grupos, rects):
        gx, gy = gx + HUECO_GRUPO / 2, gy + HUECO_GRUPO / 2
        gw, gh = gw - HUECO_GRUPO, gh - HUECO_GRUPO
        if gw <= 0 or gh <= 0:
            continue
        orden = sorted(range(len(g.celdas)), key=lambda i: (ESTADOS.index(g.celdas[i].estado), -g.pesos[i]))
        if g.rotular_celdas:
            sub = squarify([g.pesos[i] for i in orden], gx, gy, gw, gh)
        else:
            cols, filas = calcular_grade(len(orden), gw, gh)
            cw, ch = gw / cols, gh / filas
            sub = [(gx + (k % cols) * cw, gy + (k // cols) * ch, cw, ch) for k in range(len(orden))]
        for i, (cx, cy, cw, ch) in zip(orden, sub):
            c = g.celdas[i]
            rx, ry = cx + HUECO_CELDA / 2, cy + HUECO_CELDA / 2
            rw, rh = max(cw - HUECO_CELDA, 0.5), max(ch - HUECO_CELDA, 0.5)
            relleno = ' fill="url(#rayas)"' if c.estado == "parcial" else ""
            out.append(f'<rect class="{c.estado}" x="{num(rx)}" y="{num(ry)}" width="{num(rw)}" '
                       f'height="{num(rh)}"><title>{escape(c.etiqueta)}</title></rect>')
            if relleno:
                out.append(f'<rect x="{num(rx)}" y="{num(ry)}" width="{num(rw)}" height="{num(rh)}"'
                           f'{relleno} pointer-events="none"/>')
            if g.rotular_celdas:
                corto = g.cortos[i]
                tam = next((t for t in (11, 9) if largura_texto(corto, t) + 6 <= rw and rh >= t + 5), None)
                vertical = False
                if tam is None:
                    tam = next((t for t in (11, 9) if largura_texto(corto, t) + 6 <= rh and rw >= t + 5), None)
                    vertical = tam is not None
                if tam:
                    color = {"ok": "badge-t", "parcial": "badge-v-oscuro", "pendiente": "txt-pendiente"}[c.estado]
                    tx, ty = rx + rw / 2, ry + rh / 2
                    giro = f' transform="rotate(-90 {num(tx)} {num(ty)})"' if vertical else ""
                    out.append(f'<text class="{color}" x="{num(tx)}" y="{num(ty + tam * 0.35)}" '
                               f'font-size="{tam}" text-anchor="middle"{giro} pointer-events="none">{escape(corto)}</text>')
        tam = 11
        cw_chip = largura_texto(g.nombre, tam) + 8
        if cw_chip <= gw and gh >= 16:
            etiquetas.append(f'<rect class="chip" x="{num(gx + 1)}" y="{num(gy + 1)}" width="{num(cw_chip)}" '
                             f'height="15" rx="2" pointer-events="none"/>')
            etiquetas.append(f'<text class="t1" x="{num(gx + 5)}" y="{num(gy + 12)}" font-size="{tam}" '
                             f'pointer-events="none">{escape(g.nombre)}</text>')
    return out + etiquetas

def render_svg(idioma: str, lib: list[Grupo], hw: list[Grupo]) -> str:
    t = TEXTOS[idioma]
    p_lib, ok_lib, tot_lib = calcular_porcentagem(lib)
    p_hw, _, _ = calcular_porcentagem(hw)
    w_panel = (ANCHO - 2 * MARGEN - SEP_PANELES) / 2
    y_badges = 56
    y_paneles = y_badges + 46
    y_mapa = y_paneles + 10
    y_leyenda = y_mapa + ALTO_MAPA + 22
    alto = y_leyenda + 30

    o = [f'<svg xmlns="http://www.w3.org/2000/svg" width="{ANCHO}" height="{alto}" viewBox="0 0 {ANCHO} {alto}" '
         f'{FUENTE} role="img" aria-labelledby="titulo-estado">',
         f'<title id="titulo-estado">{escape(t["titulo"])}: {escape(t["librerias"])} {fmt_pct(p_lib)}, '
         f'{escape(t["hardware"])} {fmt_pct(p_hw)}</title>',
         f"<style>{ESTILO}</style>",
         '<defs><pattern id="rayas" width="6" height="6" patternUnits="userSpaceOnUse" patternTransform="rotate(45)">'
         '<line class="rayado" x1="0" y1="0" x2="0" y2="6" stroke-width="1.5" stroke-opacity=".55"/></pattern></defs>',
         f'<rect class="fondo" width="{ANCHO}" height="{alto}" rx="6"/>',
         f'<text class="t1" x="{MARGEN}" y="34" font-size="24" font-weight="600">{escape(t["titulo"])}</text>',
         f'<line class="borde" x1="{MARGEN}" y1="44" x2="{ANCHO - MARGEN}" y2="44" stroke-width="1"/>']
    x = MARGEN
    for chave, p in ((t["librerias"], p_lib), (t["hardware"], p_hw)):
        partes, ancho = render_badge(x, y_badges, chave, fmt_pct(p), classe_badge(p))
        o += partes
        x += ancho + 8

    for i, (titulo, grupos, extra) in enumerate((
            (t["panel_lib"], lib, f" ({int(ok_lib)}/{int(tot_lib)})"),
            (t["panel_hw"], hw, ""))):
        px = MARGEN + i * (w_panel + SEP_PANELES)
        p, _, _ = calcular_porcentagem(grupos)
        o.append(f'<text class="t1" x="{num(px)}" y="{y_paneles}" font-size="14">'
                 f'{escape(titulo)}: {fmt_pct(p)}{extra}</text>')
        o += desenhar_painel(grupos, px, y_mapa, w_panel, ALTO_MAPA)

    x = MARGEN
    for estado in ESTADOS:
        o.append(f'<rect class="{estado}" x="{x}" y="{y_leyenda - 10}" width="12" height="12" rx="2"/>')
        if estado == "parcial":
            o.append(f'<rect x="{x}" y="{y_leyenda - 10}" width="12" height="12" rx="2" fill="url(#rayas)"/>')
        o.append(f'<text class="t2" x="{x + 17}" y="{y_leyenda}" font-size="12">{escape(t[estado])}</text>')
        x += 17 + largura_texto(t[estado], 12) + 18
    o.append(f'<text class="t2" x="{MARGEN}" y="{y_leyenda + 20}" font-size="11">{escape(t["pie"])}</text>')
    o.append("</svg>")
    return "\n".join(o) + "\n"

def render_markdown(idioma: str, lib: list[Grupo], filas_lib: list[dict], hw: list[Grupo], filas_hw: list[dict]) -> str:
    t = TEXTOS[idioma]
    sufijo = IDIOMAS[idioma][0]
    p_lib, ok_lib, tot_lib = calcular_porcentagem(lib)
    p_hw, _, _ = calcular_porcentagem(hw)
    estado = lambda e: f"{ICONO[e]} {t[e]}"
    o = [f"# {t['detalle_titulo']}", "", f"![{t['titulo']}](mapa.{sufijo}.svg)", "", t["detalle_intro"], "",
         f"## {t['panel_lib']}: {fmt_pct(p_lib)} ({int(ok_lib)}/{int(tot_lib)})", "",
         f"| {t['col_lib']} | {t['col_func']} | {t['col_estado']} | {t['col_nota']} |", "|---|---:|---|---|"]
    for f in sorted(filas_lib, key=lambda f: f["desde"]):
        o.append(f"| `{f['nombre']}` | {f['n']} | {estado(f['estado'])} | {f['nota']} |")
    o += ["", f"## {t['panel_hw']}: {fmt_pct(p_hw)}", "",
          f"| {t['col_grupo']} | {t['col_comp']} | {t['col_peso']} | {t['col_estado']} | {t['col_nota']} |",
          "|---|---|---:|---|---|"]
    for f in filas_hw:
        o.append(f"| {f['grupo']} | {f['nombre']} | {f['peso']} | {estado(f['estado'])} | {f['nota']} |")
    o += ["", t["pie"], ""]
    return "\n".join(o)

def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--comprobar", action="store_true", help="Não grava arquivos; apenas falha se houver defasagem")
    args = ap.parse_args()

    with DATOS.open("rb") as f:
        dados = tomllib.load(f)

    SALIDA.mkdir(parents=True, exist_ok=True)
    esperados: dict[Path, str] = {}
    for idioma in IDIOMAS:
        lib, filas_lib = processar_librerias(dados, idioma)
        hw, filas_hw = processar_hardware(dados, idioma)
        sufijo = IDIOMAS[idioma][0]
        esperados[SALIDA / f"mapa.{sufijo}.svg"] = render_svg(idioma, lib, hw)
        esperados[SALIDA / f"detalhes.{sufijo}.md"] = render_markdown(idioma, lib, filas_lib, hw, filas_hw)

    desfasados = [p for p, c in esperados.items()
                  if not p.exists() or p.read_text(encoding="utf-8") != c]
    if args.comprobar:
        for p in desfasados:
            print(f"desatualizado: {p.relative_to(RAIZ).as_posix()}")
        if desfasados:
            print("Execute: python tools/estado/gerar.py")
        return 1 if desfasados else 0
    for p in desfasados:
        p.write_text(esperados[p], encoding="utf-8", newline="\n")
        print(f"escrito: {p.relative_to(RAIZ).as_posix()}")
    if not desfasados:
        print("Arquivos do mapa de estado já estão atualizados.")
    return 0

if __name__ == "__main__":
    sys.exit(main())
