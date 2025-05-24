#include "Vtop_module.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
#include "../../generator/bitty_instruction_generator.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

vluint64_t main_time = 0;

void tick(Vtop_module *tb, VerilatedVcdC *tfp)
{
    tb->clk = 0;
    tb->eval();
    tfp->dump(main_time++);

    tb->clk = 1;
    tb->eval();
    tfp->dump(main_time++);
}

int main(int argc, char **argv)
{
    BittyInstructionGenerator generator;

    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vtop_module *tb = new Vtop_module;
    VerilatedVcdC *tfp = new VerilatedVcdC;

    tb->trace(tfp, 99);
    tfp->open("dump.vcd");

    std::srand(std::time(nullptr));
    int n = 255;
    int tests = 0;
    std::string generate = "./generate_inst " + std::to_string(n);
    int result = system(generate.c_str());
    if (result != 0)
    {
        std::cerr << "Failed to run instruction generator\n";
        return 1;
    }

    tb->clk = 0;
    tb->reset = 1;
    tb->run = 0;

    for (int i = 0; i < 6; i++)
    {
        tick(tb, tfp);
    }

    tb->reset = 0;
    tb->run = 1;
    int pc = 0;
    int max_pc = 1000;

    while (pc < max_pc)
    {
        for (int i = 0; i < 5; i++)
        {
            tick(tb, tfp);
        }
        pc++;
        tests++;
    }

    std::cout << "\nTop_module tests complete. Tests ran: " << tests << std::endl;
    tb->final();
    tfp->close();
    delete tb;
    return 0;
}