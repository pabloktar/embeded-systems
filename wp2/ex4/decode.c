// (C) Pavlo Ovchynnykov, Stefan Tram, Danis Music, group 19 (2025)
// Work package 2
// Exercise 4
// Submission code: 246649
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define bit0 0b1        // |
#define bit1 0b10       // |
#define bit2 0b100      // |
#define bit3 0b1000     // | macros for bits from 0 to 7;
#define bit4 0b10000    // |
#define bit5 32         // |
#define bit6 64         // |
#define bit7 128        // |


enum DATA{ENGINE_ON = 0, GEAR_POS = 1, KEY_POS = 2, BRAKE1 = 3, BRAKE2 = 4};// enum for DATA;


// Decoder function. Takes the code in and writes the decoded data in the decode array;
int decoder (int code, char* decode){
    if((code < 0) | (code > 255)){                              // verify that code fits a byte;
        return 1;                                           // exit function with error code; 
    }
    decode[ENGINE_ON] = (code & bit7) / bit7;               // decode ENIGINE_ON bit;
    if(decode[ENGINE_ON] > 1) return 1;                     // verify ENGINE_ON value;

    decode[GEAR_POS] = (code & (bit6 | bit5 | bit4)) / bit4;// decode GEAR_POS bits;
    if(decode[GEAR_POS] > 4) return 1;                      // verify GEAR_POS value;

    decode[KEY_POS] = (code & (bit3 | bit2)) / bit2;        // decode KEY_POS bits;
    if(decode[KEY_POS] > 2) return 1;                       // verify KEY_POS value;

    decode[BRAKE1] = (code & bit1) / bit1;                  // decode BRAKE1 bit;
    if(decode[BRAKE1] > 1) return 1;                        // verify BRAKE1 value;

    decode[BRAKE2] = code & bit0;                           // decode BRAKE2 bit;
    if(decode[BRAKE2] > 1) return 1;                        // verify BRAKE2 value;
    return 0;                                               // exit the function;
}

// Function to print decoded data. Takes code and the decoder function as parameters;
void printDecode (int code, int (*decoder)(int, char*)) {
    char decode[] = "00000";                        // initialise decode string;
    if (decoder(code, decode) != 0) {               // verify decoder output
        printf("ERROR: faulty input detected");     // print error message;
        return;                                     // exit the funciton;
    }

    printf("%-20s%-20s\n", "Name", "Value");        // print table headers;
    printf("%s\n", "-----------------------------");// print separator line;
    printf("%-20s%d\n", "engine_on", decode[0]);    // print engine_on line;
    printf("%-20s%d\n", "gear_pos", decode[1]);     // print gear_pos line;
    printf("%-20s%d\n", "key_pos", decode[2]);      // print key_pos line;
    printf("%-20s%d\n", "brake1", decode[3]);       // print brake1 line;
    printf("%-20s%d\n", "brake2", decode[4]);       // print brake2 line;
}


int main (int argc, char **argv){
    if (argc != 2){                                     // check the number of arguments; 
        printf("ERROR: too many or too little arguments.");// print the error message;
        return 2;                                       // exit the program with error code;
    }
    char *endptr;
    int code = (int) strtol(argv[1], &endptr, 16);         // convert argument to int;
    
    if (*endptr != '\0' || argv[1] == endptr) {            // verify the code;
        printf("ERROR: bad input.");                    // print error message;
        return 2;                                       // exit the program with error code;
    }

    printDecode(code, decoder);                         // print decoded data or error;
    return 0;                                           // exit the program;
}
