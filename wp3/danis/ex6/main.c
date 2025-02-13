#include <stdio.h>
#include <string.h>

#define MAX_CHAR_LIMIT 20

int check_input(char *userinput);
void copyString(char *stringCopyTo, char *stringCopyFrom);
void clearstdin(void); // Clears the buffer of remaining characters


int main(int argc, char **argv) {
    char inputString[MAX_CHAR_LIMIT];
    char copy[MAX_CHAR_LIMIT];
    
    if (fgets(inputString, MAX_CHAR_LIMIT, stdin) == NULL) {
        printf("Error, cannot parse input.\n");
        return 0;
    } 

    if (check_input(inputString)) {
        return 0;
    }
    
    
    strcpy(copy, inputString);
    printf("Original: %s | Copy: %s\n", inputString, copy);
    
    copyString(copy, inputString);
    printf("Custom string copy method\n");
    printf("Original: %s | Copy: %s\n", inputString, copy);
    return 0;
}

// Clears the buffer of characters 
void clearstdin(void) {
    char temp; // Declare the variable that is going to store a character from the buffer
    while ((temp = getchar()) != '\n' && temp != EOF); // As long as the character is not a return character or an end of file character, iterate.   
}

int check_input(char *userinput) {
    _Bool errorFound = 0; // Declare and initialize a variable indidacting the error status of input 

    if (strchr(userinput, '\n') == NULL && !feof(stdin)) { // Checks if the user input has a newline character and that its the end of file
        printf("Error, input is over the character limit.\n"); // Shows user error message indicating that the input has to many characters
        clearstdin(); // Clean the buffer
        errorFound = 1; // Indicate an error occurred by assigning the value one to variable
    }

    if (userinput[0] == '\n') { // Checks if user input only has the newline character
        printf("Error, you did not put in any value.\n"); // Shows user error message indicating no 'real' values were put in input
        errorFound = 1; // Indicate an error occurred by assigning the value one to variable
    }
    
    userinput[strcspn(userinput, "\n")] = 0; // Replace newline character with empty character to reset input buffer
    return errorFound; // Return the status of the input
}

void copyString(char *stringCopyTo, char *stringCopyFrom) {
    int i;
    for (i = 0; i < strlen(stringCopyFrom); i++) {
        stringCopyTo[i] = stringCopyFrom[i];
    }
    stringCopyTo[i] = '\0';
    
}