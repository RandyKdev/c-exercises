// link to problem statement
// https://cs50.harvard.edu/x/2021/psets/2/caesar/

// todo: Add comments

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define LEN_OF_PLAINTEXT 50

int getCipherChar(int plainChar, int key, int startingChar);

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
    char plaintext[LEN_OF_PLAINTEXT];

    printf("plaintext: ");
    scanf("%[^\n]s", plaintext);
    printf("ciphertext: ");

    for(int i = 0, len = strlen(plaintext); i < len; i++)
        if(islower(plaintext[i]))
            printf("%c", getCipherChar(plaintext[i], key, 'a'));
        else if(isupper(plaintext[i]))
            printf("%c", getCipherChar(plaintext[i], key, 'A'));
        else printf("%c", plaintext[i]);
    
    printf("\n");
    
    return 0;
}

int getCipherChar(int plainChar, int key, int startingChar) {
    plainChar = plainChar - startingChar;
    plainChar = (plainChar + key) % 26;
    plainChar = plainChar + startingChar;
    return plainChar;
}