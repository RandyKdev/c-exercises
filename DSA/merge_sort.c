/**
 * @file
 * @brief A program that implements merge sort algo
 */

#include<assert.h>  // for assert function

/**
 * @brief Merges two sorted sub arrays
 * @param numbers the array containing the two sub sorted arrays
 * @param leftIndex the start index of one of the sorted arrays
 * @param rightIndex the end index of the sorted array
 * @param middle the index at which the two sorted arrays meet
 * @returns void
 */
void merge(int numbers[], int leftIndex, int rightIndex, int middle) {
    int tempLeftArr[middle - leftIndex + 1]; // left sub array
    int tempRightArr[rightIndex - middle]; // right sub array

    int tempLeftArrLength = 0; // length of left sub array
    int tempRightArrLength = 0; // length of right sub array

    // filling in left sub array
    for(int i = leftIndex; i <= middle; i++)
        tempLeftArr[tempLeftArrLength++] = numbers[i];

    // filling in right sub array
    for(int i = middle + 1; i <= rightIndex; i++)
        tempRightArr[tempRightArrLength++] = numbers[i];

    // putting elements in left and right sub arrays in the main array, sorted
    for(int i = leftIndex, tempLeftArrIndex = 0, tempRightArrIndex = 0; i <= rightIndex; i++)
        if(tempLeftArrIndex == tempLeftArrLength) numbers[i] = tempRightArr[tempRightArrIndex++];
        else if(tempRightArrIndex == tempRightArrLength) numbers[i] = tempLeftArr[tempLeftArrIndex++];
        else if(tempLeftArr[tempLeftArrIndex] < tempRightArr[tempRightArrIndex]) numbers[i] = tempLeftArr[tempLeftArrIndex++];
        else numbers[i] = tempRightArr[tempRightArrIndex++];
}

/**
 * @brief Sorts an array of numbers using merge sort algo
 * @param numbers the array of numbers to be sorted
 * @param leftIndex the start left index of `numbers`
 * @param rightIndex the end right index of `numbers`
 * @returns void
 */
void merge_sort(int numbers[], int leftIndex, int rightIndex) {

    if(leftIndex == rightIndex) return; // edge case, when there is only one number in the array

    int middle = (leftIndex + rightIndex) / 2; // calculates the middle of array

    merge_sort(numbers, leftIndex, middle); // merge left sub array
    merge_sort(numbers, middle + 1, rightIndex); // merge right sub array

    merge(numbers, leftIndex, rightIndex, middle); // merging sub arrays in main array
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
     // The following lines tests the program of correct behaviour
    int test1[] = {5, 4, 3, 2, 1};
    int test2[] = {6, 5, 4, 3, 2, 1};
    int test3[] = {-2, -3, -1, 0};

    merge_sort(test1, 0, 4);
    merge_sort(test2, 0, 5);
    merge_sort(test3, 0, 3);

    for(int i = 0; i < 5; i++)
        assert(test1[i] == i + 1);
    for(int i = 0; i < 6; i++) 
        assert(test2[i] == i + 1);
    for(int i = 0; i < 4; i++)
        assert(test3[i] == i - 3);    
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}