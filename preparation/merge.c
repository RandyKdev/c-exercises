#include <stdio.h>

void split(int *arr, int start, int end);
void merge_sort(int *arr, int middle, int start, int end);

int main(void) 
{

    return 0;
}

void split(int *arr, int start, int end)
{
    if (start == end) return;

    int middle = (start + end) / 2;
    split(arr, start, middle);
    split(arr, middle+1, end);

    merge_sort(arr, middle, start, end);
}

void merge_sort(int *arr, int middle, int start, int end)
{
    int arr1[middle - start + 1], arr2[end - middle];

    for (int i = start, x = 0; i <= middle; i++, x++)
        arr1[x] = arr[i];
}