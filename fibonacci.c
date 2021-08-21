/**
 * @file
 * @brief Finds the nth term of the fibonacci sequence
 */

#include <assert.h> // for assert function
#include <inttypes.h> // for uint64_t and uint32_t data types

/**
 * @brief Computes the nth term of the fibonacci sequence
 * @param number the term position in the fibonacci sequence
 * @returns The number at the position `number` of the fibonacci sequence
 */
uint64_t fibonacci(uint32_t number) {
    if(number == 0) return 0; // first base case
    if(number == 1) return 1; // second base case
    return fibonacci(number - 1) + fibonacci(number - 2);
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
    // The following lines tests the program of correct behaviour
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);
    assert(fibonacci(2) == 1);
    assert(fibonacci(10) == 55);
    assert(fibonacci(20) == 6765);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // runs self-test implementation of the program
    return 0;
}