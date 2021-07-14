// link to problem statement
// https://cs50.harvard.edu/x/2021/psets/2/readability/

#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>

int main(void) {
    int c, letters = 0, words = 1, sentences = 0;

    while((c = getchar()) != '\n') {
        if(isalpha(c)) {
            letters++;
        } else if(c == ' ') {
            words++;
        } else if (c == '?' || c == '.' || c == '!') {
            sentences++;
        }
    }

    float lettersPer100Words = ((float)letters / (float) words) * 100.0;
    float sentencesPer100Words = ((float)sentences / (float) words) * 100.0;

    float index = (0.0588 * lettersPer100Words) - (0.296 * sentencesPer100Words) - 15.8;
    index = (float)round(index);

    if(index < 1) printf("Before Grade 1\n");
    else if(index > 15) printf("Grade 16+\n");
    else printf("Grade %.0f\n", index);

    return 0;
}