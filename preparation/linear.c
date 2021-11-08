#include <stdio.h>
#define LEN (int) (sizeof(arr) / sizeof(arr[0]))

int search(int arr[], int length, int item) {

    for(int i = 0; i < length; i++) {
        if(arr[i] == item) return i;
    }

    return -1;
}


int main(void) {
    int arr[] = {0,1,2,3,4};
     int length = LEN;
    int index = search(arr, length, 50);
    printf("%d\n", index);
    return 0;
}