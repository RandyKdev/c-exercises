/**
 * @file
 * @brief Translates a string of words to spinal case
 * @details
 * Problem Statement
 * Convert a string to spinal case. Spinal case is all-lowercase-words-joined-by-dashes.
 * Example: spinalCase("This Is Spinal Tap") should return the string this-is-spinal-tap
 */

#include <ctype.h> // for tolower function
#include <stdlib.h> // for malloc function
#include <string.h> // for strlen function

/**
 * @brief translates a string to spinal case
 * @param str the string to be turned to spinal case
 * @returns the pointer to spinal case string
 */
char *spinalCase(const char *str) {
    int lenOfStr = strlen(str); // computes length of str
                              
    // reserves enough space to store spinal string
    char *spinalStr = (char *) malloc(lenOfStr + 1); 
                              
    int posOfStr = 0; // holds position in str
    int posOfSpinalStr = 0; // holds position in spinal string
    char temp; // holds a temporal character from str

    // Goes through str
    while(str[posOfStr] != '\0') {
        temp = tolower(str[posOfStr]); // converts character found in str
        
        // prevents more than one '-' to be placed in a row due to multiple spaces and also
        // prevents '-' to be placed at the beginning of the string
        if(isspace(temp) && (posOfSpinalStr == 0 || spinalStr[posOfSpinalStr - 1] == '-')) {
            posOfStr++;
            continue;
        }

        // stores a '-' where ever there is a space
        if(isspace(temp)) {
            spinalStr[posOfSpinalStr++] = '-';
            posOfStr++;
            continue;
        }
        
        // stores any other character apart from spaces in spinal str in lowercase
        spinalStr[posOfSpinalStr++] = temp;
        posOfStr++;
    }

    // removes '-' at the end of spinal str if it exists
    if(spinalStr[posOfSpinalStr - 1] == '-') {
        posOfSpinalStr--;
    }

    spinalStr[posOfSpinalStr] = '\0'; // marks the end of spinal str

    return spinalStr;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program of correct behaviour
    char *solnStr = spinalCase("   This   is    spinal     case   ");
    assert(strcmp(solnStr, "this-is-spinal-case") == 0);
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