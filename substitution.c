// link to problem statement
// https://cs50.harvard.edu/x/2021/psets/2/substitution/

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int len = strlen(argv[1]);
    if(len != 26) {
        printf("Key must contain 26 characters.");
        return 1;
    }
    for(int i = 0; i < len; i++) {
        if(!isalpha(argv[1][i])){
            printf("Key must contain only letters of the alphabet\n");
            return 1;
        }
    }

    for(int i = 0; i < len; i++)
        for(int j = i + 1; j < len; j++)
            if(argv[1][i] == argv[1][j]) {
                printf("Key must contain unique letters\n");
                return 1;
            }

    

    return 0;
}