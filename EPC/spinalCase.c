#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *spinalCase(const char *str) {
    int lenOfStr = strlen(str); // computes length of str
    char *spinalStr = (char *) malloc(lenOfStr); // reserves enough space to store spinal string
    int posOfStr = 0; // holds position in str
    int posOfSpinalStr = 0; // holds position in spinal string
    char temp; // holds a temporal character from str

    // Goes through str
    while(str[posOfStr] != '\0') {
        temp = tolower(str[posOfStr]); // converts character found in str
        
        // prevents more than one '-' to be places in a row due to multiple spaces and also
        // prevents '-' to be placed at the beginning of the string
        if(isspace(temp) && (posOfSpinalStr == 0 || spinalStr[posOfSpinalStr - 1] == '-')) {
            posOfStr++;
            continue;
        }

        // stores a '-' whereever there is a space
        if(isspace(temp)) {
            spinalStr[posOfSpinalStr++] = '-';
            posOfStr++;
            continue;
        }
        
        // stores anyother character apart from spaces in spinal str in lowercase
        spinalStr[posOfSpinalStr++] = temp;
        posOfStr++;
    }

    // removes '-' at the end of the end of spinal str if it exists
    if(spinalStr[posOfSpinalStr - 1] == '-') {
        posOfSpinalStr--;
    }

    spinalStr[posOfSpinalStr] = '\0'; // marks the end of spinal str

    return spinalStr;
}

int main() {
    char str[] = "   This   is    spinal     case   ";
    printf("%s h\n", spinalCase(str));
    return 0;
}