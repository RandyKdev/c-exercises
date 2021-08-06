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
#include <stdbool.h>
#include <math.h>
#include <inttypes.h> // for uint64_t, uint16_t data types

/**
 * @brief Checks if `number` is prime
 * @param number the number to check if it is prime 
 * @returns `true` if `number` IS prime 
 * @returns `false`  if `number` is NOT prime
 */
bool isPrime(uint64_t number) {
    if(number == 2 || number == 3) return true;

    if(number % 2 == 0) return false;

    for(uint64_t i = 3; i <= sqrt(number); i += 2) {
        if(number % i == 0) {
            return false;
        }
    }

    return true;
}

// todo: complete comments

/**
 * @brief Finds the largest prime factor of `number`
 * @param number the number to find the largest prime factor of
 * @returns The largest prime factor of `number` 
 */
uint64_t largestPrimeFactor(uint64_t number) {
    // the for loop starts from 2 because that is the first prime number
    // the for loop runs through square root of `number` because [...](https://www.geeksforgeeks.org/prime-factor/)
    for(uint64_t i = 2; i <= sqrt(number); i++) {
        if(number % i == 0 && isPrime(i)) { 
            number /= i;
            i = 1;
        }
    }

    return number;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
    // The following lines tests the program of correct behaviour
    assert(largestPrimeFactor(600851475143) == 6857);
    assert(largestPrimeFactor(13195) == 29);
    assert(largestPrimeFactor(10) == 5);
    assert(largestPrimeFactor(20) == 5);
    assert(largestPrimeFactor(4) == 2);
    assert(largestPrimeFactor(5) == 5);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // runs self-test implementation of the program
    return 0;
}