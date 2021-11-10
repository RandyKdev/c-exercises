#include <stdio.h>

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void insertion(int arr[], int length) {
    //  int i, key, j;
    // for (i = 1; i < length; i++) {
    //     key = arr[i];
    //     j = i - 1;
 
    //     /* Move elements of arr[0..i-1], that are
    //       greater than key, to one position ahead
    //       of their current position */
    //     while (j >= 0 && arr[j] > key) {
    //         arr[j + 1] = arr[j];
    //         j = j - 1;
    //     }
    //     arr[j + 1] = key;
    // }
    
    int j,  key;
    for(int i = 1; i < length; i++) {
        key = arr[i];
        j = i - 1;
        while((arr[j] > key) && (j >= 0)) {
            arr[j + 1] = arr[j];
            j = j -1;
        }
        arr[j + 1] = key;
    }
}

int main(void) {
    int arr[] = {3,2,1,67,3,2};
    insertion(arr, 6);
    for(int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}