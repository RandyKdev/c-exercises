/**
 * @file
 * @brief A program to search for a number in a sorted list of numbers using the binary search algo
 */

#include<stdio.h>
#include<assert.h>

int binarySearch(int length, int* numbers, int searchElem) {
    int start = 0;
    int end = length - 1;
    int middle;
    while (start != end) {
        middle = (start + end) / 2;
        if(numbers[middle] == searchElem) return middle;
        if(numbers[middle] > searchElem) end = middle - 1;
        else start = middle + 1;
    }
    return -1;
}

void test() {

}

int main() {
    
    test();

    return 0;
}