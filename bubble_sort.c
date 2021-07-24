/**
*@file
*@brief A program that sorts a list (array) of numbers (int)
*in ascending order using bubble sort algo
*/

#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

void bubbleSort(int *numbers, int length) {
    bool swapped = false;
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length - 1 - i; j++)
            if(numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swapped = true;
            }
        
        if(!swapped) return;
        swapped = false;
    }
}

void test() {
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

int main(void) {

    test();

    return 0;
}