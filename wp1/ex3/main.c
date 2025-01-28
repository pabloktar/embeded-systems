// (C) Pavlo Ovchynnykov, Stefan Tram, Danis Music, group 19 (2025)
// Work package 1
// Exercise 3
// Submission code: 452706
// #include <stdio.h> // The I/O header file contains the necessary logic for printing and inputting information
#include <stdlib.h>
#include <string.h> // The string header file containts the necessary methods to interact with strings.
#include <ctype.h> // The ctype header file is used to identify the the type of the inputs aswell as changing the parameter to another data type.
#include <time.h>  // Time header used to get a seed for RNG

#define MAX_NUM_GUESSES 10  // max number of guesses given to user
#define MAX_INPUT_NUM 100   // upper limit of generated number
#define MIN_INPUT_NUM 1     // lower limit of generated number
#define MAX_INPUT_LEN 100   

#define bool int            // macro for boolean
#define true 1              // macro for true 
#define false 0             // macro for false 

int randNumMinMax(int min, int max);


// play a round of a guessing game with user 
void play_round() {
    int user_guesses = 0;                               // user guesses counter
    int randomNumber = randNumMinMax(MIN_INPUT_NUM, MAX_INPUT_NUM);// generate a number for the game  
    char userInput[MAX_INPUT_LEN];                                 // Array to store the user's input
    while (user_guesses < MAX_NUM_GUESSES) {// play while the guess counter hasn't exceeded the limit 

        int isNumber = 1;                   // Flag to check if the input is a valid number
        printf("Put in your guess: ");      // Print message to user to put i ntheir guess
        fgets(userInput, MAX_INPUT_NUM, stdin); // Get the user's input
        
        if (userInput[strlen(userInput) - 1] == '\n') { // Check if the last character of the input is a newline
            userInput[strlen(userInput) - 1] = '\0';   // Replace the newline character with a null terminator
        }

        for (int i = 0; i < strlen(userInput); i++) {           // Loop to check if each character is an integer
            if (!isdigit((int)userInput[i])) {                  // Check if the current character is an integer
                isNumber = 0;                                   // If current character is not a integer, set isNumber = 0 (act as false in boolean)
                break;                                          // Break out of loop
            }
        }

        if (!isNumber) {                                        // Check if user input contained a non-integer
            printf("The input should only contain a number.\n");// Print warning message if user input is not an integer
            continue;                                           // Skip the loop iteration
        }

        int guess = atoi(userInput);

        if (guess < MIN_INPUT_NUM || guess > MAX_INPUT_NUM) {   // Checker for if guess is within threshold
            printf("The number provided was not within the 1-100 threshold.\n");  // Print warning message if message user input is not within given range
            continue;                                           // Skip the loop iteration
        }

        user_guesses++;                         // increment the guesses number at the start of the round

        if (guess == randomNumber) {                    // if user guesses correctly... 
            printf("You have guessed %d times and your guess is correct!\n", user_guesses); // print victory message & 
            return;                                     // exit function
        } else if(guess < randomNumber) {               // else if the guess is too low ...
            printf("Your guess is too low, please try again\n"); // print that the number is bigger
        } else if (guess > randomNumber) {              // else if the guess is too high ... 
            printf("Your guess is too high, please try again\n");// print that the number is smaller 
        }
    }

    printf("You have exceeded the maximum number of guesses"); // print loss message
    return;                                             // exit function

}

int main(int argc, char **argv) {                        

    srand(time(0));                                     // set a seed for RNG based on time
    
    bool play_again = false;                                // bool to check if user wants to play again
    do {                                                    // start the game 
        play_round();
        
        printf("Play again? 1-yes, 0-no: ");                // prompt player if they want to play again 
        scanf("%d", &play_again);                           // save players decisicion
        while (getchar() != '\n');                          // clear buffer until next new line (we don't have a input checker here)
        
    } while (play_again);                                   // loop if player decides to play again
    
    return 0;                                               // exit the program
}

int randNumMinMax(int min, int max) {                       // get a random number in range min..max 
    return rand() % (max - min + 1) + min;                  // generate a random number in range min..max
}
