#include "bitty_emu.h"

BittyEmulator::BittyEmulator() : registers_(8, 0)
{
}

uint16_t BittyEmulator::Evaluate(uint16_t instruction)
{
    uint16_t a = registers_[(instruction >> 13) & 0x7];
    uint16_t b;
    if ((instruction % 4) == 1)
        b = (instruction >> 5) & 0xFF;
    else
        b = registers_[(instruction >> 10) & 0x7];

    uint16_t sel = ((instruction >> 2) & 0x7);
    uint16_t out;

    switch (sel)
    {
    case 0x0:
        out = a + b;
        break;
    case 0x1:
        out = a - b;
        break;
    case 0x2:
        out = a & b;
        break;
    case 0x3:
        out = a | b;
        break;
    case 0x4:
        out = a ^ b;
        break;
    case 0x5:
        out = a << b % 16;
        break;
    case 0x6:
        out = a >> b % 16;
        break;
    case 0x7:
        if (a == b)
            out = 0;
        else if (a > b)
            out = 1;
        else
            out = 2;
        break;
    default:
        out = 0;
        break;
    }
    registers_[(instruction >> 13) & 0x7] = out;
    return out;
}

uint16_t BittyEmulator::GetRegisterValue(uint16_t reg_num)
{
    return registers_[reg_num];
}