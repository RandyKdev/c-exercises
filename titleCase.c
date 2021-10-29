/**
 * @file
 * @brief Title Case a Sentence
 * @details
 * Problem Statement
 * Return the provided string with the first letter of each word capitalized. 
 * Make sure the rest of the word is in lower case.
 * For the purpose of this exercise, you should also capitalize connecting words like the and of.
 */

#include <assert.h> // for assert function
#include <string.h> // for strcmp function
#include <ctype.h> // for toupper and isspace functions
#include <stdbool.h> // for bool data type

/**
 * @brief Title case a string of words
 * @param str the string to title case
 * @returns void
 */
void titleCase(char *str) {
    bool metSpace = false; // holds true if a space is found
    // capitalize first letter in `str`
    if(*str) *str = toupper(*str); 
    // goes through `str`
    while(*str) {
        // checks if it is a space
        if(isspace(*str)) metSpace = true;
        // checks if a space was encountered before
        else if(metSpace) {
            *str = toupper(*str);
            metSpace = false;
        }
        str++; // increments `str`
    }
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program of correct behaviour
    char str[] = "i am a worker isn't?";
    titleCase(str);
    assert(strcmp(str, "I Am A Worker Isn't?") == 0);

    char str1[] = " i am a worker isn't? ";
    titleCase(str1);
    assert(strcmp(str1, " I Am A Worker Isn't? ") == 0);

    char str2[] = "i  am a worker isn't?";
    titleCase(str2);
    assert(strcmp(str2, "I  Am A Worker Isn't?") == 0);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}