# Rendimiento y Optimizaciones — Okami Recomp

## Optimizaciones de Arquitectura

1. **Ruta Rapida de EE**:
   Los puntos de control del EE solo actualizan la contabilidad de ciclos cuando se alcanza un plazo o un lote del IOP (parche `ps2recomp-ee-via-rapida.patch`), reduciendo la sobrecarga de sincronizacion a una fraccion del tiempo normal.

2. **Procesamiento de Lotes GS (Batching)**:
   Los paquetes GIF se procesan en bloques agrupados hacia la cola del GS, permitiendo que la GPU mantenga alta ocupacion sin llamadas de dibujo innecesarias.

3. **Modo 120 Hz**:
   Mediante la variable `OKAMI_HZ=120`, la logica de cuadros y presentacion puede desacoplarse del limite original de 60 Hz NTSC, permitiendo hasta 120 imagenes por segundo fluidas en monitores de alta frecuencia.
