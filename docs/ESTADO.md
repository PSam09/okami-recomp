# Estado do Projeto — Okami Recomp

Port nativo para PC de *Okami* (PS2, `SLUS-21115`).

## Marcos do Projeto

| Marco | Estado | Notas |
|---|---|---|
| Extração de disco com mapeamento de setores (`.disc_layout`, `.disc_meta`) | ✅ Concluído | 8 arquivos e 53 setores de metadados extraídos |
| Varredura e mapeamento de funções ELF (`tools/elf_functions.py`) | ✅ Concluído | 12.806 funções mapeadas em `config/funcmap.csv` |
| Configuração e validação de stubs (`recomp.template.toml`) | ✅ Concluído | Validado com 0 erros e 0 avisos |
| Pilha de patches de runtime nativo (Waffle565 + melhorias de GS/latência) | ✅ Concluído | 41 patches organizados em `patches/` (`ps2recomp-okami-runtime.patch` integrado) |
| Ferramentas de automação de erros (`tools/analisar_erros.py`, `tools/auto_fix.py`) | ✅ Concluído | Detecção automática de padrões de compilador, runtime e desmontagem direta do ELF |
| Compilação do executável nativo C++ com MSVC | ✅ Concluído | `ps2EntryRunner.exe` gerado com sucesso via Ninja |
| Inicialização de tela e apresentação GS OpenGL | ✅ Concluído | Janela GLFW/Win32, OpenGL 3.3, FBO 640x512 2x, WASAPI 48kHz |
| Boot do `crt0` e entrada no código principal do jogo | ✅ Concluído | Inicialização do SDK superada; código do jogo em execução em `0x003439D8` |
| Inicialização de subsistemas nativos (IOP Heap, Áudio, DTX/SJUNI, Padman) | ✅ Concluído | Todos os canais de áudio, sintetizador e controle inicializados com sucesso |
| Carregamento de dados de disco e cache de arquivos (`DVCI`) | ✅ Concluído | Virtual Cache Interface ativo; leitura contínua de setores do disco |
| Execução contínua da engine do jogo | 🔧 Em progresso | Mais de 4 bilhões de ciclos EE executados continuamente sem travamentos |
| Apresentação de menus / telas de título | ⏳ Próximo | Renderização de quadros GS pós-inicialização de cena |
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

5. **Loop de Confirmação do SIF RPC (`sceSifCheckInit` em `0x00404698`)**:
   - *Padrão*: Execução presa em laço de inicialização aguardando confirmação do IOP.
   - *Causa*: O SDK da Sony requeria confirmação de boot do IOP em `0x00444B48`.
   - *Solução por Padrão*: Implementado `okamiOverride_SceSifCheckInit` limpando a flag e retornando 1 imediatamente.

6. **Divisão Inteira de 64 Bits MIPS em Software (`__divdi3` / `__udivdi3`)**:
   - *Padrão*: `[guest-branch:missing-target]` em `0x00407348` e consumo massivo de instruções.
   - *Causa*: O `funcmap.csv` cortava a rotina de divisão de 64 bits do GCC antes do delay slot.
   - *Solução por Padrão*: Implementado `okamiOverride_Divdi3` e `okamiOverride_Udivdi3` com divisão nativa x86-64 em 1 ciclo de CPU.

7. **Bypass de Busca de Módulos IRX Soltos (`sub_00214DF0`)**:
   - *Padrão*: O jogo tentava carregar módulos IRX individuais (`SIO2MAN`, `PADMAN`, `LIBSD`, `SDRDRV`, `SDHD`, `SNDDRV`, `CRI_ADXI`, `MCMAN`, `MCSERV`) que estão empacotados em `MODULES/IRX.IMS`.
   - *Causa*: No PC nativo, esses módulos são substituídos por subsistemas nativos do host (XInput / Raylib / WASAPI).
   - *Solução por Padrão*: Implementado `okamiOverride_LoadModule` retornando sucesso imediato (`1`), avançando a inicialização de periféricos sem bloquear.

8. **Família de Getters/Setters Estáticos e Callbacks Indiretos (`0x003D4000..0x003DB000`)**:
   - *Padrão*: Falhas repetitivas de `[guest-branch:missing-target]` em pequenas sub-rotinas de 24 a 48 bytes logo após `jr $ra`.
   - *Causa*: O desensamblador agrupou setters e callbacks (`0x003DAC90`, `0x003DAE70`, `0x003D86F8`, `0x003D6E30`, `0x003D5230`, `0x003DA690`, `0x003D4678`, `0x003D84D0`, `0x003D6C68`) dentro das funções anteriores.
   - *Solução por Padrão*: Varredura completa da seção de texto, identificação de todos os 5 pares da família e implementação nativa em bloco em `src/okami_overrides.cpp`.

9. **Alocação de Heap do IOP (`0x80000003` / `0x00403DC0`)**:
   - *Padrão*: Laço fatal em `SJX_Init` (`"E0100301: SJX_Init can't allocate IOP Heap"`).
   - *Causa*: O jogo invoca o RPC `0x80000003` esperando o endereço de memória alocado no buffer de recepção `0x007BA0C0`.
   - *Solução por Padrão*: Implementada alocação dinâmica alinhada a 64 bytes no manipulador de RPC nativo, retornando ponteiros válidos no RDRAM.

10. **Subsistema DTX / SJUNI / SJX (`0x90000200`)**:
    - *Padrão*: Erros em cascata `"E0100302: SJX_Init can't create DTX"`, `"E0110102: can't creat SJUNI_CreaetRmt"`, `"E0100401: can't create SJX of IOP"`.
    - *Causa*: Uma família inteira de comandos de criação de objetos (`0x0002`, `0x0400`, `0x0422`, `0x0408`) esperava handles/descritores remotos não nulos no `recvBuff`.
    - *Solução por Padrão*: Implementada resposta automática com gerador sequencial de handles únicos para toda a família de comandos do driver `0x90000200`.

11. **Estabilização do Driver de Controle PADMAN (`0x80000100` / `0x80000101`)**:
    - *Padrão*: Laço de dezenas de milhares de consultas repetitivas de `scePadInit` (`0x003ED4B0`).
    - *Causa*: `scePadInit` avalia o offset 12 do buffer de recepção esperando o status `PAD_STATE_STABLE` (`0x0402`).
    - *Solução por Padrão*: Resposta imediata do RPC com o estado estável e versão correspondente, completando `scePadInit` e `scePadPortOpen` na primeira tentativa.

12. **Restauração do Printf Nativo de Diagnóstico (`0x003CA8B0..0x003CA930`)**:
    - *Padrão*: Mensagens de log da engine silenciosas devido ao truncamento de `sub_003CA8B0` para 4 bytes em `funcmap.csv`.
    - *Solução por Padrão*: Conexão de `okamiOverride_Printf` ao `stderr`, revelando mensagens e diagnósticos em tempo real da engine do jogo (`PS2RNA`, `DVCI`).
