#include "Vlock.h"
#include "verilated.h"
#include <iostream>
#include <cstdlib>
#include <cassert>

int next_state(int current, int in)
{
    int next;
    switch (current)
    {
    case 0:
        return (in == 3) ? current + 1 : 0;
    case 1:
        return (in == 3) ? current + 1 : 0;
    case 2:
        return (in == 5) ? current + 1 : 0;
    case 3:
        return (in == 2) ? current + 1 : 0;
    case 4:
        return (in == 5) ? current + 1 : 0;
    case 5:
        return (in == 6) ? current + 1 : 0;
    case 6:
        return 6;
    default:
        return 0;
    }
}

void reset(Vlock *tb, int &expected_state)
{
    tb->reset = 1;
    tb->clk = 0;
    tb->eval();

    tb->clk = 1;
    tb->eval();

    tb->reset = 0;
    expected_state = 0;
}

void test_input(Vlock *tb, int &expected_state, uint8_t i)
{
    tb->clk = 0;
    tb->in = i;
    tb->eval();

    tb->clk = 1;
    tb->eval();

    expected_state = next_state(expected_state, i);
    bool expected_locked = (expected_state != 6);
    assert(tb->locked == expected_locked);
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vlock *tb = new Vlock;
    int expected_state = 0;
    tb->reset = 0;
    int in[6] = {3, 3, 5, 2, 5, 6}; // state are 0, 1, 2, 3, 4, 5, 6 (0 is the initial and 6 is the final)
    // Test passing all the states
    for (int i = 0; i < 6; i++)
    {
        test_input(tb, expected_state, in[i]);
        std::cout << " Step " << i + 1
                  << " | Expected state: " << expected_state
                  << " | Locked: " << (int)tb->locked << "\n";
    }
    assert(expected_state == 6);

    // Test reset
    std::cout << "\nTesting reset during sequence\n";
    reset(tb, expected_state);
    test_input(tb, expected_state, 3); // State 1
    test_input(tb, expected_state, 3); // State 2
    reset(tb, expected_state);
    test_input(tb, expected_state, 3); // Should go to state 1
    assert(expected_state == 1);

    // Test 3: Incorrect digit at each position
    std::cout << "\nTesting each state transition to 0\n";
    reset(tb, expected_state);
    assert(expected_state == 0);
    test_input(tb, expected_state, 6); // State 0
    assert(expected_state == 0);
    test_input(tb, expected_state, 3); // State 1
    assert(expected_state == 1);
    test_input(tb, expected_state, 6); // State 0 again
    assert(expected_state == 0);

    test_input(tb, expected_state, 3); // State 1
    test_input(tb, expected_state, 3); // State 2
    test_input(tb, expected_state, 6); // State 0 again
    assert(expected_state == 0);

    test_input(tb, expected_state, 3); // State 1
    test_input(tb, expected_state, 3); // State 2
    test_input(tb, expected_state, 5); // State 3
    assert(expected_state == 3);
    test_input(tb, expected_state, 6); // State 0 again

    test_input(tb, expected_state, 3); // State 1
    test_input(tb, expected_state, 3); // State 2
    test_input(tb, expected_state, 5); // State 3
    test_input(tb, expected_state, 2); // State 4
    assert(expected_state == 4);
    test_input(tb, expected_state, 6); // State 0 again
    assert(expected_state == 0);

    test_input(tb, expected_state, 3); // State 1
    test_input(tb, expected_state, 3); // State 2
    test_input(tb, expected_state, 5); // State 3
    test_input(tb, expected_state, 2); // State 4
    test_input(tb, expected_state, 5); // State 5
    assert(expected_state == 5);
    test_input(tb, expected_state, 8); // State 0 again

    test_input(tb, expected_state, 3); // State 1
    test_input(tb, expected_state, 3); // State 2
    test_input(tb, expected_state, 5); // State 3
    test_input(tb, expected_state, 2); // State 4
    test_input(tb, expected_state, 5); // State 5
    test_input(tb, expected_state, 6); // State 6
    assert(expected_state == 6);
    assert(tb->locked == 0);
    // unlocked

    std::cout << "\nTesting post-unlock behavior\n";
    for (int i = 0; i < 5; i++)
    {
        test_input(tb, expected_state, rand() % 16);
        assert(expected_state == 6);
        assert(tb->locked == 0);
    }

    std::cout << "\nAll tests passed!\n";
    // Cleanup
    tb->final();
    delete tb;
    return 0;
}
