#include "Vfetch_unit.h"
#include "verilated.h"
#include <iostream>
#include <fstream>

void tick(Vfetch_unit *tb)
{
    tb->clk = 0;
    tb->eval();
    tb->clk = 1;
    tb->eval();
}

void reset(Vfetch_unit *tb)
{
    tb->reset = 1;
    tick(tb);
    tick(tb);
    tb->reset = 0;
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vfetch_unit *tb = new Vfetch_unit;

    std::ifstream in("/mnt/c/Users/Professional/Desktop/mdv101/bitty_lab16/instructions.hex");
    std::string line;

    while (std::getline(in, line))
    {
        tb->done = 1;
        tick(tb);
        uint16_t instruction = std::stoul(line, nullptr, 16); // read hex
        std::cout << "Read instruction: 0x"
                  << std::hex << std::uppercase << instruction;
        std::cout << "  Equivalent from tb: " << tb->out << std::endl;
        if (tb->out != instruction)
        {
            std::cout << "MISMATCH\n";
        }
        tb->done = 0;
        tick(tb);
    }

    std::cout << "\n fetch_unit tests complete. No Errors in fetch_unit" << std::endl;
    in.close();
    tb->final();
    delete tb;
    return 0;
}
