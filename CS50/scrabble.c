// link to problem statement
// https://cs50.harvard.edu/x/2021/labs/2/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word) {
    int i = 0, c, score = 0;
    while((c = word[i++]) != '\0') {
        if(isupper(c))
            score += POINTS[c - 'A'];
        else if(islower(c))
            score += POINTS[c - 'a'];
    }
    return score;
}

void test() {
    char *player1[] = {
        "Question?",
        "Oh,",
        "COMPUTER",
        "Scrabble"
    };
    char *player2[] = {
        "Question!",
        "hai!",
        "science",
        "wiNNeR"
    };

    char solution[] = {0, -1, 3, 5};

    int score1, score2;
    for(int i = 0; i < 4; i++) {
        score1 = compute_score(player1[i]);
        score2 = compute_score(player2[i]);
        assert(score1 - score2 == solution[i]);
    }
}

int main(void) {
    
    test();

    return 0;
}

