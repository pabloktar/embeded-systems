#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100 // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers


// ------ Function declarations ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab );

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq );

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq );

int calc_int_length(int num);

// ------ Function definitions ----------
void create_random(int *tab ){
    for (int i = 0; i < MAX; i++){          // iterate over the indicies of *tab 
        tab[i] = rand() % (MAXNUMBER + 1);  // initialise a cell in *tab with a random number in range 0..MAXNUMBER
    }
}

void count_frequency(int *tab, int *freq ){
    for (int i = 0; i <= MAXNUMBER; i++){   // iterate over the indicies of *freq
        freq[i] = 0;                        // initialise each cell in *freq with 0
    }
    for (int i = 0; i < MAX; i++){          // iterate over the indicies of *tab
        freq[tab[i]]++;                     // increment frequency of tab[i] 
    }
}

void draw_histogram(int *freq) {
    for (int i = 0; i <= MAXNUMBER; i++){   // iterate over all numbers in range 0..MAXNUMBER
        if (freq[i] != 0) {                 // check if the number appears at least once 
            printf("%-4d", i);              // print number, aligning it to the left 
            for (int j = 0; j < freq[i]; j++){// iterate freq[i] times ... 
                printf("x");                // ... and print "x" each iteration 
            }
            printf("\n");                   // new line to end the bar 
        }
    }
}

// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main (void){
    int table[MAX], n ;
    int frequency[MAXNUMBER+1];
    
    srand(time(0));                         // set a random seed for RNG

    create_random(table);                   // step 1: fill table with random numbers 
    count_frequency(table, frequency);      // step 2: calculate numbers frequencies 
    draw_histogram(frequency);              // step 3: draw frequency histogram 

    return 0;                               // exit the program
}

