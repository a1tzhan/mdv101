#include "Valu.h"
#include "verilated.h"
#include <iostream>
#include <random>
#include <bitset>

void compute_arithmetic(uint16_t a, uint16_t b, uint8_t sel,
                        uint16_t &ar_out);

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Valu *tb = new Valu;

    // Initialize random number generators
    std::mt19937 gen(42); // Seed for reproducibility
    std::uniform_int_distribution<uint32_t> dist(0, 0xFFFF);
    std::bernoulli_distribution bdist(0.5);

    int errors = 0;
    const int NUM_TESTS = 1000;

    // Test all modes and operations
    for (int sel = 0; sel < 8; sel++)
    {
        for (int i = 0; i < NUM_TESTS; i++)
        {
            // Generate random inputs
            uint16_t a = dist(gen);
            uint16_t b = dist(gen);
            uint8_t cin = bdist(gen);

            // Apply inputs to DUT
            tb->in_a = a;
            tb->in_b = b;
            tb->select = sel;

            // Evaluate design
            tb->eval();

            // Compute expected values
            uint16_t exp_ar_out, exp_lo_out, exp_alu_out;
            compute_arithmetic(a, b, sel, exp_ar_out);
            exp_alu_out = exp_ar_out;

            // Check results
            bool error = false;
            if (tb->alu_out != exp_alu_out)
            {
                std::cerr << "ERROR: Sel=" << std::bitset<3>(sel)
                          << " a=" << std::hex << a << " b=" << b
                          << "\n  ALU_OUT: Exp=" << exp_alu_out
                          << " Got=" << tb->alu_out << std::endl;
                error = true;
            }
            if (error)
                errors++;
        }
    }
    std::cout << "\nALU tests complete. Errors: " << errors << std::endl;
    tb->final();
    delete tb;
    return errors ? 1 : 0;
}

void compute_arithmetic(uint16_t a, uint16_t b, uint8_t sel,
                        uint16_t &ar_out)
{
    uint32_t temp;
    switch (sel)
    {
    case 0x0:
        temp = a + b;
        break;
    case 0x1:
        temp = a - b;
        break;
    case 0x2:
        temp = a & b;
        break;
    case 0x3:
        temp = a | b;
        break;
    case 0x4:
        temp = a ^ b;
        break;
    case 0x5:
        temp = a << b % 16;
        break;
    case 0x6:
        temp = a >> b % 16;
        break;
    case 0x7:
        if (a == b)
            temp = 0;
        else if (a > b)
            temp = 1;
        else
            temp = 2;
        break;
    default:
        temp = 0;
        break;
    }
    ar_out = temp & 0xFFFF;
}