#include "Vbranch_logic.h"
#include "verilated.h"
#include <iostream>
// to do
int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vbranch_logic *tb = new Vbranch_logic;
    uint16_t instruction[255];

    int i = 0;
    int pc = 0;
    for (int j = 0; j < 255; j++)
    {
        tb->done = 1;

        if (tb->new_pc != instruction)
        {
            std::cout << "MISMATCH\n";
        }
        tb->done = 0;
    }

    std::cout << "\n branch_logic tests complete. No Errors in branch_logic" << std::endl;
    in.close();
    tb->final();
    delete tb;
    return 0;
}
