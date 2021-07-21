/**
*@file
*@brief A program that implements linear search
*@details The program goes through a list of numbers (sorted or unsorted)
* and returns the index of the first occurence of the search element if found, otherwise it returns -1
*/

#include<stdio.h>
#include<assert.h>

int linearSearch(int length, int* numbers, int searchElem) {
    for(int i = 0; i < length; i++) 
        if(numbers[i] == searchElem) return i;

    return -1;
}

void test() {
    int numbers1[] = {0, 5, 6, 2, -4};
    int numbers2[] = {-3, -5, -7, -2};
    int numbers3[] = {4, 5, 5, 6};
    int numbers4[] = {10};

    assert(linearSearch(5, numbers1, 0) == 0);
    assert(linearSearch(4, numbers2, -7) == 2);
    assert(linearSearch(5, numbers3, 5) == 1);
    assert(linearSearch(1, numbers4, 4) == -1);
}
int main() {

    test();

    return 0;
}