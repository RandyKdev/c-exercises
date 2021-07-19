// link to problem statement
// https://cs50.harvard.edu/x/2021/psets/2/substitution/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define LEN_OF_PLAINTEXT 50

char getCipherChar(char plainChar, char *key);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int lenOfKey = strlen(argv[1]);
    if(lenOfKey != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for(int i = 0; i < lenOfKey; i++) {
        if(!isalpha(argv[1][i])){
            printf("Key must contain only letters of the alphabet\n");
            return 1;
        }
    }

    for(int i = 0; i < lenOfKey; i++)
        for(int j = i + 1; j < lenOfKey; j++)
            if(argv[1][i] == argv[1][j]) {
                printf("Key must contain unique letters\n");
                return 1;
            }

    char plaintext[LEN_OF_PLAINTEXT];
    printf("plaintext: ");
    scanf("%[^\n]s", plaintext);
    printf("ciphertext: ");

    for(int i = 0, lenOfPlaintext; i < strlen(plaintext); i++)
        if(isalpha(plaintext[i])) printf("%c", getCipherChar(plaintext[i], argv[1]));
        else printf("%c", plaintext[i]);
    
    printf("\n");

    return 0;
}

char getCipherChar(char plainChar, char *key) {
    int index = tolower(plainChar) - 'a';
    return islower(plainChar) ? tolower(key[index]) : toupper(key[index]);
}