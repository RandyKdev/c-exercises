/**
 * @file
 * @brief Translates a word to latin
 * @details
 * Problem Statement
 * Latin is a way of altering English Words. The rules are as follows:
 * If a word begins with a consonant, take the first consonant or consonant cluster, 
 * move it to the end of the word, and add ay to it.
 * If a word begins with a vowel, just add way at the end.
 * Example : 
 * For consonant : translateLatin("paragraphs") should return the string aragraphspay
 * For Vowel: translateLatin("eight") should return the string eightway.
 */

#include <assert.h> // for assert function
#include <stdlib.h> // for malloc function
#include <string.h> // for strlen, strcat, strncat, strcpy functions
#include <stdbool.h> // for bool data type

/**
 * @brief Checks if a letter is a vowel
 * @param letter letter to be checked if it is a vowel
 * @returns true if `letter` is a vowel
 * @returns false if `letter` is not a vowel
 */
bool isVowel(char letter) {
    const char *vowels = "aeiou"; // list of vowels
    
    // Goes through the vowel list
    while(*vowels) {
        // Checks if the letter is a vowel
        if(letter == *vowels++) {
            return true;
        }
    }

    // if not,
    return false;
}

/**
 * @brief Checks if a letter is a consonant
 * @param letter letter to be checked if it is a consonant
 * @returns true if `letter` is a consonant
 * @returns false if `letter` is not a consonant
 */
bool isConsonant(char letter) {
    // list of consonants
    const char *consonants = "bcdfghjklmnpqrstvwxyz";
    
    // Goes through list of consonants
    while (*consonants) {
        // checks if the letter is a consonant
        if(letter == *consonants++) {
            return true;
        }
    }

    // if not,
    return false;
}

/**
 * @brief Gets the location (pointer) Of the first non-consonant letter in `word`
 * @param word the word in which the first non-consonant letter is to be checked
 * @returns the pointer to the first non-consonant letter in `word`
 */
char *getLocationOfFirstNonConsonant(char *word) {
    // Goes through the word
    while(*word) {
        // checks if it has found a letter which is not a consonant
        if(!isConsonant(*word)) {
            // returns the position of the first non consonant letter
            return word;
        }
        word++; // goes to next letter in word
    }

    // otherwise returns the last position in word
    return word;
}

/**
 * @brief Translates `word` to latin
 * @param word the word to be translated to latin
 * @returns A pointer to a string which contains the latin word
 */
char *translateToLatin(char *word) {
    char *latinWord; // pointer to the latin word
    
    // Checks if the first letter of word is a vowel
    if(isVowel(word[0])) {
        // allocates enough memory for "way" and nul char
        latinWord = (char *) malloc(strlen(word) + 4);
        strcpy(latinWord, word); // copies whole word to latin word
        strcat(latinWord, "way"); // appends "way" to the end of latin word
        return latinWord; // returns formed latin word
    }

    // checks if the first letter of word is a consonant
    if(isConsonant(word[0])) {
        // allocates enough memory for "ay" and nul char
        latinWord = (char *) malloc(strlen(word) + 3);
        // gets the location of the first non-consonant letter in word
        char *locationOfFirstNonConsonant = getLocationOfFirstNonConsonant(word);
        // copies rest of letters found in word starting from the first non-consonant letter
        // to latin word
        strcpy(latinWord, locationOfFirstNonConsonant);
        // appends the letters which were left at the beginning of word to latin word
        strncat(latinWord, word, locationOfFirstNonConsonant - word);
        strcat(latinWord, "ay"); // appends "ay" to the end of the word
        return latinWord; // returns formed latin word
    }

    // if it doesn't start with a vowel or consonant, copies the exact word and returns it
    latinWord = (char *) malloc(strlen(word) + 1);
    strcpy(latinWord, word);
    return latinWord;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program of correct behaviour
    char *str = "224wa";
    char *solnStr = translateToLatin(str);
    assert(strcmp(solnStr, "224wa") == 0);
    free(solnStr);
    
    str = "paragraph";
    solnStr = translateToLatin(str);
    assert(strcmp(solnStr, "aragraphpay") == 0);
    free(solnStr);

    str = "eight";
    solnStr = translateToLatin(str);
    assert(strcmp(solnStr, "eightway") == 0);
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