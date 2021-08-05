/**
 * @file
 * @brief Finds the largest prime factor of a given positive integer
 * @details
 * A brief overview
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * So given 13195 as input to the program it will return 29
 * 600851475143
 * link to [problem statement](https://projecteuler.net/problem=3)
 */

#include <assert.h> // for assert function
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h> // for uint64_t, uint16_t data types

/**
 * @brief Checks if `number` is prime
 * @param number the number to check if it is prime 
 * @returns `true` if `number` IS prime 
 * @returns `false`  if `number` is NOT prime
 */
bool isPrime(uint64_t number) {
    for(uint64_t i = 2; i < number; i++) {
        if(number % i == 0) {
            return false;
        }
    }

    return true;
}

/**
 * @brief Finds the largest prime factor of `number`
 * @param number the number to find the largest prime factor of
 * @returns The largest prime factor of `number` 
 */
uint64_t largestPrimeFactor(uint64_t number) {
    for(uint64_t i = number / 2; i > 0; i--) {
        if(number % i == 0 && isPrime(i)) {
            return i;
        }
    }
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
    // The following lines tests the program of correct behaviour
    assert(largestPrimeFactor(13195) == 29);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // runs self-test implementation of the program
    return 0;
}