#include "Vregister.h"
#include "verilated.h"
#include <iostream>

void reset(Vregister *tb)
{
    tb->reset = 1;
    tb->clk = 0;
    tb->eval();

    tb->clk = 1;
    tb->eval();

    tb->reset = 0;
    if (tb->d_out != 0 && tb->en != 0)
    {
        std::cout << "Reset failed";
    }
}

void test_input(Vregister *tb, uint16_t i)
{
    tb->clk = 0;
    tb->d_in = i;
    tb->eval();

    tb->clk = 1;
    tb->eval();
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vregister *tb = new Vregister;

    // test input with enable = 0
    tb->en = 0;
    tb->reset = 0;
    test_input(tb, 26);
    test_input(tb, 52);
    test_input(tb, 8);
    if (tb->d_out != 0)
    {
        std::cout << "Error accepts input with en = 0\n";
    }

    // test input with enable = 1
    tb->clk = 0;
    tb->en = 1;
    tb->eval();

    tb->clk = 1;
    tb->eval(); // setting enable = 1

    test_input(tb, 26);
    if (tb->d_out != 26)
    {
        std::cout << "Input is not working";
    }
    test_input(tb, 52);
    if (tb->d_out != 52)
    {
        std::cout << "Input is not working";
    }
    test_input(tb, 8);
    if (tb->d_out != 8)
    {
        std::cout << "Input is not working";
    }
    // testing reset
    reset(tb);
    // testing input with reset on
    tb->reset = 1;
    test_input(tb, 26);
    test_input(tb, 52);
    test_input(tb, 8);
    if (tb->d_out != 0)
    {
        std::cout << "Error accepts input with en = 0\n";
    }

    std::cout << "\n Register test complete. No Errors in register" << std::endl;
    tb->final();
    delete tb;
    return 0;
}
