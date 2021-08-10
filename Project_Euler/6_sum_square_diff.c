/**
 * @file 
 * @brief Finds the difference between the sum of the squares and the square of the sum
 * of a range of numbers 
 * @details
 * A brief overview
 * The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is, (1 + 2 + 3 + ... + 10)^2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and 
 * the square of the sum is 3025 - 385 = 2640
 * link to [problem statement](https://projecteuler.net/problem=6)
 */

#include <assert.h>   // for assert function
#include <inttypes.h> // for uint64_t, uint32_t data types
#include <stdio.h>

static uint64_t getSumSquareDiff(uint32_t start, uint32_t end) {
    uint64_t sumSquareDiff = 0;
    for(uint32_t i = start; i < end; i++) {
        for(uint32_t j = i + 1; j <= end; j++) {
            sumSquareDiff += 2 * i * j;
        }
    }

    return sumSquareDiff;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
static void test() {
    // The following lines tests the program of correct behaviour
    printf("%ld\n", getSumSquareDiff(1, 100));
    assert(getSumSquareDiff(1, 10) == 2640);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // runs self-test implementation of the program
    return 0;
}

// TODO: [Modify logic](https://projecteuler.net/action=quote;post_id=42)