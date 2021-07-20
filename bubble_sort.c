/*
*@file
*@brief A program that sorts a list (array) of numbers (int) using bubble sort algo
*/

#include<stdio.h>
#include<stdbool.h>

void bubbleSort(int *numbers, int length) {
    bool swapped = false;
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length - 1; j++) {
            if(numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swapped = true;
            }
        }
        if(!swapped) return;
        swapped = false;
    }
}

int main(void) {

}