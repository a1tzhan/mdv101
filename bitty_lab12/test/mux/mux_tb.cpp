#include "Vmux.h"
#include "verilated.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <bitset>
#include <ctime>

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vmux *tb = new Vmux;

    std::mt19937 gen(42); // Seed for reproducibility
    std::uniform_int_distribution<uint32_t> dist(0, 0xFFFF);
    std::bernoulli_distribution bdist(0.5);
    srand(time(0));

    uint16_t regs[8];

    uint16_t out;
    int errors = 0;
    const int NUM_TESTS = 1000;

    for (int j = 0; j < NUM_TESTS; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            regs[i] = dist(gen);
        }
        tb->reg_0 = regs[0];
        tb->reg_1 = regs[1];
        tb->reg_2 = regs[2];
        tb->reg_3 = regs[3];
        tb->reg_4 = regs[4];
        tb->reg_5 = regs[5];
        tb->reg_6 = regs[6];
        tb->reg_7 = regs[7];
        uint8_t sel = rand() % 8;
        tb->sel = sel;
        tb->eval();
        if (regs[sel] != tb->out)
        {
            errors++;
            std::cout << "Error, expected 0x" << std::hex << regs[sel] << ", but got 0x" << tb->out << std::dec << std::endl;
        }
    }

    std::cout << "\nMux tests complete. Errors: " << errors << std::endl;
    tb->final();
    delete tb;
    return errors ? 1 : 0;
}
