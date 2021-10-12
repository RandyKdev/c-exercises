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
            strncat(newStr, replace, strlen(replace));
            str += strlen(replace);
            newStr += strlen(replace);
            continue;
        }
        strncat(newStr++, str++, 1);
    }
    *newStr = '\0';
    return newStrPtr;
}

int main() {
    printf("%s\n", searchAndReplace("hey i am a", "am", "he"));
    // assert(strcmp(searchAndReplace("hey i am", "am", "hey"), "hey i hey") == 0);
    return 0;
}