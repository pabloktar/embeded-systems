// (C) Pavlo Ovchynnykov, Stefan Tram, Danis Music, group 19 (2025)
// Work package 3
// Exercise 6
// Submission code: 631050
#include <stdio.h> // The I/O header file contains the necessary logic for printing and inputting information
#include <string.h> // The string header file containts the necessary methods to interact with strings.

#define MAX_CHAR_LIMIT 20 // Define character limit for input from console or file


// --- Function Prototypes ---
int check_input(char *userinput); 
void copyString(char *stringCopyTo, char *stringCopyFrom);
void clearstdin(void); // Clears the buffer of remaining characters


int main(int argc, char **argv) {
    char inputString[MAX_CHAR_LIMIT]; // Declare string to store input
    char copy[MAX_CHAR_LIMIT]; // Declare string to store copy
    
    if (fgets(inputString, MAX_CHAR_LIMIT, stdin) == NULL) { // If input cannot be read
        printf("Error, cannot parse input.\n"); // Show user error message
        return 0; // Exit the program
    } 

    if (check_input(inputString)) { // Check if the input is not valid
        return 0; // Exit the program
    }
    
    strcpy(copy, inputString); // Use inbuild string copy method
    printf("Original: %s | Copy: %s\n", inputString, copy); // Print out the original and the copy
    
    copyString(copy, inputString); // Use custom string copy method
    printf("Custom string copy method\n"); // Indicate that the custom method is being utilized
    printf("Original: %s | Copy: %s\n", inputString, copy); // Print out the original and the copy
    return 0; // Exit the program
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
    int i; // Declare i outside of loop to use it to add null terminator at the end
    for (int i = 0; i < strlen(stringCopyFrom); i++) { // Iterate over characters in the string to copy from
        stringCopyTo[i] = stringCopyFrom[i]; // Add value from string to copy from
    }
    stringCopyTo[i] = '\0'; // Add null terminator
    
}