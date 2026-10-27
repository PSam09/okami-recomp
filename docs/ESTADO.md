# Estado do Projeto — Okami Recomp

Port nativo para PC de *Okami* (PS2, `SLUS-21115`).

## Marcos do Projeto

| Marco | Estado | Notas |
|---|---|---|
| Extração de disco com mapeamento de setores (`.disc_layout`, `.disc_meta`) | ✅ Concluído | 8 arquivos e 53 setores de metadados extraídos |
| Varredura e mapeamento de funções ELF (`tools/elf_functions.py`) | ✅ Concluído | 12.806 funções mapeadas em `config/funcmap.csv` |
| Configuração e validação de stubs (`recomp.template.toml`) | ✅ Concluído | Validado com 0 erros e 0 avisos |
| Pilha de patches de runtime nativo (Waffle565 + melhorias de GS/latência) | ✅ Concluído | 40 patches organizados em `patches/` |
| Ferramentas de automação de erros (`tools/analisar_erros.py`, `tools/auto_fix.py`) | ✅ Concluído | Detecção automática de padrões de compilador e runtime |
| Compilação inicial de C++ gerado com MSVC | 🔧 Em progresso | Pronto para execução com `scripts/2_compilar.cmd` |
| Inicialização de tela e apresentação GS OpenGL | ⏳ Pendente | A ser verificado após compilar `ps2EntryRunner.exe` |
| Sistema de som e streaming CRI ADX nativo | ⏳ Pendente | Identificado em `MODULES/IRX.IMS` |
| Entrada de controles nativa (gamepad / teclado) | ⏳ Pendente | Mapeamento através do backend SDL2 do host |
| Campanha completa jogável | ⏳ Futuro | Objetivos futuros |

## Registro de Pesquisa

- **Extração do disco**: A imagem `Okami (USA).iso` (3.9 GB) contém dois arquivos principais de dados (`_DATA0.AFS` com ~2.14 GB e `_DATA1.AFS` com ~1.79 GB), a tabela de setores `0FLISTDV.DIR`, a lista de arquivos `WOLVES_U.FST` e os módulos `MODULES/IOPRP300.IMG` e `IRX.IMS`.
- **Módulos IRX**: `IRX.IMS` contém `sio2man.irx`, `padman.irx`, `mcman.irx`, `mcserv.irx`, `libsd.irx`, `SDRDRV.IRX`, `sdhd.irx`, `snddrv.irx`, e `cri_adxi.irx`.
- **Estrutura DVP (Vector Unit)**: O executável ELF possui seções `.DVP.ovlytab` e `.DVP.ovlystrtab`, indicando o uso de microprogramas VU0/VU1 dinamicamente intercambiáveis via overlays DVP oficiais da Sony.
