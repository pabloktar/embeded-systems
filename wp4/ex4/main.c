#include "stdlib.h"
#include "stdio.h"

int search_number(int number, int tab[], int size);
void sort(int number, int tab[]);


void printArray(int tab[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void printSearch(int tab[], int size, int num){
    printf("Searching %d, result: %d\n", num, search_number(num, tab, size));
}

int main(void){
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    int size = 10;
    
    printf("Starting array: ");
    printArray(test, size);
    printSearch(test, size, 1); 
    printSearch(test, size, 34);
    printSearch(test, size, 0);
    printSearch(test, size, 10);
    printSearch(test, size, 100);

    printf("Sorting array...\n");
    sort(size, test);
    printf("Sorted array: ");
    printArray(test, size);

}

int search_number(int number, int tab[], int size){
    for (int i = 0; i < size; i++){
        if(tab[i] == number){
            return i;
        }
    }
    return -1;
}

void sort(int number, int tab[]){
    for(int i = 0; i < number - 1; i++) {
        int min_index = i;
        int min = tab[i];
        for(int j = i+1; j < number; j++) {
            if(min > tab[j]){
                min = tab[j];
                min_index = j;
            }
        }

        int tmp = tab[i];
        tab[i] = tab[min_index];
        tab[min_index] = tmp;

        
    }
}
