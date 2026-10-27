# Pipeline de Renderização Gráfica — Okami Recomp

## Descarte da Emulação de Hardware GS

Em emuladores convencionais de PS2, cada primitiva gráfica precisa ser calculada reproduzindo fielmente a memória local de 4 MB da eDRAM do console, interpretando registros internos de sincronização, limites de páginas de texturas de 4/8 bits com tabelas de paleta (CLUT), e transferências reversas pesadas na CPU.

No Okami Recomp, utiliza-se a arquitetura com alvos de renderização (**OpenGL FBO**):
- Pacotes GIF emitidos pelo EE ou VU1 são agrupados e processados diretamente na GPU.
- Texturas e paletas são mapeadas na memória de vídeo nativa do PC em um armazenamento dedicado (`texture/CLUT store`), eliminando o custo de emulação de VRAM.
- A resolução interna renderiza por padrão em múltiplos nativos (2x+), proporcionando imagem nítida sem perda de estilo.
- Preservação integral dos filtros e efeitos característicos do estilo Sumi-e (aquarela e tinta japonesa) de Okami.
