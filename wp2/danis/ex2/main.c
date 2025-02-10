#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #### Constants #####
#define MAX 5
#define MIN_NUM_VALUE 0
#define MAX_NUM_VALUE 99
// ##### typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);
int randNumMinMax(int min, int max);
// ###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); // Random seed
    head = random_list();
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    act_post = add_first(head, 69);
    printf("\n\n With new head:\n");
    nr = 0;

    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }
    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }
    return 0;
}
// ==== End of main ======================================
REGTYPE *random_list(void) {
    int nr, i = 0;
    REGTYPE *top, *old, *item;
    
    top = malloc(sizeof(REGTYPE));
    top->number = randNumMinMax(MIN_NUM_VALUE, MAX_NUM_VALUE); 
    top->next = NULL;
    top->prev = NULL;

    old = top;
    for (i = 0; i < MAX; i++) {
        item = malloc(sizeof(REGTYPE));
        item->number = randNumMinMax(MIN_NUM_VALUE, MAX_NUM_VALUE);
        item->next = NULL;
        item->prev = old;
        old->next = item;
        old = item;
    }
    

    return (top);
}
//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data) {

    REGTYPE *first = malloc(sizeof(REGTYPE));

    first->number = data;
    first->prev = NULL;
    first->next = temp;
    temp->prev = first;

    return first;
}

int randNumMinMax(int min, int max) { 
    return rand() % (max - min + 1) + min; // Uses the two int parameter values and using modulo generates a value within min and max values.
}