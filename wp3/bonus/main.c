#include "stdio.h"

int main (void ){
    int n, m;                                   // declare matrixes size;
    printf("Input the size: ");                 // prompt matrixes size;
    if(scanf("%d%d", &n, &m) != 2){             // scan matrixes size and check input;
        printf("invalid");                 // print error message;
        return 0;                               // exit program;
    }
    if(n < 0 || n > 4 || m < 0 || m > 4){       // verify matrixes size;
        printf("invalid");                 // print error message;
        return 0;                               // exit program;
    }
    
    int mtrx1[4][4], mtrx2[4][4];               // declare matrixes;
    printf("Input elements of matrix 1: ");     // prompt first matrix;
    for(int i = 0; i < n; i++){                 // iterate over rows;
        for(int j = 0; j < m; j++){             // iterate over columns;
            if(scanf("%d", &mtrx1[i][j]) != 1) {// scan matrix element [i][j] and check input;
                printf("invalid");         // print error message;
                return 0;                       // exit program;
            }
        }
    }

    printf("Input elements of matrix 2: ");     // prompt second matrix;
    for(int i = 0; i < n; i++){                 // iterate over rows;
        for(int j = 0; j < m; j++){             // iterate over columns;
            if(scanf("%d", &mtrx2[i][j]) != 1){ // scan matrix element[i][j] and check input;
                printf("invalid");         // print error message;
                return 0;                       // exit program;
            }
        }
    }

    printf("The sum is: \n");                   // print result message;
    for(int i = 0; i < n; i++){                 // iterate over rows;
        for(int j = 0; j < m; j++){             // iterate over columns;
            printf("%d", mtrx1[i][j] + mtrx2[i][j]);// print the matrix sum for the cell [i][j];
            printf(" ");                        // print tabulation " ";
        }
        printf("\n");                           // print tabulation new line at the and of the row;
    }

}
