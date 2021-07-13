// link to problem statement
// https://cs50.harvard.edu/x/2021/labs/2/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);

int main(void) {
    // Get input words from both players
    // printf("%d %d", isupper('Z'), 'Z');
    // return 0;
    char word1[46], word2[46];

    printf("Player 1: ");
    scanf("%s", word1);

    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 > score2) printf("Player 1 wins!\n");
    else if(score1 < score2) printf("Player 2 wins!\n");
    else printf("Tie!\n");

    return 0;
}

int compute_score(char *word) {
    int i = 0, c, score = 0;
    while((c = word[i++]) != '\0') {
        if(isupper(c))
            score += POINTS[c - 65];
        else if(islower(c))
            score += POINTS[c - 97];
    }
    return score;
}