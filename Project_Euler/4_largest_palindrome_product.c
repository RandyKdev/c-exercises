/**
 * @file
 * @brief Finds the largest palindrome product of 2 numbers having 
 * a certain number of digits
 * @details
 * A brief overview
 * A palindromic number reads the same both ways. The largest palindrome 
 * made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * link to [problem statement](https://projecteuler.net/problem=4)
 */

#include <assert.h>   // for assert function
#include <inttypes.h> // for uint64_t, uint32_t, uint8_t data types
#include <math.h>     // for pow function
#include <stdbool.h>  // for bool data type

/**
 * @brief Gets the Section Of `number` From `location` to 0
 * @param number the number to get section from
 * @param location the location of the digit to start sectioning from
 * @returns The section of `number` from `location` to 0
 */
uint64_t getSectionOfNumberFromLocation(uint64_t number, uint32_t location) {
    return number % (int)pow(10, location);
}

/**
 * @brief Gets the Digit At `location` in `number` 
 * @param number the number to get digit from
 * @param location the location of the digit in `number`
 * @returns The digit at `location` in `number`
 */
uint8_t getDigitAtLocation(uint64_t number, uint32_t location) {
    // Check if `location` corresponds to the first digit of the number
    if(location == 0) return number % 10;

    return (int)(
        getSectionOfNumberFromLocation(number, location + 1) - 
        getSectionOfNumberFromLocation(number, location)
    ) / 
    (int) pow(10, location);
}

/**
 * @brief Gets the Length Of `number` (the number of digits in `number`) 
 * @param number the number to get its length
 * @returns the length of `number`
 */
uint32_t getLengthOfNumber(uint64_t number) {
    uint32_t length = 1; // 
    while((int)(number /= 10) > 0 && length++);
    return length;
}

/**
 * @brief Checks if `number` is palindrome or not
 * @param number the number to be checked for 'palindromeness'
 * @returns `true` if `number` IS palindrome 
 * @returns `false` if `number` is NOT palindrome 
 */
bool isPalindrome(uint64_t number) {
    uint64_t length = getLengthOfNumber(number);

    for(uint64_t i = 0; i < length / 2; i++) {
        if(getDigitAtLocation(number, i) != getDigitAtLocation(number, length - i - 1)) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Gets the Smallest Number that can be represented in the 
 * specified number of digits
 * @param digits the number of digits the input number has
 * @returns The smallest number with number of digits = `digits`
 */
uint64_t getSmallestNumber(uint64_t digits) {
    return pow(10, digits - 1);
}

/**
 * @brief Gets the Largest Number that can be represented in the 
 * specified number of digits
 * @param digits the number of digits the input number has
 * @return The largest number with number of digits = `digits`
 */
uint64_t getLargestNumber(uint64_t digits) {
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
    // Holds the largest number representable in the specified number of `digits`
    uint64_t largestNum = getLargestNumber(digits); 
    
    // Holds the smallest number representable in the specified number of `digits`
    uint64_t smallestNum = getSmallestNumber(digits);

    // Holds the largest palindrome product of 2 numbers of with the specified number of `digits`
    uint64_t largestPalindromeProduct = 0;

    uint64_t temp; // holds the product of i and j temporarily

    // 
    for(uint64_t i = largestNum; i >= smallestNum; i--) {
        for(uint64_t j = i; j >= smallestNum; j--) {

            temp = i * j;

            // Checks if temp is greater than lPP and if temp is a palindrome number
            if(temp > largestPalindromeProduct && isPalindrome(temp)) {
                largestPalindromeProduct = temp; // sets largest palindrome product to temp
            }
        }
    }

    return largestPalindromeProduct;
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