/**
 * @file
 * @brief Truncates a string
 * @details
 * Problem Statement
 * Truncate a string (first argument) if it is longer than the 
 * given maximum string length (second argument). 
 */

#include <assert.h> // for assert function
#include <string.h> // for strlen, strcmp function

/**
 * @brief truncates a string
 * @param str the string to truncate
 * @param maxLength the maximum length of the truncated string
 * @returns a pointer to the truncated string
 */
char *truncateString(char *str, const int maxLength) {
    int lengthOfStr = strlen(str); // computes the length of str
    
    // checks if length of str is more than the max length required
    if(lengthOfStr > maxLength) {
        str[maxLength] = '\0'; // truncates str
    }

    return str;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program of correct behaviour
    char str[] = "224wa";
    assert(strcmp(truncateString(str, 3), "224") == 0);

    char str1[] = "i am a lad";
    assert(strcmp(truncateString(str1, 10), "i am a lad") == 0);

    char str2[] = "hey";
    assert(strcmp(truncateString(str2, 5), "hey") == 0);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}