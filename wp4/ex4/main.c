// (C) Pavlo Ovchynnykov, Stefan Tram, Danis Music, group 19 (2025)
// Work package 2
// Exercise 1
// Submission code: 953384
#include "stdlib.h"
#include "stdio.h"

// function searching for the given "number" in the given array "tab"
// of size "size", using the brude force algorithm;
int search_number(int number, int tab[], int size);

// function sorting the given array "tab" of size "number",
// using the selection sorting algorithm;
void sort(int number, int tab[]);

// helper function printing the contents of array "tab" of size "size";
void printArray(int tab[], int size){
    for (int i = 0; i < size; i++){     // iterate over elements of array;
        printf("%d ", tab[i]);          // print the element;
    }
    printf("\n");                       // new line;
}

// helper funciton annotating the search call;
void printSearch(int tab[], int size, int num){
    printf("Searching %d, result: %d\n", num, search_number(num, tab, size));
}

int main(void){
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10}; // test array;
    int size = 10;                                      // test array size;
    
    printf("Starting array: ");     // 
    printArray(test, size);         // print starting array;

    printSearch(test, size, 1);     // 
    printSearch(test, size, 34);    // 
    printSearch(test, size, 0);     // tests;
    printSearch(test, size, 10);    // 
    printSearch(test, size, 100);   // 

    printf("Sorting array...\n");
    sort(size, test);
    printf("Sorted array: ");
    printArray(test, size);

}


int search_number(int number, int tab[], int size){
    for (int i = 0; i < size; i++){     // iterate over array;
        if(tab[i] == number){           // compare the element with the searched number;
            return i;                   // print the element index if matches;
        }
    }
    return -1;                          // exit the function with "-1" return in case of no matches;
}

void sort(int number, int tab[]){
    for(int i = 0; i < number - 1; i++) {   // iterate over the array;
        int min_index = i;                  // initialise min_index as current index;
        int min = tab[i];                   // set min to current entry;
        for(int j = i+1; j < number; j++) { // iterate over the rest of the arrray;
            if(min > tab[j]){               // compare min to the j-entry;
                min = tab[j];               // if less, update min...
                min_index = j;              // and min_index;
            }
        }

        int tmp = tab[i];                   //
        tab[i] = tab[min_index];            // swap curren entry with min;
        tab[min_index] = tmp;               //

        
    }
}
