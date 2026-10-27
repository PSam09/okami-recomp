# Desempenho e Otimizações — Okami Recomp

## Otimizações de Arquitetura

1. **Caminho Rápido de EE (Fastpath)**:
   Os pontos de sincronização do EE atualizam ciclos apenas ao vencer um lote de IOP ou timer agendado (patch `ps2recomp-ee-fastpath.patch`), diminuindo drasticamente a sobrecarga do loop principal.

2. **Processamento em Lotes no GS**:
   Pacotes gráficos GIF são agrupados para minimizar trocas de estado na GPU e chamadas de desenho repetitivas.

3. **Suporte a 120 Hz**:
   Com `OKAMI_HZ=120`, a taxa de atualização da apresentação pode operar acima de 60 FPS em monitores de alta taxa de quadros, mantendo a cadência de áudio e vídeo sincronizada.
