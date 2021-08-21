/**
 * @file
 * @brief Computes the factorial of a natural number
 */

#include <assert.h> // for assert function
#include <inttypes.h> // for uint64_t, uint32_t data types

/**
 * @brief Computes the factorial of `number`
 * @param number the number for to find its factorial
 * @returns The factorial of `number`
 */
uint64_t factorial(uint32_t number) {
    if(number == 0) return 1; // base case
    return number * factorial(number - 1);
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
    // The following lines tests the program of correct behaviour
    assert(factorial(1) == 1);
    assert(factorial(5) == 120);
    assert(factorial(11) == 39916800);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}