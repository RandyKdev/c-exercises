/**
 * @file 
 * @brief Reverses a sentence
 */

#include<string.h>
#include<assert.h>

#define WORDS 30   // The max number of words contained in sentence
#define LETTERS 20 // The max number of letters a word can contain

/**
 * @brief Writes a word which begins at `inputStr` to `std_out` at position `pos`
 * @param inputStr the array which holds the word to be written
 * @param std_out the array which the word is to be written to
 * @param pos the position in the `std_out` array that the word should start from
 * @returns void
 */
void writeWordToArr(char *inputStr, char *std_out, int *pos) {
    while (*inputStr != '\0')
    {
        std_out[(*pos)++] = *inputStr++;
    }

    std_out[(*pos)++] = ' ';
}

/**
 * @brief Reverses the sentence stored in `arr` 
 * @param arr the array which holds the sentence to be reversed
 * @returns void
 */
void reverseSentence(char *arr) {
    int c, i = 0, j = 0, p = 0;
    char input[WORDS][LETTERS + 1]; 
    char lastChar;
    while((c = arr[p++]) != '\0') {
        if(c == '.' || c == '!' || c == '?') {
            lastChar = c;
            break;
        }

        if(c == ' ') {
            input[i++][j] = '\0';
            j = 0;
            continue;
        }

        input[i][j++] = c;
    }

    input[i][j] = '\0';

    j = 0;
    for(i; i >= 0; i--) {
        writeWordToArr(&input[i][0], arr, &j);
    }

    arr[--j] = lastChar;
    arr[++j] = '\0';
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
    char arr1[] = "you can cage a swallow can't you?";
    char solnarr1[] = "you can't swallow a cage can you?";

    reverseSentence(arr1);

    assert(strcmp(arr1, solnarr1) == 0);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // runs self-test implementation of the program
    return 0;
}