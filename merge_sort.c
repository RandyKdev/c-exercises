/**
 * @file
 * @brief A program that implements merge sort algo
 */

#include<stdio.h>   /// for IO operations
#include<assert.h>  /// for tests

void merge_sort(int numbers[], int leftIndex, int rightIndex) {

    if(leftIndex == rightIndex) return; // edge case, when there is only one number in the array

    int middle = (leftIndex + rightIndex) / 2; // calculates the middle of array

    merge_sort(numbers, leftIndex, middle); // merge left sub array
    merge_sort(numbers, middle + 1, rightIndex); // merge right sub array

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

void test() {
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

int main() {

    test();

    return 0;
}