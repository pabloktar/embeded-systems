// (C) Pavlo Ovchynnykov, Stefan Tram, Danis Music, group 19 (2025)
// Work package 3
// Exercise 5
// Submission code: 631050
#include <stdio.h> // The I/O header file contains the necessary logic for printing and inputting information
#include <stdlib.h> // header file that defines certain types and macros 
#include <time.h> // header file for macros and types for manipulating time

#define MAX_ELEMENTS 10 // Max elements allowed for the int array
#define MIN_INT_VALUE 1 // Minimum allowed value for a random num in array
#define MAX_INT_VALUE 99 // Maximum allowed value for a random num in array

// ---- Function Prototypes ----
int randNumMinMax(int min, int max); // Function for getting a random number within a range

int main(int argc, char**argv) {
    int intArray[MAX_ELEMENTS]; // Declare int array for storing the random numbers
    srand(time(0)); // Random seed 


    for (int i = 0; i < MAX_ELEMENTS; i++) { // For every index in int array
        intArray[i] = randNumMinMax(MIN_INT_VALUE, MAX_INT_VALUE); // Create and store a random number
    }

    printf("-----------------< General Info on Array >-----------------\n"); // Start of info
    printf("The value of the address of the array (pointer) is:  0x%p\n", &intArray); // Show the memory address of int array
    printf("First integer in the array is: %d\n", intArray[0]); // Show the first integer in int array
    printf("The last integer in the array is: %d\n", intArray[MAX_ELEMENTS - 1]); // Show the last integer in int array
    printf("The size of an integer (number of bytes) is: %d\n", (int)sizeof(int)); // Show the size of an integer in number of bytes 
    printf("The size of the whole array in bytes is: %d\n", (int)sizeof(int) * MAX_ELEMENTS); // Show the size of the int array in bytes
    printf("-----------------< Specific Info on Array Elements >-----------------\n"); // End of info
    printf("\nNormal Values: \n\n"); // Show values not multiplied
    int *pointer = &intArray[0]; // Declare and initialize pointer pointing to first value in memory address of array
    for (int i = 0; i < MAX_ELEMENTS; i++) { // iterate over the elements in the array
        printf("This is the %d integer in array with value: %d\n", i + 1, *pointer); // Show the index aswell as value of integer
        pointer++; // Increment pointer
    }

    pointer = intArray; // Reset the pointer back to the start
    printf("\nValues Multiplied by Two: \n\n"); // Show values multiplied by 2
    for (int i = 0; i < MAX_ELEMENTS; i++) { // Iterate over the elements in the array
        printf("This is the %d integer in array with value: %d\n", i + 1, *pointer * 2); // Show the index aswell as the value of integer multiplied by 2
        pointer++; // Increment pointer
    }

    return 0; // Exit the program
    
}

int randNumMinMax(int min, int max) { 
    return rand() % (max - min + 1) + min; // Uses the two int parameter values and using modulo generates a value within min and max values.
}