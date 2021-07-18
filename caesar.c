// link to problem statement
// 

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define LEN_OF_PLAINTEXT 50

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

   for(int i = 0, len = strlen(argv[1]); i < len; i++)
        if(!isdigit(argv[1][i])) {
            printf("Usage: ./caesar key\n");
            return  1;
        }

    int key = atoi(argv[1]);

    char plaintext[50];
    printf("plaintext: ");\
    scanf("%[^\n]s", plaintext);
    printf("ciphertext: ");
    for(int c, i = 0, len = strlen(plaintext); i < len; i++) {
        c = plaintext[i];
        if(islower(c)) {
            c = c - 'a';
            c = (c + key) % 26;
            c = c + 'a';
            printf("%c", c);
        } else if(isupper(c)) {
            c = c - 'A';
            c = (c + key) % 26;
            c = c + 'A';
            printf("%c", c);
        } else printf("%c", c);
    }   
    printf("\n");
    return 0;
}

