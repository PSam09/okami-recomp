import sys
from pathlib import Path

p = Path(r"C:\okamiport\PS2Recomp\ps2xRuntime\src\lib\ps2_runtime.cpp")
c = p.read_text(encoding="utf-8")

target1 = """bool PS2Runtime::replaceFunction(uint32_t address, RecompiledFunction func)
{
    uint32_t slot = 0u;
    if (!generatedFunctionTableSlot(address, slot))
    {
        std::cerr << "[function-table] cannot replace guest PC 0x" << std::hex << address
                  << ": outside generated dense table [0x" << g_ps2RecompiledFunctionTableBase
                  << ", 0x" << g_ps2RecompiledFunctionTableEnd << ")"
                  << std::dec << std::endl;
        return false;
    }

    g_ps2RecompiledFunctionTable[slot] = func;
    return true;
}"""

repl1 = """bool PS2Runtime::replaceFunction(uint32_t address, RecompiledFunction func)
{
    uint32_t slot = 0u;
    if (!generatedFunctionTableSlot(address, slot))
    {
        // Okami-Port: store in dynamic function map when outside the dense table
        m_dynamicFunctions[address] = func;
        return true;
    }

    g_ps2RecompiledFunctionTable[slot] = func;
    return true;
}"""

target2 = """bool PS2Runtime::hasFunction(uint32_t address) const
{
    uint32_t slot = 0u;
    return generatedFunctionTableSlot(address, slot) && g_ps2RecompiledFunctionTable[slot] != nullptr;
}"""

repl2 = """bool PS2Runtime::hasFunction(uint32_t address) const
{
    uint32_t slot = 0u;
    if (generatedFunctionTableSlot(address, slot) && g_ps2RecompiledFunctionTable[slot] != nullptr)
        return true;
    return m_dynamicFunctions.find(address) != m_dynamicFunctions.end();
}"""

target4 = """    if (generatedFunctionTableSlot(address, slot))
    {
        RecompiledFunction fn = g_ps2RecompiledFunctionTable[slot];
        if (fn != nullptr)
        {
            return fn;
        }
    }

    std::cerr << "Error: No exact recompiled function for guest PC 0x\""""

repl4 = """    if (generatedFunctionTableSlot(address, slot))
    {
        RecompiledFunction fn = g_ps2RecompiledFunctionTable[slot];
        if (fn != nullptr)
        {
            return fn;
        }
    }

    // Okami-Port: fallback to dynamic functions
    auto it = m_dynamicFunctions.find(address);
    if (it != m_dynamicFunctions.end())
    {
        return it->second;
    }

    std::cerr << "Error: No exact recompiled function for guest PC 0x\""""

is_crlf = "\r\n" in c
if is_crlf:
    target1 = target1.replace("\n", "\r\n")
    repl1 = repl1.replace("\n", "\r\n")
    target2 = target2.replace("\n", "\r\n")
    repl2 = repl2.replace("\n", "\r\n")
    target4 = target4.replace("\n", "\r\n")
    repl4 = repl4.replace("\n", "\r\n")

assert target1 in c, "target1 not found"
c = c.replace(target1, repl1, 1)

assert target2 in c, "target2 not found"
c = c.replace(target2, repl2, 1)

assert target4 in c, "target4 not found"
c = c.replace(target4, repl4, 1)

p.write_text(c, encoding="utf-8")
print("Successfully patched ps2_runtime.cpp")
