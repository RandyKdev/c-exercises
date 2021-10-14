/**
 * @file
 * @brief Seaches and replaces a string with another in a given strin
 * @details
 * Problem Statement
 * Perform a search and replace on the sentence using the arguments provided and return the new sentence.
 * First argument is the sentence to perform the search and replace on.
 * Second argument is the word that you will be replacing (before).
 * Third argument is what you will be replacing the second argument with (after).
 * 
 * For simplicity this solutions takes into condideration only 
 * the case where the search and replace strings are of equal length
 */

#include <assert.h> // for assert function
#include <stdlib.h> // for malloc and free function
#include <string.h> // for strlen, strcat, strncat and strncmp functions

/**
 * @brief Seaches and replaces a string with another in a given string 
 * @param str the string to be formatted
 * @param search the string to be replaced in `str`
 * @param replace the string to be replaced in place of `search`
 * @returns pointer to the new formatted string
 */
char *searchAndReplace(const char *str, const char *search, const char *replace) {
    int lenReplace = strlen(replace);
    int lenSearch = strlen(search);
    int lenStr = strlen(str);
    char *newStr = (char *) malloc(lenStr + 1);
    *newStr = '\0';
    char *newStrPtr = newStr;
    while(*(str + lenSearch - 1)) {
        if(strncmp(str, search, lenSearch) == 0) {
            strcat(newStr, replace);
            str += lenReplace;
            newStr += lenReplace;
            continue;
        }
        strncat(newStr++, str++, 1);
    }
    strcat(newStr, str);
    return newStrPtr;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program of correct behaviour
    char *solnStr = searchAndReplace("hey i am", "am", "he");
    assert(strcmp(solnStr, "hey i he") == 0);
    free(solnStr);

    solnStr = searchAndReplace("I am a worker in a company", "worker", "should");
    assert(strcmp(solnStr, "I am a should in a company") == 0);
    free(solnStr);

    solnStr = searchAndReplace("I am in worker in a company", "in", "an");
    assert(strcmp(solnStr, "I am an worker an a company") == 0);
    free(solnStr);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}