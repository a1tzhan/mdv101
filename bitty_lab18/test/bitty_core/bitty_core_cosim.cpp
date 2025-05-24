#include "Vbitty_core.h"
#include "verilated.h"
#include "../../emulator/bitty_emu.h"

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <random>
#include <bitset>
#include <ctime>

void tick(Vbitty_core *tb)
{
    tb->clk = 0;
    tb->eval();
    tb->clk = 1;
    tb->eval();
}

void reset(Vbitty_core *tb)
{
    tb->reset = 1;
    tick(tb);
    tick(tb);
    tb->reset = 0;
    tb->run = 0;
}

uint16_t get_register(Vbitty_core *tb, int index)
{
    switch (index)
    {
    case 0:
        return tb->reg_0;
    case 1:
        return tb->reg_1;
    case 2:
        return tb->reg_2;
    case 3:
        return tb->reg_3;
    case 4:
        return tb->reg_4;
    case 5:
        return tb->reg_5;
    case 6:
        return tb->reg_6;
    case 7:
        return tb->reg_7;
    default:
        assert(false && "Invalid register index!");
        return 0;
    }
}

uint16_t gen_inst()
{
    // Generate random values for the specified fields
    uint16_t first_operand = rand() % 8; // 3 bits (0-7)
    uint16_t alu_select = rand() % 8;    // 3 bits (0-7)
    uint16_t mode = rand() % 3;          // 2 bits (0-3)

    // Construct the instruction following the format
    uint16_t instruction = (mode % 4) == 1 ? ((first_operand << 13) |
                                              (rand() % 256 << 5) |
                                              (alu_select << 2) | mode)
                                           : ((first_operand << 13) |
                                              (rand() % 8 << 10) |
                                              (alu_select << 2) | mode);
    return instruction;
}

void test_inst(Vbitty_core *tb, uint16_t instruction, int &errors, BittyEmulator *emulator)
{
    tb->instruction = instruction;
    tb->run = 1;
    while (!tb->done)
    {
        tick(tb);
    }
    tick(tb);
    uint16_t expected_value = emulator->Evaluate(instruction);
    uint16_t actual_result = get_register(tb, ((instruction >> 13) & 0x7));

    if (actual_result != expected_value)
    {
        std::cerr << "Error: Expected 0x" << std::hex << expected_value
                  << ", but got 0x" << actual_result << std::dec << std::endl;
        errors++;
    }
    assert(tb->reg_0 == emulator->GetRegisterValue(0));
    assert(tb->reg_1 == emulator->GetRegisterValue(1));
    assert(tb->reg_2 == emulator->GetRegisterValue(2));
    assert(tb->reg_3 == emulator->GetRegisterValue(3));
    assert(tb->reg_4 == emulator->GetRegisterValue(4));
    assert(tb->reg_5 == emulator->GetRegisterValue(5));
    assert(tb->reg_6 == emulator->GetRegisterValue(6));
    assert(tb->reg_7 == emulator->GetRegisterValue(7));
    tb->run = 0;
    tick(tb);
}

int main(int argc, char **argv)
{
    BittyEmulator emulator;
    Verilated::commandArgs(argc, argv);
    Vbitty_core *tb = new Vbitty_core;

    srand(time(0));

    int errors = 0;
    const int NUM_TESTS = 1000;

    reset(tb);
    for (int i = 0; i < NUM_TESTS; i++)
    {
        // Generate instruction
        uint16_t instruction = gen_inst();
        std::bitset<16> x(instruction);
        std::cout << "Instruction is: " << x << std::dec << std::endl;
        // Test instruction on inputs
        test_inst(tb, instruction, errors, &emulator);
        std::cout << tb->reg_0 << "   " << tb->reg_1 << "   " << tb->reg_2 << "   " << tb->reg_3 << "   " << tb->reg_4 << "   " << tb->reg_5 << "   " << tb->reg_6 << "   " << tb->reg_7 << std::endl;
        std::cout << emulator.GetRegisterValue(0) << "   " << emulator.GetRegisterValue(1) << "   " << emulator.GetRegisterValue(2) << "   " << emulator.GetRegisterValue(3) << "   " << emulator.GetRegisterValue(4) << "   " << emulator.GetRegisterValue(5) << "   " << emulator.GetRegisterValue(6) << "   " << emulator.GetRegisterValue(7) << std::endl;
    }

    std::cout << "\nBitty_core tests complete. Errors: " << errors << std::endl;
    tb->final();
    delete tb;
    return errors ? 1 : 0;
}