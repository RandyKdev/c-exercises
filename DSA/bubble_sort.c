/**
*@file
*@brief A program that sorts a list (array) of numbers (int)
*in ascending order using bubble sort algo
*/

#include <stdbool.h> // for bool data type
#include <assert.h> // for assert function

/**
 * @brief Swaps numbers contained in `num1` and `num2`
 * @param num1 Pointer to number to swap
 * @param num2 Pointer to number to swap
 * @returns void
 */
void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/**
 * @brief Sorts a list of numbers
 * @param numbers the array of numbers to be sorted
 * @param length the length of `numbers`
 * @returns void
 */
void bubbleSort(int *numbers, int length) {
    bool swapped = false;
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length - 1 - i; j++)
            if(numbers[j] > numbers[j + 1]) {
                swap(&numbers[j], &numbers[j + 1]);
                swapped = true;
            }
        
        if(!swapped) return;
        swapped = false;
    }
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
     // The following lines tests the program of correct behaviour
    int numbers1[] = {1};
    int numbers2[] = {5, 4, 3, 2, 1, 0};
    int numbers3[] = {-1, -4, -2, 0};

    int solution3[] = {-4, -2, -1, 0};

    bubbleSort(numbers1, 1);
    assert(numbers1[0] == 1);

    bubbleSort(numbers2, 6);
    for(int i = 0; i < 6; i++)
        assert(numbers2[i] == i);
    
    bubbleSort(numbers3, 4);
    for(int i = 0; i < 4; i++) 
        assert(numbers3[i] == solution3[i]);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}