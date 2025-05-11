#include <iostream>
#include <cstdlib>
#include <random>
#include <bitset>
#include <ctime>

class BittyInstructionGenerator
{
public:
    BittyInstructionGenerator() = default;
    uint16_t Generate();
};