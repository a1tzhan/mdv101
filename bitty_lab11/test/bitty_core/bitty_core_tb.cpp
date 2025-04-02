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

void compute_arithmetic(uint16_t a, uint16_t b, uint8_t sel,
                        uint16_t &ar_out);
uint16_t compute_logic(uint16_t a, uint16_t b, uint8_t sel);

uint16_t mux_sel(uint16_t index, uint16_t reg_00, uint16_t reg_01, uint16_t reg_02, uint16_t reg_03, uint16_t reg_04, uint16_t reg_05, uint16_t reg_06, uint16_t reg_07)
{
    switch (index)
    {
    case 0:
        return reg_00;
    case 1:
        return reg_01;
    case 2:
        return reg_02;
    case 3:
        return reg_03;
    case 4:
        return reg_04;
    case 5:
        return reg_05;
    case 6:
        return reg_06;
    case 7:
        return reg_07;
    default:
        return 0;
    }
}

uint16_t gen_inst()
{
    // Generate random values for the specified fields
    uint16_t first_operand = rand() % 8;  // 3 bits (0-7)
    uint16_t second_operand = rand() % 8; // 3 bits (0-7)
    uint16_t alu_select = rand() % 16;    // 4 bits (0-15)
    uint16_t alu_mode = rand() % 2;       // 1 bit  (0-1)

    // Construct the instruction following the format
    uint16_t instruction = (first_operand << 13) |
                           (second_operand << 10) |
                           (alu_select << 3) |
                           (alu_mode << 2);

    return instruction;
}

void test_inst(Vbitty_core *tb, uint16_t instruction, uint16_t expected_result, int &errors)
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

    reset(tb);

    // Set all registers and test all ALU operations on them. Do it 1000 times.
    // I have to  check that outputs are correct in the correct register but restore the register value afterwards.
    for (int i = 0; i < NUM_TESTS; i++)
    {
        // Generate random inputs
        uint16_t reg_00 = dist(gen);
        uint16_t reg_01 = dist(gen);
        uint16_t reg_02 = dist(gen);
        uint16_t reg_03 = dist(gen);
        uint16_t reg_04 = dist(gen);
        uint16_t reg_05 = dist(gen);
        uint16_t reg_06 = dist(gen);
        uint16_t reg_07 = dist(gen);

        // Apply inputs
        tb->reg_00 = reg_00;
        tb->reg_01 = reg_01;
        tb->reg_02 = reg_02;
        tb->reg_03 = reg_03;
        tb->reg_04 = reg_04;
        tb->reg_05 = reg_05;
        tb->reg_06 = reg_06;
        tb->reg_07 = reg_07;

        // Generate instruction
        uint16_t instruction = gen_inst();
        uint16_t a = mux_sel((instruction >> 13) & 0x7, reg_00, reg_01, reg_02, reg_03, reg_04, reg_05, reg_06, reg_07);
        uint16_t b = mux_sel((instruction >> 10) & 0x7, reg_00, reg_01, reg_02, reg_03, reg_04, reg_05, reg_06, reg_07);
        // Calculate expected value
        uint16_t exp_ar_out, exp_lo_out, exp_alu_out;
        compute_arithmetic(a, b, ((instruction >> 3) & 0xF), exp_ar_out);
        exp_lo_out = compute_logic(a, b, ((instruction >> 3) & 0xF));
        exp_alu_out = ((instruction >> 2) & 0x1) ? exp_lo_out : exp_ar_out;
        std::cout << "Instruction is: " << std::hex << instruction << std::endl;
        std::cout << "Executing: A=" << a << ", B=" << b << ", ALU Sel="
                  << ((instruction >> 3) & 0xF) << ", Mode="
                  << ((instruction >> 2) & 0x1) << std::endl;

        // Test instruction on inputs
        test_inst(tb, instruction, exp_alu_out, errors);
        // std::cout << tb->reg_0 << "   " << tb->reg_1 << "   " << tb->reg_2 << "   " << tb->reg_3 << "   " << tb->reg_4 << "   " << tb->reg_5 << "   " << tb->reg_6 << "   " << tb->reg_7 << std::endl;
    }

    std::cout << "\nBitty_core tests complete. Errors: " << errors << std::endl;
    tb->final();
    delete tb;
    return errors ? 1 : 0;
}

void compute_arithmetic(uint16_t a, uint16_t b, uint8_t sel,
                        uint16_t &ar_out)
{
    uint32_t temp;
    uint16_t b_not = ~b & 0xFFFF;
    switch (sel)
    {
    case 0x0:
        temp = a;
        break;
    case 0x1:
        temp = (a | b);
        break;
    case 0x2: // A | ~B (16-bit exact)
        temp = (a | b_not);
        temp &= 0xFFFF; // Force 16-bit result
        break;
    case 0x3:
        temp = 0xFFFF;
        break;
    case 0x4:
        temp = a | (a & ~b);
        break;
    case 0x5:
        temp = (a | b) + (a & ~b);
        break;
    case 0x6:
        temp = a - b - 1;
        break;
    case 0x7:
        temp = (a & ~b) - 1;
        break;
    case 0x8:
        temp = a + (a & b);
        break;
    case 0x9:
        temp = a + b;
        break;
    case 0xA: // (A | ~B) + (A & B)(17-bit add)
        temp = (uint32_t)(a | b_not) +
               (uint32_t)(a & b);
        break;
    case 0xB:
        temp = (a & b) - 1;
        break;
    case 0xC:
        temp = a + a;
        break;
    case 0xD:
        temp = (a | b) + a;
        break;
    case 0xE: // (A | ~B) + A(17-bit add)
        temp = (uint32_t)(a | b_not) +
               (uint32_t)a;
        break;
    case 0xF:
        temp = a - 1;
        break;
    default:
        temp = 0;
    }

    // Handle 17-bit arithmetic
    ar_out = temp & 0xFFFF;
}

uint16_t compute_logic(uint16_t a, uint16_t b, uint8_t sel)
{
    switch (sel)
    {
    case 0x0:
        return ~a;
    case 0x1:
        return ~(a | b);
    case 0x2:
        return (~a) & b;
    case 0x3:
        return 0;
    case 0x4:
        return ~(a & b);
    case 0x5:
        return ~b;
    case 0x6:
        return a ^ b;
    case 0x7:
        return a & ~b;
    case 0x8:
        return ~a | b;
    case 0x9:
        return ~(a ^ b);
    case 0xA:
        return b;
    case 0xB:
        return a & b;
    case 0xC:
        return 0xFFFF;
    case 0xD:
        return a | ~b;
    case 0xE:
        return a | b;
    case 0xF:
        return a;
    default:
        return 0;
    }
}