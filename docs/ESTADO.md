# Estado del Proyecto — Okami Recomp

Port nativo para PC de *Okami* (PS2, `SLUS-21115`).

## Hitos

| Hito | Estado | Notas |
|---|---|---|
| Extraccion de disco con mapeo de sectores (`.disc_layout`, `.disc_meta`) | ✅ Completado | 8 archivos y 53 sectores de metadatos extraidos |
| Escaneo y analisis de funciones ELF (`tools/elf_functions.py`) | ✅ Completado | 12.806 funciones mapeadas en `config/funcmap.csv` |
| Configuracion y validacion de stubs (`recomp.template.toml`) | ✅ Completado | Validado en verde con 0 errores y 0 avisos |
| Pila de parches del runtime nativo (Waffle565 + mejoras de latencia/GS) | ✅ Listo | 40 parches integrados en `patches/` |
| Herramientas de automatizacion de errores (`tools/analisar_erros.py`, `tools/auto_fix.py`) | ✅ Operativo | Deteccion automatica de patrones de compilador y runtime |
| Compilacion inicial de C++ generado con MSVC | 🔧 En progreso | Preparado para primera ejecucion con `scripts/2_compilar.cmd` |
| Arranque de pantalla y presentacion GS OpenGL | ⏳ Pendiente | Por verificar tras compilar `ps2EntryRunner.exe` |
| Sistema de sonido y streaming CRI ADX nativo | ⏳ Pendiente | Identificado en `MODULES/IRX.IMS` |
| Entrada de mando nativo (gamepad / teclado) | ⏳ Pendiente | Mapeo mediante backend SDL2 del host |
| Partida jugable completa | ⏳ Pendiente | Objetivos futuros |

## Registro de Investigacion

- **Extraccion del disco**: La imagen `Okami (USA).iso` (3.9 GB) contiene dos contenedores principales (`_DATA0.AFS` de ~2.14 GB y `_DATA1.AFS` de ~1.79 GB), la tabla de sectores `0FLISTDV.DIR`, la lista de archivos `WOLVES_U.FST` y los modulos `MODULES/IOPRP300.IMG` e `IRX.IMS`.
- **Modulos IRX**: `IRX.IMS` contiene `sio2man.irx`, `padman.irx`, `mcman.irx`, `mcserv.irx`, `libsd.irx`, `SDRDRV.IRX`, `sdhd.irx`, `snddrv.irx`, y `cri_adxi.irx`.
- **Estructura DVP (Vector Unit)**: El ELF contiene secciones `.DVP.ovlytab` y `.DVP.ovlystrtab`, lo que indica el uso de microprogramas VU0/VU1 dinamicamente intercambiables mediante overlays DVP.
