/**
 * @file
 * @brief Finds the largest prime factor of a given positive integer
 * @details
 * A brief overview
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * So given 13195 as input to the program it will return 29
 * 600851475143
 * [problem statement](https://projecteuler.net/problem=3)
 * [hints and explanation](https://www.geeksforgeeks.org/prime-factor/)
 */

#include <assert.h>   // for assert function
#include <stdbool.h>  // for bool data type
#include <math.h>     // for sqrt (square root) function
#include <inttypes.h> // for uint64_t, uint16_t data types

/**
 * @brief Checks if `number` is prime
 * @param number the number to check if it is prime 
 * @returns `true` if `number` IS prime 
 * @returns `false`  if `number` is NOT prime
 */
bool isPrime(uint64_t number) {
    // if `number` is 2 or 3, it is prime
    if(number == 2 || number == 3) return true;

    // if `number` is divisible by 2, it is not prime
    if(number % 2 == 0) return false;

    // `number` at this stage must be odd
    // for loop runs from 3 and increments by 2 because only odd numbers divides odd numbers
    // for loop ends at square root of `number` being less than i
    int sqRoot = sqrt(number); // holds the square root of `number`
    for(uint64_t i = 3; i <= sqRoot; i += 2) {
        if(number % i == 0) { // if `number` is divisible by `i`, then it is not prime
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
    while(number % 2 == 0 && 2 <= sqrt(number)) { // Executes while `number` is still even and square root of number is greater than 2
        number /= 2; // divides current `number` by 2
    }

    // the for loop starts from 3 because that is the first odd prime number
    // the for loop runs through square root of `number` because [...](https://www.geeksforgeeks.org/prime-factor/)
    // i is incremented by 2 because the `number` at this stage cannot be even
    for(uint64_t i = 3; i <= sqrt(number); i+=2) {
        if(number % i == 0 && isPrime(i)) {  // checks if the current `number` is disible by `i` and if `i` is prime
            number /= i; // divides current `number` by `i`
            i = 3; // resets `i` to 3 because it might happen that lower prime numbers could still divide the current `number`
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
    assert(largestPrimeFactor(3) == 3);
    assert(largestPrimeFactor(2) == 2);
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