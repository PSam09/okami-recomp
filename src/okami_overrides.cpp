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
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

namespace ps2_syscalls
{
    void sceSifCallRpc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime);
}

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

    struct DiscEntry
    {
        uint32_t lsn = 0;
        uint32_t size = 0;
        std::string filename;
    };

    static std::vector<DiscEntry> s_discEntries;
    static bool s_discLayoutLoaded = false;

    std::string normalizeDiscName(std::string name)
    {
        if (name.rfind("cdrom0:", 0) == 0) name = name.substr(7);
        else if (name.rfind("cdrom:", 0) == 0) name = name.substr(6);

        while (!name.empty() && (name.front() == '\\' || name.front() == '/'))
            name.erase(name.begin());

        const size_t semi = name.find(';');
        if (semi != std::string::npos)
            name = name.substr(0, semi);

        for (char &c : name)
        {
            if (c == '\\')
                c = '/';
            else
                c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }

        return name;
    }

    void loadDiscLayout()
    {
        if (s_discLayoutLoaded) return;
        s_discLayoutLoaded = true;

        std::ifstream layout(".disc_layout");
        if (!layout.is_open())
        {
            layout.open("game/.disc_layout");
        }

        if (layout.is_open())
        {
            std::string line;
            while (std::getline(layout, line))
            {
                std::istringstream iss(line);
                std::string tag;
                iss >> tag;
                if (tag == "file")
                {
                    DiscEntry entry;
                    iss >> entry.lsn >> entry.size >> entry.filename;
                    s_discEntries.push_back(entry);
                }
            }
        }
        else
        {
            // Fallback para o layout fixo de Okami SLUS-21115
            s_discEntries.push_back({277u, 2147561472u, "_DATA0.AFS"});
            s_discEntries.push_back({1048891u, 275921u, "MODULES/IOPRP300.IMG"});
            s_discEntries.push_back({1049026u, 315008u, "MODULES/IRX.IMS"});
            s_discEntries.push_back({1049180u, 1794191360u, "_DATA1.AFS"});
            s_discEntries.push_back({1925250u, 38u, "0FLISTDV.DIR"});
            s_discEntries.push_back({1925251u, 3903532u, "SLUS_211.15"});
            s_discEntries.push_back({1927158u, 57u, "SYSTEM.CNF"});
            s_discEntries.push_back({1927159u, 73520u, "WOLVES_U.FST"});
        }
    }

    std::ifstream openDiscFile(const std::string &filename)
    {
        std::ifstream stream(filename, std::ios::binary);
        if (!stream.is_open())
        {
            stream.open("game/" + filename, std::ios::binary);
        }
        if (!stream.is_open())
        {
            std::string winPath = filename;
            std::replace(winPath.begin(), winPath.end(), '/', '\\');
            stream.open(winPath, std::ios::binary);
            if (!stream.is_open())
            {
                stream.open("game\\" + winPath, std::ios::binary);
            }
        }
        return stream;
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

    // Override para trampolins de pre-prologo de sceSifSendCmd (0x00401008) e sceSifSendSysCmd (0x00401048)
    // No ELF, essas rotinas ajustam os registradores $v0, $v1 e $t3 e caem diretamente (fallthrough)
    // no prologo addiu $sp em 0x00401014 / 0x00401054. Encaminhamos o fluxo chamando o corpo compilado.
    void okamiOverride_SceSifSendCmd(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t cmd = getRegU32(ctx, 4);
        const uint32_t pktAddr = getRegU32(ctx, 5);
        const uint32_t p0 = readGuest32(rdram, pktAddr);
        const uint32_t p1 = readGuest32(rdram, pktAddr + 4);
        const uint32_t p2 = readGuest32(rdram, pktAddr + 8);
        const uint32_t p3 = readGuest32(rdram, pktAddr + 12);
        std::fprintf(stderr, "[okami-overrides] SceSifSendCmd cmd=0x%08x pkt=0x%08x [0x%08x 0x%08x 0x%08x 0x%08x]\n",
                     cmd, pktAddr, p0, p1, p2, p3);

        // Se for o comando de handshake de inicialização do SIF RPC (0x80000002):
        // No hardware original, o IOP responderia com confirmação escrevendo 1 no status de sistema.
        // Como o port nativo descarta emulação de hardware do IOP, confirmamos o status diretamente.
        if (cmd == 0x80000002u)
        {
            writeGuest32(rdram, 0x007B6F80u, 1u);
        }

        ctx->r[2] = ctx->r[6];   // daddu $v0, $a2, $zero
        ctx->r[3] = ctx->r[7];   // daddu $v1, $a3, $zero
        ctx->r[11] = ctx->r[8];  // daddu $t3, $t0, $zero
        sub_00401014_0x401014(rdram, ctx, runtime);
    }

    void okamiOverride_SceSifSendSysCmd(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        std::fprintf(stderr, "[okami-overrides] okamiOverride_SceSifSendSysCmd cmd=0x%08x\n", getRegU32(ctx, 4));
        ctx->r[2] = ctx->r[6];   // daddu $v0, $a2, $zero
        ctx->r[3] = ctx->r[7];   // daddu $v1, $a3, $zero
        ctx->r[11] = ctx->r[8];  // daddu $t3, $t0, $zero
        sub_00401054_0x401054(rdram, ctx, runtime);
    }

    void okamiOverride_SceSifBindRpc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t clientPtr = getRegU32(ctx, 4);
        const uint32_t rpcId = getRegU32(ctx, 5);
        const uint32_t ra = getRegU32(ctx, 31);
        std::fprintf(stderr, "[okami-overrides] sceSifBindRpc client=0x%08x rpcId=0x%08x ra=0x%08x\n",
                     clientPtr, rpcId, ra);
        ps2_stubs::sceSifBindRpc(rdram, ctx, runtime);

        // Se o subsistema IOP nativo nao possuir o servidor registrado na rota ativa,
        // garantimos que client->server (offset 0x24) seja preenchido com descritor valido
        // no heap guest para que o jogo confirme a conexao imediatamente sem esperar hardware.
        if (clientPtr)
        {
            uint32_t server = readGuest32(rdram, clientPtr + 0x24u);
            if (!server)
            {
                static uint32_t s_nextServerAddr = 0x000F0000u;
                const uint32_t dummyServer = s_nextServerAddr;
                s_nextServerAddr += 0x40u;
                writeGuest32(rdram, dummyServer + 0x00u, rpcId);
                writeGuest32(rdram, clientPtr + 0x24u, dummyServer);
            }
        }
        ctx->pc = ra;
    }

    void okamiOverride_SceSifCallRpc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t clientPtr = getRegU32(ctx, 4);
        const uint32_t rpcNum = getRegU32(ctx, 5);
        const uint32_t sendBuff = getRegU32(ctx, 7);
        const uint32_t recvBuff = getRegU32(ctx, 9);
        const uint32_t ra = getRegU32(ctx, 31);

        uint32_t rpcId = 0u;
        if (clientPtr)
        {
            const uint32_t server = readGuest32(rdram, clientPtr + 0x24u);
            if (server)
            {
                rpcId = readGuest32(rdram, server + 0x00u);
            }
        }

        std::fprintf(stderr, "[okami-overrides] sceSifCallRpc client=0x%08x (rpcId=0x%08x) rpcNum=0x%08x sendBuff=0x%08x recvBuff=0x%08x ra=0x%08x\n",
                     clientPtr, rpcId, rpcNum, sendBuff, recvBuff, ra);

        // RPC 0x80000003: Alocador de IOP Heap nativo
        if (clientPtr == 0x007BA080u || rpcId == 0x80000003u)
        {
            if (rpcNum == 1u) // sceSifAllocIopHeap
            {
                const uint32_t reqSize = sendBuff ? readGuest32(rdram, sendBuff) : 2256u;
                static uint32_t s_nextIopHeap = 0x00080000u;
                const uint32_t allocated = s_nextIopHeap;
                s_nextIopHeap = (s_nextIopHeap + reqSize + 63u) & ~63u; // alinhamento 64 bytes
                if (recvBuff)
                {
                    writeGuest32(rdram, recvBuff, allocated);
                }
                std::fprintf(stderr, "[okami-overrides] sceSifAllocIopHeap reqSize=%u -> iopPtr=0x%08x em recvBuff=0x%08x\n",
                             reqSize, allocated, recvBuff);
            }
            else if (rpcNum == 2u) // sceSifFreeIopHeap
            {
                if (recvBuff)
                {
                    writeGuest32(rdram, recvBuff, 0u);
                }
            }
        }
        // RPC 0x80000100 e 0x80000101: Driver de controle PADMAN do PS2
        else if (clientPtr == 0x007B4B80u || clientPtr == 0x007B4BA8u || rpcId == 0x80000100u || rpcId == 0x80000101u)
        {
            if (recvBuff)
            {
                // Status PAD_STATE_STABLE (4) e versao 2 no byte inferior (0x0402)
                // Offset 12 (0x0C) e lido por sub_003EE2E8 para confirmar versao e estado estavel
                writeGuest32(rdram, recvBuff + 0u, 1u);
                writeGuest32(rdram, recvBuff + 4u, 1u);
                writeGuest32(rdram, recvBuff + 8u, 0u);
                writeGuest32(rdram, recvBuff + 12u, 0x0402u);
            }
            std::fprintf(stderr, "[okami-overrides] PADMAN RPC rpcId=0x%08x rpcNum=%u -> estado estavel 0x0402 em recvBuff=0x%08x\n",
                         rpcId, rpcNum, recvBuff);
        }
        // RPC 0x90000200: Driver DTX / SJUNI / SJX do Okami
        else if (clientPtr == 0x0042CD80u || rpcId == 0x90000200u)
        {
            static uint32_t s_nextDtxHandle = 1u;
            if (rpcNum == 3u) // DTX_Delete
            {
                if (recvBuff)
                {
                    writeGuest32(rdram, recvBuff, 0u);
                }
            }
            else
            {
                // Para comandos de criacao e despache DTX/SJUNI/SJX (rpcNum == 2 ou 0x400..0x4FF),
                // o jogo espera um handle/descritor de objeto remoto nao-nulo e valido retornado no recvBuff.
                const uint32_t handle = s_nextDtxHandle++;
                if (recvBuff)
                {
                    writeGuest32(rdram, recvBuff, handle);
                    writeGuest32(rdram, recvBuff + 4u, handle);
                }
                std::fprintf(stderr, "[okami-overrides] DTX/SJUNI RPC rpcNum=0x%04x -> handle=%u em recvBuff=0x%08x\n",
                             rpcNum, handle, recvBuff);
            }
        }
        // RPC 0x80000597: CD_SERVER_SEARCHFILE (busca de arquivos no disco nativo do PC)
        else if (clientPtr == 0x007B5080u || rpcId == 0x80000597u)
        {
            loadDiscLayout();
            std::string reqPath;
            if (sendBuff)
            {
                const char *rawPath = reinterpret_cast<const char *>(rdram + ((sendBuff + 0x24u) & 0x01FFFFFFu));
                reqPath = normalizeDiscName(rawPath);
            }

            const DiscEntry *found = nullptr;
            for (const auto &entry : s_discEntries)
            {
                if (normalizeDiscName(entry.filename) == reqPath)
                {
                    found = &entry;
                    break;
                }
            }

            if (found && sendBuff)
            {
                writeGuest32(rdram, sendBuff + 0x00u, found->lsn);
                writeGuest32(rdram, sendBuff + 0x04u, found->size);
                char nameBuf[16] = {0};
                std::strncpy(nameBuf, reqPath.c_str(), 15);
                std::memcpy(rdram + ((sendBuff + 0x08u) & 0x01FFFFFFu), nameBuf, 16);
                std::memset(rdram + ((sendBuff + 0x18u) & 0x01FFFFFFu), 0, 8); // date
                if (recvBuff)
                {
                    writeGuest32(rdram, recvBuff, 1u);
                }
                std::fprintf(stderr, "[okami-overrides] sceCdSearchFile '%s' -> lsn=%u size=%u (sucesso)\n",
                             reqPath.c_str(), found->lsn, found->size);
            }
            else
            {
                if (recvBuff)
                {
                    writeGuest32(rdram, recvBuff, 0u);
                }
                std::fprintf(stderr, "[okami-overrides] sceCdSearchFile '%s' -> nao encontrado\n", reqPath.c_str());
            }
        }
        // RPC 0x80000595: CD_SERVER_NCMD (comandos assincronos: sceCdRead, sceCdSeek, etc.)
        else if (clientPtr == 0x00443610u || rpcId == 0x80000595u)
        {
            loadDiscLayout();
            if (rpcNum == 1u && sendBuff) // CD_NCMD_READ
            {
                const uint32_t lsn = readGuest32(rdram, sendBuff + 0x00u);
                const uint32_t sectors = readGuest32(rdram, sendBuff + 0x04u);
                const uint32_t bufAddr = readGuest32(rdram, sendBuff + 0x08u);
                const uint32_t totalBytes = sectors * 2048u;

                bool readSuccess = false;
                for (const auto &entry : s_discEntries)
                {
                    const uint32_t fileSectors = (entry.size + 2047u) / 2048u;
                    if (lsn >= entry.lsn && lsn < entry.lsn + fileSectors)
                    {
                        const uint64_t fileOffset = static_cast<uint64_t>(lsn - entry.lsn) * 2048u;
                        std::ifstream stream = openDiscFile(entry.filename);
                        if (stream.is_open())
                        {
                            stream.seekg(static_cast<std::streamoff>(fileOffset));
                            const size_t bytesToRead = std::min<uint64_t>(totalBytes, entry.size > fileOffset ? entry.size - fileOffset : 0u);
                            uint8_t *dst = rdram + (bufAddr & 0x01FFFFFFu);
                            stream.read(reinterpret_cast<char *>(dst), static_cast<std::streamsize>(bytesToRead));
                            if (bytesToRead < totalBytes)
                            {
                                std::memset(dst + bytesToRead, 0, totalBytes - bytesToRead);
                            }
                            readSuccess = true;
                            std::fprintf(stderr, "[okami-overrides] sceCdRead lsn=%u sectors=%u buf=0x%08x -> %zu bytes lidos de '%s'\n",
                                         lsn, sectors, bufAddr, bytesToRead, entry.filename.c_str());
                        }
                        else
                        {
                            std::fprintf(stderr, "[okami-overrides] sceCdRead nao pode abrir '%s'!\n", entry.filename.c_str());
                        }
                        break;
                    }
                }

                if (!readSuccess)
                {
                    std::fprintf(stderr, "[okami-overrides] sceCdRead lsn=%u sectors=%u buf=0x%08x -> nao mapeado em nenhum arquivo!\n",
                                 lsn, sectors, bufAddr);
                }

                if (recvBuff)
                {
                    writeGuest32(rdram, recvBuff, readSuccess ? 1u : 0u);
                }
            }
            else
            {
                if (recvBuff)
                {
                    writeGuest32(rdram, recvBuff, 1u);
                }
            }
        }
        // RPC 0x80000593: CD_SERVER_SCMD (comandos sincronos: status, disk type, get error)
        else if (clientPtr == 0x00443FC0u || rpcId == 0x80000593u)
        {
            uint32_t callerOfCaller = 0;
            if (ra == 0x003F0144u)
            {
                const uint32_t sp = getRegU32(ctx, 29);
                callerOfCaller = readGuest32(rdram, sp + 0x20u);
            }

            if (recvBuff)
            {
                if (rpcNum == 0x0Cu) // CD_SCMD_STATUS
                {
                    // SCECdStatPause (0x0A): disco pronto para leitura
                    writeGuest32(rdram, recvBuff, 0x0Au);
                }
                else if (rpcNum == 0x03u) // CD_SCMD_GETDISKTYPE
                {
                    writeGuest32(rdram, recvBuff, 0x14u); // SCECdPS2DVD
                }
                else
                {
                    writeGuest32(rdram, recvBuff, 0u);
                }
            }
            std::fprintf(stderr, "[okami-overrides] CD SCMD rpcNum=0x%02x -> recvBuff=0x%08x val=0x%08x (caller=0x%08x)\n",
                         rpcNum, recvBuff, recvBuff ? readGuest32(rdram, recvBuff) : 0u, callerOfCaller);
        }
        // RPC 0x80000592: CD_SERVER_INIT (inicializacao do driver de CD/DVD)
        else if (clientPtr == 0x007B50A8u || rpcId == 0x80000592u)
        {
            if (recvBuff)
            {
                writeGuest32(rdram, recvBuff, 1u);
            }
            std::fprintf(stderr, "[okami-overrides] CD INIT RPC rpcNum=0x%02x -> ok\n", rpcNum);
        }
        else
        {
            ps2_syscalls::sceSifCallRpc(rdram, ctx, runtime);
        }

        // Notifica que o comando SIF RPC foi concluido de forma sincrona no PC:
        // 1. Marca o pacote SIF RPC do cliente como concluido (nao ocupado para sceSifCheckStatRpc)
        if (clientPtr)
        {
            const uint32_t pkt = readGuest32(rdram, clientPtr + 0x00u);
            if (pkt != 0u)
            {
                writeGuest32(rdram, pkt + 0x10u, 0u);
            }
        }

        // 2. Conclui estado do driver CDVD e zera flags de ocupado
        writeGuest32(rdram, 0x00442474u, 0u); // s_cd_sync_flag = 0
        writeGuest32(rdram, 0x004424A0u, 0u); // s_cd_cmd_type = 0
        writeGuest32(rdram, 0x0044245Cu, 0u); // s_cd_busy = 0

        // 3. Sinaliza semaforos de sincronizacao de CDVD se estiverem com count = 0
        for (uint32_t semaAddr : {0x00442468u, 0x00442460u, 0x0044246Cu, 0x00442470u})
        {
            const uint32_t semaId = readGuest32(rdram, semaAddr);
            if (semaId != 0u && semaId != 0xFFFFFFFFu)
            {
                auto *sem = runtime->eeScheduler().semaphore(static_cast<int>(semaId));
                if (sem && sem->count == 0)
                {
                    runtime->eeScheduler().signalSemaphore(static_cast<int>(semaId), false);
                }
            }
        }

        setReturnS32(ctx, 0);
        ctx->pc = ra;
    }

    // Substituicao nativa para sub_003CA8B0 (printf do jogo, 0x003CA8B0..0x003CA930).
    // O funcmap.csv truncou a funcao em 4 bytes (sub_003CA8B0..0x003CA8B4).
    // Implementamos o printf nativo para registrar mensagens de diagnostico do jogo no stderr.
    void okamiOverride_Printf(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t fmtPtr = getRegU32(ctx, 4);
        if (fmtPtr)
        {
            const char *fmt = reinterpret_cast<const char *>(rdram + (fmtPtr & 0x01FFFFFFu));
            const uint32_t a1 = getRegU32(ctx, 5);
            const uint32_t a2 = getRegU32(ctx, 6);
            const uint32_t a3 = getRegU32(ctx, 7);
            char buf[512];
            if (std::strstr(fmt, "%s") != nullptr)
            {
                const char *s1 = a1 ? reinterpret_cast<const char *>(rdram + (a1 & 0x01FFFFFFu)) : "(null)";
                std::snprintf(buf, sizeof(buf), fmt, s1, a2, a3);
            }
            else
            {
                std::snprintf(buf, sizeof(buf), fmt, a1, a2, a3);
            }
            std::fprintf(stderr, "[okami-printf] %s", buf);
        }
        const uint32_t ra = getRegU32(ctx, 31);
        setReturnS32(ctx, 0);
        ctx->pc = ra;
    }

    void okamiOverride_SceSifCheckStatRpc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        const uint32_t ra = getRegU32(ctx, 31);
        ps2_stubs::sceSifCheckStatRpc(rdram, ctx, runtime);
        ctx->pc = ra;
    }

    // Substituicao nativa para sceSdBlockTransStatus (0x003EF428..0x003EF4C8)
    // e sceSdVoiceTransStatus (0x003EF4C8..0x003EF538).
    // No hardware original de PS2, essas rotinas entram em sleep (DelayThread)
    // aguardando que a DMA de som do IOP conclua e limpe as flags em 0x00442474 / 0x004424A0.
    // Como o port nativo descarta emulacao de SPU2 do PS2 e processa audio nativamente via WASAPI/miniaudio,
    // as transferencias sao imediatas e retornam 0 sem bloquear.
    void okamiOverride_SceSdTransStatus(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        writeGuest32(rdram, 0x00442474u, 0u);
        writeGuest32(rdram, 0x004424A0u, 0u);
        const uint32_t ra = getRegU32(ctx, 31);
        setReturnS32(ctx, 0);
        ctx->pc = ra;
    }

    // Override para sceSifCheckInit (0x00404698..0x004046E8).
    // Como os subsistemas nativos em PC nao dependem do boot assincrono do IOP do PS2,
    // confirmamos a inicializacao imediata retornando 1 e limpando o flag em 0x00444B48.
    void okamiOverride_SceSifCheckInit(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        writeGuest32(rdram, 0x00444B48u, 0u);
        const uint32_t ra = getRegU32(ctx, 31);
        std::fprintf(stderr, "[okami-overrides] sceSifCheckInit (0x00404698) chamado! Retornando 1 para ra=0x%08x\n", ra);
        setReturnS32(ctx, 1);
        ctx->pc = ra;
    }

    // Substituicao nativa para rotinas de divisao inteira de 64 bits do GCC / Sony SDK:
    // 0x00407328..0x004078F8: __divdi3 (divisao com sinal de 64 bits)
    // 0x004078F8..0x00407E38: __udivdi3 (divisao sem sinal de 64 bits)
    // No PC x86-64, a divisao e executada em 1 ciclo de CPU nativo, eliminando centenas de
    // instrucoes de software emuladas e corrigindo divisoes artificiais de funcoes no funcmap.csv.
    void okamiOverride_Divdi3(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)rdram;
        (void)runtime;
        const int64_t a0 = GPR_S64(ctx, 4);
        const int64_t a1 = GPR_S64(ctx, 5);
        const uint32_t ra = getRegU32(ctx, 31);
        int64_t quot = 0;
        int64_t rem = 0;
        if (a1 != 0)
        {
            quot = a0 / a1;
            rem = a0 % a1;
        }
        setReturnU64(ctx, static_cast<uint64_t>(quot));
        SET_GPR_S64(ctx, 3, rem);
        ctx->pc = ra;
    }

    void okamiOverride_Udivdi3(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)rdram;
        (void)runtime;
        const uint64_t a0 = GPR_U64(ctx, 4);
        const uint64_t a1 = GPR_U64(ctx, 5);
        const uint32_t ra = getRegU32(ctx, 31);
        uint64_t quot = 0;
        uint64_t rem = 0;
        if (a1 != 0)
        {
            quot = a0 / a1;
            rem = a0 % a1;
        }
        setReturnU64(ctx, quot);
        SET_GPR_U64(ctx, 3, rem);
        ctx->pc = ra;
    }

    // Substituicao nativa para o carregador de modulos IOP do jogo (0x00214DF0..0x00215010).
    // O Okami busca carregar SIO2MAN.IRX, PADMAN.IRX, MCMAN.IRX e MCSERV.IRX.
    // Como o port nativo descarta emulacao de IOP/hardware de PS2 e utiliza subsistemas
    // nativos de PC para controles (Raylib/XInput) e Memory Card, simulamos o carregamento
    // com sucesso imediato (retornando ID de modulo valido 1), evitando loops de busca no disco.
    void okamiOverride_LoadModule(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t pathPtr = getRegU32(ctx, 5); // $a1
        const char *pathStr = pathPtr ? reinterpret_cast<const char *>(rdram + (pathPtr & 0x01FFFFFFu)) : "null";
        std::fprintf(stderr, "[okami-overrides] loadModule path='%s' -> sucesso nativo (ret=1)\n", pathStr);
        const uint32_t ra = getRegU32(ctx, 31);
        setReturnS32(ctx, 1);
        ctx->pc = ra;
    }

    // Substituicao nativa para sub_003DAC90 (0x003DAC90..0x003DACA8).
    // O funcmap.csv agrupou erroneamente 0x003DAC78 e 0x003DAC90 na mesma funcao.
    // Como 0x003DAC90 e chamado via ponteiro indireto (JALR) em 0x003D4788,
    // implementamos a rotina diretamente: carrega $v1=0x00432D38, $v0=0x00432D48, $a0=[$v1] e retorna.
    void okamiOverride_GetStaticPointers_3dac90(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t v1 = 0x00432D38u;
        const uint32_t v0 = 0x00432D48u;
        const uint32_t a0 = readGuest32(rdram, v1);
        SET_GPR_S32(ctx, 3, static_cast<int32_t>(v1));
        SET_GPR_S32(ctx, 2, static_cast<int32_t>(v0));
        SET_GPR_S32(ctx, 4, static_cast<int32_t>(a0));
        const uint32_t ra = getRegU32(ctx, 31);
        ctx->pc = ra;
    }

    // Substituicao nativa para sub_003DAE70 (0x003DAE70..0x003DAE88).
    // O funcmap.csv agrupou 0x003DAE18 e 0x003DAE70 na mesma funcao.
    // Chamada via ponteiro indireto (JALR) em 0x003D4750: grava $a0 em 0x00432D3C e $a1 em 0x00432D40.
    void okamiOverride_SetStaticPointers_3dae70(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t a0 = getRegU32(ctx, 4);
        const uint32_t a1 = getRegU32(ctx, 5);
        writeGuest32(rdram, 0x00432D3Cu, a0);
        writeGuest32(rdram, 0x00432D40u, a1);
        SET_GPR_S32(ctx, 2, 0x00430000);
        SET_GPR_S32(ctx, 3, 0x00430000);
        const uint32_t ra = getRegU32(ctx, 31);
        ctx->pc = ra;
    }

    // Substituicao nativa para sub_003D4678 (0x003D4678..0x003D46A8).
    // O funcmap.csv registrou 0x003D467C deslocado por 4 bytes do inicio real da rotina (0x003D4678).
    // Se invocado via ponteiro indireto registrado por 0x003D4750, executa o callback em 0x0042C43C com arg 0x0042C440.
    void okamiOverride_Callback_3d4678(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t target = readGuest32(rdram, 0x0042C43Cu);
        if (target != 0)
        {
            const uint32_t arg = readGuest32(rdram, 0x0042C440u);
            SET_GPR_S32(ctx, 4, static_cast<int32_t>(arg));
            ctx->pc = target;
        }
        else
        {
            const uint32_t ra = getRegU32(ctx, 31);
            ctx->pc = ra;
        }
    }

    // Familia de getters e setters estaticos e callbacks de despache do Okami (0x003D4000..0x003DB000)
    // O funcmap.csv nao dividiu essas funcoes compactas de 24-48 bytes que residem logo apos jr $ra.
    void okamiOverride_SetStaticPointers_3d86f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t a0 = getRegU32(ctx, 4);
        const uint32_t a1 = getRegU32(ctx, 5);
        writeGuest32(rdram, 0x0042DFACu, a0);
        writeGuest32(rdram, 0x0042DFB0u, a1);
        SET_GPR_S32(ctx, 2, 0x00430000);
        SET_GPR_S32(ctx, 3, 0x00430000);
        const uint32_t ra = getRegU32(ctx, 31);
        ctx->pc = ra;
    }

    void okamiOverride_Callback_3d84d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t target = readGuest32(rdram, 0x0042DFACu);
        if (target != 0)
        {
            const uint32_t arg = readGuest32(rdram, 0x0042DFB0u);
            SET_GPR_S32(ctx, 4, static_cast<int32_t>(arg));
            ctx->pc = target;
        }
        else
        {
            const uint32_t ra = getRegU32(ctx, 31);
            ctx->pc = ra;
        }
    }

    void okamiOverride_SetStaticPointers_3d6e30(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t a0 = getRegU32(ctx, 4);
        const uint32_t a1 = getRegU32(ctx, 5);
        writeGuest32(rdram, 0x0042D114u, a0);
        writeGuest32(rdram, 0x0042D118u, a1);
        SET_GPR_S32(ctx, 2, 0x00430000);
        SET_GPR_S32(ctx, 3, 0x00430000);
        const uint32_t ra = getRegU32(ctx, 31);
        ctx->pc = ra;
    }

    void okamiOverride_Callback_3d6c68(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t target = readGuest32(rdram, 0x0042D114u);
        if (target != 0)
        {
            const uint32_t arg = readGuest32(rdram, 0x0042D118u);
            SET_GPR_S32(ctx, 4, static_cast<int32_t>(arg));
            ctx->pc = target;
        }
        else
        {
            const uint32_t ra = getRegU32(ctx, 31);
            ctx->pc = ra;
        }
    }

    void okamiOverride_SetStaticPointers_3d5230(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t a0 = getRegU32(ctx, 4);
        const uint32_t a1 = getRegU32(ctx, 5);
        if (a0 == 0)
        {
            writeGuest32(rdram, 0x0042C43Cu, 0);
            writeGuest32(rdram, 0x0042C440u, 0);
        }
        else
        {
            writeGuest32(rdram, 0x0042C43Cu, a0);
            writeGuest32(rdram, 0x0042C440u, a1);
        }
        SET_GPR_S32(ctx, 2, 0x00430000);
        SET_GPR_S32(ctx, 3, 0x00430000);
        const uint32_t ra = getRegU32(ctx, 31);
        ctx->pc = ra;
    }

    void okamiOverride_SetStaticPointers_3da690(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t a0 = getRegU32(ctx, 4);
        const uint32_t a1 = getRegU32(ctx, 5);
        if (a0 == 0)
        {
            writeGuest32(rdram, 0x0042E510u, 0);
            writeGuest32(rdram, 0x0042E514u, 0);
        }
        else
        {
            writeGuest32(rdram, 0x0042E510u, a0);
            writeGuest32(rdram, 0x0042E514u, a1);
        }
        SET_GPR_S32(ctx, 2, 0x00430000);
        SET_GPR_S32(ctx, 3, 0x00430000);
        const uint32_t ra = getRegU32(ctx, 31);
        ctx->pc = ra;
    }

    // Interceptador para a funcao de registro de erros/mensagens do jogo (0x003C6EC0..0x003C6F38).
    void okamiOverride_GameLogger(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;
        const uint32_t strPtr = getRegU32(ctx, 4);
        const uint32_t ra = getRegU32(ctx, 31);
        if (strPtr)
        {
            const char *msg = reinterpret_cast<const char *>(rdram + (strPtr & 0x01FFFFFFu));
            std::fprintf(stderr, "[okami-game-log] ra=0x%08x msg='%s'\n", ra, msg);
            char *dst = reinterpret_cast<char *>(rdram + 0x00418DD8u);
            std::strncpy(dst, msg, 255);
            dst[255] = '\0';
        }
        ctx->pc = ra;
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

    // Conexao de fallthrough do Sony SDK para sceSifSendCmd e sceSifSendSysCmd
    replaceFunctionRange(runtime, 0x00401008u, 0x00401014u, okamiOverride_SceSifSendCmd);
    replaceFunctionRange(runtime, 0x00401048u, 0x00401054u, okamiOverride_SceSifSendSysCmd);

    // Substituicao nativa para SIF RPC (elimina espera de hardware do IOP)
    replaceFunctionRange(runtime, 0x004018C8u, 0x00401AA8u, okamiOverride_SceSifBindRpc);
    replaceFunctionRange(runtime, 0x00401AA8u, 0x00401CA8u, okamiOverride_SceSifCallRpc);
    replaceFunctionRange(runtime, 0x00401CA8u, 0x00401CE8u, okamiOverride_SceSifCheckStatRpc);

    // Substituicao nativa para sceSifCheckInit (0x00404698..0x004046E8)
    replaceFunctionRange(runtime, 0x00404698u, 0x004046E8u, okamiOverride_SceSifCheckInit);

    // Status de transferencia de som instantaneo para PC nativo (libsd)
    replaceFunctionRange(runtime, 0x003EF428u, 0x003EF538u, okamiOverride_SceSdTransStatus);

    // Substituicao nativa para operacoes de divisao inteira de 64 bits (__divdi3 / __udivdi3)
    replaceFunctionRange(runtime, 0x00407328u, 0x004078F8u, okamiOverride_Divdi3);
    replaceFunctionRange(runtime, 0x004078F8u, 0x00407E38u, okamiOverride_Udivdi3);

    // Carregamento nativo imediato de modulos IOP (SIO2MAN, PADMAN, MCMAN, MCSERV)
    replaceFunctionRange(runtime, 0x00214DF0u, 0x00215010u, okamiOverride_LoadModule);

    // Funcoes chamadas por ponteiro indireto ou desalinhadas em funcmap.csv (familia 0x003D4000..0x003DB000)
    replaceFunctionRange(runtime, 0x003DAC90u, 0x003DACA8u, okamiOverride_GetStaticPointers_3dac90);
    replaceFunctionRange(runtime, 0x003DAE70u, 0x003DAE88u, okamiOverride_SetStaticPointers_3dae70);
    replaceFunctionRange(runtime, 0x003D4678u, 0x003D46A8u, okamiOverride_Callback_3d4678);
    replaceFunctionRange(runtime, 0x003D86F8u, 0x003D8710u, okamiOverride_SetStaticPointers_3d86f8);
    replaceFunctionRange(runtime, 0x003D84D0u, 0x003D8500u, okamiOverride_Callback_3d84d0);
    replaceFunctionRange(runtime, 0x003D6E30u, 0x003D6E48u, okamiOverride_SetStaticPointers_3d6e30);
    replaceFunctionRange(runtime, 0x003D6C68u, 0x003D6C98u, okamiOverride_Callback_3d6c68);
    replaceFunctionRange(runtime, 0x003D5230u, 0x003D5258u, okamiOverride_SetStaticPointers_3d5230);
    replaceFunctionRange(runtime, 0x003DA690u, 0x003DA6B8u, okamiOverride_SetStaticPointers_3da690);

    // Printf nativo de diagnostico (0x003CA8B0..0x003CA930)
    replaceFunctionRange(runtime, 0x003CA8B0u, 0x003CA930u, okamiOverride_Printf);

    std::fprintf(stdout, "[okami-port] Overrides nativos aplicados com sucesso para Okami (SLUS-21115).\n");
}

PS2_REGISTER_GAME_OVERRIDE("Okami (SLUS-21115)", "SLUS_211.15", 0x00100008u, 0u, applyOkamiOverrides)
