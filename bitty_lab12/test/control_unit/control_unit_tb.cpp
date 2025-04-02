#include "Vcontrol_unit.h"
#include <verilated.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <bitset>

void clock(Vcontrol_unit *tb)
{
    tb->clk = 0;
    tb->eval();
    tb->clk = 1;
    tb->eval();
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vcontrol_unit *tb = new Vcontrol_unit;

    // Initialize random number generators
    std::mt19937 gen(42); // Seed for reproducibility
    std::uniform_int_distribution<uint32_t> dist(0, 0xFFFF);
    std::bernoulli_distribution bdist(0.5);

    int errors = 0;
    const int NUM_TESTS = 100;

    for (int i = 0; i < NUM_TESTS; i++)
    {
        uint16_t instruction = dist(gen);
        uint8_t inst_a = (instruction >> 13) & 0x7;
        uint8_t inst_b = (instruction >> 10) & 0x7;
        uint8_t alu_sel = (instruction >> 2) & 0x7;

        tb->reset = 1;
        tb->run = 0;
        tb->instruction = instruction;
        clock(tb);

        tb->reset = 0;
        clock(tb);
        if (tb->en_0 || tb->en_1 || tb->en_2 || tb->en_3 || tb->en_4 || tb->en_5 || tb->en_6 || tb->en_7 || tb->en_i || tb->en_c || tb->en_s || tb->done)
        {
            errors++;
            std::cout << "En's after reset are not 0" << std::endl;
        }

        tb->run = 1;
        tb->eval(); // should be in S0

        if (tb->en_i == 0)
        {
            errors++;
            std::cout << "en_i is not 1 in S0" << std::endl;
        }

        clock(tb); // should be in S1

        if (tb->en_s == 0)
        {
            errors++;
            std::cout << "en_s is not 1 in S1" << std::endl;
        }
        if (tb->mux_sel != inst_a)
        {
            errors++;
            std::cout << "mux_sel is not instruction[15:13]" << std::endl;
        }

        clock(tb);

        if (tb->en_c == 0)
        {
            errors++;
            std::cout << "en_c is not 1 in S2" << std::endl;
        }
        if (tb->mux_sel != inst_b)
        {
            errors++;
            std::cout << "mux_sel is not instruction[12:10]" << std::endl;
        }
        if (tb->alu_sel != alu_sel)
        {
            errors++;
            std::cout << "alu_sel is not instruction[6:4]" << std::endl;
        }

        clock(tb); // now in S3

        if (tb->done == 0)
        {
            errors++;
            std::cout << "done is not 1 in S3" << std::endl;
        }
        switch (inst_a)
        {
        case 1:
            if (!tb->en_1)
            {
                errors++;
                std::cout << "Incorrect en_ to save" << std::endl;
            }
            break;
        case 2:
            if (!tb->en_2)
            {
                errors++;
                std::cout << "Incorrect en_ to save" << std::endl;
            }
            break;
        case 3:
            if (!tb->en_3)
            {
                errors++;
                std::cout << "Incorrect en_ to save" << std::endl;
            }
            break;
        case 4:
            if (!tb->en_4)
            {
                errors++;
                std::cout << "Incorrect en_ to save" << std::endl;
            }
            break;
        case 5:
            if (!tb->en_5)
            {
                errors++;
                std::cout << "Incorrect en_ to save" << std::endl;
            }
            break;
        case 6:
            if (!tb->en_6)
            {
                errors++;
                std::cout << "Incorrect en_ to save" << std::endl;
            }
            break;
        case 7:
            if (!tb->en_7)
            {
                errors++;
                std::cout << "Incorrect en_ to save" << std::endl;
            }
            break;
        }
        clock(tb); // now in state S0 again

        if (tb->en_i == 0)
        {
            errors++;
            std::cout << "en_i is not 1 in S0" << std::endl;
        }
    }

    std::cout << "Control unit tests complete. Errors:" << errors << std::endl;
    delete tb;
    return 0;
}
