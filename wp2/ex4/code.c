#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define byte unsigned char
#define bit0 0b1
#define bit1 0b10
#define bit2 0b100
#define bit3 0b1000
#define bit4 0b10000
#define bit5 0b100000
#define bit6 0b1000000
#define bit7 0b10000000

enum ARGV{ENGINE_ON = 1, GEAR_POS = 2, KEY_POS = 3, BRAKE1 = 4, BRAKE2 = 5};

int checkInput(char *str, int range){
    if (strlen(str) > 1){
        return 0;
    }
    char c = str[0];
    if (c < '0' || c > '9'){
        return 0;
    }
    char num = c - '0';
    if (num > range){
        return 0;
    }
    return 1;
}

int main (int argc, char **argv){
    if (argc != 6){                 // check if the number of arguments provided is exactly 5;
        printf("ERROR: number of arguments provided is not supported.");// print error message;
        return 1;                   // exit the program with error code 2;
    }

    int ranges[6] = {0, 1, 4, 2, 1, 1};
    int intArgv[6] = {0, 0, 0, 0, 0, 0};

    for (int i = ENGINE_ON; i <= BRAKE2; i++) {
        if (checkInput(argv[i], ranges[i])) {
            intArgv[i] = atoi(argv[i]);
        } else {
            printf("ERROR: wrong argument format");
            return 2;
        }
    }

    byte code = 0;
    
    code = code + bit7 * intArgv[ENGINE_ON];
    code = code + bit4 * intArgv[GEAR_POS];
    code = code + bit2 * intArgv[KEY_POS];
    code = code + bit1 * intArgv[BRAKE1];
    code = code + bit0 * intArgv[BRAKE2];
    
    printf("%X", code);

    return 0;                       // exit the program
}
