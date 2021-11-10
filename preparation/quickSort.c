#include <stdio.h>
#include <assert.h>

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 =  temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = (start - 1);
    for(int j = start; j < end; j++) {
        if(arr[j] <= pivot) {
            swap(&arr[++i], &arr[j]);
        }
    }
    swap(&arr[++i], &arr[end]);
    return i;
}

void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int main() {
    int arr[] = {2,6,4,3,6,8};
    quickSort(arr, 0, 5);
    assert(arr[0] == 2);
    assert(arr[1] == 3);
    assert(arr[2] == 4);
    assert(arr[3] == 6);
    assert(arr[4] == 6);
    assert(arr[5] == 8);
    return 0;
}