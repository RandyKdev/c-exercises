/**
 * @file
 * @brief Finds the largest palindrome product of 2 numbers having a certain number of digits
 * @details
 * A brief overview
 * A palindromic number reads the same both ways. The largest palindrome 
 * made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * link to [problem statement](https://projecteuler.net/problem=4)
 */

#include <assert.h>   // for assert function
#include <inttypes.h> // for uint64_t, uint16_t data types
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

uint8_t getDigitAtLocation(uint64_t number, uint32_t location) {
    if(location == 0) return number % 10;
    return (int)((number % (int)pow(10, location + 1)) - (number % (int)pow(10, location))) / (int)pow(10, location);
}

bool isPalindrome(uint64_t number) {
    uint64_t length = 1;
    uint64_t tempNum = number;
    while((int)(tempNum / 10) > 0) {
        length++;
        tempNum = (int) (tempNum / 10);
    }

    for(uint64_t i = 0; i < length / 2; i++) {
        if(getDigitAtLocation(number, i) != getDigitAtLocation(number, length - i - 1)) {
            return false;
        }
    }
    return true;
}

uint64_t getSmallestNum(uint64_t digits) {
    return pow(10, digits - 1);
}

uint64_t getLargestNum(uint64_t digits) {
    uint64_t largestNum = 0;

    for(int i = 0; i < digits; i++) {
        largestNum += (9 * pow(10, i));
    }

    return largestNum;
}

/**
 * @brief Calculates the largest palindrome product of 2 numbers having
 * number of digits = `digits`
 * @param digits the number of digits each, of the 2 numbers
 * @returns the largest palindrome product
 */
uint64_t getLargetPalindromeProduct(uint64_t digits) {
    uint64_t largestNum = getLargestNum(digits);
    uint64_t smallestNum = getSmallestNum(digits);
    uint64_t largestPalindrome = 0;
    uint64_t temp;

    for(uint64_t i = largestNum; i >= smallestNum; i--) {
        for(uint64_t j = i; j >= smallestNum; j--) {
            temp = i * j;
            if(temp > largestPalindrome && isPalindrome(i * j)) {
                largestPalindrome = i * j;
            }
        }
    }
    return largestPalindrome;
    // printf("%ld\n", largestProduct);
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
    // The following lines tests the program of correct behaviour
    assert(getLargetPalindromeProduct(4) == 99000099);
    assert(getLargetPalindromeProduct(3) == 906609);
    assert(getLargetPalindromeProduct(2) == 9009);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // runs self-test implementation of the program
    return 0;
}