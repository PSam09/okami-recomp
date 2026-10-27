# Status do port: detalhes

![Status](mapa.pt-BR.svg)

Gerado automaticamente por `tools/estado/gerar.py` a partir de `docs/estado/dados.toml` e `config/funcmap.csv`. Não edite diretamente este arquivo.

## Bibliotecas do SDK da Sony*: 86.0% (781/908)

| Biblioteca | Funções | Status | Nota |
|---|---:|---|---|
| `libgraph` | 130 | ✅ Funciona | Renderizador nativo OpenGL com render targets (FBO), resolução interna 2x+ |
| `libdma` | 277 | ✅ Funciona | Cadeias DMA despachadas diretamente para a GPU e VIF1/VU1 com buffers reutilizáveis |
| `libcdvd` | 146 | ✅ Funciona | Lê arquivos extraídos diretamente do disco com mapeamento exato de setores (.disc_layout) |
| `libpad` | 67 | 🔧 Parcial | Mapeamento nativo de controle (DualShock 2 / gamepad / teclado via SDL2) |
| `libsd` | 60 | 🔧 Parcial | Motor de som nativo guiado por chamadas LIBSD e streaming direto CRI ADX |
| `libkernel` | 53 | ✅ Funciona | Kernel EE: threads, semáforos, alarmes e despacho de interrupções |
| `sif` | 40 | ✅ Funciona | Comunicação SIF: RPC e DMA entre EE e subsistemas de E/S |
| `libc` | 99 | ✅ Funciona | Biblioteca C padrão nativa (formatação de texto, memória e utilitários) |
| `libm` | 36 | ✅ Funciona | Funções matemáticas em ponto flutuante com controle de arredondamento MXCSR em x86-64 |

## Hardware do PS2: 60.5%

| Grupo | Componente | Peso | Status | Nota |
|---|---|---:|---|---|
| EE | CPU R5900 (recompilada para C++) | 5 | ✅ Funciona | 12.806 funções estaticamente recompiladas para C++ x64 |
| EE | Kernel: threads, semáforos e alarmes | 3 | ✅ Funciona |  |
| EE | FPU (COP1) e instruções multimídia MMI | 2 | ✅ Funciona |  |
| EE | INTC: VSync e interrupção do GS | 2 | ✅ Funciona |  |
| EE | Controlador DMA nativo | 2 | ✅ Funciona | Cadeias DMA vão direto para a GPU sem emulação de barramento |
| EE | Temporizadores nativos | 1 | ✅ Funciona |  |
| GS / VU | GS: primitivas e framebuffer | 3 | 🔧 Parcial | Renderizador OpenGL nativo com resolução interna 2x+ |
| GS / VU | VIF1 e VU1 | 3 | 🔧 Parcial | Microcódigo compilado AOT e UNPACK rápido com suporte a DVP overlays |
| GS / VU | GS: texturas e tabelas CLUT | 2 | 🔧 Parcial | Armazenamento em VRAM da GPU sem custo de emulação de eDRAM |
| GS / VU | GIF (PATH1-3) | 2 | ✅ Funciona |  |
| GS / VU | DVP Overlays / VU0 | 2 | 🔧 Parcial | Gerenciamento de microcódigo via tabelas .DVP.ovlytab no ELF |
| IOP | CPU R3000A / Módulos IRX | 3 | ✅ Funciona | Módulos IRX compilados AOT ou executados via serviços HLE |
| IOP | SPU2: áudio e streaming CRI ADX | 3 | 🔧 Parcial | Motor de som nativo guiado por LIBSD e reprodução de canais ADX |
| IOP | Módulos IRX originais | 2 | ✅ Funciona |  |
| IOP | SIF: RPC e DMA EE ↔ IOP | 2 | ✅ Funciona |  |
| IOP | CDVD: leitor de disco com layout nativo | 2 | ✅ Funciona | Leitura instantânea de setores originais (.disc_layout) |
| IOP | Controle DualShock 2 nativo | 2 | 🔧 Parcial | Serviço de gamepad nativo com suporte a XInput e DualSense |
| IOP | Memory Card nativo | 2 | 🔧 Parcial | Arquivos de save salvos diretamente no sistema de arquivos do PC |

* Funções das bibliotecas estáticas da Sony ligadas no executável SLUS_211.15 (config/funcmap.csv). Hardware: ponderado por componente.
