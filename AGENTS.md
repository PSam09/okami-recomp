# Guia para Agentes e Colaboradores — Okami Recomp

Port nativo de *Okami* (PS2, `SLUS-21115`) por recompilação estática com [PS2Recomp](https://github.com/ran-j/PS2Recomp).
Este repositório não contém nenhum arquivo protegido por direitos autorais do jogo nem o código C++ gerado: apenas o código e configurações específicos de Okami.

## Localização dos Componentes

| Tarefa / Alteração | Localização |
|---|---|
| Substituições de funções e diagnósticos do jogo | `src/okami_overrides.cpp` |
| Headers e estruturas de dados auxiliares | `src/*.h` |
| Patches do runtime nativo do PS2Recomp | `patches/` (um por tema) |
| Mapeamento de funções e stubs do recompilador | `config/funcmap.csv`, `config/recomp.template.toml` |
| Scripts de automação do pipeline de build no Windows | `scripts/` (`compilar.ps1`, `executar.ps1`, `.cmd`) |
| Ferramentas de automação e extração de mídia | `tools/` |
| Análise automatizada de padrões de erro | `tools/analisar_erros.py` |
| Correção automatizada em lote (batch auto-fix) | `tools/auto_fix.py` |
| Registro de estado, pesquisas e descobertas | `docs/ESTADO.md` |

## Regra de Ouro: Automação de Erros por Padrões

> **Importante**: Durante o processo de recompilação e execução inicial surgirão múltiplos erros.
> Em vez de corrigir cada erro individualmente à mão:
> 1. Execute sempre `python tools/analisar_erros.py <log>` para identificar classes e padrões recorrentes.
> 2. Projete ou expanda `tools/auto_fix.py` ou scripts dedicados para solucionar categorias inteiras de erros de uma só vez.
> 3. Documente o padrão encontrado e sua solução em `docs/ESTADO.md`.

## Patches do PS2Recomp

- Os patches são aplicados sobre o commit fixado em `scripts/common.ps1` (`$PS2RecompCommit`) na ordem especificada em `scripts/compilar.ps1` com `git apply --ignore-whitespace`.
- Para adicionar um novo patch, adicione o arquivo em `patches/` e registre-o em `scripts/compilar.ps1`.
- Marque alterações manuais no runtime com o comentário identificador `// Okami-Port:`.

## Validações

Antes de enviar alterações para o repositório remoto, valide a integridade da configuração:
```sh
python tools/ci/validar_config.py
python tools/ci/patches.py
```
Certifique-se de que reporte `0 erros; 0 avisos`.

## Legalidade

Nunca adicione nem faça commit de arquivos proprietários do jogo (`SLUS_211.15`, `.AFS`, `.FST`, `.DIR`, `.IRX`, `.iso`), dumps de memória ou capturas de RAM/VRAM. Os diretórios `game/` e `logs/` estão estritamente incluídos no `.gitignore`.
