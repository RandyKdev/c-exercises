/**
 * @file 
 * @brief Gets the smallest possible multiple that is evenly divisible 
 * by all integers in a certain continuous range
 * @details
 * A brief overview
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * The program finds the smallest number that is evenly divisible by a continuous range of numbers
 * link to [problem statement](https://projecteuler.net/problem=5)
 */

#include <assert.h>   // for assert function
#include <inttypes.h> // for uint64_t, uint32_t data types

/**
 * @brief Gets the Smallest Possible Multiple that is evenly divisible 
 * by all integers in the range `begin` to `end` inclusive
 * @param begin marks the start of the range of numbers
 * @param end marks the end of the range of numbers
 * @returns The smallest possible multiple divisible by all numbers from `start` to `end`
 */
static uint64_t getSmallestMultiple(uint32_t begin, uint32_t end) {
    // holds the smallest multiple
    uint64_t smallestMultiple = end;

    // while runs till the smalles multiple is found
    while(1) {
        
        // runs from `begin` to `end`
        for(uint32_t i = begin; i <= end; i++) {
            
            // checks if current `smallestMultiple` is divisible by `i`
            if(smallestMultiple % i != 0) {
                break;
            }

            // Checks if `i` is equal to `end`
            if(i == end) {
                return smallestMultiple;
            }
        }

        // adds `end` to `smallestMultiple`
        smallestMultiple += end;
    }
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
static void test() {
    // The following lines tests the program of correct behaviour
    assert(getSmallestMultiple(1, 20) == 232792560);
    assert(getSmallestMultiple(1, 10) == 2520);
    // TODO: test for 1 to 30
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