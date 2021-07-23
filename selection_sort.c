/**
 * @file
 * @brief  A program to sort an array of numbers using the selection sort algo
 */

#include<stdio.h>

void selectionSort(int length, int* numbers) {
    for(int smallestAtIndex, temp, i = 0; i < length - 1; i++) {
        smallestAtIndex = i;
        
        for(int j = i; j < length; j++)
            if(numbers[j] < numbers[smallestAtIndex]) smallestAtIndex = j;

        temp = numbers[smallestAtIndex];
        numbers[smallestAtIndex] = numbers[i];
        numbers[i] = temp;
    }
}

void test() {
    int numbers[] = {5,4,3,2,1};
    selectionSort(5, numbers);
    for(int i = 0; i < 5; i++)
    printf("%d ", numbers[i]);
    printf("\n");
}

int main() {

    test();

    return 0;
}