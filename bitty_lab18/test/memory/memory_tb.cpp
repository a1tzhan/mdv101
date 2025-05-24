#include "Vmemory.h"
#include "verilated.h"
#include <iostream>
#include <fstream>

void tick(Vmemory *tb)
{
    tb->clk = 0;
    tb->eval();
    tb->clk = 1;
    tb->eval();
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vmemory *tb = new Vmemory;

    std::ifstream in("/mnt/c/Users/Professional/Desktop/mdv101/bitty_lab16/generator/instructions.hex");

    if (!in)
    {
        std::cerr << "Error: cannot open 'instructions.hex' for reading.\n";
        return 1;
    }

    std::string line;
    int i = 0;
    while (std::getline(in, line))
    {
        tb->addr = i;
        tick(tb);
        uint16_t instruction = std::stoul(line, nullptr, 16); // read hex
        std::cout << "Read instruction: 0x"
                  << std::hex << std::uppercase << instruction;
        std::cout << "  Equivalent from tb: " << tb->out << std::endl;
        if (tb->out != instruction)
        {
            std::cout << "MISMATCH\n";
        }
        i++;
    }

    std::cout << "\n Memory tests complete. No Errors in memory" << std::endl;
    in.close();
    tb->final();
    delete tb;
    return 0;
}
