#include "Vtop_module.h"
#include "verilated.h"
#include "../../generator/bitty_instruction_generator.h"

#include <iostream>
#include <bitset>
#include <fstream>
#include <cstdlib>
#include <ctime>

void tick(Vtop_module *tb)
{
    tb->clk = 0;
    tb->eval();
    tb->clk = 1;
    tb->eval();
}

void reset(Vtop_module *tb)
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
    Vtop_module *tb = new Vtop_module;

    std::srand(std::time(nullptr));
    int n = rand() % 255;
    std::ifstream in("/mnt/c/Users/Professional/Desktop/mdv101/bitty_lab16/instructions.hex");
    std::string line;
    std::string generate = "./generate_inst " + std::to_string(n);
    int result = system(generate.c_str());
    int tests = 0;
    if (result != 0)
    {
        std::cerr << "Failed to run instruction generator\n";
        return 1;
    }

    if (!in)
    {
        std::cerr << "Error: cannot open 'instructions.hex' for reading.\n";
        return 1;
    }
    reset(tb);

    while (std::getline(in, line))
    {
        uint16_t instruction = std::stoul(line, nullptr, 16); // read hex
        std::bitset<16> x(instruction);
        std::cout << "Instruction is: " << x << std::dec << std::endl;
        tb->run = 1;
        for (int i = 0; i < 5; i++)
        {
            tick(tb);
        }
        tb->run = 0;
        tick(tb);
        tests++;
    }

    std::cout << "\nTop_module tests complete. Tests ran: " << tests << std::endl;
    in.close();
    tb->final();
    delete tb;
    return 0;
}