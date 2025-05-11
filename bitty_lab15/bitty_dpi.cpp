#include "emulator/bitty_emu.h"
#include "svdpi.h"
#include <iostream>

extern "C" void test_instruction(svBitVecVal *instruction,
                                 svBitVecVal *reg0, svBitVecVal *reg1, svBitVecVal *reg2, svBitVecVal *reg3,
                                 svBitVecVal *reg4, svBitVecVal *reg5, svBitVecVal *reg6, svBitVecVal *reg7)
{
    static BittyEmulator emulator;

    emulator.Evaluate(static_cast<uint16_t>(instruction[0] & 0xFFFF));

    uint16_t registers[8] = {reg0[0], reg1[0], reg2[0], reg3[0], reg4[0], reg5[0], reg6[0], reg7[0]};

    for (int i = 0; i < 8; i++)
    {
        if (emulator.GetRegisterValue(i) != registers[i])
        {
            std::cout << "Mismatch! ";
            std::cout << reg0[0] << "   " << reg1[0] << "   " << reg2[0] << "   " << reg3[0] << "   " << reg4[0] << "   " << reg5[0] << "   " << reg6[0] << "   " << reg7[0] << std::endl;
            std::cout << emulator.GetRegisterValue(0) << "   " << emulator.GetRegisterValue(1) << "   " << emulator.GetRegisterValue(2) << "   " << emulator.GetRegisterValue(3) << "   " << emulator.GetRegisterValue(4) << "   " << emulator.GetRegisterValue(5) << "   " << emulator.GetRegisterValue(6) << "   " << emulator.GetRegisterValue(7) << std::endl;
        }
    }
}
