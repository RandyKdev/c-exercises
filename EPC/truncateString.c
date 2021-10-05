#include <stdio.h>
#include <string.h>

char *truncateString(char *str, const int maxLength) {
    int lengthOfStr = strlen(str); // computes the length of str
    
    // checks if length of str is more than the max length required
    if(lengthOfStr > maxLength) {
        str[maxLength] = '\0'; // truncates str
    }

    return str;
}

int main() {
    char str[] = "Hey I am just a string";
    printf("%s\n", truncateString(str, 70));

    return 0;
}