#include <stdio.h> // The I/O header file contains the necessary logic for printing and inputting information
#include <stdlib.h>
#include <string.h> // The string header file containts the necessary methods to interact with strings.
#include <ctype.h> // The ctype header file is used to identify the the type of the inputs aswell as changing the parameter to another data type.

#define MAX_8BIT_VALUE 255
#define MAX_16BIT_VALUE 65535
#define MAX_32BIT_VALUE 4294967295
#define MAX_64BIT_VALUE 18446744073709551615UL

#define byte1 8 
#define byte2 16
#define byte3 32
#define byte4 64

int smallestBitSize(unsigned long number);

int main(int argc, char **argv) {
    unsigned long userInput = atoi(argv[1]);
    int maxBits = smallestBitSize(userInput);
    int *binaryArray = calloc(maxBits, sizeof(int));
    int i = 0;


    while (userInput > 0) {
        binaryArray[i] = userInput % 2;
        userInput = userInput / 2;
        i++;
    }
    
    for (int j = maxBits - 1; j >= 0; j--) {
        printf("%d", binaryArray[j]);
        
    }
    
    return 0;
}

int smallestBitSize(unsigned long number) {
    if (number <= MAX_8BIT_VALUE) {
        return byte1;
    } else if (number <= MAX_16BIT_VALUE) {
        return byte2;
    } else if (number <= MAX_32BIT_VALUE) {
        return byte3;
    } else if (number <= MAX_64BIT_VALUE) {
        return byte4;
    }
    return byte4;
}
