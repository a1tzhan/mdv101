#include "Vmux.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vmux *tb = new Vmux;

    uint16_t out = 0;
    for (uint8_t sel = 0; sel < 8; sel++)
    {
        tb->sel = sel;
        tb->eval();
        switch (sel)
        {
        case 0:
            if (out != tb->out)
                std::cout << "Error Case 0";
            break;
        case 1:
            if (out != tb->out)
                std::cout << "Error Case 1";
            break;
        case 2:
            if (out != tb->out)
                std::cout << "Error Case 2";
            break;
        case 3:
            if (out != tb->out)
                std::cout << "Error Case 3";
            break;
        case 4:
            if (out != tb->out)
                std::cout << "Error Case 4";
            break;
        case 5:
            if (out != tb->out)
                std::cout << "Error Case 5";
            break;
        case 6:
            if (out != tb->out)
                std::cout << "Error Case 6";
            break;
        case 7:
            if (out != tb->out)
                std::cout << "Error Case 7";
            break;
        default:
            break;
        }
    }

    std::cout << " No errors found in Mux Tests\n";
    tb->final();
    delete tb;
    return 0;
}