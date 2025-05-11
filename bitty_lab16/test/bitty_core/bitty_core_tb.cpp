#include "Vbitty_core.h"
#include "verilated.h"

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

void compute_instruction(uint16_t a, uint16_t b, uint8_t sel,
                         uint16_t &ar_out);

uint16_t gen_inst()
{
    // Generate random values for the specified fields
    uint16_t first_operand = rand() % 8;  // 3 bits (0-7)
    uint16_t second_operand = rand() % 8; // 3 bits (0-7)
    uint16_t alu_select = rand() % 8;     // 3 bits (0-7)
    uint16_t mode = rand() % 3;           // 2 bits (0-3)

    // Construct the instruction following the format
    uint16_t instruction = (first_operand << 13) |
                           (second_operand << 10) |
                           (alu_select << 2) | mode;
    return instruction;
}

void test_inst(Vbitty_core *tb, uint16_t instruction, uint16_t expected_result, int &errors, uint16_t regs[])
{
    tb->instruction = instruction;
    tb->run = 1;
    while (!tb->done)
    {
        tick(tb);
    }
    tick(tb);
    uint16_t actual_result = get_register(tb, ((instruction >> 13) & 0x7));

    if (actual_result != expected_result)
    {
        std::cerr << "Error: Expected 0x" << std::hex << expected_result
                  << ", but got 0x" << actual_result << std::dec << std::endl;
        errors++;
    }
    else
    {
        // std::cout << "Correct: Expected 0x" << std::hex << expected_result << ", got 0x" << actual_result << std::dec << std::endl;
    }

    tb->run = 0;
    tick(tb);
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vbitty_core *tb = new Vbitty_core;

    std::mt19937 gen(42); // Seed for reproducibility
    std::uniform_int_distribution<uint32_t> dist(0, 0xFFFF);
    std::bernoulli_distribution bdist(0.5);
    srand(time(0));

    int errors = 0;
    const int NUM_TESTS = 1000;
    uint16_t regs[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    reset(tb);

    // Set all registers and test all ALU operations on them. Do it 1000 times.
    // I have to  check that outputs are correct in the correct register but restore the register value afterwards.
    for (int i = 0; i < NUM_TESTS; i++)
    {
        // Generate instruction
        uint16_t instruction = gen_inst();
        uint16_t a = regs[(instruction >> 13) & 0x7];
        uint16_t b;
        int imm = 0;
        if ((instruction % 4) == 1)
            b = (instruction >> 5) & 0xFF;
        else
            b = regs[(instruction >> 10) & 0x7];
        // Calculate expected value
        uint16_t exp_ar_out;
        compute_instruction(a, b, ((instruction >> 2) & 0x7), exp_ar_out);
        regs[(instruction >> 13) & 0x7] = exp_ar_out;
        std::bitset<16> x(instruction);
        std::cout
            << "Instruction is: " << x << std::dec << std::endl;
        std::cout << "Executing: A=" << a << ", B=" << b << ", ALU Sel="
                  << ((instruction >> 2) & 0x7) << std::endl;

        // Test instruction on inputs
        test_inst(tb, instruction, exp_ar_out, errors, regs);
        std::cout << tb->reg_0 << "   " << tb->reg_1 << "   " << tb->reg_2 << "   " << tb->reg_3 << "   " << tb->reg_4 << "   " << tb->reg_5 << "   " << tb->reg_6 << "   " << tb->reg_7 << std::endl;
        std::cout << regs[0] << "   " << regs[1] << "   " << regs[2] << "   " << regs[3] << "   " << regs[4] << "   " << regs[5] << "   " << regs[6] << "   " << regs[7] << std::endl;
    }

    std::cout << "\nBitty_core tests complete. Errors: " << errors << std::endl;
    tb->final();
    delete tb;
    return errors ? 1 : 0;
}

void compute_instruction(uint16_t a, uint16_t b, uint8_t sel,
                         uint16_t &ar_out)
{
    switch (sel)
    {
    case 0x0:
        ar_out = a + b;
        break;
    case 0x1:
        ar_out = a - b;
        break;
    case 0x2:
        ar_out = a & b;
        break;
    case 0x3:
        ar_out = a | b;
        break;
    case 0x4:
        ar_out = a ^ b;
        break;
    case 0x5:
        ar_out = a << b % 16;
        break;
    case 0x6:
        ar_out = a >> b % 16;
        break;
    case 0x7:
        if (a == b)
            ar_out = 0;
        else if (a > b)
            ar_out = 1;
        else
            ar_out = 2;
        break;
    default:
        ar_out = 0;
        break;
    }
}