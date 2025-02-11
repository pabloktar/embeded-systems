#include <stdio.h>
#include <string.h>

#define MAX_CHAR_LIMIT 20

void copyString(char *stringCopyTo, char *stringCopyFrom);

int main(int argc, char **argv) {
    char inputString[MAX_CHAR_LIMIT];
    char copy[MAX_CHAR_LIMIT];
    
    if (fgets(inputString, MAX_CHAR_LIMIT, stdin) == NULL) {
        if (feof(stdin)) {
            printf("Error, reached end of file.\n");
        } else {
            printf("Error, cannot parse input.\n");
        }
        return -1;
    } 

    strcpy(copy, inputString);
    printf("Original: %s | Copy: %s\n", inputString, copy);
    
    copyString(copy, inputString);
    printf("Custom string copy method\n");
    printf("Original: %s | Copy: %s\n", inputString, copy);
    return 0;
}


void copyString(char *stringCopyTo, char *stringCopyFrom) {
    int i;
    for (i = 0; i < strlen(stringCopyFrom); i++) {
        stringCopyTo[i] = stringCopyFrom[i];
    }
    stringCopyTo[i] = '\0';
    
}