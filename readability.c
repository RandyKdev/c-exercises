// link to problem statement
// https://cs50.harvard.edu/x/2021/psets/2/readability/

#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

int main(void) {
    int c, letters = 0, words = 0, sentences = 0;
    // bool inWord, inSentence;

    while((c = getchar()) != '\n') {
        if(isalpha(c)) {
            letters++;
        } else if(c == ' ') {
            words++;
        } else if (c == '?' || c == '.' || c == '!') {
            sentences++;
        }
    }
    printf("%d\n", letters);
printf("%d\n", words);
printf("%d\n", sentences);
    return 0;
}