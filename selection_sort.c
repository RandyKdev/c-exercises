/**
 * @file
 * @brief  A program to sort an array of numbers using the selection sort algo
 */

#include<stdio.h>

void selectionSort(int length, int* numbers) {
    int endOfSorted= 0; // exclusive
    // int startOfUnsorted = 0; // [3, 2,1] -> [1, 2, 3] -> 1, 2, 3
    int smallestIndex = 0;
    int temp;
    for(int i = 0; i < length - 1; i++) {
        for(int j = endOfSorted; j < length; j++) {
            if(numbers[j] < numbers[smallestIndex]) smallestIndex = j;
        }
        temp = numbers[smallestIndex];
        numbers[smallestIndex] = numbers[endOfSorted];
        numbers[endOfSorted] = temp;
        endOfSorted++;
    }
}

void test() {
    
}

int main() {

    test();

    return 0;
}