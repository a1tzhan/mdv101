#include "bitty_emu.h"

int main()
{
    BittyEmulator emu;

    auto make_imm = [&](int dest, int sel, uint8_t bval)
    {
        // bits: [15-13]=dest, [12-5]=imm8, [4-2]=sel, [1-0]=01
        return uint16_t((dest & 7) << 13) | uint16_t(bval << 5) | uint16_t((sel & 7) << 2) | uint16_t(1);
    };
    auto make_reg = [&](int dest, int sel, int breg)
    {
        // bits: [15-13]=dest, [12-10]=breg, [4-2]=sel, [1-0]=00
        return uint16_t((dest & 7) << 13) | uint16_t((breg & 7) << 10) | uint16_t((sel & 7) << 2);
    };

    // 1) Test ADD (sel=0)
    emu.Evaluate(make_imm(1, 0, 15)); // R1 = R1(0) + 15;
    emu.Evaluate(make_imm(2, 0, 5));  // R2 = R2(0) + 5
    emu.Evaluate(make_imm(3, 0, 0));  // R3 = R3(0) + 0
    emu.Evaluate(make_reg(3, 0, 1));  // R3 = R3 + R1 = 15
    emu.Evaluate(make_reg(3, 0, 2));  // R3 = 15 + R2 = 20
    assert(emu.GetRegisterValue(3) == 20);

    // 2) Test SUB (sel=1)
    emu.Evaluate(make_imm(6, 0, 50)); // R6 = R6 + 50;
    emu.Evaluate(make_reg(6, 1, 3));  // R6 = R6(50) - R3(20) = 30;
    emu.Evaluate(make_imm(7, 1, 20)); // R7 = R7(0) - 20 = 0xFFEC
    assert(emu.GetRegisterValue(6) == uint8_t(30));
    assert(emu.GetRegisterValue(7) == 0xFFEC);

    // 3) Test AND (sel=2)
    emu.Evaluate(make_imm(0, 0, 0xF0)); // R0 = 0 + 0xF0
    emu.Evaluate(make_imm(0, 2, 0x2E)); // R0 = 0x2E & 0xF0
    emu.Evaluate(make_reg(6, 2, 7));    // R6 = 0x1E & 0xFFEC = 0xC
    assert(emu.GetRegisterValue(6) == 0xC);
    assert(emu.GetRegisterValue(0) == 0x20);

    // 4) Test OR (sel=3)
    emu.Evaluate(make_imm(4, 3, 0x0F)); // R4 = R4(0) | 0x0F
    emu.Evaluate(make_reg(5, 3, 4));    // R5 = R5(old=0) | R4(=0x0F) = 0x0F
    assert(emu.GetRegisterValue(5) == 0x0F);

    // 5) Test XOR (sel=4)
    emu.Evaluate(make_imm(7, 4, 0x55)); // R7 = R7(0xFFEC) ^ 0x55
    emu.Evaluate(make_reg(0, 4, 7));    // R0 = R0(0x20) ^ R7(=0xffb9) = 0x55
    assert(emu.GetRegisterValue(0) == 0xff99);

    // 6) Test SLL (sel=5)
    emu.Evaluate(make_imm(1, 5, 4)); // R1 = R1(15) << 4
    assert(emu.GetRegisterValue(1) == 0xF0);
    emu.Evaluate(make_reg(3, 5, 2)); // R3 = R3(20) << R2(5)
    assert(emu.GetRegisterValue(3) == 640);

    // 7) Test SRL (sel=6)
    emu.Evaluate(make_imm(4, 6, 4)); // R4 = 0x0F >> 4 = 0
    assert(emu.GetRegisterValue(4) == 0);
    emu.Evaluate(make_reg(6, 6, 5)); // R6 = R6(0xC) >> R5(0x0F)
    assert(emu.GetRegisterValue(6) == 0);

    // 8) Test CMP (sel=7)
    // Immediate: R7 = compare 10 vs 10 → 0
    emu.Evaluate(make_imm(6, 0, 16)); // R6 = 16
    emu.Evaluate(make_imm(6, 7, 16));
    assert(emu.GetRegisterValue(6) == 0);
    emu.Evaluate(make_reg(2, 7, 1)); // R2= cmp (R2(5) vs R1(0xF0))
    assert(emu.GetRegisterValue(2) == 2);
    emu.Evaluate(make_reg(1, 7, 2)); // R2= cmp (R2(5) vs R1(0xF0))
    assert(emu.GetRegisterValue(1) == 1);

    std::cout << "All tests passed successfully!\n";
    return 0;
}