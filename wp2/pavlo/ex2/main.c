#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5
#define MAX_VALUE 100

// ##### typedefs ####
typedef struct q{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main(int argc, char *argv[])
{
    int nr=0;
    REGTYPE *act_post , *head=NULL;
    srand(time(0)); // Random seed
    head=random_list();
    act_post=head;
    while( act_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, act_post->number);
        act_post=act_post->next;
    }
    
    printf("\n\nRun add_first() and adding 123...\n");
    head = add_first(head, 123);
    act_post = head;
    nr = 0;

    while( act_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, act_post->number);
        act_post=act_post->next;
    }


    // --- Free the allocated memory ---
    while((act_post=head)!=NULL){
        head=act_post->next;
        free(act_post);
    }
    return 0;
}
// ==== End of main ======================================


REGTYPE* random_list(void ){
    int nr, i=0;
    REGTYPE *top, *old, *item;

    if (MAX == 0){
        return NULL;
    }
    old = NULL;
    for (i = 0; i < MAX; i++){
        item = (REGTYPE*)malloc(sizeof(REGTYPE));
        if (i == 0) {
            top = item;
        }
        item->number = rand() % (MAX_VALUE+1);
        item->next = NULL;
        item->prev = old;
        
        if (old != NULL) {
            old->next = item;
        }
        old = item;
    }

    return(top);
}
//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
    REGTYPE *item = (REGTYPE*) malloc(sizeof(REGTYPE));

    item->number = data;
    item->next = temp;
    item->prev = NULL;

    temp->prev = item;

    return item;
}
