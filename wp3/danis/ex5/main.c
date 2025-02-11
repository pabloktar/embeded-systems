
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define MIN_INT_VALUE 1
#define MAX_INT_VALUE 99

// ---- Function Prototypes ----
int randNumMinMax(int min, int max);

int main(int argc, char**argv) {
    int intArray[MAX_ELEMENTS];
    srand(time(0)); // Random seed


    for (int i = 0; i < MAX_ELEMENTS; i++) {
        intArray[i] = randNumMinMax(MIN_INT_VALUE, MAX_INT_VALUE);
    }

    printf("-----------------< General Info on Array >-----------------\n");
    printf("The value of the address of the array (pointer) is:  %p\n", &intArray);
    printf("First integer in the array is: %d\n", intArray[0]);
    printf("The last integer in the array is: %d\n", intArray[MAX_ELEMENTS - 1]);
    printf("The size of an integer (number of bytes) is: %d\n", (int)sizeof(int));
    printf("The size of the whole array in bytes is: %d\n", (int)sizeof(int) * MAX_ELEMENTS);
    printf("-----------------< Specific Info on Array Elements >-----------------\n");
    printf("\nNormal Values: \n\n");
    int *pointer = &intArray[0];
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("This is the %d integer in array with value: %d\n", i + 1, *pointer);
        pointer++;
    }

    pointer = intArray;
    printf("\nValues Multiplied by Two: \n\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("This is the %d integer in array with value: %d\n", i + 1, *pointer * 2);
        pointer++;
    }

    return 0;
    
}

int randNumMinMax(int min, int max) { 
    return rand() % (max - min + 1) + min; // Uses the two int parameter values and using modulo generates a value within min and max values.
}