#include <iostream>
#include <cstdlib>
#include <random>
#include <bitset>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>

class BittyInstructionGenerator
{
public:
    BittyInstructionGenerator() = default;
    uint16_t Generate();
};