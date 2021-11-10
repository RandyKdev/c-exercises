#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *q) {
    int p1 = *(int *) p;
    int q1 = *(int *) q;
    return q1 - p1;
}
int main(void) {
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int key = 6;
    int *item = (int *) bsearch(&key, arr, 12, sizeof(int), compare);
    if(item == NULL) {
        printf("Not found\n");
    } else printf("Found item %ld\n", item - arr);

    return 0;
}