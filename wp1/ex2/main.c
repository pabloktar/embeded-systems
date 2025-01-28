// (C) Pavlo Ovchynnykov, Stefan Tram, Danis Music, group 19 (2025)
// Work package 1
// Exercise 2
// Submission code: 452706
#include <stdio.h> // The I/O header file contains the necessary logic for printing and inputting information
#include <string.h> // The string header file containts the necessary methods to interact with strings.
#include <ctype.h> // The ctype header file is used to identify the the type of the inputs aswell as changing the parameter to another data type.

#define ALPHABET_SIZE 26 // Constant used as a divisor for the ASCII values for the alphabet.
#define BASE_10 10 // Constant used as a divisor for the ASCII values of the base 10

int main(int argc, char **argv) {
    char userInput[26]; // Where the message from the user will be stored to be encrypted later on.

    while (1) { // As long as something inside of the loop does not exit, keep going.
        printf("Please provide the message that will be encrypted: \n"); // Output to inform the user to provide their message.
         
        if (!fgets(userInput, sizeof(userInput), stdin)){ // If the input from the user is not a message (EOF), then exit the program.
            printf("End of line."); // Inform the user that the program ended with "End of line." message
            break; // Exit the loop and end the program.
        }
        
        printf("The provided input: %s\n", userInput); // Shows the input provided by the user.
        
        for (int i = 0; i < strlen(userInput); i++) { // Iterate for each character of the message provided by the user.
            if (isalpha(userInput[i])) { // Checks if the current character in the message is a letter.
                if (isupper(userInput[i])) { // Checks if the current letter is of uppercase
                    userInput[i] = 'A' + (userInput[i] - 'A' + atoi(argv[1])) % ALPHABET_SIZE; // Use the ASCII values aswell as the parameter to determine the encrypted uppercase letter.
                } else { // If the letter is not uppercase, then it must be lowercase.
                    userInput[i] = 'a' + (userInput[i] - 'a' + atoi(argv[1])) % ALPHABET_SIZE; // Use the ASCII values aswell as the parameter to determine the encrypted lowercase letter.
                }
            } else if (isdigit(userInput[i])) { // Checks if the current character is a number.
                userInput[i] = '0' + (userInput[i] - '0' + atoi(argv[1])) % BASE_10; // Use the ASCII values aswell as the parameter to determine the encrypted number.
            }
        }
        
        printf("Encrypted: %s\n", userInput); // Show the user the encrypted version of their input.
    }
    
    return 0; // Indicates that the system has run with no issues indicated.
}
