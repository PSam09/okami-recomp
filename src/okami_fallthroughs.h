// Okami-Port: Trampolins de fallthrough gerados automaticamente por tools/auto_fix.py --fallthroughs
// Conecta blocos de prologo truncados em funcmap.csv diretamente a funcao alvo.
#pragma once

#include "ps2_runtime.h"
#include <ps2_recompiled_functions.h>

namespace okami_fallthroughs
{
    inline void chain_0x00130b20(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00130B20_0x130b20(rdram, ctx, runtime);
        if (ctx->pc == 0x00130B24u)
        {
            auto fn = runtime->lookupFunction(0x00130B24u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00132378(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00132378_0x132378(rdram, ctx, runtime);
        if (ctx->pc == 0x0013237Cu)
        {
            auto fn = runtime->lookupFunction(0x0013237Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00134268(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00134268_0x134268(rdram, ctx, runtime);
        if (ctx->pc == 0x0013426Cu)
        {
            auto fn = runtime->lookupFunction(0x0013426Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00134c28(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00134C28_0x134c28(rdram, ctx, runtime);
        if (ctx->pc == 0x00134C2Cu)
        {
            auto fn = runtime->lookupFunction(0x00134C2Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001368a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001368A0_0x1368a0(rdram, ctx, runtime);
        if (ctx->pc == 0x00136900u)
        {
            auto fn = runtime->lookupFunction(0x00136900u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00136a78(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00136A78_0x136a78(rdram, ctx, runtime);
        if (ctx->pc == 0x00136B20u)
        {
            auto fn = runtime->lookupFunction(0x00136B20u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00136bf0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00136BF0_0x136bf0(rdram, ctx, runtime);
        if (ctx->pc == 0x00136BF4u)
        {
            auto fn = runtime->lookupFunction(0x00136BF4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00136d70(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00136D70_0x136d70(rdram, ctx, runtime);
        if (ctx->pc == 0x00136E78u)
        {
            auto fn = runtime->lookupFunction(0x00136E78u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00144048(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00144048_0x144048(rdram, ctx, runtime);
        if (ctx->pc == 0x00144240u)
        {
            auto fn = runtime->lookupFunction(0x00144240u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00144310(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00144310_0x144310(rdram, ctx, runtime);
        if (ctx->pc == 0x00144324u)
        {
            auto fn = runtime->lookupFunction(0x00144324u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00148b60(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00148B60_0x148b60(rdram, ctx, runtime);
        if (ctx->pc == 0x00148BB0u)
        {
            auto fn = runtime->lookupFunction(0x00148BB0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0014a9d8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0014A9D8_0x14a9d8(rdram, ctx, runtime);
        if (ctx->pc == 0x0014A9DCu)
        {
            auto fn = runtime->lookupFunction(0x0014A9DCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0014c108(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0014C108_0x14c108(rdram, ctx, runtime);
        if (ctx->pc == 0x0014C228u)
        {
            auto fn = runtime->lookupFunction(0x0014C228u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001546e0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001546E0_0x1546e0(rdram, ctx, runtime);
        if (ctx->pc == 0x001546E4u)
        {
            auto fn = runtime->lookupFunction(0x001546E4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0015fba0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0015FBA0_0x15fba0(rdram, ctx, runtime);
        if (ctx->pc == 0x0015FBA4u)
        {
            auto fn = runtime->lookupFunction(0x0015FBA4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00161400(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00161400_0x161400(rdram, ctx, runtime);
        if (ctx->pc == 0x00161450u)
        {
            auto fn = runtime->lookupFunction(0x00161450u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00161450(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00161450_0x161450(rdram, ctx, runtime);
        if (ctx->pc == 0x001614A0u)
        {
            auto fn = runtime->lookupFunction(0x001614A0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00161588(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00161588_0x161588(rdram, ctx, runtime);
        if (ctx->pc == 0x0016158Cu)
        {
            auto fn = runtime->lookupFunction(0x0016158Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00161db0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00161DB0_0x161db0(rdram, ctx, runtime);
        if (ctx->pc == 0x00161DB4u)
        {
            auto fn = runtime->lookupFunction(0x00161DB4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001648c8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001648C8_0x1648c8(rdram, ctx, runtime);
        if (ctx->pc == 0x001648CCu)
        {
            auto fn = runtime->lookupFunction(0x001648CCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00164cb8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00164CB8_0x164cb8(rdram, ctx, runtime);
        if (ctx->pc == 0x00164CBCu)
        {
            auto fn = runtime->lookupFunction(0x00164CBCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00164d10(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00164D10_0x164d10(rdram, ctx, runtime);
        if (ctx->pc == 0x00164D58u)
        {
            auto fn = runtime->lookupFunction(0x00164D58u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00165ca8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00165CA8_0x165ca8(rdram, ctx, runtime);
        if (ctx->pc == 0x00165CACu)
        {
            auto fn = runtime->lookupFunction(0x00165CACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001666a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001666A0_0x1666a0(rdram, ctx, runtime);
        if (ctx->pc == 0x001666A4u)
        {
            auto fn = runtime->lookupFunction(0x001666A4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00169238(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00169238_0x169238(rdram, ctx, runtime);
        if (ctx->pc == 0x001692B8u)
        {
            auto fn = runtime->lookupFunction(0x001692B8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016a010(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016A010_0x16a010(rdram, ctx, runtime);
        if (ctx->pc == 0x0016A1D0u)
        {
            auto fn = runtime->lookupFunction(0x0016A1D0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016a550(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016A550_0x16a550(rdram, ctx, runtime);
        if (ctx->pc == 0x0016A55Cu)
        {
            auto fn = runtime->lookupFunction(0x0016A55Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016af50(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016AF50_0x16af50(rdram, ctx, runtime);
        if (ctx->pc == 0x0016AF68u)
        {
            auto fn = runtime->lookupFunction(0x0016AF68u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016b9d8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016B9D8_0x16b9d8(rdram, ctx, runtime);
        if (ctx->pc == 0x0016B9DCu)
        {
            auto fn = runtime->lookupFunction(0x0016B9DCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016ba28(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016BA28_0x16ba28(rdram, ctx, runtime);
        if (ctx->pc == 0x0016BA2Cu)
        {
            auto fn = runtime->lookupFunction(0x0016BA2Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016c860(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016C860_0x16c860(rdram, ctx, runtime);
        if (ctx->pc == 0x0016C898u)
        {
            auto fn = runtime->lookupFunction(0x0016C898u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016cc68(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016CC68_0x16cc68(rdram, ctx, runtime);
        if (ctx->pc == 0x0016CC6Cu)
        {
            auto fn = runtime->lookupFunction(0x0016CC6Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016cf18(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016CF18_0x16cf18(rdram, ctx, runtime);
        if (ctx->pc == 0x0016CF1Cu)
        {
            auto fn = runtime->lookupFunction(0x0016CF1Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016cf80(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016CF80_0x16cf80(rdram, ctx, runtime);
        if (ctx->pc == 0x0016CF84u)
        {
            auto fn = runtime->lookupFunction(0x0016CF84u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016d030(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016D030_0x16d030(rdram, ctx, runtime);
        if (ctx->pc == 0x0016D034u)
        {
            auto fn = runtime->lookupFunction(0x0016D034u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016d0d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016D0D0_0x16d0d0(rdram, ctx, runtime);
        if (ctx->pc == 0x0016D0D4u)
        {
            auto fn = runtime->lookupFunction(0x0016D0D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016d5f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016D5F0_0x16d5f0(rdram, ctx, runtime);
        if (ctx->pc == 0x0016D620u)
        {
            auto fn = runtime->lookupFunction(0x0016D620u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0016d6e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0016D6E8_0x16d6e8(rdram, ctx, runtime);
        if (ctx->pc == 0x0016D708u)
        {
            auto fn = runtime->lookupFunction(0x0016D708u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00170340(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00170340_0x170340(rdram, ctx, runtime);
        if (ctx->pc == 0x001703B0u)
        {
            auto fn = runtime->lookupFunction(0x001703B0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00170710(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00170710_0x170710(rdram, ctx, runtime);
        if (ctx->pc == 0x00170A70u)
        {
            auto fn = runtime->lookupFunction(0x00170A70u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00170b08(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00170B08_0x170b08(rdram, ctx, runtime);
        if (ctx->pc == 0x00170B0Cu)
        {
            auto fn = runtime->lookupFunction(0x00170B0Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001721b8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001721B8_0x1721b8(rdram, ctx, runtime);
        if (ctx->pc == 0x001721BCu)
        {
            auto fn = runtime->lookupFunction(0x001721BCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001739d8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001739D8_0x1739d8(rdram, ctx, runtime);
        if (ctx->pc == 0x00173A10u)
        {
            auto fn = runtime->lookupFunction(0x00173A10u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00174778(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00174778_0x174778(rdram, ctx, runtime);
        if (ctx->pc == 0x0017477Cu)
        {
            auto fn = runtime->lookupFunction(0x0017477Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00174838(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00174838_0x174838(rdram, ctx, runtime);
        if (ctx->pc == 0x0017483Cu)
        {
            auto fn = runtime->lookupFunction(0x0017483Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00174eb0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00174EB0_0x174eb0(rdram, ctx, runtime);
        if (ctx->pc == 0x00174EB4u)
        {
            auto fn = runtime->lookupFunction(0x00174EB4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00175070(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00175070_0x175070(rdram, ctx, runtime);
        if (ctx->pc == 0x00175074u)
        {
            auto fn = runtime->lookupFunction(0x00175074u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001784a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001784A0_0x1784a0(rdram, ctx, runtime);
        if (ctx->pc == 0x001784A4u)
        {
            auto fn = runtime->lookupFunction(0x001784A4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00178758(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00178758_0x178758(rdram, ctx, runtime);
        if (ctx->pc == 0x001787B0u)
        {
            auto fn = runtime->lookupFunction(0x001787B0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00179568(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00179568_0x179568(rdram, ctx, runtime);
        if (ctx->pc == 0x0017956Cu)
        {
            auto fn = runtime->lookupFunction(0x0017956Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00179590(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00179590_0x179590(rdram, ctx, runtime);
        if (ctx->pc == 0x00179594u)
        {
            auto fn = runtime->lookupFunction(0x00179594u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0017a418(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0017A418_0x17a418(rdram, ctx, runtime);
        if (ctx->pc == 0x0017A41Cu)
        {
            auto fn = runtime->lookupFunction(0x0017A41Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0017c978(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0017C978_0x17c978(rdram, ctx, runtime);
        if (ctx->pc == 0x0017C97Cu)
        {
            auto fn = runtime->lookupFunction(0x0017C97Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0017d0d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0017D0D0_0x17d0d0(rdram, ctx, runtime);
        if (ctx->pc == 0x0017D0D4u)
        {
            auto fn = runtime->lookupFunction(0x0017D0D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00181c70(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00181C70_0x181c70(rdram, ctx, runtime);
        if (ctx->pc == 0x00181C74u)
        {
            auto fn = runtime->lookupFunction(0x00181C74u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00181d30(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00181D30_0x181d30(rdram, ctx, runtime);
        if (ctx->pc == 0x00181D34u)
        {
            auto fn = runtime->lookupFunction(0x00181D34u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0018c210(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0018C210_0x18c210(rdram, ctx, runtime);
        if (ctx->pc == 0x0018C214u)
        {
            auto fn = runtime->lookupFunction(0x0018C214u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0018d660(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0018D660_0x18d660(rdram, ctx, runtime);
        if (ctx->pc == 0x0018D664u)
        {
            auto fn = runtime->lookupFunction(0x0018D664u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0018dc68(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0018DC68_0x18dc68(rdram, ctx, runtime);
        if (ctx->pc == 0x0018DC6Cu)
        {
            auto fn = runtime->lookupFunction(0x0018DC6Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0018f578(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0018F578_0x18f578(rdram, ctx, runtime);
        if (ctx->pc == 0x0018F848u)
        {
            auto fn = runtime->lookupFunction(0x0018F848u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00191e78(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00191E78_0x191e78(rdram, ctx, runtime);
        if (ctx->pc == 0x00191E7Cu)
        {
            auto fn = runtime->lookupFunction(0x00191E7Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00192b60(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00192B60_0x192b60(rdram, ctx, runtime);
        if (ctx->pc == 0x001933D0u)
        {
            auto fn = runtime->lookupFunction(0x001933D0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00194010(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00194010_0x194010(rdram, ctx, runtime);
        if (ctx->pc == 0x0019401Cu)
        {
            auto fn = runtime->lookupFunction(0x0019401Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001944d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001944D0_0x1944d0(rdram, ctx, runtime);
        if (ctx->pc == 0x001944D4u)
        {
            auto fn = runtime->lookupFunction(0x001944D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00197da0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00197DA0_0x197da0(rdram, ctx, runtime);
        if (ctx->pc == 0x00197DA4u)
        {
            auto fn = runtime->lookupFunction(0x00197DA4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001982e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001982E8_0x1982e8(rdram, ctx, runtime);
        if (ctx->pc == 0x00198388u)
        {
            auto fn = runtime->lookupFunction(0x00198388u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0019f700(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0019F700_0x19f700(rdram, ctx, runtime);
        if (ctx->pc == 0x0019F70Cu)
        {
            auto fn = runtime->lookupFunction(0x0019F70Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001b27e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001B27E8_0x1b27e8(rdram, ctx, runtime);
        if (ctx->pc == 0x001B2828u)
        {
            auto fn = runtime->lookupFunction(0x001B2828u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001b2a80(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001B2A80_0x1b2a80(rdram, ctx, runtime);
        if (ctx->pc == 0x001B2AB0u)
        {
            auto fn = runtime->lookupFunction(0x001B2AB0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001b3270(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001B3270_0x1b3270(rdram, ctx, runtime);
        if (ctx->pc == 0x001B3274u)
        {
            auto fn = runtime->lookupFunction(0x001B3274u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001b3698(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001B3698_0x1b3698(rdram, ctx, runtime);
        if (ctx->pc == 0x001B369Cu)
        {
            auto fn = runtime->lookupFunction(0x001B369Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001b3a18(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001B3A18_0x1b3a18(rdram, ctx, runtime);
        if (ctx->pc == 0x001B3A1Cu)
        {
            auto fn = runtime->lookupFunction(0x001B3A1Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001b79e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001B79E8_0x1b79e8(rdram, ctx, runtime);
        if (ctx->pc == 0x001B7A28u)
        {
            auto fn = runtime->lookupFunction(0x001B7A28u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001b83f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001B83F8_0x1b83f8(rdram, ctx, runtime);
        if (ctx->pc == 0x001B83FCu)
        {
            auto fn = runtime->lookupFunction(0x001B83FCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c3940(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C3940_0x1c3940(rdram, ctx, runtime);
        if (ctx->pc == 0x001C3944u)
        {
            auto fn = runtime->lookupFunction(0x001C3944u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c52d8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C52D8_0x1c52d8(rdram, ctx, runtime);
        if (ctx->pc == 0x001C52DCu)
        {
            auto fn = runtime->lookupFunction(0x001C52DCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c56e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C56E8_0x1c56e8(rdram, ctx, runtime);
        if (ctx->pc == 0x001C56F0u)
        {
            auto fn = runtime->lookupFunction(0x001C56F0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c57a8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C57A8_0x1c57a8(rdram, ctx, runtime);
        if (ctx->pc == 0x001C57ACu)
        {
            auto fn = runtime->lookupFunction(0x001C57ACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c58f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C58F8_0x1c58f8(rdram, ctx, runtime);
        if (ctx->pc == 0x001C58FCu)
        {
            auto fn = runtime->lookupFunction(0x001C58FCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c5c08(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C5C08_0x1c5c08(rdram, ctx, runtime);
        if (ctx->pc == 0x001C5C0Cu)
        {
            auto fn = runtime->lookupFunction(0x001C5C0Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c5ce8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C5CE8_0x1c5ce8(rdram, ctx, runtime);
        if (ctx->pc == 0x001C5CECu)
        {
            auto fn = runtime->lookupFunction(0x001C5CECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c5d70(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C5D70_0x1c5d70(rdram, ctx, runtime);
        if (ctx->pc == 0x001C5D78u)
        {
            auto fn = runtime->lookupFunction(0x001C5D78u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c5da8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C5DA8_0x1c5da8(rdram, ctx, runtime);
        if (ctx->pc == 0x001C5DB0u)
        {
            auto fn = runtime->lookupFunction(0x001C5DB0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c6118(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C6118_0x1c6118(rdram, ctx, runtime);
        if (ctx->pc == 0x001C611Cu)
        {
            auto fn = runtime->lookupFunction(0x001C611Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c6198(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C6198_0x1c6198(rdram, ctx, runtime);
        if (ctx->pc == 0x001C619Cu)
        {
            auto fn = runtime->lookupFunction(0x001C619Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c6208(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C6208_0x1c6208(rdram, ctx, runtime);
        if (ctx->pc == 0x001C620Cu)
        {
            auto fn = runtime->lookupFunction(0x001C620Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c6468(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C6468_0x1c6468(rdram, ctx, runtime);
        if (ctx->pc == 0x001C646Cu)
        {
            auto fn = runtime->lookupFunction(0x001C646Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c66b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C66B0_0x1c66b0(rdram, ctx, runtime);
        if (ctx->pc == 0x001C66B4u)
        {
            auto fn = runtime->lookupFunction(0x001C66B4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c75c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C75C0_0x1c75c0(rdram, ctx, runtime);
        if (ctx->pc == 0x001C7650u)
        {
            auto fn = runtime->lookupFunction(0x001C7650u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c7650(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C7650_0x1c7650(rdram, ctx, runtime);
        if (ctx->pc == 0x001C76B8u)
        {
            auto fn = runtime->lookupFunction(0x001C76B8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c77e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C77E8_0x1c77e8(rdram, ctx, runtime);
        if (ctx->pc == 0x001C7830u)
        {
            auto fn = runtime->lookupFunction(0x001C7830u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c83b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C83B0_0x1c83b0(rdram, ctx, runtime);
        if (ctx->pc == 0x001C83B4u)
        {
            auto fn = runtime->lookupFunction(0x001C83B4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001c9298(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001C9298_0x1c9298(rdram, ctx, runtime);
        if (ctx->pc == 0x001C929Cu)
        {
            auto fn = runtime->lookupFunction(0x001C929Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001cbc30(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001CBC30_0x1cbc30(rdram, ctx, runtime);
        if (ctx->pc == 0x001CBC34u)
        {
            auto fn = runtime->lookupFunction(0x001CBC34u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001ce960(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001CE960_0x1ce960(rdram, ctx, runtime);
        if (ctx->pc == 0x001CE970u)
        {
            auto fn = runtime->lookupFunction(0x001CE970u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001ce9b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001CE9B0_0x1ce9b0(rdram, ctx, runtime);
        if (ctx->pc == 0x001CE9C0u)
        {
            auto fn = runtime->lookupFunction(0x001CE9C0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001cf800(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001CF800_0x1cf800(rdram, ctx, runtime);
        if (ctx->pc == 0x001CF804u)
        {
            auto fn = runtime->lookupFunction(0x001CF804u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d0b10(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D0B10_0x1d0b10(rdram, ctx, runtime);
        if (ctx->pc == 0x001D0C38u)
        {
            auto fn = runtime->lookupFunction(0x001D0C38u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d0fe0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D0FE0_0x1d0fe0(rdram, ctx, runtime);
        if (ctx->pc == 0x001D1020u)
        {
            auto fn = runtime->lookupFunction(0x001D1020u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d1ae0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D1AE0_0x1d1ae0(rdram, ctx, runtime);
        if (ctx->pc == 0x001D1B60u)
        {
            auto fn = runtime->lookupFunction(0x001D1B60u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d3550(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D3550_0x1d3550(rdram, ctx, runtime);
        if (ctx->pc == 0x001D355Cu)
        {
            auto fn = runtime->lookupFunction(0x001D355Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d51a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D51A0_0x1d51a0(rdram, ctx, runtime);
        if (ctx->pc == 0x001D51A4u)
        {
            auto fn = runtime->lookupFunction(0x001D51A4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d84f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D84F0_0x1d84f0(rdram, ctx, runtime);
        if (ctx->pc == 0x001D84F4u)
        {
            auto fn = runtime->lookupFunction(0x001D84F4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d8878(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D8878_0x1d8878(rdram, ctx, runtime);
        if (ctx->pc == 0x001D887Cu)
        {
            auto fn = runtime->lookupFunction(0x001D887Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d8b58(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D8B58_0x1d8b58(rdram, ctx, runtime);
        if (ctx->pc == 0x001D8B5Cu)
        {
            auto fn = runtime->lookupFunction(0x001D8B5Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d8c78(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D8C78_0x1d8c78(rdram, ctx, runtime);
        if (ctx->pc == 0x001D8C7Cu)
        {
            auto fn = runtime->lookupFunction(0x001D8C7Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d8e08(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D8E08_0x1d8e08(rdram, ctx, runtime);
        if (ctx->pc == 0x001D8F10u)
        {
            auto fn = runtime->lookupFunction(0x001D8F10u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d94a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D94A0_0x1d94a0(rdram, ctx, runtime);
        if (ctx->pc == 0x001D94A4u)
        {
            auto fn = runtime->lookupFunction(0x001D94A4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d9500(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D9500_0x1d9500(rdram, ctx, runtime);
        if (ctx->pc == 0x001D9504u)
        {
            auto fn = runtime->lookupFunction(0x001D9504u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001d9760(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001D9760_0x1d9760(rdram, ctx, runtime);
        if (ctx->pc == 0x001D9764u)
        {
            auto fn = runtime->lookupFunction(0x001D9764u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001db638(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001DB638_0x1db638(rdram, ctx, runtime);
        if (ctx->pc == 0x001DB67Cu)
        {
            auto fn = runtime->lookupFunction(0x001DB67Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001dd900(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001DD900_0x1dd900(rdram, ctx, runtime);
        if (ctx->pc == 0x001DD904u)
        {
            auto fn = runtime->lookupFunction(0x001DD904u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001dd928(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001DD928_0x1dd928(rdram, ctx, runtime);
        if (ctx->pc == 0x001DD92Cu)
        {
            auto fn = runtime->lookupFunction(0x001DD92Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001df488(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001DF488_0x1df488(rdram, ctx, runtime);
        if (ctx->pc == 0x001DF494u)
        {
            auto fn = runtime->lookupFunction(0x001DF494u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001e0070(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001E0070_0x1e0070(rdram, ctx, runtime);
        if (ctx->pc == 0x001E007Cu)
        {
            auto fn = runtime->lookupFunction(0x001E007Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001e0130(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001E0130_0x1e0130(rdram, ctx, runtime);
        if (ctx->pc == 0x001E013Cu)
        {
            auto fn = runtime->lookupFunction(0x001E013Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001e03f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001E03F0_0x1e03f0(rdram, ctx, runtime);
        if (ctx->pc == 0x001E03F4u)
        {
            auto fn = runtime->lookupFunction(0x001E03F4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001e0bc0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001E0BC0_0x1e0bc0(rdram, ctx, runtime);
        if (ctx->pc == 0x001E0BC4u)
        {
            auto fn = runtime->lookupFunction(0x001E0BC4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001e0be8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001E0BE8_0x1e0be8(rdram, ctx, runtime);
        if (ctx->pc == 0x001E0BECu)
        {
            auto fn = runtime->lookupFunction(0x001E0BECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001e18e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001E18E8_0x1e18e8(rdram, ctx, runtime);
        if (ctx->pc == 0x001E18F4u)
        {
            auto fn = runtime->lookupFunction(0x001E18F4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001f4ae0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001F4AE0_0x1f4ae0(rdram, ctx, runtime);
        if (ctx->pc == 0x001F4AE4u)
        {
            auto fn = runtime->lookupFunction(0x001F4AE4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001f5730(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001F5730_0x1f5730(rdram, ctx, runtime);
        if (ctx->pc == 0x001F5734u)
        {
            auto fn = runtime->lookupFunction(0x001F5734u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001f5938(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001F5938_0x1f5938(rdram, ctx, runtime);
        if (ctx->pc == 0x001F593Cu)
        {
            auto fn = runtime->lookupFunction(0x001F593Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001f72e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001F72E8_0x1f72e8(rdram, ctx, runtime);
        if (ctx->pc == 0x001F72ECu)
        {
            auto fn = runtime->lookupFunction(0x001F72ECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001f7330(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001F7330_0x1f7330(rdram, ctx, runtime);
        if (ctx->pc == 0x001F7334u)
        {
            auto fn = runtime->lookupFunction(0x001F7334u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001f76f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001F76F0_0x1f76f0(rdram, ctx, runtime);
        if (ctx->pc == 0x001F76F4u)
        {
            auto fn = runtime->lookupFunction(0x001F76F4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001f77e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001F77E8_0x1f77e8(rdram, ctx, runtime);
        if (ctx->pc == 0x001F77ECu)
        {
            auto fn = runtime->lookupFunction(0x001F77ECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001f8c08(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001F8C08_0x1f8c08(rdram, ctx, runtime);
        if (ctx->pc == 0x001F8C10u)
        {
            auto fn = runtime->lookupFunction(0x001F8C10u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001faf00(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001FAF00_0x1faf00(rdram, ctx, runtime);
        if (ctx->pc == 0x001FAF04u)
        {
            auto fn = runtime->lookupFunction(0x001FAF04u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001fca60(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001FCA60_0x1fca60(rdram, ctx, runtime);
        if (ctx->pc == 0x001FCA64u)
        {
            auto fn = runtime->lookupFunction(0x001FCA64u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001fdc90(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001FDC90_0x1fdc90(rdram, ctx, runtime);
        if (ctx->pc == 0x001FDC94u)
        {
            auto fn = runtime->lookupFunction(0x001FDC94u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001fdd50(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001FDD50_0x1fdd50(rdram, ctx, runtime);
        if (ctx->pc == 0x001FDD54u)
        {
            auto fn = runtime->lookupFunction(0x001FDD54u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001fde10(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001FDE10_0x1fde10(rdram, ctx, runtime);
        if (ctx->pc == 0x001FDE14u)
        {
            auto fn = runtime->lookupFunction(0x001FDE14u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x001fdf38(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_001FDF38_0x1fdf38(rdram, ctx, runtime);
        if (ctx->pc == 0x001FDF3Cu)
        {
            auto fn = runtime->lookupFunction(0x001FDF3Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00200a08(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00200A08_0x200a08(rdram, ctx, runtime);
        if (ctx->pc == 0x00200A0Cu)
        {
            auto fn = runtime->lookupFunction(0x00200A0Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00202470(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00202470_0x202470(rdram, ctx, runtime);
        if (ctx->pc == 0x00202474u)
        {
            auto fn = runtime->lookupFunction(0x00202474u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002035f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002035F0_0x2035f0(rdram, ctx, runtime);
        if (ctx->pc == 0x00203604u)
        {
            auto fn = runtime->lookupFunction(0x00203604u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002052b8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002052B8_0x2052b8(rdram, ctx, runtime);
        if (ctx->pc == 0x002052BCu)
        {
            auto fn = runtime->lookupFunction(0x002052BCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00205bd8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00205BD8_0x205bd8(rdram, ctx, runtime);
        if (ctx->pc == 0x00205BDCu)
        {
            auto fn = runtime->lookupFunction(0x00205BDCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00206868(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00206868_0x206868(rdram, ctx, runtime);
        if (ctx->pc == 0x002068D0u)
        {
            auto fn = runtime->lookupFunction(0x002068D0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00206910(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00206910_0x206910(rdram, ctx, runtime);
        if (ctx->pc == 0x00206914u)
        {
            auto fn = runtime->lookupFunction(0x00206914u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00206980(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00206980_0x206980(rdram, ctx, runtime);
        if (ctx->pc == 0x00206984u)
        {
            auto fn = runtime->lookupFunction(0x00206984u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00207cf8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00207CF8_0x207cf8(rdram, ctx, runtime);
        if (ctx->pc == 0x00207D18u)
        {
            auto fn = runtime->lookupFunction(0x00207D18u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00207d60(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00207D60_0x207d60(rdram, ctx, runtime);
        if (ctx->pc == 0x00207D64u)
        {
            auto fn = runtime->lookupFunction(0x00207D64u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00207dc0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00207DC0_0x207dc0(rdram, ctx, runtime);
        if (ctx->pc == 0x00207DC4u)
        {
            auto fn = runtime->lookupFunction(0x00207DC4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00207e58(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00207E58_0x207e58(rdram, ctx, runtime);
        if (ctx->pc == 0x00207FB0u)
        {
            auto fn = runtime->lookupFunction(0x00207FB0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00208520(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00208520_0x208520(rdram, ctx, runtime);
        if (ctx->pc == 0x00208580u)
        {
            auto fn = runtime->lookupFunction(0x00208580u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00208ef8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00208EF8_0x208ef8(rdram, ctx, runtime);
        if (ctx->pc == 0x00208EFCu)
        {
            auto fn = runtime->lookupFunction(0x00208EFCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00208fe0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00208FE0_0x208fe0(rdram, ctx, runtime);
        if (ctx->pc == 0x00208FE4u)
        {
            auto fn = runtime->lookupFunction(0x00208FE4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002091b8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002091B8_0x2091b8(rdram, ctx, runtime);
        if (ctx->pc == 0x002091BCu)
        {
            auto fn = runtime->lookupFunction(0x002091BCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00209310(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00209310_0x209310(rdram, ctx, runtime);
        if (ctx->pc == 0x00209314u)
        {
            auto fn = runtime->lookupFunction(0x00209314u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00209430(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00209430_0x209430(rdram, ctx, runtime);
        if (ctx->pc == 0x00209434u)
        {
            auto fn = runtime->lookupFunction(0x00209434u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002094a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002094A0_0x2094a0(rdram, ctx, runtime);
        if (ctx->pc == 0x002094A4u)
        {
            auto fn = runtime->lookupFunction(0x002094A4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00209cb0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00209CB0_0x209cb0(rdram, ctx, runtime);
        if (ctx->pc == 0x00209DA8u)
        {
            auto fn = runtime->lookupFunction(0x00209DA8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0020a040(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0020A040_0x20a040(rdram, ctx, runtime);
        if (ctx->pc == 0x0020A044u)
        {
            auto fn = runtime->lookupFunction(0x0020A044u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0020ce40(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0020CE40_0x20ce40(rdram, ctx, runtime);
        if (ctx->pc == 0x0020CE44u)
        {
            auto fn = runtime->lookupFunction(0x0020CE44u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0020d6f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0020D6F8_0x20d6f8(rdram, ctx, runtime);
        if (ctx->pc == 0x0020D6FCu)
        {
            auto fn = runtime->lookupFunction(0x0020D6FCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0020e868(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0020E868_0x20e868(rdram, ctx, runtime);
        if (ctx->pc == 0x0020E86Cu)
        {
            auto fn = runtime->lookupFunction(0x0020E86Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0020f5e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0020F5E8_0x20f5e8(rdram, ctx, runtime);
        if (ctx->pc == 0x0020F5ECu)
        {
            auto fn = runtime->lookupFunction(0x0020F5ECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00210ee0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00210EE0_0x210ee0(rdram, ctx, runtime);
        if (ctx->pc == 0x00210F38u)
        {
            auto fn = runtime->lookupFunction(0x00210F38u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00211430(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00211430_0x211430(rdram, ctx, runtime);
        if (ctx->pc == 0x00211434u)
        {
            auto fn = runtime->lookupFunction(0x00211434u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00211478(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00211478_0x211478(rdram, ctx, runtime);
        if (ctx->pc == 0x0021147Cu)
        {
            auto fn = runtime->lookupFunction(0x0021147Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00211ae0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00211AE0_0x211ae0(rdram, ctx, runtime);
        if (ctx->pc == 0x00211B68u)
        {
            auto fn = runtime->lookupFunction(0x00211B68u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00213278(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00213278_0x213278(rdram, ctx, runtime);
        if (ctx->pc == 0x00213288u)
        {
            auto fn = runtime->lookupFunction(0x00213288u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00215670(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00215670_0x215670(rdram, ctx, runtime);
        if (ctx->pc == 0x00215718u)
        {
            auto fn = runtime->lookupFunction(0x00215718u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00215718(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00215718_0x215718(rdram, ctx, runtime);
        if (ctx->pc == 0x0021571Cu)
        {
            auto fn = runtime->lookupFunction(0x0021571Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00215a90(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00215A90_0x215a90(rdram, ctx, runtime);
        if (ctx->pc == 0x00215A94u)
        {
            auto fn = runtime->lookupFunction(0x00215A94u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00215ce8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00215CE8_0x215ce8(rdram, ctx, runtime);
        if (ctx->pc == 0x00215CECu)
        {
            auto fn = runtime->lookupFunction(0x00215CECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00215db8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00215DB8_0x215db8(rdram, ctx, runtime);
        if (ctx->pc == 0x00215DBCu)
        {
            auto fn = runtime->lookupFunction(0x00215DBCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00216300(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00216300_0x216300(rdram, ctx, runtime);
        if (ctx->pc == 0x00216304u)
        {
            auto fn = runtime->lookupFunction(0x00216304u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002165a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002165A0_0x2165a0(rdram, ctx, runtime);
        if (ctx->pc == 0x00216600u)
        {
            auto fn = runtime->lookupFunction(0x00216600u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002168d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002168D0_0x2168d0(rdram, ctx, runtime);
        if (ctx->pc == 0x00216938u)
        {
            auto fn = runtime->lookupFunction(0x00216938u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00217650(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00217650_0x217650(rdram, ctx, runtime);
        if (ctx->pc == 0x00217654u)
        {
            auto fn = runtime->lookupFunction(0x00217654u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00217ce0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00217CE0_0x217ce0(rdram, ctx, runtime);
        if (ctx->pc == 0x00217CE4u)
        {
            auto fn = runtime->lookupFunction(0x00217CE4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00217e88(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00217E88_0x217e88(rdram, ctx, runtime);
        if (ctx->pc == 0x00217EB8u)
        {
            auto fn = runtime->lookupFunction(0x00217EB8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00218538(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00218538_0x218538(rdram, ctx, runtime);
        if (ctx->pc == 0x0021853Cu)
        {
            auto fn = runtime->lookupFunction(0x0021853Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00218620(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00218620_0x218620(rdram, ctx, runtime);
        if (ctx->pc == 0x00218624u)
        {
            auto fn = runtime->lookupFunction(0x00218624u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00218838(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00218838_0x218838(rdram, ctx, runtime);
        if (ctx->pc == 0x0021883Cu)
        {
            auto fn = runtime->lookupFunction(0x0021883Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00218990(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00218990_0x218990(rdram, ctx, runtime);
        if (ctx->pc == 0x00218994u)
        {
            auto fn = runtime->lookupFunction(0x00218994u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00219020(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00219020_0x219020(rdram, ctx, runtime);
        if (ctx->pc == 0x00219050u)
        {
            auto fn = runtime->lookupFunction(0x00219050u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00219a88(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00219A88_0x219a88(rdram, ctx, runtime);
        if (ctx->pc == 0x00219A8Cu)
        {
            auto fn = runtime->lookupFunction(0x00219A8Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021c288(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021C288_0x21c288(rdram, ctx, runtime);
        if (ctx->pc == 0x0021C290u)
        {
            auto fn = runtime->lookupFunction(0x0021C290u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021c3d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021C3D0_0x21c3d0(rdram, ctx, runtime);
        if (ctx->pc == 0x0021C3D4u)
        {
            auto fn = runtime->lookupFunction(0x0021C3D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021cb78(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021CB78_0x21cb78(rdram, ctx, runtime);
        if (ctx->pc == 0x0021CB7Cu)
        {
            auto fn = runtime->lookupFunction(0x0021CB7Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021d140(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021D140_0x21d140(rdram, ctx, runtime);
        if (ctx->pc == 0x0021D144u)
        {
            auto fn = runtime->lookupFunction(0x0021D144u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021d300(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021D300_0x21d300(rdram, ctx, runtime);
        if (ctx->pc == 0x0021D304u)
        {
            auto fn = runtime->lookupFunction(0x0021D304u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021d760(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021D760_0x21d760(rdram, ctx, runtime);
        if (ctx->pc == 0x0021D764u)
        {
            auto fn = runtime->lookupFunction(0x0021D764u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021e720(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021E720_0x21e720(rdram, ctx, runtime);
        if (ctx->pc == 0x0021E76Cu)
        {
            auto fn = runtime->lookupFunction(0x0021E76Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021e820(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021E820_0x21e820(rdram, ctx, runtime);
        if (ctx->pc == 0x0021E82Cu)
        {
            auto fn = runtime->lookupFunction(0x0021E82Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021ec40(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021EC40_0x21ec40(rdram, ctx, runtime);
        if (ctx->pc == 0x0021EC44u)
        {
            auto fn = runtime->lookupFunction(0x0021EC44u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021ed10(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021ED10_0x21ed10(rdram, ctx, runtime);
        if (ctx->pc == 0x0021ED14u)
        {
            auto fn = runtime->lookupFunction(0x0021ED14u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021ee88(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021EE88_0x21ee88(rdram, ctx, runtime);
        if (ctx->pc == 0x0021EE8Cu)
        {
            auto fn = runtime->lookupFunction(0x0021EE8Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021f6b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021F6B0_0x21f6b0(rdram, ctx, runtime);
        if (ctx->pc == 0x0021F6B4u)
        {
            auto fn = runtime->lookupFunction(0x0021F6B4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0021fd70(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0021FD70_0x21fd70(rdram, ctx, runtime);
        if (ctx->pc == 0x0021FF18u)
        {
            auto fn = runtime->lookupFunction(0x0021FF18u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00221f70(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00221F70_0x221f70(rdram, ctx, runtime);
        if (ctx->pc == 0x00221FE0u)
        {
            auto fn = runtime->lookupFunction(0x00221FE0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00226040(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00226040_0x226040(rdram, ctx, runtime);
        if (ctx->pc == 0x00226044u)
        {
            auto fn = runtime->lookupFunction(0x00226044u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00226044(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00226044_0x226044(rdram, ctx, runtime);
        if (ctx->pc == 0x00226098u)
        {
            auto fn = runtime->lookupFunction(0x00226098u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00226150(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00226150_0x226150(rdram, ctx, runtime);
        if (ctx->pc == 0x00226154u)
        {
            auto fn = runtime->lookupFunction(0x00226154u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002286c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002286C0_0x2286c0(rdram, ctx, runtime);
        if (ctx->pc == 0x00228750u)
        {
            auto fn = runtime->lookupFunction(0x00228750u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00229398(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00229398_0x229398(rdram, ctx, runtime);
        if (ctx->pc == 0x0022939Cu)
        {
            auto fn = runtime->lookupFunction(0x0022939Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002293c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002293C0_0x2293c0(rdram, ctx, runtime);
        if (ctx->pc == 0x002293C4u)
        {
            auto fn = runtime->lookupFunction(0x002293C4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00229ce0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00229CE0_0x229ce0(rdram, ctx, runtime);
        if (ctx->pc == 0x00229CECu)
        {
            auto fn = runtime->lookupFunction(0x00229CECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00229ee8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00229EE8_0x229ee8(rdram, ctx, runtime);
        if (ctx->pc == 0x00229EECu)
        {
            auto fn = runtime->lookupFunction(0x00229EECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0022a608(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0022A608_0x22a608(rdram, ctx, runtime);
        if (ctx->pc == 0x0022A60Cu)
        {
            auto fn = runtime->lookupFunction(0x0022A60Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0022bf68(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0022BF68_0x22bf68(rdram, ctx, runtime);
        if (ctx->pc == 0x0022BFE8u)
        {
            auto fn = runtime->lookupFunction(0x0022BFE8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0022cab0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0022CAB0_0x22cab0(rdram, ctx, runtime);
        if (ctx->pc == 0x0022CB60u)
        {
            auto fn = runtime->lookupFunction(0x0022CB60u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0022eb90(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0022EB90_0x22eb90(rdram, ctx, runtime);
        if (ctx->pc == 0x0022EBE0u)
        {
            auto fn = runtime->lookupFunction(0x0022EBE0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002304e0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002304E0_0x2304e0(rdram, ctx, runtime);
        if (ctx->pc == 0x00230560u)
        {
            auto fn = runtime->lookupFunction(0x00230560u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00231350(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00231350_0x231350(rdram, ctx, runtime);
        if (ctx->pc == 0x00231354u)
        {
            auto fn = runtime->lookupFunction(0x00231354u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002317d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002317D0_0x2317d0(rdram, ctx, runtime);
        if (ctx->pc == 0x002317D8u)
        {
            auto fn = runtime->lookupFunction(0x002317D8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00231970(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00231970_0x231970(rdram, ctx, runtime);
        if (ctx->pc == 0x00231974u)
        {
            auto fn = runtime->lookupFunction(0x00231974u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00232838(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00232838_0x232838(rdram, ctx, runtime);
        if (ctx->pc == 0x0023283Cu)
        {
            auto fn = runtime->lookupFunction(0x0023283Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00232868(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00232868_0x232868(rdram, ctx, runtime);
        if (ctx->pc == 0x0023286Cu)
        {
            auto fn = runtime->lookupFunction(0x0023286Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00234f18(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00234F18_0x234f18(rdram, ctx, runtime);
        if (ctx->pc == 0x00234F1Cu)
        {
            auto fn = runtime->lookupFunction(0x00234F1Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00234fd8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00234FD8_0x234fd8(rdram, ctx, runtime);
        if (ctx->pc == 0x00234FDCu)
        {
            auto fn = runtime->lookupFunction(0x00234FDCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00236fe8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00236FE8_0x236fe8(rdram, ctx, runtime);
        if (ctx->pc == 0x00236FF4u)
        {
            auto fn = runtime->lookupFunction(0x00236FF4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002387c8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002387C8_0x2387c8(rdram, ctx, runtime);
        if (ctx->pc == 0x002387D0u)
        {
            auto fn = runtime->lookupFunction(0x002387D0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0023a5d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0023A5D0_0x23a5d0(rdram, ctx, runtime);
        if (ctx->pc == 0x0023A638u)
        {
            auto fn = runtime->lookupFunction(0x0023A638u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0023aba8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0023ABA8_0x23aba8(rdram, ctx, runtime);
        if (ctx->pc == 0x0023ABACu)
        {
            auto fn = runtime->lookupFunction(0x0023ABACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0023d558(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0023D558_0x23d558(rdram, ctx, runtime);
        if (ctx->pc == 0x0023D570u)
        {
            auto fn = runtime->lookupFunction(0x0023D570u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0023d778(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0023D778_0x23d778(rdram, ctx, runtime);
        if (ctx->pc == 0x0023D790u)
        {
            auto fn = runtime->lookupFunction(0x0023D790u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0023e8d8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0023E8D8_0x23e8d8(rdram, ctx, runtime);
        if (ctx->pc == 0x0023E8DCu)
        {
            auto fn = runtime->lookupFunction(0x0023E8DCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0023f180(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0023F180_0x23f180(rdram, ctx, runtime);
        if (ctx->pc == 0x0023F184u)
        {
            auto fn = runtime->lookupFunction(0x0023F184u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0023f3e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0023F3E8_0x23f3e8(rdram, ctx, runtime);
        if (ctx->pc == 0x0023F418u)
        {
            auto fn = runtime->lookupFunction(0x0023F418u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0023f518(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0023F518_0x23f518(rdram, ctx, runtime);
        if (ctx->pc == 0x0023F5A0u)
        {
            auto fn = runtime->lookupFunction(0x0023F5A0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002434f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002434F8_0x2434f8(rdram, ctx, runtime);
        if (ctx->pc == 0x002434FCu)
        {
            auto fn = runtime->lookupFunction(0x002434FCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00243a80(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00243A80_0x243a80(rdram, ctx, runtime);
        if (ctx->pc == 0x00243A84u)
        {
            auto fn = runtime->lookupFunction(0x00243A84u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00243b10(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00243B10_0x243b10(rdram, ctx, runtime);
        if (ctx->pc == 0x00243B14u)
        {
            auto fn = runtime->lookupFunction(0x00243B14u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002463c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002463C0_0x2463c0(rdram, ctx, runtime);
        if (ctx->pc == 0x002463CCu)
        {
            auto fn = runtime->lookupFunction(0x002463CCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00252250(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00252250_0x252250(rdram, ctx, runtime);
        if (ctx->pc == 0x00252254u)
        {
            auto fn = runtime->lookupFunction(0x00252254u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002522f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002522F0_0x2522f0(rdram, ctx, runtime);
        if (ctx->pc == 0x002522F4u)
        {
            auto fn = runtime->lookupFunction(0x002522F4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00252620(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00252620_0x252620(rdram, ctx, runtime);
        if (ctx->pc == 0x00252624u)
        {
            auto fn = runtime->lookupFunction(0x00252624u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00258960(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00258960_0x258960(rdram, ctx, runtime);
        if (ctx->pc == 0x002589B0u)
        {
            auto fn = runtime->lookupFunction(0x002589B0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0025bae8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0025BAE8_0x25bae8(rdram, ctx, runtime);
        if (ctx->pc == 0x0025BC00u)
        {
            auto fn = runtime->lookupFunction(0x0025BC00u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0025e0a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0025E0A0_0x25e0a0(rdram, ctx, runtime);
        if (ctx->pc == 0x0025E0A4u)
        {
            auto fn = runtime->lookupFunction(0x0025E0A4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00260ab8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00260AB8_0x260ab8(rdram, ctx, runtime);
        if (ctx->pc == 0x00260B18u)
        {
            auto fn = runtime->lookupFunction(0x00260B18u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002615c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002615C0_0x2615c0(rdram, ctx, runtime);
        if (ctx->pc == 0x002615C4u)
        {
            auto fn = runtime->lookupFunction(0x002615C4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00262b10(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00262B10_0x262b10(rdram, ctx, runtime);
        if (ctx->pc == 0x00262B14u)
        {
            auto fn = runtime->lookupFunction(0x00262B14u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00264198(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00264198_0x264198(rdram, ctx, runtime);
        if (ctx->pc == 0x002641B0u)
        {
            auto fn = runtime->lookupFunction(0x002641B0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00264708(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00264708_0x264708(rdram, ctx, runtime);
        if (ctx->pc == 0x0026470Cu)
        {
            auto fn = runtime->lookupFunction(0x0026470Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002647a8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002647A8_0x2647a8(rdram, ctx, runtime);
        if (ctx->pc == 0x002647ACu)
        {
            auto fn = runtime->lookupFunction(0x002647ACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00264b08(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00264B08_0x264b08(rdram, ctx, runtime);
        if (ctx->pc == 0x00264B0Cu)
        {
            auto fn = runtime->lookupFunction(0x00264B0Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00265050(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00265050_0x265050(rdram, ctx, runtime);
        if (ctx->pc == 0x00265054u)
        {
            auto fn = runtime->lookupFunction(0x00265054u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002675b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002675B0_0x2675b0(rdram, ctx, runtime);
        if (ctx->pc == 0x002675B4u)
        {
            auto fn = runtime->lookupFunction(0x002675B4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002675e0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002675E0_0x2675e0(rdram, ctx, runtime);
        if (ctx->pc == 0x002675E4u)
        {
            auto fn = runtime->lookupFunction(0x002675E4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002677a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002677A0_0x2677a0(rdram, ctx, runtime);
        if (ctx->pc == 0x002677A4u)
        {
            auto fn = runtime->lookupFunction(0x002677A4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00267998(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00267998_0x267998(rdram, ctx, runtime);
        if (ctx->pc == 0x0026799Cu)
        {
            auto fn = runtime->lookupFunction(0x0026799Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0026ad58(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0026AD58_0x26ad58(rdram, ctx, runtime);
        if (ctx->pc == 0x0026AD5Cu)
        {
            auto fn = runtime->lookupFunction(0x0026AD5Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0026b1f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0026B1F8_0x26b1f8(rdram, ctx, runtime);
        if (ctx->pc == 0x0026B1FCu)
        {
            auto fn = runtime->lookupFunction(0x0026B1FCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0026b538(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0026B538_0x26b538(rdram, ctx, runtime);
        if (ctx->pc == 0x0026B53Cu)
        {
            auto fn = runtime->lookupFunction(0x0026B53Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0026bba8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0026BBA8_0x26bba8(rdram, ctx, runtime);
        if (ctx->pc == 0x0026BBACu)
        {
            auto fn = runtime->lookupFunction(0x0026BBACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0026c8a8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0026C8A8_0x26c8a8(rdram, ctx, runtime);
        if (ctx->pc == 0x0026C8ACu)
        {
            auto fn = runtime->lookupFunction(0x0026C8ACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0026cf50(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0026CF50_0x26cf50(rdram, ctx, runtime);
        if (ctx->pc == 0x0026CF54u)
        {
            auto fn = runtime->lookupFunction(0x0026CF54u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0026cf54(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0026CF54_0x26cf54(rdram, ctx, runtime);
        if (ctx->pc == 0x0026CFB8u)
        {
            auto fn = runtime->lookupFunction(0x0026CFB8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0026d018(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0026D018_0x26d018(rdram, ctx, runtime);
        if (ctx->pc == 0x0026D044u)
        {
            auto fn = runtime->lookupFunction(0x0026D044u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0029b230(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0029B230_0x29b230(rdram, ctx, runtime);
        if (ctx->pc == 0x0029B268u)
        {
            auto fn = runtime->lookupFunction(0x0029B268u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0029b268(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0029B268_0x29b268(rdram, ctx, runtime);
        if (ctx->pc == 0x0029B308u)
        {
            auto fn = runtime->lookupFunction(0x0029B308u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002acf64(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002ACF64_0x2acf64(rdram, ctx, runtime);
        if (ctx->pc == 0x002AD224u)
        {
            auto fn = runtime->lookupFunction(0x002AD224u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002ae270(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002AE270_0x2ae270(rdram, ctx, runtime);
        if (ctx->pc == 0x002AE298u)
        {
            auto fn = runtime->lookupFunction(0x002AE298u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002ba988(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002BA988_0x2ba988(rdram, ctx, runtime);
        if (ctx->pc == 0x002BAA38u)
        {
            auto fn = runtime->lookupFunction(0x002BAA38u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002bab68(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002BAB68_0x2bab68(rdram, ctx, runtime);
        if (ctx->pc == 0x002BADE0u)
        {
            auto fn = runtime->lookupFunction(0x002BADE0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002cc3c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002CC3C0_0x2cc3c0(rdram, ctx, runtime);
        if (ctx->pc == 0x002CC3D4u)
        {
            auto fn = runtime->lookupFunction(0x002CC3D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002cc708(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002CC708_0x2cc708(rdram, ctx, runtime);
        if (ctx->pc == 0x002CC70Cu)
        {
            auto fn = runtime->lookupFunction(0x002CC70Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d14e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D14E8_0x2d14e8(rdram, ctx, runtime);
        if (ctx->pc == 0x002D14ECu)
        {
            auto fn = runtime->lookupFunction(0x002D14ECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d1630(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D1630_0x2d1630(rdram, ctx, runtime);
        if (ctx->pc == 0x002D1698u)
        {
            auto fn = runtime->lookupFunction(0x002D1698u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d1f10(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D1F10_0x2d1f10(rdram, ctx, runtime);
        if (ctx->pc == 0x002D1F14u)
        {
            auto fn = runtime->lookupFunction(0x002D1F14u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d1f68(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D1F68_0x2d1f68(rdram, ctx, runtime);
        if (ctx->pc == 0x002D1F6Cu)
        {
            auto fn = runtime->lookupFunction(0x002D1F6Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d2038(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D2038_0x2d2038(rdram, ctx, runtime);
        if (ctx->pc == 0x002D203Cu)
        {
            auto fn = runtime->lookupFunction(0x002D203Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d2228(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D2228_0x2d2228(rdram, ctx, runtime);
        if (ctx->pc == 0x002D222Cu)
        {
            auto fn = runtime->lookupFunction(0x002D222Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d2338(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D2338_0x2d2338(rdram, ctx, runtime);
        if (ctx->pc == 0x002D233Cu)
        {
            auto fn = runtime->lookupFunction(0x002D233Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d2730(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D2730_0x2d2730(rdram, ctx, runtime);
        if (ctx->pc == 0x002D2848u)
        {
            auto fn = runtime->lookupFunction(0x002D2848u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d7f58(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D7F58_0x2d7f58(rdram, ctx, runtime);
        if (ctx->pc == 0x002D8010u)
        {
            auto fn = runtime->lookupFunction(0x002D8010u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d80f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D80F0_0x2d80f0(rdram, ctx, runtime);
        if (ctx->pc == 0x002D81B8u)
        {
            auto fn = runtime->lookupFunction(0x002D81B8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002d82d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002D82D0_0x2d82d0(rdram, ctx, runtime);
        if (ctx->pc == 0x002D82D4u)
        {
            auto fn = runtime->lookupFunction(0x002D82D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002dc4d8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002DC4D8_0x2dc4d8(rdram, ctx, runtime);
        if (ctx->pc == 0x002DC4DCu)
        {
            auto fn = runtime->lookupFunction(0x002DC4DCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002dc508(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002DC508_0x2dc508(rdram, ctx, runtime);
        if (ctx->pc == 0x002DC50Cu)
        {
            auto fn = runtime->lookupFunction(0x002DC50Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002e98e0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002E98E0_0x2e98e0(rdram, ctx, runtime);
        if (ctx->pc == 0x002E98ECu)
        {
            auto fn = runtime->lookupFunction(0x002E98ECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002ea018(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002EA018_0x2ea018(rdram, ctx, runtime);
        if (ctx->pc == 0x002EA058u)
        {
            auto fn = runtime->lookupFunction(0x002EA058u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002ea5a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002EA5A0_0x2ea5a0(rdram, ctx, runtime);
        if (ctx->pc == 0x002EA5A4u)
        {
            auto fn = runtime->lookupFunction(0x002EA5A4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002ea6b8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002EA6B8_0x2ea6b8(rdram, ctx, runtime);
        if (ctx->pc == 0x002EA6BCu)
        {
            auto fn = runtime->lookupFunction(0x002EA6BCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002ead30(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002EAD30_0x2ead30(rdram, ctx, runtime);
        if (ctx->pc == 0x002EB138u)
        {
            auto fn = runtime->lookupFunction(0x002EB138u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002ec560(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002EC560_0x2ec560(rdram, ctx, runtime);
        if (ctx->pc == 0x002EC568u)
        {
            auto fn = runtime->lookupFunction(0x002EC568u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002ecf88(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002ECF88_0x2ecf88(rdram, ctx, runtime);
        if (ctx->pc == 0x002ECF8Cu)
        {
            auto fn = runtime->lookupFunction(0x002ECF8Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f0be8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F0BE8_0x2f0be8(rdram, ctx, runtime);
        if (ctx->pc == 0x002F0CF0u)
        {
            auto fn = runtime->lookupFunction(0x002F0CF0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f0eb8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F0EB8_0x2f0eb8(rdram, ctx, runtime);
        if (ctx->pc == 0x002F0EC0u)
        {
            auto fn = runtime->lookupFunction(0x002F0EC0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f1860(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F1860_0x2f1860(rdram, ctx, runtime);
        if (ctx->pc == 0x002F1998u)
        {
            auto fn = runtime->lookupFunction(0x002F1998u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f3360(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F3360_0x2f3360(rdram, ctx, runtime);
        if (ctx->pc == 0x002F3364u)
        {
            auto fn = runtime->lookupFunction(0x002F3364u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f5480(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F5480_0x2f5480(rdram, ctx, runtime);
        if (ctx->pc == 0x002F5510u)
        {
            auto fn = runtime->lookupFunction(0x002F5510u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f6fc8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F6FC8_0x2f6fc8(rdram, ctx, runtime);
        if (ctx->pc == 0x002F6FCCu)
        {
            auto fn = runtime->lookupFunction(0x002F6FCCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f7e38(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F7E38_0x2f7e38(rdram, ctx, runtime);
        if (ctx->pc == 0x002F7E40u)
        {
            auto fn = runtime->lookupFunction(0x002F7E40u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f7ee8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F7EE8_0x2f7ee8(rdram, ctx, runtime);
        if (ctx->pc == 0x002F7EF0u)
        {
            auto fn = runtime->lookupFunction(0x002F7EF0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f7fb8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F7FB8_0x2f7fb8(rdram, ctx, runtime);
        if (ctx->pc == 0x002F7FC0u)
        {
            auto fn = runtime->lookupFunction(0x002F7FC0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f8560(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F8560_0x2f8560(rdram, ctx, runtime);
        if (ctx->pc == 0x002F8568u)
        {
            auto fn = runtime->lookupFunction(0x002F8568u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f8be0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F8BE0_0x2f8be0(rdram, ctx, runtime);
        if (ctx->pc == 0x002F8BE8u)
        {
            auto fn = runtime->lookupFunction(0x002F8BE8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002f9830(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002F9830_0x2f9830(rdram, ctx, runtime);
        if (ctx->pc == 0x002F9834u)
        {
            auto fn = runtime->lookupFunction(0x002F9834u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x002fcff0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_002FCFF0_0x2fcff0(rdram, ctx, runtime);
        if (ctx->pc == 0x002FCFF4u)
        {
            auto fn = runtime->lookupFunction(0x002FCFF4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00305108(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00305108_0x305108(rdram, ctx, runtime);
        if (ctx->pc == 0x00305138u)
        {
            auto fn = runtime->lookupFunction(0x00305138u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00305500(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00305500_0x305500(rdram, ctx, runtime);
        if (ctx->pc == 0x00305530u)
        {
            auto fn = runtime->lookupFunction(0x00305530u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003058f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003058F8_0x3058f8(rdram, ctx, runtime);
        if (ctx->pc == 0x00305928u)
        {
            auto fn = runtime->lookupFunction(0x00305928u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00305cf0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00305CF0_0x305cf0(rdram, ctx, runtime);
        if (ctx->pc == 0x00305D20u)
        {
            auto fn = runtime->lookupFunction(0x00305D20u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003060e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003060E8_0x3060e8(rdram, ctx, runtime);
        if (ctx->pc == 0x00306118u)
        {
            auto fn = runtime->lookupFunction(0x00306118u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003064e0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003064E0_0x3064e0(rdram, ctx, runtime);
        if (ctx->pc == 0x00306510u)
        {
            auto fn = runtime->lookupFunction(0x00306510u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0030a1d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0030A1D0_0x30a1d0(rdram, ctx, runtime);
        if (ctx->pc == 0x0030A200u)
        {
            auto fn = runtime->lookupFunction(0x0030A200u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0030c378(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0030C378_0x30c378(rdram, ctx, runtime);
        if (ctx->pc == 0x0030C37Cu)
        {
            auto fn = runtime->lookupFunction(0x0030C37Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0030d848(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0030D848_0x30d848(rdram, ctx, runtime);
        if (ctx->pc == 0x0030D850u)
        {
            auto fn = runtime->lookupFunction(0x0030D850u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00317378(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00317378_0x317378(rdram, ctx, runtime);
        if (ctx->pc == 0x0031737Cu)
        {
            auto fn = runtime->lookupFunction(0x0031737Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003174b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003174B0_0x3174b0(rdram, ctx, runtime);
        if (ctx->pc == 0x003174B4u)
        {
            auto fn = runtime->lookupFunction(0x003174B4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00319e30(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00319E30_0x319e30(rdram, ctx, runtime);
        if (ctx->pc == 0x00319EBCu)
        {
            auto fn = runtime->lookupFunction(0x00319EBCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0031bf80(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0031BF80_0x31bf80(rdram, ctx, runtime);
        if (ctx->pc == 0x0031BF84u)
        {
            auto fn = runtime->lookupFunction(0x0031BF84u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0031f72c(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0031F72C_0x31f72c(rdram, ctx, runtime);
        if (ctx->pc == 0x0031F88Cu)
        {
            auto fn = runtime->lookupFunction(0x0031F88Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003202a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003202A0_0x3202a0(rdram, ctx, runtime);
        if (ctx->pc == 0x00320338u)
        {
            auto fn = runtime->lookupFunction(0x00320338u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003209c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003209C0_0x3209c0(rdram, ctx, runtime);
        if (ctx->pc == 0x003209C4u)
        {
            auto fn = runtime->lookupFunction(0x003209C4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00321920(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00321920_0x321920(rdram, ctx, runtime);
        if (ctx->pc == 0x00321924u)
        {
            auto fn = runtime->lookupFunction(0x00321924u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003392c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003392C0_0x3392c0(rdram, ctx, runtime);
        if (ctx->pc == 0x003392C4u)
        {
            auto fn = runtime->lookupFunction(0x003392C4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0033ff78(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0033FF78_0x33ff78(rdram, ctx, runtime);
        if (ctx->pc == 0x0033FF80u)
        {
            auto fn = runtime->lookupFunction(0x0033FF80u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003403d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003403D0_0x3403d0(rdram, ctx, runtime);
        if (ctx->pc == 0x003403D4u)
        {
            auto fn = runtime->lookupFunction(0x003403D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003404d8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003404D8_0x3404d8(rdram, ctx, runtime);
        if (ctx->pc == 0x003404DCu)
        {
            auto fn = runtime->lookupFunction(0x003404DCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00340860(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00340860_0x340860(rdram, ctx, runtime);
        if (ctx->pc == 0x00340870u)
        {
            auto fn = runtime->lookupFunction(0x00340870u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00340f68(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00340F68_0x340f68(rdram, ctx, runtime);
        if (ctx->pc == 0x00340F90u)
        {
            auto fn = runtime->lookupFunction(0x00340F90u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003412a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003412A0_0x3412a0(rdram, ctx, runtime);
        if (ctx->pc == 0x00341428u)
        {
            auto fn = runtime->lookupFunction(0x00341428u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00343930(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00343930_0x343930(rdram, ctx, runtime);
        if (ctx->pc == 0x00343934u)
        {
            auto fn = runtime->lookupFunction(0x00343934u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003439d8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003439D8_0x3439d8(rdram, ctx, runtime);
        if (ctx->pc == 0x00343E30u)
        {
            auto fn = runtime->lookupFunction(0x00343E30u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003443b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003443B0_0x3443b0(rdram, ctx, runtime);
        if (ctx->pc == 0x003443B4u)
        {
            auto fn = runtime->lookupFunction(0x003443B4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00345520(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00345520_0x345520(rdram, ctx, runtime);
        if (ctx->pc == 0x00345524u)
        {
            auto fn = runtime->lookupFunction(0x00345524u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00345d30(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00345D30_0x345d30(rdram, ctx, runtime);
        if (ctx->pc == 0x00345D34u)
        {
            auto fn = runtime->lookupFunction(0x00345D34u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003460f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003460F0_0x3460f0(rdram, ctx, runtime);
        if (ctx->pc == 0x003461A0u)
        {
            auto fn = runtime->lookupFunction(0x003461A0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00346fe0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00346FE0_0x346fe0(rdram, ctx, runtime);
        if (ctx->pc == 0x00346FE4u)
        {
            auto fn = runtime->lookupFunction(0x00346FE4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003479e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003479E8_0x3479e8(rdram, ctx, runtime);
        if (ctx->pc == 0x003479F0u)
        {
            auto fn = runtime->lookupFunction(0x003479F0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0034a708(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0034A708_0x34a708(rdram, ctx, runtime);
        if (ctx->pc == 0x0034A70Cu)
        {
            auto fn = runtime->lookupFunction(0x0034A70Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0034b600(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0034B600_0x34b600(rdram, ctx, runtime);
        if (ctx->pc == 0x0034B7F0u)
        {
            auto fn = runtime->lookupFunction(0x0034B7F0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0035b768(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0035B768_0x35b768(rdram, ctx, runtime);
        if (ctx->pc == 0x0035B76Cu)
        {
            auto fn = runtime->lookupFunction(0x0035B76Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0035bde8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0035BDE8_0x35bde8(rdram, ctx, runtime);
        if (ctx->pc == 0x0035BDF4u)
        {
            auto fn = runtime->lookupFunction(0x0035BDF4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0035d720(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0035D720_0x35d720(rdram, ctx, runtime);
        if (ctx->pc == 0x0035D860u)
        {
            auto fn = runtime->lookupFunction(0x0035D860u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0035e010(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0035E010_0x35e010(rdram, ctx, runtime);
        if (ctx->pc == 0x0035E014u)
        {
            auto fn = runtime->lookupFunction(0x0035E014u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0035e138(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0035E138_0x35e138(rdram, ctx, runtime);
        if (ctx->pc == 0x0035E13Cu)
        {
            auto fn = runtime->lookupFunction(0x0035E13Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0035e6e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0035E6E8_0x35e6e8(rdram, ctx, runtime);
        if (ctx->pc == 0x0035E6ECu)
        {
            auto fn = runtime->lookupFunction(0x0035E6ECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00362bf0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00362BF0_0x362bf0(rdram, ctx, runtime);
        if (ctx->pc == 0x00362BF4u)
        {
            auto fn = runtime->lookupFunction(0x00362BF4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00363220(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00363220_0x363220(rdram, ctx, runtime);
        if (ctx->pc == 0x00363224u)
        {
            auto fn = runtime->lookupFunction(0x00363224u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00363328(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00363328_0x363328(rdram, ctx, runtime);
        if (ctx->pc == 0x0036332Cu)
        {
            auto fn = runtime->lookupFunction(0x0036332Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00363350(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00363350_0x363350(rdram, ctx, runtime);
        if (ctx->pc == 0x00363354u)
        {
            auto fn = runtime->lookupFunction(0x00363354u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00363410(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00363410_0x363410(rdram, ctx, runtime);
        if (ctx->pc == 0x0036341Cu)
        {
            auto fn = runtime->lookupFunction(0x0036341Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00363500(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00363500_0x363500(rdram, ctx, runtime);
        if (ctx->pc == 0x00363504u)
        {
            auto fn = runtime->lookupFunction(0x00363504u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0037f400(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0037F400_0x37f400(rdram, ctx, runtime);
        if (ctx->pc == 0x0037F404u)
        {
            auto fn = runtime->lookupFunction(0x0037F404u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0037f4d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0037F4D0_0x37f4d0(rdram, ctx, runtime);
        if (ctx->pc == 0x0037F4D4u)
        {
            auto fn = runtime->lookupFunction(0x0037F4D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0037f800(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0037F800_0x37f800(rdram, ctx, runtime);
        if (ctx->pc == 0x0037F804u)
        {
            auto fn = runtime->lookupFunction(0x0037F804u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00386900(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00386900_0x386900(rdram, ctx, runtime);
        if (ctx->pc == 0x00386948u)
        {
            auto fn = runtime->lookupFunction(0x00386948u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0038a570(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0038A570_0x38a570(rdram, ctx, runtime);
        if (ctx->pc == 0x0038A574u)
        {
            auto fn = runtime->lookupFunction(0x0038A574u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0038a5b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0038A5B0_0x38a5b0(rdram, ctx, runtime);
        if (ctx->pc == 0x0038A5B4u)
        {
            auto fn = runtime->lookupFunction(0x0038A5B4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0038e490(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0038E490_0x38e490(rdram, ctx, runtime);
        if (ctx->pc == 0x0038E4D0u)
        {
            auto fn = runtime->lookupFunction(0x0038E4D0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0038e6f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0038E6F8_0x38e6f8(rdram, ctx, runtime);
        if (ctx->pc == 0x0038E738u)
        {
            auto fn = runtime->lookupFunction(0x0038E738u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0038e8e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0038E8E8_0x38e8e8(rdram, ctx, runtime);
        if (ctx->pc == 0x0038E90Cu)
        {
            auto fn = runtime->lookupFunction(0x0038E90Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0038e968(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0038E968_0x38e968(rdram, ctx, runtime);
        if (ctx->pc == 0x0038E98Cu)
        {
            auto fn = runtime->lookupFunction(0x0038E98Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0038ea40(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0038EA40_0x38ea40(rdram, ctx, runtime);
        if (ctx->pc == 0x0038EA44u)
        {
            auto fn = runtime->lookupFunction(0x0038EA44u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00390fe8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00390FE8_0x390fe8(rdram, ctx, runtime);
        if (ctx->pc == 0x003919E0u)
        {
            auto fn = runtime->lookupFunction(0x003919E0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00392cb8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00392CB8_0x392cb8(rdram, ctx, runtime);
        if (ctx->pc == 0x00392FF8u)
        {
            auto fn = runtime->lookupFunction(0x00392FF8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00393d90(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00393D90_0x393d90(rdram, ctx, runtime);
        if (ctx->pc == 0x00393DC0u)
        {
            auto fn = runtime->lookupFunction(0x00393DC0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00393f48(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00393F48_0x393f48(rdram, ctx, runtime);
        if (ctx->pc == 0x00393F4Cu)
        {
            auto fn = runtime->lookupFunction(0x00393F4Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003942e0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003942E0_0x3942e0(rdram, ctx, runtime);
        if (ctx->pc == 0x003942E4u)
        {
            auto fn = runtime->lookupFunction(0x003942E4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003946c8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003946C8_0x3946c8(rdram, ctx, runtime);
        if (ctx->pc == 0x00394888u)
        {
            auto fn = runtime->lookupFunction(0x00394888u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00399a20(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00399A20_0x399a20(rdram, ctx, runtime);
        if (ctx->pc == 0x00399A28u)
        {
            auto fn = runtime->lookupFunction(0x00399A28u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0039b5c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0039B5C0_0x39b5c0(rdram, ctx, runtime);
        if (ctx->pc == 0x0039B5F0u)
        {
            auto fn = runtime->lookupFunction(0x0039B5F0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x0039d9c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_0039D9C0_0x39d9c0(rdram, ctx, runtime);
        if (ctx->pc == 0x0039DCB0u)
        {
            auto fn = runtime->lookupFunction(0x0039DCB0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003a8310(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003A8310_0x3a8310(rdram, ctx, runtime);
        if (ctx->pc == 0x003A831Cu)
        {
            auto fn = runtime->lookupFunction(0x003A831Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003a9360(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003A9360_0x3a9360(rdram, ctx, runtime);
        if (ctx->pc == 0x003A936Cu)
        {
            auto fn = runtime->lookupFunction(0x003A936Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003aaaa8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003AAAA8_0x3aaaa8(rdram, ctx, runtime);
        if (ctx->pc == 0x003AAAB4u)
        {
            auto fn = runtime->lookupFunction(0x003AAAB4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003abb20(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003ABB20_0x3abb20(rdram, ctx, runtime);
        if (ctx->pc == 0x003ABB80u)
        {
            auto fn = runtime->lookupFunction(0x003ABB80u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003b37c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003B37C0_0x3b37c0(rdram, ctx, runtime);
        if (ctx->pc == 0x003B3950u)
        {
            auto fn = runtime->lookupFunction(0x003B3950u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003b49e0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003B49E0_0x3b49e0(rdram, ctx, runtime);
        if (ctx->pc == 0x003B50F8u)
        {
            auto fn = runtime->lookupFunction(0x003B50F8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003b7948(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003B7948_0x3b7948(rdram, ctx, runtime);
        if (ctx->pc == 0x003B7AD8u)
        {
            auto fn = runtime->lookupFunction(0x003B7AD8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003bf000(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003BF000_0x3bf000(rdram, ctx, runtime);
        if (ctx->pc == 0x003BF00Cu)
        {
            auto fn = runtime->lookupFunction(0x003BF00Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003bfa30(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003BFA30_0x3bfa30(rdram, ctx, runtime);
        if (ctx->pc == 0x003BFA38u)
        {
            auto fn = runtime->lookupFunction(0x003BFA38u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c21e0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C21E0_0x3c21e0(rdram, ctx, runtime);
        if (ctx->pc == 0x003C22A0u)
        {
            auto fn = runtime->lookupFunction(0x003C22A0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c23b8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C23B8_0x3c23b8(rdram, ctx, runtime);
        if (ctx->pc == 0x003C23C8u)
        {
            auto fn = runtime->lookupFunction(0x003C23C8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c23c8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C23C8_0x3c23c8(rdram, ctx, runtime);
        if (ctx->pc == 0x003C23CCu)
        {
            auto fn = runtime->lookupFunction(0x003C23CCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c24a8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C24A8_0x3c24a8(rdram, ctx, runtime);
        if (ctx->pc == 0x003C24ACu)
        {
            auto fn = runtime->lookupFunction(0x003C24ACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c2704(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C2704_0x3c2704(rdram, ctx, runtime);
        if (ctx->pc == 0x003C2818u)
        {
            auto fn = runtime->lookupFunction(0x003C2818u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c42e0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C42E0_0x3c42e0(rdram, ctx, runtime);
        if (ctx->pc == 0x003C42E4u)
        {
            auto fn = runtime->lookupFunction(0x003C42E4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c4e20(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C4E20_0x3c4e20(rdram, ctx, runtime);
        if (ctx->pc == 0x003C4E24u)
        {
            auto fn = runtime->lookupFunction(0x003C4E24u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c5ae0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C5AE0_0x3c5ae0(rdram, ctx, runtime);
        if (ctx->pc == 0x003C5AE4u)
        {
            auto fn = runtime->lookupFunction(0x003C5AE4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c62e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C62E8_0x3c62e8(rdram, ctx, runtime);
        if (ctx->pc == 0x003C62ECu)
        {
            auto fn = runtime->lookupFunction(0x003C62ECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c6e48(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C6E48_0x3c6e48(rdram, ctx, runtime);
        if (ctx->pc == 0x003C6E4Cu)
        {
            auto fn = runtime->lookupFunction(0x003C6E4Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c6e80(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C6E80_0x3c6e80(rdram, ctx, runtime);
        if (ctx->pc == 0x003C6E84u)
        {
            auto fn = runtime->lookupFunction(0x003C6E84u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c6fd0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C6FD0_0x3c6fd0(rdram, ctx, runtime);
        if (ctx->pc == 0x003C6FD4u)
        {
            auto fn = runtime->lookupFunction(0x003C6FD4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c7218(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C7218_0x3c7218(rdram, ctx, runtime);
        if (ctx->pc == 0x003C7278u)
        {
            auto fn = runtime->lookupFunction(0x003C7278u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c7800(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C7800_0x3c7800(rdram, ctx, runtime);
        if (ctx->pc == 0x003C781Cu)
        {
            auto fn = runtime->lookupFunction(0x003C781Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c83a8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C83A8_0x3c83a8(rdram, ctx, runtime);
        if (ctx->pc == 0x003C84B8u)
        {
            auto fn = runtime->lookupFunction(0x003C84B8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c8fd8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C8FD8_0x3c8fd8(rdram, ctx, runtime);
        if (ctx->pc == 0x003C9028u)
        {
            auto fn = runtime->lookupFunction(0x003C9028u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c9068(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C9068_0x3c9068(rdram, ctx, runtime);
        if (ctx->pc == 0x003C9090u)
        {
            auto fn = runtime->lookupFunction(0x003C9090u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c9298(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C9298_0x3c9298(rdram, ctx, runtime);
        if (ctx->pc == 0x003C9428u)
        {
            auto fn = runtime->lookupFunction(0x003C9428u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c9b98(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C9B98_0x3c9b98(rdram, ctx, runtime);
        if (ctx->pc == 0x003C9B9Cu)
        {
            auto fn = runtime->lookupFunction(0x003C9B9Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c9c40(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C9C40_0x3c9c40(rdram, ctx, runtime);
        if (ctx->pc == 0x003C9C44u)
        {
            auto fn = runtime->lookupFunction(0x003C9C44u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c9cc8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C9CC8_0x3c9cc8(rdram, ctx, runtime);
        if (ctx->pc == 0x003C9CCCu)
        {
            auto fn = runtime->lookupFunction(0x003C9CCCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003c9d50(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003C9D50_0x3c9d50(rdram, ctx, runtime);
        if (ctx->pc == 0x003C9D54u)
        {
            auto fn = runtime->lookupFunction(0x003C9D54u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ca708(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CA708_0x3ca708(rdram, ctx, runtime);
        if (ctx->pc == 0x003CA790u)
        {
            auto fn = runtime->lookupFunction(0x003CA790u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ca7c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CA7C0_0x3ca7c0(rdram, ctx, runtime);
        if (ctx->pc == 0x003CA808u)
        {
            auto fn = runtime->lookupFunction(0x003CA808u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ca838(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CA838_0x3ca838(rdram, ctx, runtime);
        if (ctx->pc == 0x003CA83Cu)
        {
            auto fn = runtime->lookupFunction(0x003CA83Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ca8b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CA8B0_0x3ca8b0(rdram, ctx, runtime);
        if (ctx->pc == 0x003CA8B4u)
        {
            auto fn = runtime->lookupFunction(0x003CA8B4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ca930(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CA930_0x3ca930(rdram, ctx, runtime);
        if (ctx->pc == 0x003CA9A0u)
        {
            auto fn = runtime->lookupFunction(0x003CA9A0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ca9f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CA9F0_0x3ca9f0(rdram, ctx, runtime);
        if (ctx->pc == 0x003CAA38u)
        {
            auto fn = runtime->lookupFunction(0x003CAA38u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cab40(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CAB40_0x3cab40(rdram, ctx, runtime);
        if (ctx->pc == 0x003CAB80u)
        {
            auto fn = runtime->lookupFunction(0x003CAB80u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cab80(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CAB80_0x3cab80(rdram, ctx, runtime);
        if (ctx->pc == 0x003CABA8u)
        {
            auto fn = runtime->lookupFunction(0x003CABA8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cabb0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CABB0_0x3cabb0(rdram, ctx, runtime);
        if (ctx->pc == 0x003CAC10u)
        {
            auto fn = runtime->lookupFunction(0x003CAC10u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cc0d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CC0D0_0x3cc0d0(rdram, ctx, runtime);
        if (ctx->pc == 0x003CC0E8u)
        {
            auto fn = runtime->lookupFunction(0x003CC0E8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cc288(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CC288_0x3cc288(rdram, ctx, runtime);
        if (ctx->pc == 0x003CC28Cu)
        {
            auto fn = runtime->lookupFunction(0x003CC28Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cc360(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CC360_0x3cc360(rdram, ctx, runtime);
        if (ctx->pc == 0x003CC364u)
        {
            auto fn = runtime->lookupFunction(0x003CC364u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cc478(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CC478_0x3cc478(rdram, ctx, runtime);
        if (ctx->pc == 0x003CC480u)
        {
            auto fn = runtime->lookupFunction(0x003CC480u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cd5b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CD5B0_0x3cd5b0(rdram, ctx, runtime);
        if (ctx->pc == 0x003CD5D0u)
        {
            auto fn = runtime->lookupFunction(0x003CD5D0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cd610(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CD610_0x3cd610(rdram, ctx, runtime);
        if (ctx->pc == 0x003CD630u)
        {
            auto fn = runtime->lookupFunction(0x003CD630u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cd670(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CD670_0x3cd670(rdram, ctx, runtime);
        if (ctx->pc == 0x003CD728u)
        {
            auto fn = runtime->lookupFunction(0x003CD728u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cd870(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CD870_0x3cd870(rdram, ctx, runtime);
        if (ctx->pc == 0x003CD874u)
        {
            auto fn = runtime->lookupFunction(0x003CD874u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cd970(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CD970_0x3cd970(rdram, ctx, runtime);
        if (ctx->pc == 0x003CDA18u)
        {
            auto fn = runtime->lookupFunction(0x003CDA18u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cda50(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CDA50_0x3cda50(rdram, ctx, runtime);
        if (ctx->pc == 0x003CDA78u)
        {
            auto fn = runtime->lookupFunction(0x003CDA78u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cda90(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CDA90_0x3cda90(rdram, ctx, runtime);
        if (ctx->pc == 0x003CDBF0u)
        {
            auto fn = runtime->lookupFunction(0x003CDBF0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ce000(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CE000_0x3ce000(rdram, ctx, runtime);
        if (ctx->pc == 0x003CE004u)
        {
            auto fn = runtime->lookupFunction(0x003CE004u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ce028(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CE028_0x3ce028(rdram, ctx, runtime);
        if (ctx->pc == 0x003CE02Cu)
        {
            auto fn = runtime->lookupFunction(0x003CE02Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ce050(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CE050_0x3ce050(rdram, ctx, runtime);
        if (ctx->pc == 0x003CE054u)
        {
            auto fn = runtime->lookupFunction(0x003CE054u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ce2a8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CE2A8_0x3ce2a8(rdram, ctx, runtime);
        if (ctx->pc == 0x003CE318u)
        {
            auto fn = runtime->lookupFunction(0x003CE318u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ce788(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CE788_0x3ce788(rdram, ctx, runtime);
        if (ctx->pc == 0x003CE7D0u)
        {
            auto fn = runtime->lookupFunction(0x003CE7D0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ceda8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CEDA8_0x3ceda8(rdram, ctx, runtime);
        if (ctx->pc == 0x003CEE08u)
        {
            auto fn = runtime->lookupFunction(0x003CEE08u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cf1a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CF1A0_0x3cf1a0(rdram, ctx, runtime);
        if (ctx->pc == 0x003CF1E8u)
        {
            auto fn = runtime->lookupFunction(0x003CF1E8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cf310(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CF310_0x3cf310(rdram, ctx, runtime);
        if (ctx->pc == 0x003CF3D8u)
        {
            auto fn = runtime->lookupFunction(0x003CF3D8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cf3d8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CF3D8_0x3cf3d8(rdram, ctx, runtime);
        if (ctx->pc == 0x003CF450u)
        {
            auto fn = runtime->lookupFunction(0x003CF450u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cf4c8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CF4C8_0x3cf4c8(rdram, ctx, runtime);
        if (ctx->pc == 0x003CF5C8u)
        {
            auto fn = runtime->lookupFunction(0x003CF5C8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cf600(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CF600_0x3cf600(rdram, ctx, runtime);
        if (ctx->pc == 0x003CF640u)
        {
            auto fn = runtime->lookupFunction(0x003CF640u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cf7f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CF7F8_0x3cf7f8(rdram, ctx, runtime);
        if (ctx->pc == 0x003CF940u)
        {
            auto fn = runtime->lookupFunction(0x003CF940u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003cfbf8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003CFBF8_0x3cfbf8(rdram, ctx, runtime);
        if (ctx->pc == 0x003CFC40u)
        {
            auto fn = runtime->lookupFunction(0x003CFC40u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d0008(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D0008_0x3d0008(rdram, ctx, runtime);
        if (ctx->pc == 0x003D0030u)
        {
            auto fn = runtime->lookupFunction(0x003D0030u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d0080(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D0080_0x3d0080(rdram, ctx, runtime);
        if (ctx->pc == 0x003D01A0u)
        {
            auto fn = runtime->lookupFunction(0x003D01A0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d01f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D01F0_0x3d01f0(rdram, ctx, runtime);
        if (ctx->pc == 0x003D0370u)
        {
            auto fn = runtime->lookupFunction(0x003D0370u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d1278(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D1278_0x3d1278(rdram, ctx, runtime);
        if (ctx->pc == 0x003D1290u)
        {
            auto fn = runtime->lookupFunction(0x003D1290u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d1e48(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D1E48_0x3d1e48(rdram, ctx, runtime);
        if (ctx->pc == 0x003D1FA0u)
        {
            auto fn = runtime->lookupFunction(0x003D1FA0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d1ff0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D1FF0_0x3d1ff0(rdram, ctx, runtime);
        if (ctx->pc == 0x003D20E8u)
        {
            auto fn = runtime->lookupFunction(0x003D20E8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d2208(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D2208_0x3d2208(rdram, ctx, runtime);
        if (ctx->pc == 0x003D2248u)
        {
            auto fn = runtime->lookupFunction(0x003D2248u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d2608(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D2608_0x3d2608(rdram, ctx, runtime);
        if (ctx->pc == 0x003D26A8u)
        {
            auto fn = runtime->lookupFunction(0x003D26A8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d2f08(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D2F08_0x3d2f08(rdram, ctx, runtime);
        if (ctx->pc == 0x003D2F80u)
        {
            auto fn = runtime->lookupFunction(0x003D2F80u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d3480(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D3480_0x3d3480(rdram, ctx, runtime);
        if (ctx->pc == 0x003D3538u)
        {
            auto fn = runtime->lookupFunction(0x003D3538u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d3800(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D3800_0x3d3800(rdram, ctx, runtime);
        if (ctx->pc == 0x003D3840u)
        {
            auto fn = runtime->lookupFunction(0x003D3840u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d4628(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D4628_0x3d4628(rdram, ctx, runtime);
        if (ctx->pc == 0x003D462Cu)
        {
            auto fn = runtime->lookupFunction(0x003D462Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d46a8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D46A8_0x3d46a8(rdram, ctx, runtime);
        if (ctx->pc == 0x003D46E0u)
        {
            auto fn = runtime->lookupFunction(0x003D46E0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d5118(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D5118_0x3d5118(rdram, ctx, runtime);
        if (ctx->pc == 0x003D5230u)
        {
            auto fn = runtime->lookupFunction(0x003D5230u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d5230(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D5230_0x3d5230(rdram, ctx, runtime);
        if (ctx->pc == 0x003D5280u)
        {
            auto fn = runtime->lookupFunction(0x003D5280u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d5a38(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D5A38_0x3d5a38(rdram, ctx, runtime);
        if (ctx->pc == 0x003D5B78u)
        {
            auto fn = runtime->lookupFunction(0x003D5B78u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d5f38(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D5F38_0x3d5f38(rdram, ctx, runtime);
        if (ctx->pc == 0x003D6050u)
        {
            auto fn = runtime->lookupFunction(0x003D6050u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d6050(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D6050_0x3d6050(rdram, ctx, runtime);
        if (ctx->pc == 0x003D6054u)
        {
            auto fn = runtime->lookupFunction(0x003D6054u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d6054(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D6054_0x3d6054(rdram, ctx, runtime);
        if (ctx->pc == 0x003D60D8u)
        {
            auto fn = runtime->lookupFunction(0x003D60D8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d60f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D60F8_0x3d60f8(rdram, ctx, runtime);
        if (ctx->pc == 0x003D6150u)
        {
            auto fn = runtime->lookupFunction(0x003D6150u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d61a0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D61A0_0x3d61a0(rdram, ctx, runtime);
        if (ctx->pc == 0x003D61A4u)
        {
            auto fn = runtime->lookupFunction(0x003D61A4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d61d8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D61D8_0x3d61d8(rdram, ctx, runtime);
        if (ctx->pc == 0x003D61DCu)
        {
            auto fn = runtime->lookupFunction(0x003D61DCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d64f0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D64F0_0x3d64f0(rdram, ctx, runtime);
        if (ctx->pc == 0x003D64F4u)
        {
            auto fn = runtime->lookupFunction(0x003D64F4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d6558(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D6558_0x3d6558(rdram, ctx, runtime);
        if (ctx->pc == 0x003D65D8u)
        {
            auto fn = runtime->lookupFunction(0x003D65D8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d6c68(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D6C68_0x3d6c68(rdram, ctx, runtime);
        if (ctx->pc == 0x003D6C6Cu)
        {
            auto fn = runtime->lookupFunction(0x003D6C6Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d75d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D75D0_0x3d75d0(rdram, ctx, runtime);
        if (ctx->pc == 0x003D7640u)
        {
            auto fn = runtime->lookupFunction(0x003D7640u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d8350(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D8350_0x3d8350(rdram, ctx, runtime);
        if (ctx->pc == 0x003D8428u)
        {
            auto fn = runtime->lookupFunction(0x003D8428u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d84d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D84D0_0x3d84d0(rdram, ctx, runtime);
        if (ctx->pc == 0x003D84D4u)
        {
            auto fn = runtime->lookupFunction(0x003D84D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d9700(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D9700_0x3d9700(rdram, ctx, runtime);
        if (ctx->pc == 0x003D9708u)
        {
            auto fn = runtime->lookupFunction(0x003D9708u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003d9810(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003D9810_0x3d9810(rdram, ctx, runtime);
        if (ctx->pc == 0x003D9888u)
        {
            auto fn = runtime->lookupFunction(0x003D9888u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003da5a8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DA5A8_0x3da5a8(rdram, ctx, runtime);
        if (ctx->pc == 0x003DA5ACu)
        {
            auto fn = runtime->lookupFunction(0x003DA5ACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003daca8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DACA8_0x3daca8(rdram, ctx, runtime);
        if (ctx->pc == 0x003DACACu)
        {
            auto fn = runtime->lookupFunction(0x003DACACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003db658(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DB658_0x3db658(rdram, ctx, runtime);
        if (ctx->pc == 0x003DB65Cu)
        {
            auto fn = runtime->lookupFunction(0x003DB65Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003db8c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DB8C0_0x3db8c0(rdram, ctx, runtime);
        if (ctx->pc == 0x003DB8C4u)
        {
            auto fn = runtime->lookupFunction(0x003DB8C4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003dc378(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DC378_0x3dc378(rdram, ctx, runtime);
        if (ctx->pc == 0x003DC37Cu)
        {
            auto fn = runtime->lookupFunction(0x003DC37Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003dc440(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DC440_0x3dc440(rdram, ctx, runtime);
        if (ctx->pc == 0x003DC444u)
        {
            auto fn = runtime->lookupFunction(0x003DC444u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003dc444(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DC444_0x3dc444(rdram, ctx, runtime);
        if (ctx->pc == 0x003DC4D4u)
        {
            auto fn = runtime->lookupFunction(0x003DC4D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003dcb28(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DCB28_0x3dcb28(rdram, ctx, runtime);
        if (ctx->pc == 0x003DCB64u)
        {
            auto fn = runtime->lookupFunction(0x003DCB64u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003dcffc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DCFFC_0x3dcffc(rdram, ctx, runtime);
        if (ctx->pc == 0x003DD064u)
        {
            auto fn = runtime->lookupFunction(0x003DD064u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003dd0a8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DD0A8_0x3dd0a8(rdram, ctx, runtime);
        if (ctx->pc == 0x003DD0ACu)
        {
            auto fn = runtime->lookupFunction(0x003DD0ACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003dd0ac(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DD0AC_0x3dd0ac(rdram, ctx, runtime);
        if (ctx->pc == 0x003DD110u)
        {
            auto fn = runtime->lookupFunction(0x003DD110u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ddda8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DDDA8_0x3ddda8(rdram, ctx, runtime);
        if (ctx->pc == 0x003DDE88u)
        {
            auto fn = runtime->lookupFunction(0x003DDE88u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003df6e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003DF6E8_0x3df6e8(rdram, ctx, runtime);
        if (ctx->pc == 0x003DF730u)
        {
            auto fn = runtime->lookupFunction(0x003DF730u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e05e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E05E8_0x3e05e8(rdram, ctx, runtime);
        if (ctx->pc == 0x003E05ECu)
        {
            auto fn = runtime->lookupFunction(0x003E05ECu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e0728(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E0728_0x3e0728(rdram, ctx, runtime);
        if (ctx->pc == 0x003E072Cu)
        {
            auto fn = runtime->lookupFunction(0x003E072Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e07f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E07F8_0x3e07f8(rdram, ctx, runtime);
        if (ctx->pc == 0x003E0848u)
        {
            auto fn = runtime->lookupFunction(0x003E0848u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e10b8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E10B8_0x3e10b8(rdram, ctx, runtime);
        if (ctx->pc == 0x003E10BCu)
        {
            auto fn = runtime->lookupFunction(0x003E10BCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e19c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E19C0_0x3e19c0(rdram, ctx, runtime);
        if (ctx->pc == 0x003E19C4u)
        {
            auto fn = runtime->lookupFunction(0x003E19C4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e2a18(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E2A18_0x3e2a18(rdram, ctx, runtime);
        if (ctx->pc == 0x003E2A28u)
        {
            auto fn = runtime->lookupFunction(0x003E2A28u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e2c70(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E2C70_0x3e2c70(rdram, ctx, runtime);
        if (ctx->pc == 0x003E2D4Cu)
        {
            auto fn = runtime->lookupFunction(0x003E2D4Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e2dd8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E2DD8_0x3e2dd8(rdram, ctx, runtime);
        if (ctx->pc == 0x003E2DDCu)
        {
            auto fn = runtime->lookupFunction(0x003E2DDCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e2e70(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E2E70_0x3e2e70(rdram, ctx, runtime);
        if (ctx->pc == 0x003E2F08u)
        {
            auto fn = runtime->lookupFunction(0x003E2F08u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e3628(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E3628_0x3e3628(rdram, ctx, runtime);
        if (ctx->pc == 0x003E362Cu)
        {
            auto fn = runtime->lookupFunction(0x003E362Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e3758(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E3758_0x3e3758(rdram, ctx, runtime);
        if (ctx->pc == 0x003E375Cu)
        {
            auto fn = runtime->lookupFunction(0x003E375Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e3978(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E3978_0x3e3978(rdram, ctx, runtime);
        if (ctx->pc == 0x003E3AF8u)
        {
            auto fn = runtime->lookupFunction(0x003E3AF8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e3cc0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E3CC0_0x3e3cc0(rdram, ctx, runtime);
        if (ctx->pc == 0x003E3CE8u)
        {
            auto fn = runtime->lookupFunction(0x003E3CE8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e53b8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E53B8_0x3e53b8(rdram, ctx, runtime);
        if (ctx->pc == 0x003E53F8u)
        {
            auto fn = runtime->lookupFunction(0x003E53F8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e5cf8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E5CF8_0x3e5cf8(rdram, ctx, runtime);
        if (ctx->pc == 0x003E5DF0u)
        {
            auto fn = runtime->lookupFunction(0x003E5DF0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e5df0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E5DF0_0x3e5df0(rdram, ctx, runtime);
        if (ctx->pc == 0x003E5DF4u)
        {
            auto fn = runtime->lookupFunction(0x003E5DF4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e60d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E60D0_0x3e60d0(rdram, ctx, runtime);
        if (ctx->pc == 0x003E60D4u)
        {
            auto fn = runtime->lookupFunction(0x003E60D4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e6e60(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E6E60_0x3e6e60(rdram, ctx, runtime);
        if (ctx->pc == 0x003E6E80u)
        {
            auto fn = runtime->lookupFunction(0x003E6E80u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e7248(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E7248_0x3e7248(rdram, ctx, runtime);
        if (ctx->pc == 0x003E7270u)
        {
            auto fn = runtime->lookupFunction(0x003E7270u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003e95e0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003E95E0_0x3e95e0(rdram, ctx, runtime);
        if (ctx->pc == 0x003E95E4u)
        {
            auto fn = runtime->lookupFunction(0x003E95E4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003eada0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EADA0_0x3eada0(rdram, ctx, runtime);
        if (ctx->pc == 0x003EAED8u)
        {
            auto fn = runtime->lookupFunction(0x003EAED8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003eb050(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EB050_0x3eb050(rdram, ctx, runtime);
        if (ctx->pc == 0x003EB078u)
        {
            auto fn = runtime->lookupFunction(0x003EB078u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003eb2b0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EB2B0_0x3eb2b0(rdram, ctx, runtime);
        if (ctx->pc == 0x003EB2C0u)
        {
            auto fn = runtime->lookupFunction(0x003EB2C0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003edba0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EDBA0_0x3edba0(rdram, ctx, runtime);
        if (ctx->pc == 0x003EDBB4u)
        {
            auto fn = runtime->lookupFunction(0x003EDBB4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003edc18(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EDC18_0x3edc18(rdram, ctx, runtime);
        if (ctx->pc == 0x003EDC2Cu)
        {
            auto fn = runtime->lookupFunction(0x003EDC2Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003edd50(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EDD50_0x3edd50(rdram, ctx, runtime);
        if (ctx->pc == 0x003EDD64u)
        {
            auto fn = runtime->lookupFunction(0x003EDD64u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003edd64(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EDD64_0x3edd64(rdram, ctx, runtime);
        if (ctx->pc == 0x003EDDB8u)
        {
            auto fn = runtime->lookupFunction(0x003EDDB8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003eddb8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EDDB8_0x3eddb8(rdram, ctx, runtime);
        if (ctx->pc == 0x003EDDCCu)
        {
            auto fn = runtime->lookupFunction(0x003EDDCCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ee1f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EE1F8_0x3ee1f8(rdram, ctx, runtime);
        if (ctx->pc == 0x003EE20Cu)
        {
            auto fn = runtime->lookupFunction(0x003EE20Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ee278(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EE278_0x3ee278(rdram, ctx, runtime);
        if (ctx->pc == 0x003EE28Cu)
        {
            auto fn = runtime->lookupFunction(0x003EE28Cu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ee28c(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EE28C_0x3ee28c(rdram, ctx, runtime);
        if (ctx->pc == 0x003EE2E8u)
        {
            auto fn = runtime->lookupFunction(0x003EE2E8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ee2e8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EE2E8_0x3ee2e8(rdram, ctx, runtime);
        if (ctx->pc == 0x003EE360u)
        {
            auto fn = runtime->lookupFunction(0x003EE360u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003eea88(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EEA88_0x3eea88(rdram, ctx, runtime);
        if (ctx->pc == 0x003EEAE0u)
        {
            auto fn = runtime->lookupFunction(0x003EEAE0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003eeb60(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EEB60_0x3eeb60(rdram, ctx, runtime);
        if (ctx->pc == 0x003EECC0u)
        {
            auto fn = runtime->lookupFunction(0x003EECC0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003eeda8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003EEDA8_0x3eeda8(rdram, ctx, runtime);
        if (ctx->pc == 0x003EEDACu)
        {
            auto fn = runtime->lookupFunction(0x003EEDACu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f03f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F03F8_0x3f03f8(rdram, ctx, runtime);
        if (ctx->pc == 0x003F04B8u)
        {
            auto fn = runtime->lookupFunction(0x003F04B8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f0af0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F0AF0_0x3f0af0(rdram, ctx, runtime);
        if (ctx->pc == 0x003F0AF4u)
        {
            auto fn = runtime->lookupFunction(0x003F0AF4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f0ce0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F0CE0_0x3f0ce0(rdram, ctx, runtime);
        if (ctx->pc == 0x003F0CE4u)
        {
            auto fn = runtime->lookupFunction(0x003F0CE4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f0dd0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F0DD0_0x3f0dd0(rdram, ctx, runtime);
        if (ctx->pc == 0x003F0DD4u)
        {
            auto fn = runtime->lookupFunction(0x003F0DD4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f35c8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F35C8_0x3f35c8(rdram, ctx, runtime);
        if (ctx->pc == 0x003F35D0u)
        {
            auto fn = runtime->lookupFunction(0x003F35D0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f4020(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F4020_0x3f4020(rdram, ctx, runtime);
        if (ctx->pc == 0x003F4024u)
        {
            auto fn = runtime->lookupFunction(0x003F4024u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f53c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F53C0_0x3f53c0(rdram, ctx, runtime);
        if (ctx->pc == 0x003F5598u)
        {
            auto fn = runtime->lookupFunction(0x003F5598u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f55b8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F55B8_0x3f55b8(rdram, ctx, runtime);
        if (ctx->pc == 0x003F55BCu)
        {
            auto fn = runtime->lookupFunction(0x003F55BCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f5940(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F5940_0x3f5940(rdram, ctx, runtime);
        if (ctx->pc == 0x003F5944u)
        {
            auto fn = runtime->lookupFunction(0x003F5944u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f67d0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F67D0_0x3f67d0(rdram, ctx, runtime);
        if (ctx->pc == 0x003F67DCu)
        {
            auto fn = runtime->lookupFunction(0x003F67DCu);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f6830(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F6830_0x3f6830(rdram, ctx, runtime);
        if (ctx->pc == 0x003F6840u)
        {
            auto fn = runtime->lookupFunction(0x003F6840u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f6d60(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F6D60_0x3f6d60(rdram, ctx, runtime);
        if (ctx->pc == 0x003F6D64u)
        {
            auto fn = runtime->lookupFunction(0x003F6D64u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f7c98(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F7C98_0x3f7c98(rdram, ctx, runtime);
        if (ctx->pc == 0x003F7CA0u)
        {
            auto fn = runtime->lookupFunction(0x003F7CA0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f7ee0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F7EE0_0x3f7ee0(rdram, ctx, runtime);
        if (ctx->pc == 0x003F7EE8u)
        {
            auto fn = runtime->lookupFunction(0x003F7EE8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f8060(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F8060_0x3f8060(rdram, ctx, runtime);
        if (ctx->pc == 0x003F8064u)
        {
            auto fn = runtime->lookupFunction(0x003F8064u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f8088(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F8088_0x3f8088(rdram, ctx, runtime);
        if (ctx->pc == 0x003F8128u)
        {
            auto fn = runtime->lookupFunction(0x003F8128u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003f9a90(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003F9A90_0x3f9a90(rdram, ctx, runtime);
        if (ctx->pc == 0x003F9A94u)
        {
            auto fn = runtime->lookupFunction(0x003F9A94u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003fbc80(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003FBC80_0x3fbc80(rdram, ctx, runtime);
        if (ctx->pc == 0x003FBC88u)
        {
            auto fn = runtime->lookupFunction(0x003FBC88u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003fbcf0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003FBCF0_0x3fbcf0(rdram, ctx, runtime);
        if (ctx->pc == 0x003FBCF4u)
        {
            auto fn = runtime->lookupFunction(0x003FBCF4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003fcf48(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003FCF48_0x3fcf48(rdram, ctx, runtime);
        if (ctx->pc == 0x003FCFB0u)
        {
            auto fn = runtime->lookupFunction(0x003FCFB0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003fe2c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003FE2C0_0x3fe2c0(rdram, ctx, runtime);
        if (ctx->pc == 0x003FE2C4u)
        {
            auto fn = runtime->lookupFunction(0x003FE2C4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x003ff348(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_003FF348_0x3ff348(rdram, ctx, runtime);
        if (ctx->pc == 0x003FF420u)
        {
            auto fn = runtime->lookupFunction(0x003FF420u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00400b28(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00400B28_0x400b28(rdram, ctx, runtime);
        if (ctx->pc == 0x00400B50u)
        {
            auto fn = runtime->lookupFunction(0x00400B50u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00401008(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00401008_0x401008(rdram, ctx, runtime);
        if (ctx->pc == 0x00401014u)
        {
            auto fn = runtime->lookupFunction(0x00401014u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00401048(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00401048_0x401048(rdram, ctx, runtime);
        if (ctx->pc == 0x00401054u)
        {
            auto fn = runtime->lookupFunction(0x00401054u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00402198(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00402198_0x402198(rdram, ctx, runtime);
        if (ctx->pc == 0x004021D8u)
        {
            auto fn = runtime->lookupFunction(0x004021D8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00403718(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00403718_0x403718(rdram, ctx, runtime);
        if (ctx->pc == 0x00403AF8u)
        {
            auto fn = runtime->lookupFunction(0x00403AF8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00403dc0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00403DC0_0x403dc0(rdram, ctx, runtime);
        if (ctx->pc == 0x00403DC4u)
        {
            auto fn = runtime->lookupFunction(0x00403DC4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00403e30(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00403E30_0x403e30(rdram, ctx, runtime);
        if (ctx->pc == 0x00403E34u)
        {
            auto fn = runtime->lookupFunction(0x00403E34u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00403ea8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00403EA8_0x403ea8(rdram, ctx, runtime);
        if (ctx->pc == 0x00403ED8u)
        {
            auto fn = runtime->lookupFunction(0x00403ED8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x004044f8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_004044F8_0x4044f8(rdram, ctx, runtime);
        if (ctx->pc == 0x00404540u)
        {
            auto fn = runtime->lookupFunction(0x00404540u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00404860(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00404860_0x404860(rdram, ctx, runtime);
        if (ctx->pc == 0x00404868u)
        {
            auto fn = runtime->lookupFunction(0x00404868u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x004056b8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_004056B8_0x4056b8(rdram, ctx, runtime);
        if (ctx->pc == 0x00405710u)
        {
            auto fn = runtime->lookupFunction(0x00405710u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x004057c0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_004057C0_0x4057c0(rdram, ctx, runtime);
        if (ctx->pc == 0x00405840u)
        {
            auto fn = runtime->lookupFunction(0x00405840u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00405a60(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00405A60_0x405a60(rdram, ctx, runtime);
        if (ctx->pc == 0x00405AE0u)
        {
            auto fn = runtime->lookupFunction(0x00405AE0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00405cc0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00405CC0_0x405cc0(rdram, ctx, runtime);
        if (ctx->pc == 0x00405DE8u)
        {
            auto fn = runtime->lookupFunction(0x00405DE8u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00405de8(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00405DE8_0x405de8(rdram, ctx, runtime);
        if (ctx->pc == 0x00405ED0u)
        {
            auto fn = runtime->lookupFunction(0x00405ED0u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00406cc0(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00406CC0_0x406cc0(rdram, ctx, runtime);
        if (ctx->pc == 0x00406CC4u)
        {
            auto fn = runtime->lookupFunction(0x00406CC4u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void chain_0x00407328(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        sub_00407328_0x407328(rdram, ctx, runtime);
        if (ctx->pc == 0x00407344u)
        {
            auto fn = runtime->lookupFunction(0x00407344u);
            if (fn)
            {
                fn(rdram, ctx, runtime);
            }
        }
    }

    inline void applyOkamiFallthroughs(PS2Runtime &runtime)
    {
        runtime.replaceFunction(0x00130B20u, chain_0x00130b20);
        runtime.replaceFunction(0x00132378u, chain_0x00132378);
        runtime.replaceFunction(0x00134268u, chain_0x00134268);
        runtime.replaceFunction(0x00134C28u, chain_0x00134c28);
        runtime.replaceFunction(0x001368A0u, chain_0x001368a0);
        runtime.replaceFunction(0x00136A78u, chain_0x00136a78);
        runtime.replaceFunction(0x00136BF0u, chain_0x00136bf0);
        runtime.replaceFunction(0x00136D70u, chain_0x00136d70);
        runtime.replaceFunction(0x00144048u, chain_0x00144048);
        runtime.replaceFunction(0x00144310u, chain_0x00144310);
        runtime.replaceFunction(0x00148B60u, chain_0x00148b60);
        runtime.replaceFunction(0x0014A9D8u, chain_0x0014a9d8);
        runtime.replaceFunction(0x0014C108u, chain_0x0014c108);
        runtime.replaceFunction(0x001546E0u, chain_0x001546e0);
        runtime.replaceFunction(0x0015FBA0u, chain_0x0015fba0);
        runtime.replaceFunction(0x00161400u, chain_0x00161400);
        runtime.replaceFunction(0x00161450u, chain_0x00161450);
        runtime.replaceFunction(0x00161588u, chain_0x00161588);
        runtime.replaceFunction(0x00161DB0u, chain_0x00161db0);
        runtime.replaceFunction(0x001648C8u, chain_0x001648c8);
        runtime.replaceFunction(0x00164CB8u, chain_0x00164cb8);
        runtime.replaceFunction(0x00164D10u, chain_0x00164d10);
        runtime.replaceFunction(0x00165CA8u, chain_0x00165ca8);
        runtime.replaceFunction(0x001666A0u, chain_0x001666a0);
        runtime.replaceFunction(0x00169238u, chain_0x00169238);
        runtime.replaceFunction(0x0016A010u, chain_0x0016a010);
        runtime.replaceFunction(0x0016A550u, chain_0x0016a550);
        runtime.replaceFunction(0x0016AF50u, chain_0x0016af50);
        runtime.replaceFunction(0x0016B9D8u, chain_0x0016b9d8);
        runtime.replaceFunction(0x0016BA28u, chain_0x0016ba28);
        runtime.replaceFunction(0x0016C860u, chain_0x0016c860);
        runtime.replaceFunction(0x0016CC68u, chain_0x0016cc68);
        runtime.replaceFunction(0x0016CF18u, chain_0x0016cf18);
        runtime.replaceFunction(0x0016CF80u, chain_0x0016cf80);
        runtime.replaceFunction(0x0016D030u, chain_0x0016d030);
        runtime.replaceFunction(0x0016D0D0u, chain_0x0016d0d0);
        runtime.replaceFunction(0x0016D5F0u, chain_0x0016d5f0);
        runtime.replaceFunction(0x0016D6E8u, chain_0x0016d6e8);
        runtime.replaceFunction(0x00170340u, chain_0x00170340);
        runtime.replaceFunction(0x00170710u, chain_0x00170710);
        runtime.replaceFunction(0x00170B08u, chain_0x00170b08);
        runtime.replaceFunction(0x001721B8u, chain_0x001721b8);
        runtime.replaceFunction(0x001739D8u, chain_0x001739d8);
        runtime.replaceFunction(0x00174778u, chain_0x00174778);
        runtime.replaceFunction(0x00174838u, chain_0x00174838);
        runtime.replaceFunction(0x00174EB0u, chain_0x00174eb0);
        runtime.replaceFunction(0x00175070u, chain_0x00175070);
        runtime.replaceFunction(0x001784A0u, chain_0x001784a0);
        runtime.replaceFunction(0x00178758u, chain_0x00178758);
        runtime.replaceFunction(0x00179568u, chain_0x00179568);
        runtime.replaceFunction(0x00179590u, chain_0x00179590);
        runtime.replaceFunction(0x0017A418u, chain_0x0017a418);
        runtime.replaceFunction(0x0017C978u, chain_0x0017c978);
        runtime.replaceFunction(0x0017D0D0u, chain_0x0017d0d0);
        runtime.replaceFunction(0x00181C70u, chain_0x00181c70);
        runtime.replaceFunction(0x00181D30u, chain_0x00181d30);
        runtime.replaceFunction(0x0018C210u, chain_0x0018c210);
        runtime.replaceFunction(0x0018D660u, chain_0x0018d660);
        runtime.replaceFunction(0x0018DC68u, chain_0x0018dc68);
        runtime.replaceFunction(0x0018F578u, chain_0x0018f578);
        runtime.replaceFunction(0x00191E78u, chain_0x00191e78);
        runtime.replaceFunction(0x00192B60u, chain_0x00192b60);
        runtime.replaceFunction(0x00194010u, chain_0x00194010);
        runtime.replaceFunction(0x001944D0u, chain_0x001944d0);
        runtime.replaceFunction(0x00197DA0u, chain_0x00197da0);
        runtime.replaceFunction(0x001982E8u, chain_0x001982e8);
        runtime.replaceFunction(0x0019F700u, chain_0x0019f700);
        runtime.replaceFunction(0x001B27E8u, chain_0x001b27e8);
        runtime.replaceFunction(0x001B2A80u, chain_0x001b2a80);
        runtime.replaceFunction(0x001B3270u, chain_0x001b3270);
        runtime.replaceFunction(0x001B3698u, chain_0x001b3698);
        runtime.replaceFunction(0x001B3A18u, chain_0x001b3a18);
        runtime.replaceFunction(0x001B79E8u, chain_0x001b79e8);
        runtime.replaceFunction(0x001B83F8u, chain_0x001b83f8);
        runtime.replaceFunction(0x001C3940u, chain_0x001c3940);
        runtime.replaceFunction(0x001C52D8u, chain_0x001c52d8);
        runtime.replaceFunction(0x001C56E8u, chain_0x001c56e8);
        runtime.replaceFunction(0x001C57A8u, chain_0x001c57a8);
        runtime.replaceFunction(0x001C58F8u, chain_0x001c58f8);
        runtime.replaceFunction(0x001C5C08u, chain_0x001c5c08);
        runtime.replaceFunction(0x001C5CE8u, chain_0x001c5ce8);
        runtime.replaceFunction(0x001C5D70u, chain_0x001c5d70);
        runtime.replaceFunction(0x001C5DA8u, chain_0x001c5da8);
        runtime.replaceFunction(0x001C6118u, chain_0x001c6118);
        runtime.replaceFunction(0x001C6198u, chain_0x001c6198);
        runtime.replaceFunction(0x001C6208u, chain_0x001c6208);
        runtime.replaceFunction(0x001C6468u, chain_0x001c6468);
        runtime.replaceFunction(0x001C66B0u, chain_0x001c66b0);
        runtime.replaceFunction(0x001C75C0u, chain_0x001c75c0);
        runtime.replaceFunction(0x001C7650u, chain_0x001c7650);
        runtime.replaceFunction(0x001C77E8u, chain_0x001c77e8);
        runtime.replaceFunction(0x001C83B0u, chain_0x001c83b0);
        runtime.replaceFunction(0x001C9298u, chain_0x001c9298);
        runtime.replaceFunction(0x001CBC30u, chain_0x001cbc30);
        runtime.replaceFunction(0x001CE960u, chain_0x001ce960);
        runtime.replaceFunction(0x001CE9B0u, chain_0x001ce9b0);
        runtime.replaceFunction(0x001CF800u, chain_0x001cf800);
        runtime.replaceFunction(0x001D0B10u, chain_0x001d0b10);
        runtime.replaceFunction(0x001D0FE0u, chain_0x001d0fe0);
        runtime.replaceFunction(0x001D1AE0u, chain_0x001d1ae0);
        runtime.replaceFunction(0x001D3550u, chain_0x001d3550);
        runtime.replaceFunction(0x001D51A0u, chain_0x001d51a0);
        runtime.replaceFunction(0x001D84F0u, chain_0x001d84f0);
        runtime.replaceFunction(0x001D8878u, chain_0x001d8878);
        runtime.replaceFunction(0x001D8B58u, chain_0x001d8b58);
        runtime.replaceFunction(0x001D8C78u, chain_0x001d8c78);
        runtime.replaceFunction(0x001D8E08u, chain_0x001d8e08);
        runtime.replaceFunction(0x001D94A0u, chain_0x001d94a0);
        runtime.replaceFunction(0x001D9500u, chain_0x001d9500);
        runtime.replaceFunction(0x001D9760u, chain_0x001d9760);
        runtime.replaceFunction(0x001DB638u, chain_0x001db638);
        runtime.replaceFunction(0x001DD900u, chain_0x001dd900);
        runtime.replaceFunction(0x001DD928u, chain_0x001dd928);
        runtime.replaceFunction(0x001DF488u, chain_0x001df488);
        runtime.replaceFunction(0x001E0070u, chain_0x001e0070);
        runtime.replaceFunction(0x001E0130u, chain_0x001e0130);
        runtime.replaceFunction(0x001E03F0u, chain_0x001e03f0);
        runtime.replaceFunction(0x001E0BC0u, chain_0x001e0bc0);
        runtime.replaceFunction(0x001E0BE8u, chain_0x001e0be8);
        runtime.replaceFunction(0x001E18E8u, chain_0x001e18e8);
        runtime.replaceFunction(0x001F4AE0u, chain_0x001f4ae0);
        runtime.replaceFunction(0x001F5730u, chain_0x001f5730);
        runtime.replaceFunction(0x001F5938u, chain_0x001f5938);
        runtime.replaceFunction(0x001F72E8u, chain_0x001f72e8);
        runtime.replaceFunction(0x001F7330u, chain_0x001f7330);
        runtime.replaceFunction(0x001F76F0u, chain_0x001f76f0);
        runtime.replaceFunction(0x001F77E8u, chain_0x001f77e8);
        runtime.replaceFunction(0x001F8C08u, chain_0x001f8c08);
        runtime.replaceFunction(0x001FAF00u, chain_0x001faf00);
        runtime.replaceFunction(0x001FCA60u, chain_0x001fca60);
        runtime.replaceFunction(0x001FDC90u, chain_0x001fdc90);
        runtime.replaceFunction(0x001FDD50u, chain_0x001fdd50);
        runtime.replaceFunction(0x001FDE10u, chain_0x001fde10);
        runtime.replaceFunction(0x001FDF38u, chain_0x001fdf38);
        runtime.replaceFunction(0x00200A08u, chain_0x00200a08);
        runtime.replaceFunction(0x00202470u, chain_0x00202470);
        runtime.replaceFunction(0x002035F0u, chain_0x002035f0);
        runtime.replaceFunction(0x002052B8u, chain_0x002052b8);
        runtime.replaceFunction(0x00205BD8u, chain_0x00205bd8);
        runtime.replaceFunction(0x00206868u, chain_0x00206868);
        runtime.replaceFunction(0x00206910u, chain_0x00206910);
        runtime.replaceFunction(0x00206980u, chain_0x00206980);
        runtime.replaceFunction(0x00207CF8u, chain_0x00207cf8);
        runtime.replaceFunction(0x00207D60u, chain_0x00207d60);
        runtime.replaceFunction(0x00207DC0u, chain_0x00207dc0);
        runtime.replaceFunction(0x00207E58u, chain_0x00207e58);
        runtime.replaceFunction(0x00208520u, chain_0x00208520);
        runtime.replaceFunction(0x00208EF8u, chain_0x00208ef8);
        runtime.replaceFunction(0x00208FE0u, chain_0x00208fe0);
        runtime.replaceFunction(0x002091B8u, chain_0x002091b8);
        runtime.replaceFunction(0x00209310u, chain_0x00209310);
        runtime.replaceFunction(0x00209430u, chain_0x00209430);
        runtime.replaceFunction(0x002094A0u, chain_0x002094a0);
        runtime.replaceFunction(0x00209CB0u, chain_0x00209cb0);
        runtime.replaceFunction(0x0020A040u, chain_0x0020a040);
        runtime.replaceFunction(0x0020CE40u, chain_0x0020ce40);
        runtime.replaceFunction(0x0020D6F8u, chain_0x0020d6f8);
        runtime.replaceFunction(0x0020E868u, chain_0x0020e868);
        runtime.replaceFunction(0x0020F5E8u, chain_0x0020f5e8);
        runtime.replaceFunction(0x00210EE0u, chain_0x00210ee0);
        runtime.replaceFunction(0x00211430u, chain_0x00211430);
        runtime.replaceFunction(0x00211478u, chain_0x00211478);
        runtime.replaceFunction(0x00211AE0u, chain_0x00211ae0);
        runtime.replaceFunction(0x00213278u, chain_0x00213278);
        runtime.replaceFunction(0x00215670u, chain_0x00215670);
        runtime.replaceFunction(0x00215718u, chain_0x00215718);
        runtime.replaceFunction(0x00215A90u, chain_0x00215a90);
        runtime.replaceFunction(0x00215CE8u, chain_0x00215ce8);
        runtime.replaceFunction(0x00215DB8u, chain_0x00215db8);
        runtime.replaceFunction(0x00216300u, chain_0x00216300);
        runtime.replaceFunction(0x002165A0u, chain_0x002165a0);
        runtime.replaceFunction(0x002168D0u, chain_0x002168d0);
        runtime.replaceFunction(0x00217650u, chain_0x00217650);
        runtime.replaceFunction(0x00217CE0u, chain_0x00217ce0);
        runtime.replaceFunction(0x00217E88u, chain_0x00217e88);
        runtime.replaceFunction(0x00218538u, chain_0x00218538);
        runtime.replaceFunction(0x00218620u, chain_0x00218620);
        runtime.replaceFunction(0x00218838u, chain_0x00218838);
        runtime.replaceFunction(0x00218990u, chain_0x00218990);
        runtime.replaceFunction(0x00219020u, chain_0x00219020);
        runtime.replaceFunction(0x00219A88u, chain_0x00219a88);
        runtime.replaceFunction(0x0021C288u, chain_0x0021c288);
        runtime.replaceFunction(0x0021C3D0u, chain_0x0021c3d0);
        runtime.replaceFunction(0x0021CB78u, chain_0x0021cb78);
        runtime.replaceFunction(0x0021D140u, chain_0x0021d140);
        runtime.replaceFunction(0x0021D300u, chain_0x0021d300);
        runtime.replaceFunction(0x0021D760u, chain_0x0021d760);
        runtime.replaceFunction(0x0021E720u, chain_0x0021e720);
        runtime.replaceFunction(0x0021E820u, chain_0x0021e820);
        runtime.replaceFunction(0x0021EC40u, chain_0x0021ec40);
        runtime.replaceFunction(0x0021ED10u, chain_0x0021ed10);
        runtime.replaceFunction(0x0021EE88u, chain_0x0021ee88);
        runtime.replaceFunction(0x0021F6B0u, chain_0x0021f6b0);
        runtime.replaceFunction(0x0021FD70u, chain_0x0021fd70);
        runtime.replaceFunction(0x00221F70u, chain_0x00221f70);
        runtime.replaceFunction(0x00226040u, chain_0x00226040);
        runtime.replaceFunction(0x00226044u, chain_0x00226044);
        runtime.replaceFunction(0x00226150u, chain_0x00226150);
        runtime.replaceFunction(0x002286C0u, chain_0x002286c0);
        runtime.replaceFunction(0x00229398u, chain_0x00229398);
        runtime.replaceFunction(0x002293C0u, chain_0x002293c0);
        runtime.replaceFunction(0x00229CE0u, chain_0x00229ce0);
        runtime.replaceFunction(0x00229EE8u, chain_0x00229ee8);
        runtime.replaceFunction(0x0022A608u, chain_0x0022a608);
        runtime.replaceFunction(0x0022BF68u, chain_0x0022bf68);
        runtime.replaceFunction(0x0022CAB0u, chain_0x0022cab0);
        runtime.replaceFunction(0x0022EB90u, chain_0x0022eb90);
        runtime.replaceFunction(0x002304E0u, chain_0x002304e0);
        runtime.replaceFunction(0x00231350u, chain_0x00231350);
        runtime.replaceFunction(0x002317D0u, chain_0x002317d0);
        runtime.replaceFunction(0x00231970u, chain_0x00231970);
        runtime.replaceFunction(0x00232838u, chain_0x00232838);
        runtime.replaceFunction(0x00232868u, chain_0x00232868);
        runtime.replaceFunction(0x00234F18u, chain_0x00234f18);
        runtime.replaceFunction(0x00234FD8u, chain_0x00234fd8);
        runtime.replaceFunction(0x00236FE8u, chain_0x00236fe8);
        runtime.replaceFunction(0x002387C8u, chain_0x002387c8);
        runtime.replaceFunction(0x0023A5D0u, chain_0x0023a5d0);
        runtime.replaceFunction(0x0023ABA8u, chain_0x0023aba8);
        runtime.replaceFunction(0x0023D558u, chain_0x0023d558);
        runtime.replaceFunction(0x0023D778u, chain_0x0023d778);
        runtime.replaceFunction(0x0023E8D8u, chain_0x0023e8d8);
        runtime.replaceFunction(0x0023F180u, chain_0x0023f180);
        runtime.replaceFunction(0x0023F3E8u, chain_0x0023f3e8);
        runtime.replaceFunction(0x0023F518u, chain_0x0023f518);
        runtime.replaceFunction(0x002434F8u, chain_0x002434f8);
        runtime.replaceFunction(0x00243A80u, chain_0x00243a80);
        runtime.replaceFunction(0x00243B10u, chain_0x00243b10);
        runtime.replaceFunction(0x002463C0u, chain_0x002463c0);
        runtime.replaceFunction(0x00252250u, chain_0x00252250);
        runtime.replaceFunction(0x002522F0u, chain_0x002522f0);
        runtime.replaceFunction(0x00252620u, chain_0x00252620);
        runtime.replaceFunction(0x00258960u, chain_0x00258960);
        runtime.replaceFunction(0x0025BAE8u, chain_0x0025bae8);
        runtime.replaceFunction(0x0025E0A0u, chain_0x0025e0a0);
        runtime.replaceFunction(0x00260AB8u, chain_0x00260ab8);
        runtime.replaceFunction(0x002615C0u, chain_0x002615c0);
        runtime.replaceFunction(0x00262B10u, chain_0x00262b10);
        runtime.replaceFunction(0x00264198u, chain_0x00264198);
        runtime.replaceFunction(0x00264708u, chain_0x00264708);
        runtime.replaceFunction(0x002647A8u, chain_0x002647a8);
        runtime.replaceFunction(0x00264B08u, chain_0x00264b08);
        runtime.replaceFunction(0x00265050u, chain_0x00265050);
        runtime.replaceFunction(0x002675B0u, chain_0x002675b0);
        runtime.replaceFunction(0x002675E0u, chain_0x002675e0);
        runtime.replaceFunction(0x002677A0u, chain_0x002677a0);
        runtime.replaceFunction(0x00267998u, chain_0x00267998);
        runtime.replaceFunction(0x0026AD58u, chain_0x0026ad58);
        runtime.replaceFunction(0x0026B1F8u, chain_0x0026b1f8);
        runtime.replaceFunction(0x0026B538u, chain_0x0026b538);
        runtime.replaceFunction(0x0026BBA8u, chain_0x0026bba8);
        runtime.replaceFunction(0x0026C8A8u, chain_0x0026c8a8);
        runtime.replaceFunction(0x0026CF50u, chain_0x0026cf50);
        runtime.replaceFunction(0x0026CF54u, chain_0x0026cf54);
        runtime.replaceFunction(0x0026D018u, chain_0x0026d018);
        runtime.replaceFunction(0x0029B230u, chain_0x0029b230);
        runtime.replaceFunction(0x0029B268u, chain_0x0029b268);
        runtime.replaceFunction(0x002ACF64u, chain_0x002acf64);
        runtime.replaceFunction(0x002AE270u, chain_0x002ae270);
        runtime.replaceFunction(0x002BA988u, chain_0x002ba988);
        runtime.replaceFunction(0x002BAB68u, chain_0x002bab68);
        runtime.replaceFunction(0x002CC3C0u, chain_0x002cc3c0);
        runtime.replaceFunction(0x002CC708u, chain_0x002cc708);
        runtime.replaceFunction(0x002D14E8u, chain_0x002d14e8);
        runtime.replaceFunction(0x002D1630u, chain_0x002d1630);
        runtime.replaceFunction(0x002D1F10u, chain_0x002d1f10);
        runtime.replaceFunction(0x002D1F68u, chain_0x002d1f68);
        runtime.replaceFunction(0x002D2038u, chain_0x002d2038);
        runtime.replaceFunction(0x002D2228u, chain_0x002d2228);
        runtime.replaceFunction(0x002D2338u, chain_0x002d2338);
        runtime.replaceFunction(0x002D2730u, chain_0x002d2730);
        runtime.replaceFunction(0x002D7F58u, chain_0x002d7f58);
        runtime.replaceFunction(0x002D80F0u, chain_0x002d80f0);
        runtime.replaceFunction(0x002D82D0u, chain_0x002d82d0);
        runtime.replaceFunction(0x002DC4D8u, chain_0x002dc4d8);
        runtime.replaceFunction(0x002DC508u, chain_0x002dc508);
        runtime.replaceFunction(0x002E98E0u, chain_0x002e98e0);
        runtime.replaceFunction(0x002EA018u, chain_0x002ea018);
        runtime.replaceFunction(0x002EA5A0u, chain_0x002ea5a0);
        runtime.replaceFunction(0x002EA6B8u, chain_0x002ea6b8);
        runtime.replaceFunction(0x002EAD30u, chain_0x002ead30);
        runtime.replaceFunction(0x002EC560u, chain_0x002ec560);
        runtime.replaceFunction(0x002ECF88u, chain_0x002ecf88);
        runtime.replaceFunction(0x002F0BE8u, chain_0x002f0be8);
        runtime.replaceFunction(0x002F0EB8u, chain_0x002f0eb8);
        runtime.replaceFunction(0x002F1860u, chain_0x002f1860);
        runtime.replaceFunction(0x002F3360u, chain_0x002f3360);
        runtime.replaceFunction(0x002F5480u, chain_0x002f5480);
        runtime.replaceFunction(0x002F6FC8u, chain_0x002f6fc8);
        runtime.replaceFunction(0x002F7E38u, chain_0x002f7e38);
        runtime.replaceFunction(0x002F7EE8u, chain_0x002f7ee8);
        runtime.replaceFunction(0x002F7FB8u, chain_0x002f7fb8);
        runtime.replaceFunction(0x002F8560u, chain_0x002f8560);
        runtime.replaceFunction(0x002F8BE0u, chain_0x002f8be0);
        runtime.replaceFunction(0x002F9830u, chain_0x002f9830);
        runtime.replaceFunction(0x002FCFF0u, chain_0x002fcff0);
        runtime.replaceFunction(0x00305108u, chain_0x00305108);
        runtime.replaceFunction(0x00305500u, chain_0x00305500);
        runtime.replaceFunction(0x003058F8u, chain_0x003058f8);
        runtime.replaceFunction(0x00305CF0u, chain_0x00305cf0);
        runtime.replaceFunction(0x003060E8u, chain_0x003060e8);
        runtime.replaceFunction(0x003064E0u, chain_0x003064e0);
        runtime.replaceFunction(0x0030A1D0u, chain_0x0030a1d0);
        runtime.replaceFunction(0x0030C378u, chain_0x0030c378);
        runtime.replaceFunction(0x0030D848u, chain_0x0030d848);
        runtime.replaceFunction(0x00317378u, chain_0x00317378);
        runtime.replaceFunction(0x003174B0u, chain_0x003174b0);
        runtime.replaceFunction(0x00319E30u, chain_0x00319e30);
        runtime.replaceFunction(0x0031BF80u, chain_0x0031bf80);
        runtime.replaceFunction(0x0031F72Cu, chain_0x0031f72c);
        runtime.replaceFunction(0x003202A0u, chain_0x003202a0);
        runtime.replaceFunction(0x003209C0u, chain_0x003209c0);
        runtime.replaceFunction(0x00321920u, chain_0x00321920);
        runtime.replaceFunction(0x003392C0u, chain_0x003392c0);
        runtime.replaceFunction(0x0033FF78u, chain_0x0033ff78);
        runtime.replaceFunction(0x003403D0u, chain_0x003403d0);
        runtime.replaceFunction(0x003404D8u, chain_0x003404d8);
        runtime.replaceFunction(0x00340860u, chain_0x00340860);
        runtime.replaceFunction(0x00340F68u, chain_0x00340f68);
        runtime.replaceFunction(0x003412A0u, chain_0x003412a0);
        runtime.replaceFunction(0x00343930u, chain_0x00343930);
        runtime.replaceFunction(0x003439D8u, chain_0x003439d8);
        runtime.replaceFunction(0x003443B0u, chain_0x003443b0);
        runtime.replaceFunction(0x00345520u, chain_0x00345520);
        runtime.replaceFunction(0x00345D30u, chain_0x00345d30);
        runtime.replaceFunction(0x003460F0u, chain_0x003460f0);
        runtime.replaceFunction(0x00346FE0u, chain_0x00346fe0);
        runtime.replaceFunction(0x003479E8u, chain_0x003479e8);
        runtime.replaceFunction(0x0034A708u, chain_0x0034a708);
        runtime.replaceFunction(0x0034B600u, chain_0x0034b600);
        runtime.replaceFunction(0x0035B768u, chain_0x0035b768);
        runtime.replaceFunction(0x0035BDE8u, chain_0x0035bde8);
        runtime.replaceFunction(0x0035D720u, chain_0x0035d720);
        runtime.replaceFunction(0x0035E010u, chain_0x0035e010);
        runtime.replaceFunction(0x0035E138u, chain_0x0035e138);
        runtime.replaceFunction(0x0035E6E8u, chain_0x0035e6e8);
        runtime.replaceFunction(0x00362BF0u, chain_0x00362bf0);
        runtime.replaceFunction(0x00363220u, chain_0x00363220);
        runtime.replaceFunction(0x00363328u, chain_0x00363328);
        runtime.replaceFunction(0x00363350u, chain_0x00363350);
        runtime.replaceFunction(0x00363410u, chain_0x00363410);
        runtime.replaceFunction(0x00363500u, chain_0x00363500);
        runtime.replaceFunction(0x0037F400u, chain_0x0037f400);
        runtime.replaceFunction(0x0037F4D0u, chain_0x0037f4d0);
        runtime.replaceFunction(0x0037F800u, chain_0x0037f800);
        runtime.replaceFunction(0x00386900u, chain_0x00386900);
        runtime.replaceFunction(0x0038A570u, chain_0x0038a570);
        runtime.replaceFunction(0x0038A5B0u, chain_0x0038a5b0);
        runtime.replaceFunction(0x0038E490u, chain_0x0038e490);
        runtime.replaceFunction(0x0038E6F8u, chain_0x0038e6f8);
        runtime.replaceFunction(0x0038E8E8u, chain_0x0038e8e8);
        runtime.replaceFunction(0x0038E968u, chain_0x0038e968);
        runtime.replaceFunction(0x0038EA40u, chain_0x0038ea40);
        runtime.replaceFunction(0x00390FE8u, chain_0x00390fe8);
        runtime.replaceFunction(0x00392CB8u, chain_0x00392cb8);
        runtime.replaceFunction(0x00393D90u, chain_0x00393d90);
        runtime.replaceFunction(0x00393F48u, chain_0x00393f48);
        runtime.replaceFunction(0x003942E0u, chain_0x003942e0);
        runtime.replaceFunction(0x003946C8u, chain_0x003946c8);
        runtime.replaceFunction(0x00399A20u, chain_0x00399a20);
        runtime.replaceFunction(0x0039B5C0u, chain_0x0039b5c0);
        runtime.replaceFunction(0x0039D9C0u, chain_0x0039d9c0);
        runtime.replaceFunction(0x003A8310u, chain_0x003a8310);
        runtime.replaceFunction(0x003A9360u, chain_0x003a9360);
        runtime.replaceFunction(0x003AAAA8u, chain_0x003aaaa8);
        runtime.replaceFunction(0x003ABB20u, chain_0x003abb20);
        runtime.replaceFunction(0x003B37C0u, chain_0x003b37c0);
        runtime.replaceFunction(0x003B49E0u, chain_0x003b49e0);
        runtime.replaceFunction(0x003B7948u, chain_0x003b7948);
        runtime.replaceFunction(0x003BF000u, chain_0x003bf000);
        runtime.replaceFunction(0x003BFA30u, chain_0x003bfa30);
        runtime.replaceFunction(0x003C21E0u, chain_0x003c21e0);
        runtime.replaceFunction(0x003C23B8u, chain_0x003c23b8);
        runtime.replaceFunction(0x003C23C8u, chain_0x003c23c8);
        runtime.replaceFunction(0x003C24A8u, chain_0x003c24a8);
        runtime.replaceFunction(0x003C2704u, chain_0x003c2704);
        runtime.replaceFunction(0x003C42E0u, chain_0x003c42e0);
        runtime.replaceFunction(0x003C4E20u, chain_0x003c4e20);
        runtime.replaceFunction(0x003C5AE0u, chain_0x003c5ae0);
        runtime.replaceFunction(0x003C62E8u, chain_0x003c62e8);
        runtime.replaceFunction(0x003C6E48u, chain_0x003c6e48);
        runtime.replaceFunction(0x003C6E80u, chain_0x003c6e80);
        runtime.replaceFunction(0x003C6FD0u, chain_0x003c6fd0);
        runtime.replaceFunction(0x003C7218u, chain_0x003c7218);
        runtime.replaceFunction(0x003C7800u, chain_0x003c7800);
        runtime.replaceFunction(0x003C83A8u, chain_0x003c83a8);
        runtime.replaceFunction(0x003C8FD8u, chain_0x003c8fd8);
        runtime.replaceFunction(0x003C9068u, chain_0x003c9068);
        runtime.replaceFunction(0x003C9298u, chain_0x003c9298);
        runtime.replaceFunction(0x003C9B98u, chain_0x003c9b98);
        runtime.replaceFunction(0x003C9C40u, chain_0x003c9c40);
        runtime.replaceFunction(0x003C9CC8u, chain_0x003c9cc8);
        runtime.replaceFunction(0x003C9D50u, chain_0x003c9d50);
        runtime.replaceFunction(0x003CA708u, chain_0x003ca708);
        runtime.replaceFunction(0x003CA7C0u, chain_0x003ca7c0);
        runtime.replaceFunction(0x003CA838u, chain_0x003ca838);
        runtime.replaceFunction(0x003CA8B0u, chain_0x003ca8b0);
        runtime.replaceFunction(0x003CA930u, chain_0x003ca930);
        runtime.replaceFunction(0x003CA9F0u, chain_0x003ca9f0);
        runtime.replaceFunction(0x003CAB40u, chain_0x003cab40);
        runtime.replaceFunction(0x003CAB80u, chain_0x003cab80);
        runtime.replaceFunction(0x003CABB0u, chain_0x003cabb0);
        runtime.replaceFunction(0x003CC0D0u, chain_0x003cc0d0);
        runtime.replaceFunction(0x003CC288u, chain_0x003cc288);
        runtime.replaceFunction(0x003CC360u, chain_0x003cc360);
        runtime.replaceFunction(0x003CC478u, chain_0x003cc478);
        runtime.replaceFunction(0x003CD5B0u, chain_0x003cd5b0);
        runtime.replaceFunction(0x003CD610u, chain_0x003cd610);
        runtime.replaceFunction(0x003CD670u, chain_0x003cd670);
        runtime.replaceFunction(0x003CD870u, chain_0x003cd870);
        runtime.replaceFunction(0x003CD970u, chain_0x003cd970);
        runtime.replaceFunction(0x003CDA50u, chain_0x003cda50);
        runtime.replaceFunction(0x003CDA90u, chain_0x003cda90);
        runtime.replaceFunction(0x003CE000u, chain_0x003ce000);
        runtime.replaceFunction(0x003CE028u, chain_0x003ce028);
        runtime.replaceFunction(0x003CE050u, chain_0x003ce050);
        runtime.replaceFunction(0x003CE2A8u, chain_0x003ce2a8);
        runtime.replaceFunction(0x003CE788u, chain_0x003ce788);
        runtime.replaceFunction(0x003CEDA8u, chain_0x003ceda8);
        runtime.replaceFunction(0x003CF1A0u, chain_0x003cf1a0);
        runtime.replaceFunction(0x003CF310u, chain_0x003cf310);
        runtime.replaceFunction(0x003CF3D8u, chain_0x003cf3d8);
        runtime.replaceFunction(0x003CF4C8u, chain_0x003cf4c8);
        runtime.replaceFunction(0x003CF600u, chain_0x003cf600);
        runtime.replaceFunction(0x003CF7F8u, chain_0x003cf7f8);
        runtime.replaceFunction(0x003CFBF8u, chain_0x003cfbf8);
        runtime.replaceFunction(0x003D0008u, chain_0x003d0008);
        runtime.replaceFunction(0x003D0080u, chain_0x003d0080);
        runtime.replaceFunction(0x003D01F0u, chain_0x003d01f0);
        runtime.replaceFunction(0x003D1278u, chain_0x003d1278);
        runtime.replaceFunction(0x003D1E48u, chain_0x003d1e48);
        runtime.replaceFunction(0x003D1FF0u, chain_0x003d1ff0);
        runtime.replaceFunction(0x003D2208u, chain_0x003d2208);
        runtime.replaceFunction(0x003D2608u, chain_0x003d2608);
        runtime.replaceFunction(0x003D2F08u, chain_0x003d2f08);
        runtime.replaceFunction(0x003D3480u, chain_0x003d3480);
        runtime.replaceFunction(0x003D3800u, chain_0x003d3800);
        runtime.replaceFunction(0x003D4628u, chain_0x003d4628);
        runtime.replaceFunction(0x003D46A8u, chain_0x003d46a8);
        runtime.replaceFunction(0x003D5118u, chain_0x003d5118);
        runtime.replaceFunction(0x003D5230u, chain_0x003d5230);
        runtime.replaceFunction(0x003D5A38u, chain_0x003d5a38);
        runtime.replaceFunction(0x003D5F38u, chain_0x003d5f38);
        runtime.replaceFunction(0x003D6050u, chain_0x003d6050);
        runtime.replaceFunction(0x003D6054u, chain_0x003d6054);
        runtime.replaceFunction(0x003D60F8u, chain_0x003d60f8);
        runtime.replaceFunction(0x003D61A0u, chain_0x003d61a0);
        runtime.replaceFunction(0x003D61D8u, chain_0x003d61d8);
        runtime.replaceFunction(0x003D64F0u, chain_0x003d64f0);
        runtime.replaceFunction(0x003D6558u, chain_0x003d6558);
        runtime.replaceFunction(0x003D6C68u, chain_0x003d6c68);
        runtime.replaceFunction(0x003D75D0u, chain_0x003d75d0);
        runtime.replaceFunction(0x003D8350u, chain_0x003d8350);
        runtime.replaceFunction(0x003D84D0u, chain_0x003d84d0);
        runtime.replaceFunction(0x003D9700u, chain_0x003d9700);
        runtime.replaceFunction(0x003D9810u, chain_0x003d9810);
        runtime.replaceFunction(0x003DA5A8u, chain_0x003da5a8);
        runtime.replaceFunction(0x003DACA8u, chain_0x003daca8);
        runtime.replaceFunction(0x003DB658u, chain_0x003db658);
        runtime.replaceFunction(0x003DB8C0u, chain_0x003db8c0);
        runtime.replaceFunction(0x003DC378u, chain_0x003dc378);
        runtime.replaceFunction(0x003DC440u, chain_0x003dc440);
        runtime.replaceFunction(0x003DC444u, chain_0x003dc444);
        runtime.replaceFunction(0x003DCB28u, chain_0x003dcb28);
        runtime.replaceFunction(0x003DCFFCu, chain_0x003dcffc);
        runtime.replaceFunction(0x003DD0A8u, chain_0x003dd0a8);
        runtime.replaceFunction(0x003DD0ACu, chain_0x003dd0ac);
        runtime.replaceFunction(0x003DDDA8u, chain_0x003ddda8);
        runtime.replaceFunction(0x003DF6E8u, chain_0x003df6e8);
        runtime.replaceFunction(0x003E05E8u, chain_0x003e05e8);
        runtime.replaceFunction(0x003E0728u, chain_0x003e0728);
        runtime.replaceFunction(0x003E07F8u, chain_0x003e07f8);
        runtime.replaceFunction(0x003E10B8u, chain_0x003e10b8);
        runtime.replaceFunction(0x003E19C0u, chain_0x003e19c0);
        runtime.replaceFunction(0x003E2A18u, chain_0x003e2a18);
        runtime.replaceFunction(0x003E2C70u, chain_0x003e2c70);
        runtime.replaceFunction(0x003E2DD8u, chain_0x003e2dd8);
        runtime.replaceFunction(0x003E2E70u, chain_0x003e2e70);
        runtime.replaceFunction(0x003E3628u, chain_0x003e3628);
        runtime.replaceFunction(0x003E3758u, chain_0x003e3758);
        runtime.replaceFunction(0x003E3978u, chain_0x003e3978);
        runtime.replaceFunction(0x003E3CC0u, chain_0x003e3cc0);
        runtime.replaceFunction(0x003E53B8u, chain_0x003e53b8);
        runtime.replaceFunction(0x003E5CF8u, chain_0x003e5cf8);
        runtime.replaceFunction(0x003E5DF0u, chain_0x003e5df0);
        runtime.replaceFunction(0x003E60D0u, chain_0x003e60d0);
        runtime.replaceFunction(0x003E6E60u, chain_0x003e6e60);
        runtime.replaceFunction(0x003E7248u, chain_0x003e7248);
        runtime.replaceFunction(0x003E95E0u, chain_0x003e95e0);
        runtime.replaceFunction(0x003EADA0u, chain_0x003eada0);
        runtime.replaceFunction(0x003EB050u, chain_0x003eb050);
        runtime.replaceFunction(0x003EB2B0u, chain_0x003eb2b0);
        runtime.replaceFunction(0x003EDBA0u, chain_0x003edba0);
        runtime.replaceFunction(0x003EDC18u, chain_0x003edc18);
        runtime.replaceFunction(0x003EDD50u, chain_0x003edd50);
        runtime.replaceFunction(0x003EDD64u, chain_0x003edd64);
        runtime.replaceFunction(0x003EDDB8u, chain_0x003eddb8);
        runtime.replaceFunction(0x003EE1F8u, chain_0x003ee1f8);
        runtime.replaceFunction(0x003EE278u, chain_0x003ee278);
        runtime.replaceFunction(0x003EE28Cu, chain_0x003ee28c);
        runtime.replaceFunction(0x003EE2E8u, chain_0x003ee2e8);
        runtime.replaceFunction(0x003EEA88u, chain_0x003eea88);
        runtime.replaceFunction(0x003EEB60u, chain_0x003eeb60);
        runtime.replaceFunction(0x003EEDA8u, chain_0x003eeda8);
        runtime.replaceFunction(0x003F03F8u, chain_0x003f03f8);
        runtime.replaceFunction(0x003F0AF0u, chain_0x003f0af0);
        runtime.replaceFunction(0x003F0CE0u, chain_0x003f0ce0);
        runtime.replaceFunction(0x003F0DD0u, chain_0x003f0dd0);
        runtime.replaceFunction(0x003F35C8u, chain_0x003f35c8);
        runtime.replaceFunction(0x003F4020u, chain_0x003f4020);
        runtime.replaceFunction(0x003F53C0u, chain_0x003f53c0);
        runtime.replaceFunction(0x003F55B8u, chain_0x003f55b8);
        runtime.replaceFunction(0x003F5940u, chain_0x003f5940);
        runtime.replaceFunction(0x003F67D0u, chain_0x003f67d0);
        runtime.replaceFunction(0x003F6830u, chain_0x003f6830);
        runtime.replaceFunction(0x003F6D60u, chain_0x003f6d60);
        runtime.replaceFunction(0x003F7C98u, chain_0x003f7c98);
        runtime.replaceFunction(0x003F7EE0u, chain_0x003f7ee0);
        runtime.replaceFunction(0x003F8060u, chain_0x003f8060);
        runtime.replaceFunction(0x003F8088u, chain_0x003f8088);
        runtime.replaceFunction(0x003F9A90u, chain_0x003f9a90);
        runtime.replaceFunction(0x003FBC80u, chain_0x003fbc80);
        runtime.replaceFunction(0x003FBCF0u, chain_0x003fbcf0);
        runtime.replaceFunction(0x003FCF48u, chain_0x003fcf48);
        runtime.replaceFunction(0x003FE2C0u, chain_0x003fe2c0);
        runtime.replaceFunction(0x003FF348u, chain_0x003ff348);
        runtime.replaceFunction(0x00400B28u, chain_0x00400b28);
        runtime.replaceFunction(0x00401008u, chain_0x00401008);
        runtime.replaceFunction(0x00401048u, chain_0x00401048);
        runtime.replaceFunction(0x00402198u, chain_0x00402198);
        runtime.replaceFunction(0x00403718u, chain_0x00403718);
        runtime.replaceFunction(0x00403DC0u, chain_0x00403dc0);
        runtime.replaceFunction(0x00403E30u, chain_0x00403e30);
        runtime.replaceFunction(0x00403EA8u, chain_0x00403ea8);
        runtime.replaceFunction(0x004044F8u, chain_0x004044f8);
        runtime.replaceFunction(0x00404860u, chain_0x00404860);
        runtime.replaceFunction(0x004056B8u, chain_0x004056b8);
        runtime.replaceFunction(0x004057C0u, chain_0x004057c0);
        runtime.replaceFunction(0x00405A60u, chain_0x00405a60);
        runtime.replaceFunction(0x00405CC0u, chain_0x00405cc0);
        runtime.replaceFunction(0x00405DE8u, chain_0x00405de8);
        runtime.replaceFunction(0x00406CC0u, chain_0x00406cc0);
        runtime.replaceFunction(0x00407328u, chain_0x00407328);
    }
}
