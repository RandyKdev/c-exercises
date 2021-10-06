#include <stdio.h>
#include <stdlib.h> // for malloc function
#include <string.h> // for strlen, strcat, strncat, strcpy functions
#include <stdbool.h> // for bool data type

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

int main() {
    char str[] = "224wa";
    printf("%s\n", translateToLatin(str));

    return 0;
}