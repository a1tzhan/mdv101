#include "Vtop_module.h"
#include "verilated.h"
#include <iostream>
#include <random>
#include <bitset>

void compute_arithmetic(uint16_t a, uint16_t b, uint8_t cin, uint8_t sel,
                        uint16_t &ar_out, uint8_t &cout, uint8_t &cmp);
uint16_t compute_logic(uint16_t a, uint16_t b, uint8_t sel);

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vtop_module *tb = new Vtop_module;

    // Initialize random number generators
    std::mt19937 gen(42); // Seed for reproducibility
    std::uniform_int_distribution<uint32_t> dist(0, 0xFFFF);
    std::bernoulli_distribution bdist(0.5);

    int errors = 0;
    const int NUM_TESTS = 1000;

    // Test all modes and operations
    for (int mode = 0; mode <= 1; mode++)
    {
        for (int sel = 0; sel < 16; sel++)
        {
            for (int i = 0; i < NUM_TESTS; i++)
            {
                // Generate random inputs
                uint16_t a = dist(gen);
                uint16_t b = dist(gen);
                uint8_t cin = bdist(gen);

                // Apply inputs to DUT
                tb->carry_in = cin;
                tb->in_a = a;
                tb->in_b = b;
                tb->select = sel;
                tb->mode = mode;

                // Evaluate design
                tb->eval();

                // Compute expected values
                uint16_t exp_ar_out, exp_lo_out, exp_alu_out;
                uint8_t exp_cout, exp_cmp;
                compute_arithmetic(a, b, cin, sel, exp_ar_out, exp_cout, exp_cmp);
                exp_lo_out = compute_logic(a, b, sel);
                exp_alu_out = mode ? exp_lo_out : exp_ar_out;

                // Check results
                bool error = false;
                if (tb->alu_out != exp_alu_out)
                {
                    std::cerr << "ERROR: Mode=" << mode << " Sel=" << std::bitset<4>(sel)
                              << " a=" << std::hex << a << " b=" << b << " cin=" << (int)cin
                              << "\n  ALU_OUT: Exp=" << exp_alu_out
                              << " Got=" << tb->alu_out << std::endl;
                    error = true;
                }
                if (tb->cout != exp_cout)
                {
                    std::cerr << "ERROR: Mode=" << mode << " Sel=" << std::bitset<4>(sel)
                              << " a=" << std::hex << a << " b=" << b << " cin=" << (int)cin
                              << "\n  COUT: Exp=" << (int)exp_cout
                              << " Got=" << (int)tb->cout << std::endl;
                    error = true;
                }
                if (tb->compare != exp_cmp)
                {
                    std::cerr << "ERROR: Mode=" << mode << " Sel=" << std::bitset<4>(sel)
                              << " a=" << std::hex << a << " b=" << b << " cin=" << (int)cin
                              << "\n  COMPARE: Exp=" << (int)exp_cmp
                              << " Got=" << (int)tb->compare << std::endl;
                    error = true;
                }

                if (error)
                    errors++;
            }
        }
    }

    std::cout << "\nTest complete. Errors: " << errors << std::endl;
    tb->final();
    delete tb;
    return errors ? 1 : 0;
}

void compute_arithmetic(uint16_t a, uint16_t b, uint8_t cin, uint8_t sel,
                        uint16_t &ar_out, uint8_t &cout, uint8_t &cmp)
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
        temp = (a | b) + (a & ~b) + cin;
        break;
    case 0x6:
        temp = a - b - 1 - cin;
        break;
    case 0x7:
        temp = (a & ~b) - 1 - cin;
        break;
    case 0x8:
        temp = a + (a & b) + cin;
        break;
    case 0x9:
        temp = a + b + cin;
        break;
    case 0xA: // (A | ~B) + (A & B) + CIN (17-bit add)
        temp = (uint32_t)(a | b_not) +
               (uint32_t)(a & b) +
               cin;
        break;
    case 0xB:
        temp = (a & b) - 1 - cin;
        break;
    case 0xC:
        temp = a + a + cin;
        break;
    case 0xD:
        temp = (a | b) + a + cin;
        break;
    case 0xE: // (A | ~B) + A + CIN (17-bit add)
        temp = (uint32_t)(a | b_not) +
               (uint32_t)a +
               cin;
        break;
    case 0xF:
        temp = a - 1 - cin;
        break;
    default:
        temp = 0;
    }

    // Handle 17-bit arithmetic
    cout = (temp > 0xFFFF) ? 1 : 0;
    ar_out = temp & 0xFFFF;
    cmp = (a == b);
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