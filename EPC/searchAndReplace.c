// For simplicity this solutions takes into condideration only 
// the case where the search and replace strings are of equal length

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *searchAndReplace(const char *str, const char *search, const char *replace) {
    char *newStr = (char *) malloc(strlen(str) + 1);
    *newStr = '\0';
    char *newStrPtr = newStr;
    while(*(str + strlen(search) - 1)) {
        if(strncmp(str, search, strlen(search)) == 0) {
            strcat(newStr, replace);
            str += strlen(replace);
            newStr += strlen(replace);
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


int main(void) {
    printf("%s\n", searchAndReplace("hey i am", "am", "he"));
    // assert(strcmp(searchAndReplace("hey i am", "am", "hey"), "hey i hey") == 0);
    return 0;
}