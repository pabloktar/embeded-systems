#include "stdio.h"

int main(int args, char **argv){
    if(args == 1){
        int num;
        scanf("%d", &num);
        printf("Number passed: %d", num);
    }
    else {
        printf("Number passed1: ");
        printf("%s", argv[1]);
    }

}
