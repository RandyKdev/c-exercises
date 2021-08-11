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

/**
 * @brief Checks if `number` is prime or not
 * @param number the number to be checked if it is prime
 * @returns `true` if `number` IS a prime number
 * @returns `false` if `number` is NOT a prime number
 */
static bool isPrimeNumber(uint32_t number) {
    // For loop starts from 3 because that is the next prime number after 2
    // For loop ends at square root of `number` as in maths
    // See solution to ``Problem 3`` for explanation
    for(uint32_t i = 3; i <= sqrt(number); i += 2) {
        if(number % i == 0) {  // checks if `number` is divisible by `i`
            return false;
        }
    }

    return true;
}

/**
 * @brief Gets the Prime Number at position = `position`
 * @param position the position of the prime number
 * @returns The prime number at position `position`
 */
static uint64_t getPrimeNumber(uint32_t position) {
    // Checks if position is 1 and returns 2 
    // which is the only prime number and the first prime number
    if(position == 1) return 2;

    uint64_t primeNumber = 2;  // holds the most recent prime number gotten
    uint32_t i = 3;  // counter variable
    
    // runs while `position` is greater than `1`
    while(position > 1) {
        if(isPrimeNumber(i)) { // checks if `i` is a prime number
            primeNumber = i;  // sets `i` to `primeNumber`
            position--;  // decrements `position`
        }
        i += 2; // increments `i` by 2
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