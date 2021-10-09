/**
 * @file
 * @brief A program to search for a number in a sorted list of numbers (ascending order) using the binary search algo
 */

#include<assert.h> // for assert function

/**
 * @brief Finds the position of an element in a list
 * @param length the length of the array
 * @param numbers the array itself
 * @param searchElem the element to search for
 * @returns the index of `searchElem` in `numbers`
 * @returns -1 if not found
 */
int binarySearch(int length, int* numbers, int searchElem) {
    int start = 0;
    int end = length - 1;
    int middle;
    while (start <= end) {
        middle = (start + end) / 2;
        if(numbers[middle] == searchElem) return middle;
        if(numbers[middle] > searchElem) end = middle - 1;
        else start = middle + 1;
    }
    return -1;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
     // The following lines tests the program of correct behaviour
    int numbers1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    assert(binarySearch(10, numbers1, 2) == 1);
    assert(binarySearch(10, numbers1, 6) == 5);
    assert(binarySearch(10, numbers1, 9) == 8);
    assert(binarySearch(10, numbers1, 10) == 9);
    assert(binarySearch(10, numbers1, 1) == 0);
    assert(binarySearch(10, numbers1, 0) == -1);
    assert(binarySearch(10, numbers1, 11) == -1);

    int numbers2[] = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0};

    assert(binarySearch(10, numbers2, -9) == 0);
    assert(binarySearch(10, numbers2, 0) == 9);
    assert(binarySearch(10, numbers2, -5) == 4);
    assert(binarySearch(10, numbers2, -3) == 6);
    assert(binarySearch(10, numbers2, -7) == 2);
    assert(binarySearch(10, numbers2, 1) == -1);
    assert(binarySearch(10, numbers2, -10) == -1);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}