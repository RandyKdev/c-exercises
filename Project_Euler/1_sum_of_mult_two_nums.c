/**
 * @file
 * @brief Finds the sum of multiples of 2 given positive whole numbers below a certain limit
 * @details 
 * Given 2 positive whole numbers and a limit, the program sums all the multiples of the 2 numbers
 * upto that limit. For example
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, 
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * link to [problem statement](https://projecteuler.net/problem=1)
 */

#include <assert.h> // for assert function

/**
 * @brief Calculates the sum of the multiples of `num1` and `num2` below `limit`
 * @param num1 the first number to sum its multiples
 * @param num2 the second number to sum its multiples
 * @param limit the maximum number to consider while getting multiples of `num1` and `num2`
 * @returns sum of the multiples of `num1` and `num2` below `limit`
 */
int sumOfMult(int num1, int num2, int limit) {
    int sum = 0;           // Holds the sum of the multiples of `num1` and `num2` 
    int tempNum1 = num1;   // Holds the progressive multiples of `num1`
    int tempNum2 = num2;   // Holds the progressive multiples of `num2`

    while(tempNum1 < limit || tempNum2 < limit) { // Executes while the current multiple of `num1` or `num2` is less than `limit`
        if(tempNum1 < limit) { // Checks if the current multiple of `num1` is less than `limit`
            sum += tempNum1;   // Adds current multiple of `num1` to `sum`
        }
        if(tempNum2 < limit && tempNum2 % num1 != 0) { // Checks if the current multiple of `num2` is less than `limit` and if `tempNum2` is also divisible by `num1`
            sum += tempNum2;   // Adds current multiple of `num2` to `sum`
        }
        tempNum1 += num1; // Goes to next multiple of `num1`
        tempNum2 += num2; // Goes to next multiple of `num2`
    }
    
    return sum;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
    // The following lines tests the program of correct behaviour
    assert(sumOfMult(2, 6, 13) == 42);
    assert(sumOfMult(3, 5, 1000) == 233168);
    assert(sumOfMult(3, 5, 10) == 23);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // runs self-test implementation of the program
    return 0;
}