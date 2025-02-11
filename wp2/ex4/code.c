#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define byte unsigned char  // macro for byte type;
#define bit0 0b1            // |
#define bit1 0b10           // |
#define bit2 0b100          // |
#define bit3 0b1000         // | macros for bits 0 to 7;
#define bit4 0b10000        // |
#define bit5 0b100000       // |
#define bit6 0b1000000      // |
#define bit7 0b10000000     // |

enum ARGV{ENGINE_ON = 1, GEAR_POS = 2, KEY_POS = 3, BRAKE1 = 4, BRAKE2 = 5};// enum for data indexes;


// Funciton to check the input to be the number in range from 0 to "range";
// Input format: 
//  - str: input string;
//  - range: allowed range of the input;
int checkInput(char *str, int range){
    if (strlen(str) > 1){       // only allow one digit inputs;
        return 0;               // exit the function with error code;
    }
    char c = str[0];            // convert string to char;
    if (c < '0' || c > '9'){    // only allow digit inputs;
        return 0;               // exit the function with error code;
    }
    int num = c - '0';          // convert char to int;
    if (num > range){           // allow only the nubmers in the 0.."range";
        return 0;               // exit the funtion with error code;
    }
    return 1;                   // exit the function;
}

int main (int argc, char **argv){
    if (argc != 6){                                 // check if the number of arguments provided is exactly 5;
        printf("ERROR: number of arguments provided is not supported.");// print error message;
        return 1;                                   // exit the program with error code 2;
    }

    int ranges[6] = {0, 1, 4, 2, 1, 1};             // declare the ranges for encoded values;
    int intArgv[6] = {0, 0, 0, 0, 0, 0};            // declare array to store argv as ints;

    for (int i = ENGINE_ON; i <= BRAKE2; i++) {     // loop through arguments;
        if (checkInput(argv[i], ranges[i])) {       // verify the argument;
            intArgv[i] = atoi(argv[i]);             // convert argv from String to int;
        } else {
            printf("ERROR: wrong argument format"); // print error message;
            return 2;                               // exit program with error code 2;
        }
    }

    byte code = 0;                                  // initialise code;
    
    code = code | (bit7 * intArgv[ENGINE_ON]);      // encode ENGINE_ON;
    code = code | (bit4 * intArgv[GEAR_POS]);       // encode GEAR_POS;
    code = code | (bit2 * intArgv[KEY_POS]);        // encode KEY_POS;
    code = code | (bit1 * intArgv[BRAKE1]);         // encode BRAKE1;
    code = code | (bit0 * intArgv[BRAKE2]);         // encode BRAKE2;
    
    printf("%X", code);             // print hexadecimal code;

    return 0;                       // exit the program
}
