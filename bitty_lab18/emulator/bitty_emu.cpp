#include "bitty_emu.h"

BittyEmulator::BittyEmulator() : registers_(8, 0), pc_(0), last_alu_result_(0), memory_(256, 0)
{
}

uint16_t BittyEmulator::Evaluate(uint16_t instruction)
{
    uint16_t a = registers_[(instruction >> 13) & 0x7];
    uint16_t b;

    if ((instruction % 4) == 1)
        b = (instruction >> 5) & 0xFF;
    else
        b = registers_[(instruction >> 10) & 0x7];

    uint16_t sel = ((instruction >> 2) & 0x7);
    uint16_t out;

    switch (sel)
    {
    case 0x0:
        out = a + b;
        break;
    case 0x1:
        out = a - b;
        break;
    case 0x2:
        out = a & b;
        break;
    case 0x3:
        out = a | b;
        break;
    case 0x4:
        out = a ^ b;
        break;
    case 0x5:
        out = a << b % 16;
        break;
    case 0x6:
        out = a >> b % 16;
        break;
    case 0x7:
        if (a == b)
            out = 0;
        else if (a > b)
            out = 1;
        else
            out = 2;
        break;
    default:
        out = 0;
        break;
    }
    registers_[(instruction >> 13) & 0x7] = out;
    last_alu_result_ = out;
    return out;
}

void BittyEmulator::EvaluateBranchInstr()
{

    uint16_t inst = memory_[pc_];
    std::cout << "Evaluating branch..." << std::hex << inst << std::dec << std::endl;
    if (inst % 4 != 2)
    {
        return;
    }

    pc_++;
    uint8_t branch_condition = (inst >> 2) & 0b11;
    if (branch_condition > 0b10)
    {
        return;
    }

    switch (branch_condition)
    {
    case 0b00:
        if (last_alu_result_ != 0)
            return;
        break;
    case 0b01:
        if (last_alu_result_ != 1)
            return;
        break;
    case 0b10:
        if (last_alu_result_ != 2)
            return;
        break;
    }

    uint8_t branch_jump_addr = (inst >> 4) & 0b11111111;
    pc_ = branch_jump_addr;
    std::cout << "Branch taken " << last_alu_result_ << " jumping to " << std::hex << memory_[pc_] << std::dec << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::hex << registers_[i] << std::dec << " ";
    }
    std::cout << std::endl;
    return;
}

bool BittyEmulator::LoadMemory(const std::string &filename, uint16_t start_address)
{
    std::ifstream in(filename);

    if (!in)
    {
        std::cerr << "Failed to open instruction file: " << filename << std::endl;
        return false;
    }

    std::string line;
    uint16_t address = start_address;

    while (std::getline(in, line))
    {
        uint16_t instruction = std::stoul(line, nullptr, 16);
        if (address > memory_.size())
            break;
        memory_[address++] = instruction;
    }

    pc_ = start_address;
    return true;
}

uint16_t BittyEmulator::Step()
{
    if (pc_ == memory_.size())
        pc_ = 0;
    uint8_t current_inst_format_type = memory_[pc_] & 0b11;
    while (current_inst_format_type == 0b10) // in case the instructions start from branch instruction
    {
        EvaluateBranchInstr(); // pc_ updated (incremented or jumped)
        current_inst_format_type = memory_[pc_] & 0b11;
    }
    uint16_t inst = memory_[pc_];
    Evaluate(inst);
    pc_ = pc_ + 1;

    uint8_t next_inst_format_type = memory_[pc_] & 0b11;
    while (next_inst_format_type == 0b10)
    {
        EvaluateBranchInstr(); // pc_ updated (incremented or jumped)
        next_inst_format_type = memory_[pc_] & 0b11;
    }
    return inst;
}

uint16_t BittyEmulator::GetRegisterValue(uint16_t reg_num)
{
    return registers_[reg_num];
}