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
| Compilação do executável nativo C++ com MSVC | ✅ Concluído | `ps2EntryRunner.exe` gerado com sucesso via Ninja |
| Inicialização de tela e apresentação GS OpenGL | ✅ Concluído | Janela GLFW/Win32, OpenGL 3.3, FBO 640x512 2x, WASAPI 48kHz |
| Boot do `crt0` e entrada no código principal do jogo | ✅ Concluído | Inicialização do SDK superada; código do jogo em execução em `0x003439D8` |
| Inicialização de heap e carregamento de dados do disco | 🔧 Em progresso | Configuração de listas de heap e despacho SIF/IOP em andamento |
| Apresentação de menus / telas de título | ⏳ Próximo | Renderização de quadros GS pós-inicialização de cena |
| Sistema de som e streaming CRI ADX nativo | ⏳ Pendente | Identificado em `MODULES/IRX.IMS` |
| Entrada de controles nativa (gamepad / teclado) | ⏳ Pendente | Mapeamento através do backend SDL2 do host |
| Campanha completa jogável | ⏳ Futuro | Objetivos futuros |

## Registro de Padrões e Soluções Automatizadas

1. **Bug dos Stubs Precoces no crt0 (`0x00100250`)**:
   - *Padrão*: Thread 1 terminando imediatamente (`main thread dormant`) ao inicializar.
   - *Causa*: `SetupThread` e rotinas de encapsulamento no início da RAM continham um `ExitThread` de segurança, que o extrator classificava como stub de syscall do kernel.
   - *Solução Automatizada*: Ajustado `tools/elf_functions.py` para classificar como syscall apenas rotinas acima de `0x003F0000`.

2. **Loop Infinito do Sony SDK `FindAddress` Probe (`sub_00404958`)**:
   - *Padrão*: Execução presa em laço infinito a 295 MHz EE consumindo ciclos sem progredir além do `_InitSys`.
   - *Causa*: O SDK da Sony usa a syscall 0x83 (`FindAddress`) para escanear `0x80000000..0x80080000` em busca da tabela de vetores do kernel para detectar o endereço base da BIOS. No PC nativo, essa memória não é emulada diretamente em RAM.
   - *Solução por Padrão*: Implementado override `okamiOverride_FindAddressProbe` em `src/okami_overrides.cpp`, gravando o endereço base esperado em `0x00444C08` e retornando limpo ao chamador.

3. **Stubs de Construtores/Destrutores C++ do crt0 (`0x003C23A8`, `0x003C23B0`)**:
   - *Padrão*: Falha de salto indireto `missing-target` no encerramento da inicialização do crt0.
   - *Causa*: Chamadas diretas a `_init` e passagem de ponteiro para `_fini` via `atexit`. Ambas as rotinas são apenas `jr $ra; nop`.
   - *Solução por Padrão*: Implementado stub genérico `okamiOverride_NopReturn`.

4. **Tabela Densa vs Trampolins Dinâmicos (`0x00407E38`)**:
   - *Padrão*: `[guest-branch:missing-target]` ao chamar trampolins fora dos limites `[TableBase, TableEnd)` da tabela densa do gerador.
   - *Causa*: Funções localizadas nos últimos bytes da seção `.text` ficavam além do limite estático do array `g_ps2RecompiledFunctionTable`.
   - *Solução por Padrão*: Expandido o runtime com tabela dinâmica de fallback (`m_dynamicFunctions`), permitindo que qualquer função em qualquer endereço do espaço de 32 bits seja registrada e despachada transparentemente.
