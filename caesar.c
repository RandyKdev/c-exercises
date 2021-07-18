// link to problem statement
// 

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./caesar key");
        return 1;
    }

    int key = atoi(argv[1]);
    printf("%d\n", key);
    return 0;
}