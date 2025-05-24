#include "bitty_instruction_generator.h"

uint16_t BittyInstructionGenerator::Generate()
{
    uint16_t instruction = 0x0000;
    // Generate random values for the specified fields
    uint16_t first_operand = rand() % 8; // 3 bits (0-7)
    uint16_t alu_select = rand() % 8;    // 3 bits (0-7)
    uint16_t mode = rand() % 3;          // 2 bits (0-3)

    // Construct the instruction following the format
    if (mode == 0b10)
    {
        int8_t branch_offset = std::rand() % 256 - 128;
        uint8_t branch_cond = std::rand() % 3; // 0, 1, or 2

        instruction = instruction | ((branch_offset & 0xFF) << 4) | (branch_cond << 2) | mode;
    }
    else
    {
        instruction = (mode % 4) == 1 ? ((first_operand << 13) |
                                         (rand() % 256 << 5) |
                                         (alu_select << 2) | mode)
                                      : ((first_operand << 13) |
                                         (rand() % 8 << 10) |
                                         (alu_select << 2) | mode);
    }

    return instruction;
}

#ifdef MAIN

int main(int argc, char *argv[])
{
    srand(time(nullptr));
    BittyInstructionGenerator generator;

    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <N>\n"
                  << "  <N>  number of instructions to generate\n";
        return 1;
    }
    int N;
    try
    {
        N = std::stoi(argv[1]);
        if (N <= 0)
            throw std::invalid_argument("non-positive");
    }
    catch (...)
    {
        std::cerr << "Error: <N> must be a positive integer.\n";
        return 1;
    }

    const std::string out_filename = "instructions.hex";
    std::ofstream out(out_filename);
    if (!out)
    {
        std::cerr << "Error: cannot open output file '" << out_filename << "' for writing.\n";
        return 2;
    }

    for (int i = 0; i < N; i++)
    {
        uint16_t instruction = generator.Generate();
        out << std::hex
            << std::setw(4)
            << std::setfill('0')
            << instruction
            << '\n';
    }
    out.close();
    std::cout << "Generated " << N << " instructions in '"
              << out_filename << "'.\n";
    return 0;
}

#endif