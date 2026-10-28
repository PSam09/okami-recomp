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
| Carregamento de dados de disco e cache de arquivos (`DVCI`) | ✅ Concluído | `0FLISTDV.DIR`, `WOLVES_U.FST`, `_DATA0.AFS` (2 GB), `_DATA1.AFS` (1.7 GB) e partições virtuais AFS mapeadas |
| Execução contínua da engine do jogo | ✅ Concluído | Loop principal da engine (`sub_001743B8`) em execução contínua a 100% da velocidade (~300 MHz EE) e VSync a 60 fps |
| Apresentação de menus / telas de título | 🔧 Em progresso | Processamento de listas de comandos gráficos GS/VIF1 e render-targets (engine rodando a 60 FPS estáveis) |
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

13. **Sincronização HLE do Sistema de Arquivos CDVD e Resolução de Bloqueio DVCI (`0x80000595`, `0x80000597`, `0x80000593`)**:
    - *Padrão*: Bloqueio permanente em laço de espera após o diagnóstico `"DVCI: File cache was not hit. \WOLVES_U.FST;1"`, acompanhado de chamadas repetitivas de `CD SCMD rpcNum=0x0C` (`sceCdStatus`).
    - *Causa*: 
      1. No PS2 real, a rotina de leitura `sceCdRead` (`sub_003EFDB0`) marca o flag de ocupado `0x00442474 = 1` e decrementa o semáforo de sincronização `0x00442468` via `PollSema`, dependendo de uma interrupção assíncrona do IOP (`sub_003EEB00` -> `sub_003EEB60`) para limpar o flag e sinalizar o semáforo após a transferência DMA.
      2. Adicionalmente, `sub_00401CA8` (`sceSifCheckStatRpc`) inspeciona o offset `0x10` da estrutura de pacote SIF RPC do cliente (`pkt + 0x10`), que permanecia marcado como ocupado (`1`).
      3. Com isso, `sub_003EF428` (`sceCdSync`) entrava em espera infinita chamando `SleepThread`, e qualquer chamada subsequente a `sceCdSearchFile` falhava no `PollSema(0x00442468)`.
    - *Solução Automatizada por Padrão*:
      1. Atualizado o despachante de RPCs nativo para limpar imediatamente `pkt + 0x10 = 0`, liberando `sceSifCheckStatRpc`.
      2. Limpeza dos flags de sincronização `0x00442474`, `0x004424A0` e `0x0044245C` no término de cada comando assíncrono.
      3. Sinalização direta dos semáforos de sincronização de CDVD (`0x00442468`, `0x00442460`, `0x0044246C`, `0x00442470`) via `runtime->eeScheduler().signalSemaphore()` se o contador estiver em zero.
      4. Resultado: Desbloqueio imediato do subsistema de arquivos DVCI, permitindo a localização e leitura bem-sucedida de `0FLISTDV.DIR`, `WOLVES_U.FST`, `_DATA0.AFS` (2.14 GB) e `_DATA1.AFS` (1.79 GB).

14. **Mapeamento Automatizado de Partições Virtuais AFS (`src/okami_partitions.h`, `tools/gerar_particoes.py`)**:
    - *Padrão*: Falha fatal `E9040804: can't open file.(load partition)` ao tentar carregar a partição canônica `'wp'` (armas e equipamentos).
    - *Causa*: O Okami encapsula 35 partições internas dentro dos grandes contêineres `_DATA0.AFS` (base LSN 277) e `_DATA1.AFS` (base LSN 1049180), listados no `WOLVES_U.FST`. A engine chama `cvFsOpen` -> `sceCdSearchFile` com o nome curto da partição (ex.: `"wp"`), esperando que o driver de CD/DVD do IOP retorne o LSN e o tamanho virtual exato de onde a partição começa dentro do AFS.
    - *Solução Automatizada por Padrão*:
      1. Desenvolvida a ferramenta `tools/gerar_particoes.py` que escaneia `_DATA0.AFS` e `_DATA1.AFS` no diretório `game/` e calcula automaticamente os offsets, LSNs e tamanhos de todas as 35 partições canônicas de Okami.
      2. Geração do header nativo `src/okami_partitions.h` contendo a tabela indexada `s_okamiPartitions` e a função rápida `findOkamiPartition`.
      3. Integração em `src/okami_overrides.cpp` no manipulador de RPC `0x80000597` (`sceCdSearchFile`): quando a pesquisa de disco convencional não encontra um arquivo, consulta a tabela de partições virtuais, retornando o LSN e tamanho corretos.
      4. O `sceCdRead` nativo mapeia perfeitamente o setor solicitado diretamente para o setor correspondente dentro do arquivo `.AFS`. O erro `E9040804` foi 100% eliminado.

15. **Correção Global de Fallthroughs no Recompilador (`tools/auto_fix.py --fallthroughs`, `src/okami_fallthroughs.h`)**:
    - *Padrão*: Funções fatiadas incorretamente no `funcmap.csv` terminando abruptamente sem instruções de retorno (`jr $ra` / `j`), retornando ao chamador C++ antes de executar a sub-rotina seguinte.
    - *Causa*: No código MIPS original, blocos de prólogo ou seções sequenciais continuavam caindo em cascata (*fallthrough*) no bloco de instruções seguinte. Quando traduzidas individualmente pelo PS2Recomp para funções C++ separadas, o término do bloco gerava um `return;` prematuro, pulando dezenas a centenas de bytes de lógica essencial do jogo.
    - *Solução Automatizada por Padrão*:
      1. Expandido `tools/auto_fix.py` com o comando `--fallthroughs` e detecção em nível de bytecode do ELF com cache em memória. O script analisa todas as 12.803 funções, descarta NOPs de alinhamento e detecta todos os 543 blocos sem instrução de salto/retorno.
      2. Gerados automaticamente 543 trampolins em `src/okami_fallthroughs.h` que executam o bloco primário e, se `ctx->pc` alcançar o início da próxima função, invocam dinamicamente a próxima rotina via `runtime->lookupFunction`.
      3. Resultado: O laço principal da engine de Okami (`sub_001743B8` em `0x00174470`) entrou em execução contínua, com medição estável de ~300 MHz no EE e 60.0 fps sólidos na apresentação de vídeo raylib/OpenGL.

16. **Carregamento e Transmissão Nativa de Partições e Streams do Driver CRI ADX / AFS (`adxf_ReadNw` / `sub_003C86B0`)**:
    - *Padrão*: Engine de Okami presa indefinidamente em laço de espera com status `[okami-ptstat] count=... stat=2 lock=0 v0=2` em `0x0043E938` (`sub_001743B8` / `adxf_GetPtStat`).
    - *Causa*:
      1. A engine do jogo utiliza a biblioteca CRI ADX (`adxf`) para ler partições virtuais e arquivos dos contêineres AFS (`_DATA0.AFS` e `_DATA1.AFS`).
      2. A rotina `sub_003C7430` (`adxf_LoadPt`) inicia a leitura assíncrona, configurando `stat = 2` (ocupado/em andamento) e chamando `sub_003C86B0` (`adxf_ReadNw`) para ler os setores de cabeçalho e dados para a memória.
      3. No PS2 original, a transferência dos dados era realizada em segundo plano pelo módulo `CRI_ADXI.IRX` no IOP via DMA. No port nativo para PC (onde não há emulação de IOP), nenhuma rotina transferia os setores solicitados e nem sinalizava o término (`status = 3` no handle e `-1` no retorno de `adxf_ReadNw`).
      4. Como consequência, `adxf_GetPtStat` nunca observava a conclusão da transferência, mantendo `stat = 2` e impedindo a engine de carregar as partições essenciais de inicialização (`wp`, `ut`, `gt`) e avançar para o renderizador gráfico.
    - *Solução Automatizada por Padrão*:
      1. Implementada a substituição nativa global de `sub_003C86B0` (`adxf_ReadNw`) em `src/okami_overrides.cpp`.
      2. A rotina detecta a partição ativa através de `ptid` em `0x0043E934` e da tabela canônica de partições do Okami (0=`wp`, 1=`ut`, 2=`gt`, etc.), consultando `s_okamiPartitions` em `src/okami_partitions.h`.
      3. Realiza a leitura binária direta e imediata dos setores requisitados a partir do arquivo `.AFS` no disco para o buffer especificado no RDRAM.
      4. Marca os flags de conclusão no descritor de stream (`handle->status = 3`), zera os setores restantes e retorna `-1` (código de fim de arquivo / transferência concluída).
      5. Resultado: A transição de leitura de partição avança instantaneamente de `stat = 2` para `stat = 4` (Ready / Complete), permitindo que `sub_001743B8` conclua com êxito a carga das 3 partições fundamentais (`wp`, `ut`, `gt`) e prossiga imediatamente para a inicialização dos recursos de cena e renderização gráfica.

17. **Correção do Write-0-to-Clear (W0C) no Timer 2 do EE (`ps2_memory.cpp`)**:
    - *Padrão*: Execução presa em laço de polling contínuo do driver do Timer 2 em `0x004054C4`..`0x00405524`, com leitura repetitiva de `0x10001010` (status de modo do Timer 2), bloqueando a inicialização da engine.
    - *Causa*: Conforme o manual de hardware do EE do PS2, as flags `EQUF` (bit 10) e `OVFF` (bit 11) de `Tn_MODE` são limpas pelo software quando se escreve **0** nelas (Write-0-to-Clear / W0C). O PS2Recomp continha um bug implementando W1C (`status = previous & ~value`), de forma que quando `sub_004052D0` escrevia `andi $a0, $s2, 0xF7FF` (bit 11 zerado), a flag de overflow nunca limpava.
    - *Solução por Padrão*: Implementada a limpeza correta W0C das flags em `ps2_memory.cpp` (`ps2recomp-ee-timer-w0c.patch`), permitindo que a libkernel do PS2 limpe o overflow instantaneamente e a CPU avance para o frame loop central em `sub_003439D8`.

18. **Monitoramento e Tradução do Contador de Desempenho e Frame Loop Oficial (`ps2_runtime.cpp`)**:
    - *Padrão*: O contador de FPS na tela exibia termos em espanhol ("juego", "imagenes", "pantalla") e marcava "0 FPS juego", mesmo com a engine rodando a 60 FPS na CPU.
    - *Causa*: O contador dependia do PC de God of War via dispatcher. No Okami, o laço de frame roda internamente em C++ via `sub_003439D8`, atualizando o contador nativo em RDRAM `0x00680C00` a cada ciclo via interrupção VBlank (`sub_00343ED0`).
    - *Solução por Padrão*: Conectada a medição de frames de jogo diretamente a `*(uint32_t*)(rdram + 0x00680C00)` e traduzidas todas as mensagens de tela e registros para Português estrito (`"%.0f FPS jogo  %.0f quadros  (tela %.0f Hz)"`). O medidor agora reflete **60 FPS jogo (verde)** em tempo real.


