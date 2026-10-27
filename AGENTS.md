# Guia para Agentes y Colaboradores — Okami Recomp

Port nativo de *Okami* (PS2, `SLUS-21115`) por recompilacion estatica con [PS2Recomp](https://github.com/ran-j/PS2Recomp).
Este repositorio no contiene ningun archivo protegido por derechos de autor del juego ni el codigo C++ generado: solo lo especifico de Okami.

## Ubicacion de Componentes

| Tarea / Cambio | Ubicacion |
|---|---|
| Reemplazos de funciones y diagnosticos del juego | `src/okami_overrides.cpp` |
| Headers y estructuras de datos | `src/*.h` |
| Parches al runtime nativo de PS2Recomp | `patches/` (uno por tema) |
| Mapeo de funciones y stubs del recompilador | `config/funcmap.csv`, `config/recomp.template.toml` |
| Scripts del pipeline de construccion en Windows | `scripts/` (`compilar.ps1`, `ejecutar.ps1`, `.cmd`) |
| Herramientas de automatizacion y extraccion | `tools/` |
| Analisis automatizado de patrones de errores | `tools/analisar_erros.py` |
| Correccion en lote automatica (batch auto-fix) | `tools/auto_fix.py` |
| Registro de estado y hallazgos | `docs/ESTADO.md` |

## Regla de Oro: Automatizacion de Errores por Patrones

> **Importante**: Durante el proceso de recompilacion y ejecucion inicial surgiran numerosos errores.
> En lugar de arreglar cada error individualmente a mano:
> 1. Ejecuta siempre `python tools/analisar_erros.py <log>` para identificar las clases y patrones recurrentes.
> 2. Disena o amplía `tools/auto_fix.py` o scripts dedicados para solucionar categorias enteras de errores de una sola pasada.
> 3. Documenta el patron encontrado y su solucion en `docs/ESTADO.md`.

## Parches de PS2Recomp

- Los parches se aplican sobre el commit fijado en `scripts/common.ps1` (`$PS2RecompCommit`) en el orden especificado en `scripts/compilar.ps1` con `git apply --ignore-whitespace`.
- Para anadir un parche nuevo, anadelo a `patches/` y registralo en `scripts/compilar.ps1`.
- Marca los cambios con un comentario identificativo `// Okami-Port:`.

## Validaciones

Antes de subir cambios, valida la configuracion del proyecto:
```sh
python tools/ci/validar_config.py
```
Asegurate de que reporte `0 errores; 0 avisos`.

## Legalidad

Nunca agregues ni hagas commit de archivos del juego (`SLUS_211.15`, `.AFS`, `.FST`, `.DIR`, `.IRX`, `.iso`), volcados de memoria o capturas de RAM/VRAM. `game/` y `logs/` estan estrictamente en `.gitignore`.
