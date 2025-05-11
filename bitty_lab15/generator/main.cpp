#include "bitty_instruction_generator.h"

int main()
{
    BittyInstructionGenerator generator;

    const int NUM_TESTS = 1000;
    for (int i = 0; i < NUM_TESTS; i++)
    {
        uint16_t instruction = generator.Generate();
        std::bitset<16> x(instruction);
        std::cout << "Instruction: " << x << std::endl;
    }
    return 0;
}