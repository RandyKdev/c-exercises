/**
 * @file
 * @brief  A program to sort an array of numbers using the selection sort algo
 */

#include<stdio.h>
#include<assert.h>

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
    int test1[] = {5,4,3,2,1};
    int test2[] = {1,3,2,4,5};
    int test3[] = {-3,-5,0,2,1,-4};
    int test4[] = {2};

    int solution1_2[] = {1,2,3,4,5};
    int solution3[] = {-5,-4,-3,0,1,2};
    
    selectionSort(5, test1);
    selectionSort(5, test2);
    selectionSort(6, test3);
    selectionSort(1, test4);

    for(int i = 0; i < 5; i++){
        assert(test1[i] == solution1_2[i]);
        assert(test2[i] == solution1_2[i]);
    }
    for(int i = 0; i < 6; i++)
        assert(test3[i] == solution3[i]);

    assert(test4[0] == 2);
}

int main() {

    test();

    return 0;
}