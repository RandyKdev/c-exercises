/**
 * @file
 * @brief Finds the nth prime number
 * @details
 * A brief overview
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, 
 * we can see that the 6th prime is 13.
 * The program finds the nth prime number
 * link to [problem statement](https://projecteuler.net/problem=7)
 */

#include <assert.h>   // for assert function
#include <inttypes.h> // for uint64_t, uint32_t data types
#include <stdbool.h>  // for bool data type
#include <math.h>     // for for sqrt function

static bool isPrimeNumber(uint32_t number) {
    for(uint32_t i = 3; i <= sqrt(number); i += 2) {
        if(number % i == 0) {
            return false;
        }
    }

    return true;
}

static uint64_t getPrimeNumber(uint32_t position) {
    if(position == 1) return 2;
    uint64_t primeNumber = 2;
    uint32_t i = 3;
    while(position > 1) {
        if(isPrimeNumber(i)) {
            primeNumber = i;
            position--;
        }
        i += 2;
    }
    return primeNumber;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
static void test() {
    // The following lines tests the program of correct behaviour
    assert(getPrimeNumber(10001) == 104743);
    assert(getPrimeNumber(6) == 13);
    assert(getPrimeNumber(2) == 3);
    assert(getPrimeNumber(1) == 2);
    assert(getPrimeNumber(5) == 11);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // runs self-test implementation of the program
    return 0;
}