# -*- coding: utf-8 -*-
"""
Gera o mapa C++ de partições e arquivos empacotados em _DATA0.AFS e _DATA1.AFS
para Okami (SLUS-21115).
"""
import struct
import re

CANONICAL_PARTITIONS = [
    'an', 'bgm', 'dll', 'dlltool', 'dr', 'em', 'es', 'et', 'etc',
    'event', 'gt', 'hl', 'hm', 'id', 'illust', 'it', 'iteminfo', 'map',
    'modules', 'movie', 'pl', 'se', 'st0', 'st1', 'st2', 'st3', 'stc',
    'std', 'ste', 'stf', 'subscr', 'us', 'ut', 'vt', 'wp'
]

def extrair_particoes():
    res = {}
    afs_configs = [
        ('game/_DATA0.AFS', 277, '_DATA0.AFS'),
        ('game/_DATA1.AFS', 1049180, '_DATA1.AFS')
    ]

    for afs_path, base_lsn, afs_name in afs_configs:
        with open(afs_path, 'rb') as f:
            magic, num_files = struct.unpack('<4sI', f.read(8))
            f.seek(8 + num_files * 8)
            dir_off, dir_sz = struct.unpack('<II', f.read(8))
            f.seek(dir_off)
            dir_data = f.read(dir_sz)

            for i in range(num_files):
                entry = dir_data[i * 48 : (i + 1) * 48]
                name = entry[:32].split(b'\x00')[0].decode('latin1', 'ignore').strip().lower()
                f.seek(8 + i * 8)
                file_off, file_sz = struct.unpack('<II', f.read(8))

                # Tentar match de particao canonica
                matched = None
                for c in sorted(CANONICAL_PARTITIONS, key=len, reverse=True):
                    if name.startswith(c):
                        # Evitar falso-positivo como animalfilemod com an
                        if len(c) == 2 and len(name) > 2 and name[2].isalpha() and not name.startswith(('st', 'hl', 'hm', 'an0', 'an1', 'an2', 'an8', 'ana', 'anb', 'anc')):
                            continue
                        matched = c
                        break

                if matched:
                    if matched not in res:
                        res[matched] = {
                            'afs': afs_name,
                            'min_off': file_off,
                            'max_end': file_off + file_sz,
                            'count': 0,
                            'base_lsn': base_lsn
                        }
                    else:
                        res[matched]['min_off'] = min(res[matched]['min_off'], file_off)
                        res[matched]['max_end'] = max(res[matched]['max_end'], file_off + file_sz)
                        res[matched]['count'] += 1

    entries = []
    for c in sorted(CANONICAL_PARTITIONS):
        if c in res:
            r = res[c]
            lsn = r['base_lsn'] + (r['min_off'] // 2048)
            sz = r['max_end'] - r['min_off']
            entries.append((c, lsn, sz, r['afs'], r['count']))
        else:
            entries.append((c, 0, 0, 'NONE', 0))
    return entries

def gerar_header():
    t = extrair_particoes()
    lines = [
        '#pragma once',
        '#include <cstdint>',
        '#include <cstddef>',
        '',
        '// Mapeamento nativo das particoes de dados de Okami (SLUS-21115)',
        '// Gerado automaticamente por tools/gerar_particoes.py a partir de _DATA0.AFS e _DATA1.AFS',
        '',
        'struct OkamiPartitionEntry {',
        '    const char *name;',
        '    uint32_t lsn;',
        '    uint32_t size;',
        '    const char *container;',
        '};',
        '',
        'static const OkamiPartitionEntry s_okamiPartitions[] = {'
    ]
    for item in t:
        lines.append(f'    {{ "{item[0]}", {item[1]}u, {item[2]}u, "{item[3]}" }}, // {item[4]} arquivos')
    lines.append('};')
    lines.append('')
    lines.append('static constexpr size_t s_okamiPartitionCount = sizeof(s_okamiPartitions) / sizeof(s_okamiPartitions[0]);')
    lines.append('')
    lines.append('inline const OkamiPartitionEntry* findOkamiPartition(const char *name) {')
    lines.append('    if (!name || !*name) return nullptr;')
    lines.append('    for (size_t i = 0; i < s_okamiPartitionCount; ++i) {')
    lines.append('        const char *p = s_okamiPartitions[i].name;')
    lines.append('        const char *s = name;')
    lines.append('        // Ignora separadores iniciais de disco (\\\\, /, :)')
    lines.append('        while (*s == \'\\\\\' || *s == \'/\') s++;')
    lines.append('        bool match = true;')
    lines.append('        while (*p) {')
    lines.append('            char cp = *p++;')
    lines.append('            char cs = *s++;')
    lines.append('            if (cp >= \'A\' && cp <= \'Z\') cp += 32;')
    lines.append('            if (cs >= \'A\' && cs <= \'Z\') cs += 32;')
    lines.append('            if (cp != cs) { match = false; break; }')
    lines.append('        }')
    lines.append('        if (match && (*s == \'\\0\' || *s == \';\' || *s == \'.\')) {')
    lines.append('            if (s_okamiPartitions[i].lsn > 0) return &s_okamiPartitions[i];')
    lines.append('        }')
    lines.append('    }')
    lines.append('    return nullptr;')
    lines.append('}')
    lines.append('')
    return '\n'.join(lines)

if __name__ == '__main__':
    content = gerar_header()
    with open('src/okami_partitions.h', 'w', encoding='utf-8') as f:
        f.write(content)
    print('src/okami_partitions.h gerado com sucesso!')
