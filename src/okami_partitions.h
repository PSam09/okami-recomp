#pragma once
#include <cstdint>
#include <cstddef>

// Mapeamento nativo das particoes de dados de Okami (SLUS-21115)
// Gerado automaticamente por tools/gerar_particoes.py a partir de _DATA0.AFS e _DATA1.AFS

struct OkamiPartitionEntry {
    const char *name;
    uint32_t lsn;
    uint32_t size;
    const char *container;
};

static const OkamiPartitionEntry s_okamiPartitions[] = {
    { "an", 962319u, 9067056u, "_DATA0.AFS" }, // 125 arquivos
    { "bgm", 3800u, 1396086784u, "_DATA0.AFS" }, // 1 arquivos
    { "dll", 0u, 0u, "NONE" }, // 0 arquivos
    { "dlltool", 0u, 0u, "NONE" }, // 0 arquivos
    { "dr", 966747u, 1378176u, "_DATA0.AFS" }, // 64 arquivos
    { "em", 968311u, 73337472u, "_DATA0.AFS" }, // 213 arquivos
    { "es", 1004121u, 18951616u, "_DATA0.AFS" }, // 142 arquivos
    { "et", 1015802u, 8560320u, "_DATA0.AFS" }, // 149 arquivos
    { "etc", 1022514u, 2653376u, "_DATA0.AFS" }, // 15 arquivos
    { "event", 782313u, 82208u, "_DATA0.AFS" }, // 1 arquivos
    { "gt", 1026338u, 3300272u, "_DATA0.AFS" }, // 52 arquivos
    { "hl", 1027969u, 37546336u, "_DATA0.AFS" }, // 226 arquivos
    { "hm", 282u, 2147405248u, "_DATA0.AFS" }, // 228 arquivos
    { "id", 0u, 0u, "NONE" }, // 0 arquivos
    { "illust", 790990u, 7590976u, "_DATA0.AFS" }, // 58 arquivos
    { "it", 1073943u, 2561664u, "_DATA1.AFS" }, // 153 arquivos
    { "iteminfo", 796947u, 523648u, "_DATA0.AFS" }, // 255 arquivos
    { "map", 797332u, 1584192u, "_DATA0.AFS" }, // 5 arquivos
    { "modules", 0u, 0u, "NONE" }, // 0 arquivos
    { "movie", 798171u, 565056u, "_DATA0.AFS" }, // 1 arquivos
    { "pl", 473087u, 672218544u, "_DATA0.AFS" }, // 35 arquivos
    { "se", 0u, 0u, "NONE" }, // 0 arquivos
    { "st0", 0u, 0u, "NONE" }, // 0 arquivos
    { "st1", 927651u, 25198320u, "_DATA0.AFS" }, // 56 arquivos
    { "st2", 939955u, 10816064u, "_DATA0.AFS" }, // 25 arquivos
    { "st3", 945237u, 13575088u, "_DATA0.AFS" }, // 35 arquivos
    { "stc", 951866u, 3776u, "_DATA0.AFS" }, // 1 arquivos
    { "std", 0u, 0u, "NONE" }, // 0 arquivos
    { "ste", 951868u, 2918704u, "_DATA0.AFS" }, // 9 arquivos
    { "stf", 953294u, 16741248u, "_DATA0.AFS" }, // 26 arquivos
    { "subscr", 0u, 0u, "NONE" }, // 0 arquivos
    { "us", 1075750u, 14588912u, "_DATA1.AFS" }, // 109 arquivos
    { "ut", 1090626u, 14638976u, "_DATA1.AFS" }, // 150 arquivos
    { "vt", 1102354u, 6333712u, "_DATA1.AFS" }, // 145 arquivos
    { "wp", 476648u, 8899744u, "_DATA0.AFS" }, // 121 arquivos
};

static constexpr size_t s_okamiPartitionCount = sizeof(s_okamiPartitions) / sizeof(s_okamiPartitions[0]);

inline const OkamiPartitionEntry* findOkamiPartition(const char *name) {
    if (!name || !*name) return nullptr;
    for (size_t i = 0; i < s_okamiPartitionCount; ++i) {
        const char *p = s_okamiPartitions[i].name;
        const char *s = name;
        // Ignora separadores iniciais de disco (\\, /, :)
        while (*s == '\\' || *s == '/') s++;
        bool match = true;
        while (*p) {
            char cp = *p++;
            char cs = *s++;
            if (cp >= 'A' && cp <= 'Z') cp += 32;
            if (cs >= 'A' && cs <= 'Z') cs += 32;
            if (cp != cs) { match = false; break; }
        }
        if (match && (*s == '\0' || *s == ';' || *s == '.')) {
            if (s_okamiPartitions[i].lsn > 0) return &s_okamiPartitions[i];
        }
    }
    return nullptr;
}
