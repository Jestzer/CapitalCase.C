#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void fixCapitalization(char *str) {
    int newWord = 1; // Flag to indicate the start of a new word.

    // Loop through each character in the string.
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') { // If the current character is a space, the next character is the start of a new word.
            newWord = 1;
        } else if (newWord) { // Capitalize the first letter of a word.
            str[i] = (char)toupper((unsigned char)str[i]);
            newWord = 0;
        } else { // Make sure the rest of the word is lowercase.
            str[i] = (char)tolower((unsigned char)str[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    // Check if there are less than 2 arguments. If so, you did something wrong.
    if (argc < 2) {
        printf("Usage: execute the program followed by the text you want to change. Ex: %s MAKE ME NOT ALL UPPERCASE\n", argv[0]);
        return 1;
    }

    // Calculate the total length of all arguments combined.
    int totalLength = 0;
    for (int i = 1; i < argc; i++) {
        totalLength += strlen(argv[i]) + 1; // Need to add 1 for null space or terminator.
    }

    // Allocate memory for the combined string.
    char *combinedStr = (char *)malloc(totalLength * sizeof(char));
    if (combinedStr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Combine all arguments into a single string.
    combinedStr[0] = '\0'; // Create the combined string.
    for (int i = 1; i < argc; i++) {
        strcat(combinedStr, argv[i]);
        if (i < argc - 1) {
            strcat(combinedStr, " ");
        }
    }

    // Capitalize the combined string.
    fixCapitalization(combinedStr);
    printf("%s\n", combinedStr);

    // Free the allocated memory, cuz C!
    free(combinedStr);

    return 0;
}