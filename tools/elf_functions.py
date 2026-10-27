#!/usr/bin/env python3
"""
Scanner y generador de mapa de funciones (funcmap.csv) y plantilla de recompilador
(recomp.template.toml) especifico para Okami (PS2, SLUS_211.15).

Analiza el binario MIPS R5900 de Okami:
1. Localiza la seccion .text y punto de entrada.
2. Identifica puntos de entrada mediante JAL, BAL, prologos de pila (addiu/daddiu $sp),
   retornos (jr $ra), y tablas de syscalls de SCE.
3. Asocia stubs de funciones estandar del kernel/SDK de PS2.
4. Genera funcmap.csv ordenado y sin solapes, y config/recomp.template.toml valido.
"""

import os
import struct
import csv
import re
import argparse
from pathlib import Path

# Mapa de syscalls estandar de EE Kernel de PS2 (num -> nombre)
SCE_SYSCALL_NAMES = {
    0x01: "ResetEE",
    0x02: "SetGsCrt",
    0x04: "Exit",
    0x06: "LoadExecPS2",
    0x07: "ExecPS2",
    0x10: "AddIntcHandler",
    0x11: "RemoveIntcHandler",
    0x12: "AddDmacHandler",
    0x13: "RemoveDmacHandler",
    0x14: "_EnableIntc",
    0x15: "_DisableIntc",
    0x16: "_EnableDmac",
    0x17: "_DisableDmac",
    0x18: "_SetAlarm",
    0x19: "_ReleaseAlarm",
    0x20: "CreateThread",
    0x21: "DeleteThread",
    0x22: "StartThread",
    0x23: "ExitThread",
    0x24: "ExitDeleteThread",
    0x25: "TerminateThread",
    0x26: "iTerminateThread",
    0x27: "DisableDispatchThread",
    0x28: "EnableDispatchThread",
    0x29: "ChangeThreadPriority",
    0x2A: "iChangeThreadPriority",
    0x2B: "RotateThreadReadyQueue",
    0x2C: "iRotateThreadReadyQueue",
    0x2D: "ReleaseWaitThread",
    0x2E: "iReleaseWaitThread",
    0x2F: "GetThreadId",
    0x30: "ReferThreadStatus",
    0x31: "iReferThreadStatus",
    0x32: "SleepThread",
    0x33: "WakeupThread",
    0x34: "iWakeupThread",
    0x35: "CancelWakeupThread",
    0x36: "iCancelWakeupThread",
    0x37: "SuspendThread",
    0x38: "iSuspendThread",
    0x39: "ResumeThread",
    0x3A: "iResumeThread",
    0x3B: "JoinThread",
    0x3C: "SetupThread",
    0x3D: "SetupContext",
    0x40: "SetupFD",
    0x41: "SetupFreeFD",
    0x64: "FlushCache",
    0x70: "_iWakeupThread",
    0x76: "SifSetDma",
    0x77: "SifSetDChain",
    0x78: "SifSetReg",
    0x79: "SifGetReg",
}

def analyze_elf(elf_path: Path):
    with open(elf_path, "rb") as f:
        ident = f.read(16)
        if ident[:4] != b"\x7fELF":
            raise ValueError(f"{elf_path} no es un ELF valido.")
        
        type_, machine, version, entry, phoff, shoff, flags, ehsize, phentsize, phnum, shentsize, shnum, shstrndx = struct.unpack('<HHIIIIIHHHHHH', f.read(36))
        
        # Tabla de nombres de secciones
        f.seek(shoff + shstrndx * shentsize)
        shstr_hdr = f.read(shentsize)
        shstr_offset, shstr_size = struct.unpack('<II', shstr_hdr[16:24])
        f.seek(shstr_offset)
        shstrtab = f.read(shstr_size)
        
        # Buscar .text
        text_addr = None
        text_offset = None
        text_size = None
        for i in range(shnum):
            f.seek(shoff + i * shentsize)
            hdr = f.read(shentsize)
            name_idx, type_, flags, addr, offset, size = struct.unpack('<IIIIII', hdr[:24])
            name = shstrtab[name_idx:].split(b'\x00')[0].decode('latin1')
            if name == '.text':
                text_addr = addr
                text_offset = offset
                text_size = size
                break
        
        if not text_addr:
            raise ValueError("No se encontro la seccion .text en el ELF.")
            
        f.seek(text_offset)
        code = f.read(text_size)
        
    return entry, text_addr, text_size, code

def scan_functions(entry, text_addr, text_size, code):
    starts = set()
    starts.add(entry)
    
    # 1. Escanear instrucciones JAL y BAL
    # 2. Escanear prologos tipicos: addiu $sp, $sp, -imm o daddiu $sp, $sp, -imm
    # 3. Detectar epilogos: jr $ra
    for i in range(0, text_size, 4):
        curr_addr = text_addr + i
        w = struct.unpack('<I', code[i:i+4])[0]
        op = (w >> 26) & 0x3F
        
        # JAL
        if op == 3:
            target = ((curr_addr + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
            if text_addr <= target < text_addr + text_size:
                starts.add(target)
                
        # BGEZAL / BLTZAL
        elif op == 1:
            rt = (w >> 16) & 0x1F
            if rt in (0x10, 0x11): # BLTZAL, BGEZAL
                imm = w & 0xFFFF
                if imm & 0x8000:
                    imm -= 0x10000
                target = curr_addr + 4 + (imm << 2)
                if text_addr <= target < text_addr + text_size:
                    starts.add(target)
                    
        # Prologo de funcion: addiu $sp, $sp, -imm (0x27BDxxxx) o daddiu $sp, $sp, -imm (0x67BDxxxx)
        elif (w & 0xFFFF0000) in (0x27BD0000, 0x67BD0000):
            imm = w & 0xFFFF
            if imm & 0x8000: # offset negativo de asignacion de pila
                starts.add(curr_addr)
                
    sorted_starts = sorted(list(starts))
    
    # Identificar syscalls en la tabla SCE (alrededor de 0x003FE380)
    syscall_names_map = {}
    for i in range(0, text_size - 8, 4):
        curr_addr = text_addr + i
        w = struct.unpack('<I', code[i:i+4])[0]
        # SYSCALL instruction
        if (w & 0xFC00003F) == 0x0000000C:
            # Buscar instruccion anterior (addiu $v1, $zero, num) -> 0x2403xxxx
            if i >= 4:
                prev_w = struct.unpack('<I', code[i-4:i])[0]
                if (prev_w & 0xFFFF0000) == 0x24030000:
                    sc_num = prev_w & 0xFFFF
                    if sc_num in SCE_SYSCALL_NAMES:
                        fn_name = SCE_SYSCALL_NAMES[sc_num]
                        func_start = curr_addr - 4
                        syscall_names_map[func_start] = fn_name
                        starts.add(func_start)

    sorted_starts = sorted(list(starts))
    seen_names = {}
    functions = []
    
    # Construir rangos continuos sin solapes
    for idx, start in enumerate(sorted_starts):
        if idx + 1 < len(sorted_starts):
            end = sorted_starts[idx + 1]
        else:
            end = text_addr + text_size
            
        size = end - start
        if size <= 0:
            continue
            
        base_name = syscall_names_map.get(start, f"sub_{start:08X}")
        if base_name in seen_names:
            name = f"{base_name}_{start:08X}"
        else:
            name = base_name
        seen_names[base_name] = seen_names.get(base_name, 0) + 1
        functions.append((name, start, end, size))
        
    return functions

def generate_recomp_toml(functions, output_path: Path):
    # Seleccionar stubs conocidos con handlers en el runtime nativo
    stubs = []
    runtime_handled_stubs = {
        "ResetEE", "Exit", "CreateThread", "StartThread", "ExitThread", "SleepThread",
        "WakeupThread", "iWakeupThread", "TerminateThread", "ChangeThreadPriority",
        "SetupThread", "SetupContext", "SetupFD", "SetupFreeFD", "FlushCache",
        "SifSetDma", "SifSetDChain", "SifSetReg", "SifGetReg", "sceCdInit", "sceCdSync",
        "sceCdSearchFile", "sceCdGetError", "sceOpen", "sceClose", "sceRead", "sceLseek",
        "sceGsResetGraph", "sceGsSyncV", "sceGsResetPath", "sceGsSyncPath", "sceDmaSend"
    }
    
    for name, start, end, size in functions:
        if name in runtime_handled_stubs:
            stubs.append(f'  "{name}@0x{start:08X}",')
            
    toml_content = f"""# PS2Recomp configuration for Okami (SLUS_211.15)
# Generado por tools/elf_functions.py

[general]
# Path to input ELF file
input = "@ELF@"

# Path to function map CSV
ghidra_output = "@MAP@"

# Path to output directory
output = "@OUT@"

# Single file output mode
single_file_output = false

# Patch policy
patch_syscalls = false
patch_cop0 = true
patch_cache = true

# Funciones stubbed con handler nativo en el runtime
stubs = [
{chr(10).join(stubs)}
]

# Entry points adicionales si aplica
entry_points = [
  "entry@0x00100008",
]

# Parches a instrucciones problematicas detectadas en el ELF
instruction_patches = [
]
"""
    with open(output_path, "w", encoding="utf-8", newline="\n") as f:
        f.write(toml_content)

def main():
    parser = argparse.ArgumentParser(description="Escanea funciones de Okami SLUS_211.15 y genera config")
    parser.add_argument("--elf", default="game/SLUS_211.15", help="Ruta al ejecutable SLUS_211.15")
    parser.add_argument("--map", default="config/funcmap.csv", help="Ruta de salida funcmap.csv")
    parser.add_argument("--toml", default="config/recomp.template.toml", help="Ruta de salida plantilla toml")
    args = parser.parse_args()
    
    elf_p = Path(args.elf)
    if not elf_p.exists():
        print(f"Error: no existe {elf_p}")
        return 1
        
    print(f"Analizando {elf_p}...")
    entry, text_addr, text_size, code = analyze_elf(elf_p)
    print(f"Entry: 0x{entry:08X}, .text: 0x{text_addr:08X} - 0x{text_addr+text_size:08X} ({text_size} bytes)")
    
    functions = scan_functions(entry, text_addr, text_size, code)
    print(f"Total de funciones detectadas: {len(functions)}")
    
    map_p = Path(args.map)
    map_p.parent.mkdir(parents=True, exist_ok=True)
    with open(map_p, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["Name", "Start", "End", "Size"])
        for name, start, end, size in functions:
            writer.writerow([name, f"0x{start:08X}", f"0x{end:08X}", size])
    print(f"Mapa escrito en: {map_p}")
    
    toml_p = Path(args.toml)
    toml_p.parent.mkdir(parents=True, exist_ok=True)
    generate_recomp_toml(functions, toml_p)
    print(f"Plantilla TOML escrita en: {toml_p}")
    return 0

if __name__ == "__main__":
    exit(main())
