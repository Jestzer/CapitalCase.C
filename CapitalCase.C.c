#include <stdio.h>
#include <string.h>
#include <ctype.h>

void fixCapitalization(char *str) {
    int newWord = 1; // Flag to indicate the start of a new word

    // Loop through each character in the string.
    for (int i = 0; str[i] != '\0'; i++) {
        // If the current character is a space, the next character is the start of a new word.
        if (str[i] == ' ') {
            newWord = 1;
        } else if (newWord) { // Capitalize the first letter of a word.
            str[i] = toupper(str[i]);
            newWord = 0;
        } else { // Make sure the rest of the word is lowercase.
            str[i] = tolower(str[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    // Check if there are less than 3 arguments. If so, you did something wrong.
    if (argc < 3) {
        printf("Usage: %s -c \"text to change capitalization\"\n", argv[0]);
        return 1;
    }

    // Look for the "-c" option in the arguments.
    for (int i = 1; i < argc - 1; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            // Capitalize the next argument.
            fixCapitalization(argv[i + 1]);
            printf("%s\n", argv[i + 1]);
            return 0;
        }
    }

    printf("The argument '-c' was found used. Usage: %s -c \"text to change capitalization\"\n");
    return 1;
}