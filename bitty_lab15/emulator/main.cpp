#include "bitty_emu.h"

uint16_t gen_inst()
{
    // Generate random values for the specified fields
    uint16_t first_operand = rand() % 8;  // 3 bits (0-7)
    uint16_t second_operand = rand() % 8; // 3 bits (0-7)
    uint16_t alu_select = rand() % 8;     // 3 bits (0-7)
    uint16_t mode = rand() % 3;           // 2 bits (0-3)

    // Construct the instruction following the format
    uint16_t instruction = (first_operand << 13) |
                           (second_operand << 10) |
                           (alu_select << 2) | mode;
    return instruction;
}

int main()
{
    BittyEmulator emulator;

    std::mt19937 gen(42); // Seed for reproducibility
    std::uniform_int_distribution<uint32_t> dist(0, 0xFFFF);
    std::bernoulli_distribution bdist(0.5);
    srand(time(0));

    int errors = 0;
    const int NUM_TESTS = 1000;
    for (int i = 0; i < NUM_TESTS; i++)
    {
        uint16_t instruction = gen_inst();
        emulator.Evaluate(testInstruction);
        uint16_t regValue = emulator.GetRegisterValue(0);
    }

    uint16_t expected_value = 16;
    std::cout << "Register 0 value: " << regValue << std::endl;
    assert(regValue == expected_value);

    return 0;
}