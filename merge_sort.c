/**
 * @file
 * @brief A program that implements merge sort algo
 */

#include<stdio.h>
#include<assert.h>

void merge_sort(int numbers[], int leftIndex, int rightIndex) {
    
}

void test() {
    int test1[] = {5,4,3,2,1};
    int test2[] = {6,5,4,3,2,1};
    int test3[] = {-2,-3,-1,0};

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