// Okami-Port: Overrides y enlaces nativos para Okami (PS2, SLUS-21115).
// Elimina emulacion de hardware de PS2 a favor de subsistemas nativos de PC.

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
}

void applyOkamiOverrides(PS2Runtime &runtime)
{
    // Diagnostico de hilos de EE con OKAMI_THREAD_WATCH=<s>
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

    // Heap privado del runtime en zona libre (debajo del ELF, que carga en 0x00100000)
    runtime.setPrivateGuestHeap(0x00020000u, 0x000FF000u);

    std::fprintf(stdout, "[okami-port] Overrides nativos aplicados correctamente para Okami (SLUS-21115).\n");
}

PS2_REGISTER_GAME_OVERRIDE("Okami (SLUS-21115)", "SLUS_211.15", 0x00100008u, 0u, applyOkamiOverrides)
