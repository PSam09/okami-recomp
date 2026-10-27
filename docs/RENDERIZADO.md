# Pipeline de Renderizado — Okami Recomp

## Descarte de la emulacion de GS

En una emulacion tradicional de PS2 (como PCSX2 software o GSdx en modos de compatibilidad estricta), cada primitiva pasa por una emulacion exacta de la memoria de video local de 4 MB de la consola (eDRAM), interpretando registros del GS, bucles de rasterizacion de texturas de 4 u 8 bits con tablas de paleta (CLUT), y lecturas lentas hacia atrás (back-readings).

En Okami Recomp, se utiliza la arquitectura de renderizado por objetivos de renderizado (FBO) en **OpenGL**:
- Los paquetes GIF recibidos del EE o de la VU1 se decodifican y procesan en lotes en la GPU.
- En lugar de mantener una simulacion de VRAM en CPU, las texturas y paletas se cargan en la memoria de video de la GPU del PC en un almacenamiento dedicado de texturas (`texture/CLUT store`).
- La resolucion interna por defecto se procesa a múltiplos nativos (2x+), mejorando nitidez sin artefactos de renderizado.
- Soporte para aceleracion de sombreado y efectos visuales tipicos del estilo artístico "Sumi-e" (tinta japonesa) de Okami.
