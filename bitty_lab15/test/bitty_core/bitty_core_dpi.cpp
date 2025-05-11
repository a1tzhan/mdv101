#include "Vbitty_core.h"
#include "verilated.h"
#include "../../generator/bitty_instruction_generator.h"

#include <iostream>
#include <bitset>

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

int main(int argc, char **argv)
{
    BittyInstructionGenerator generator;
    Verilated::commandArgs(argc, argv);
    Vbitty_core *tb = new Vbitty_core;

    const int NUM_TESTS = 10000;

    reset(tb);

    for (int i = 0; i < NUM_TESTS; i++)
    {

        uint16_t instruction = generator.Generate();
        std::bitset<16> x(instruction);
        std::cout << "Instruction is: " << x << std::dec << std::endl;

        tb->instruction = instruction;
        tb->run = 1;
        while (!tb->done)
        {
            tick(tb);
        }
        tb->run = 0;
        tick(tb);
    }

    std::cout << "\nBitty_core tests complete." << std::endl;
    tb->final();
    delete tb;
    return 0;
}