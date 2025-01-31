#include "stdio.h"          // include standard input/output header
#include "stdlib.h"         // include standard library 
#include "string.h"         // include string header
#include "limits.h"         // include types limits header

// print dec number as a binary  
void printNum2bin(int num){
    int bit_mask = INT_MAX ^ (INT_MAX >> 1);// mask of the larges bit for INT 
    
    while (bit_mask > num){     // while bit_mask bigger than num ... 
        bit_mask = bit_mask >> 1;          // ... shift bit to the right 
    }
    while (bit_mask > 0){       // loop while num is bigger than 0
        if (bit_mask & num) {   // if num has the bit ... 
            printf("%d", 1);    // ... print 1  
        } else {                // else ... 
            printf("%d", 0);    // print 0
        }
        bit_mask = bit_mask >> 1;    // shift notNum right
    }
}


// count number of zeros and ones of a given number 
void countZerosAndOnes(int num, int *numOfZeros, int *numOfOnes){
    while (num > 0){        // loop while number bigger than 0
        if (num % 2 == 0){  // if the bit is 0
            (*numOfZeros)++;// increment numOf0s
        }
        else {              // else 
            (*numOfOnes)++; // increment numOf1s
        }
        num = num >> 1;     // shift number to the right
    }
}

int main(int argc, char **argv){
    if(argc < 2){                           // check if the argument provided
        printf("Error: No number provided. Please provide a number as a command line argument.");     // print error message
        return 0;                           // exit the program
    }
    
    for(int i = 0; i < strlen(argv[1]); i++){// check if the argument is a number
        if(argv[1][i] < '0' || argv[1][i] > '9'){ // check if particular symbol is a not digit
            printf("Error: Invalid number.");// print error message
            return 0;                       // exit the program
        }
    }
    int num = atoi(argv[1]);                //store argument as a number
    printf("Number: %d\n", num);            // print number provided

    printf("Binary: 0b");                   //print number in binary(1)
    printNum2bin(num);                      //print number in binary(1)
    printf("\n");                           //print number in binary(1)
    
    int numOfZeros = 0;                     // var to store number of zeros
    int numOfOnes = 0;                      // var to store number of ones 

    countZerosAndOnes(num, &numOfZeros, &numOfOnes);// count zeros and ones 
    printf("Number of 0s: %d\n", numOfZeros);// print number of zeros 
    printf("Number of 1s: %d\n", numOfOnes);// print number of ones 
    
    return 0;                               // exit the program
}
