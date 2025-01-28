#include <stdio.h>
#include <stdlib.h>

#define bit4 15
#define A 10

int main(int argc, char**argv){
    long int bin, i = 1;
    long int hex = 0;
    

    if(argc > 1){
        bin = atoi(argv[1]);
    } else {
        scanf("%d", &bin);
    }
    
        
    while (bin > 0){
        int rem = bin % 10;
        hex = hex + rem * i;
        i = i * 2;
        bin = bin / 10;
    }

    printf("Equivalent hexadecimal value: %lX", hex);
    return 0;
}
