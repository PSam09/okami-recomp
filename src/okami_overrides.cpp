// Okami-Port: Overrides e subsistemas nativos para Okami (PS2, SLUS-21115).
// Elimina emulacao de hardware de PS2 a favor de subsistemas nativos de PC.

#include "okami_overrides.h"
#include "runtime/ee_scheduler.h"
#include "game_overrides.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_host_backend.h"
#include <ps2_recompiled_functions.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <chrono>
#include <string>
#include <algorithm>

namespace
{
    uint32_t readGuest32(const uint8_t *rdram, uint32_t addr)
    {
        uint32_t val = 0;
        std::memcpy(&val, rdram + (addr & 0x01FFFFFFu), sizeof(val));
        return val;
    }

    void writeGuest32(uint8_t *rdram, uint32_t addr, uint32_t value)
    {
        std::memcpy(rdram + (addr & 0x01FFFFFFu), &value, sizeof(value));
    }

    // Override para a rotina de busca de tabela do Sony SDK (FindAddress probe).
    // No hardware original, a biblioteca do SDK varria 0x80000000..0x80080000 em busca de ponteiros do kernel.
    // No runtime nativo em PC, essa tabela interna não reside na RAM simulada.
    // Gravamos um endereco base valido em 0x00444C08 e retornamos ao chamador (_InitSys).
    void okamiOverride_FindAddressProbe(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        writeGuest32(rdram, 0x00444C08u, 0x80001000u);
        const uint32_t returnAddress = getRegU32(ctx, 31);
        ctx->pc = returnAddress;
    }

    // Override simples para rotinas vazias/stubs do crt0 (ex: _init e _fini: jr $ra; nop)
    void okamiOverride_NopReturn(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)rdram;
        (void)runtime;
        const uint32_t returnAddress = getRegU32(ctx, 31);
        ctx->pc = returnAddress;
    }

    // Override do trampolim 0x00407E38 (registrador de heap entry no inicio do jogo)
    void okamiOverride_RegisterHeapEntry(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t a0 = 0x004463F0u;
        const uint32_t a1 = 0x007CDD70u;
        const uint32_t head = readGuest32(rdram, 0x007BDA50u);
        writeGuest32(rdram, a1 + 0x0Cu, a0);
        writeGuest32(rdram, a1 + 0x14u, head);
        writeGuest32(rdram, 0x007BDA50u, a1);
        writeGuest32(rdram, a1 + 0x08u, a0);
        writeGuest32(rdram, a1 + 0x04u, 0u);
        writeGuest32(rdram, a1 + 0x00u, 0u);
        writeGuest32(rdram, a1 + 0x10u, 0u);
        ctx->pc = getRegU32(ctx, 31);
    }

    // Override do trampolim 0x00407E50 (desregistrador de heap entry)
    void okamiOverride_UnregisterHeapEntry(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t targetA0 = 0x004463F0u;
        uint32_t prev = 0x007BDA50u;
        uint32_t curr = readGuest32(rdram, prev);
        while (curr != 0u)
        {
            const uint32_t entryA0 = readGuest32(rdram, curr + 0x08u);
            const uint32_t next = readGuest32(rdram, curr + 0x14u);
            if (entryA0 == targetA0)
            {
                writeGuest32(rdram, prev, next);
                break;
            }
            prev = curr + 0x14u;
            curr = next;
        }
        ctx->pc = getRegU32(ctx, 31);
    }

    void replaceFunctionRange(PS2Runtime &runtime, uint32_t startAddr, uint32_t endAddr, PS2Runtime::RecompiledFunction fn)
    {
        for (uint32_t addr = startAddr; addr < endAddr; addr += 4u)
        {
            runtime.replaceFunction(addr, fn);
        }
    }
}

void applyOkamiOverrides(PS2Runtime &runtime)
{
    // Diagnostico de threads EE com OKAMI_THREAD_WATCH=<s>
    if (const char *watch = std::getenv("OKAMI_THREAD_WATCH"))
    {
        const double period = std::max(1.0, std::atof(watch));
        std::thread([&runtime, period] {
            for (;;)
            {
                std::this_thread::sleep_for(std::chrono::duration<double>(period));
                const EeKernelSnapshot snapshot = runtime.eeScheduler().snapshot();
                std::fprintf(stderr, "[okami-threads] running=%d cycle=%llu\n", snapshot.runningThreadId,
                             static_cast<unsigned long long>(snapshot.eeCycle));
                for (const EeThreadSnapshot &t : snapshot.threads)
                {
                    std::fprintf(stderr, "[okami-threads]   id=%d prio=%d status=%d wait=%d/%d pc=%08x ra=%08x\n",
                                 t.id, t.currentPriority, int(t.status), int(t.waitReason), t.waitId, t.pc, t.ra);
                }
            }
        }).detach();
    }

    // Heap privado do runtime em zona livre (abaixo do ELF, que carrega em 0x00100000)
    runtime.setPrivateGuestHeap(0x00020000u, 0x000FF000u);

    // Bypassa o loop infinito de FindAddress probe em sub_00404958 (0x00404958..0x00404A58)
    replaceFunctionRange(runtime, 0x00404958u, 0x00404A58u, okamiOverride_FindAddressProbe);

    // Stubs de inicializacao C++ _init e _fini no crt0 (0x003C23A8..0x003C23B8: jr $ra; nop)
    replaceFunctionRange(runtime, 0x003C23A8u, 0x003C23B8u, okamiOverride_NopReturn);

    // Trampolins de gerenciamento de heap em 0x00407E38 e 0x00407E50
    replaceFunctionRange(runtime, 0x00407E38u, 0x00407E50u, okamiOverride_RegisterHeapEntry);
    replaceFunctionRange(runtime, 0x00407E50u, 0x00407E5Cu, okamiOverride_UnregisterHeapEntry);

    std::fprintf(stdout, "[okami-port] Overrides nativos aplicados com sucesso para Okami (SLUS-21115).\n");
}

PS2_REGISTER_GAME_OVERRIDE("Okami (SLUS-21115)", "SLUS_211.15", 0x00100008u, 0u, applyOkamiOverrides)
