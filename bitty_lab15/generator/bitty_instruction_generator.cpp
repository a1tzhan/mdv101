#include "bitty_instruction_generator.h"

uint16_t BittyInstructionGenerator::Generate()
{
    // Generate random values for the specified fields
    uint16_t first_operand = rand() % 8; // 3 bits (0-7)
    uint16_t alu_select = rand() % 8;    // 3 bits (0-7)
    uint16_t mode = rand() % 3;          // 2 bits (0-3)

    // Construct the instruction following the format
    uint16_t instruction = (mode % 4) == 1 ? ((first_operand << 13) |
                                              (rand() % 256 << 5) |
                                              (alu_select << 2) | mode)
                                           : ((first_operand << 13) |
                                              (rand() % 8 << 10) |
                                              (alu_select << 2) | mode);
    return instruction;
}