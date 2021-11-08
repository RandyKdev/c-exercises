#include <stdio.h>

int search(int arr[], int item, int start, int end) {
    if(start == end) {
        if(arr[start] == item) return start;
        return -1;
    }

    int middle = (start + end) / 2;
    if(arr[middle] == item) return middle;

    if(arr[middle] < item)
    search(arr, item, middle + 1, end);
    else search(arr, item, start, middle);
}

int main(void) {

    int arr[] = {0,1,3,6,27,35};
    int index = search(arr, 40, 0, 6);
    printf("%d\n", index);
    return 0;
}