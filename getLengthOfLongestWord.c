/**
 * @file
 * @brief Finds the longest word in a given string
 * @details
 * Problem Statement
 * Find the Longest Word in a String.
 * Return the length of the longest word in any provided string.
 * Your response should be a number (integer).
 */

#include <assert.h> // for the assert function
#include <ctype.h> // for the isalpha function

/**
 * @brief Gets the Length Of Longest Word
 * @param string the search string
 * @returns the length of the longest word in `string`
 */
int getLengthOfLongestWord(const char *string) {
    int longestLength = 0; // Stores the length of the longest word
    int currentLength = 0; // Stores the length of the current word we are on
    int i = 0; // Tracks the position of the string we are at

  	// Goes through the string and till it meets the end of the string
    while(string[i] != '\0') {
        // checks if the current character is a letter of the alphabet
      	if(isalpha(string[i++])) {
          currentLength++; // Increments currentLength
          continue; // Skips to the next iteration
        }
      
      	// checks if the length of the current word is longer 
      	// than the rest of the words already seen
        if(currentLength > longestLength) {
          // Sets length of current word as longest word seen
          longestLength = currentLength; 
        }
        
      	// resets the length of the current word to 0 
      	// because we will be checking a different word in the next iteration
    	currentLength = 0; 
    }

	// checks if the length of the current word is longer 
    // than the rest of the words already seen
    if(currentLength > longestLength) {
        // Sets length of current word as longest word seen
        longestLength = currentLength; 
    }

    return longestLength;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program of correct behaviour
    assert(getLengthOfLongestWord("Hey i am longestest word") == 10);
    assert(getLengthOfLongestWord("Hey i am longest word") == 7);
    assert(getLengthOfLongestWord("Hey") == 3);
    assert(getLengthOfLongestWord("Hey word I") == 4);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}