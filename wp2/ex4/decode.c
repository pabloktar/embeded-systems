#include "stdio.h"
#include "stdlib.h"

#define bit0 0b1
#define bit1 0b10
#define bit2 0b100
#define bit3 0b1000
#define bit4 0b10000
#define bit5 32
#define bit6 64
#define bit7 128


enum DATA{ENGINE_ON = 0, GEAR_POS = 1, KEY_POS = 2, BRAKE1 = 3, BRAKE2 = 4};

int decoder (int code, char* decode){
    if(code < 0 | code > 255){
        return 1;
    }
    decode[ENGINE_ON] = (code & bit7) / bit7;
    if(decode[ENGINE_ON] > 1) return 1;

    decode[GEAR_POS] = (code & (bit6 | bit5 | bit4)) / bit4;
    if(decode[GEAR_POS] > 4) return 1;

    decode[KEY_POS] = (code & (bit3 | bit2)) / bit2;
    if(decode[KEY_POS] > 2) return 1;

    decode[BRAKE1] = (code & bit1) / bit1;
    if(decode[BRAKE1] > 1) return 1;

    decode[BRAKE2] = code & bit0;
    if(decode[BRAKE2] > 1) return 1;
    return 0;
}

void printDecode (int code, int (*decoder)(int, char*)) {
    char decode[] = "00000";
    if (decoder(code, decode) != 0) {
        printf("ERROR: faulty input detected");
        return;
    } 

    printf("%-20s%-20s\n", "Name", "Value");
    printf("%s\n", "-----------------------------");
    printf("%-20s%d\n", "engine_on", decode[0]);
    printf("%-20s%d\n", "gear_pos", decode[1]);
    printf("%-20s%d\n", "key_pos", decode[2]);
    printf("%-20s%d\n", "brake1", decode[3]);
    printf("%-20s%d\n", "brake2", decode[4]);
}


int main (int argc, char **argv){
    if (argc != 2){
    printf("ERROR: too many or too little arguments.");
        return 2;
    }
    int code = (int) strtol(argv[1], NULL, 16);
    
    //for(unsigned char bit = 128; bit > 0; bit >>= 1) printf("%d", (bit&code) && 1);
    
    printDecode(code, decoder);
}
