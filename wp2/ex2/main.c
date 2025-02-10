#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5          // Number of nodes to be created in the linked list
#define MAX_VALUE 100  // Maximum value for random numbers in the nodes

// ##### typedefs ####
typedef struct q{   // Structure definition for a doubly linked list node
    int number;     // Integer stored in the node
    struct q *next; // Pointer to the next node
    struct q *prev; // Pointer to the previous node
} REGTYPE;

// ##### Function declarations #####
REGTYPE* random_list(void);                     // Function to create a linked list with random numbers
REGTYPE* add_first(REGTYPE* temp, int data);    // Function to add a new node at the beginning of the list

//###### Main program #######
int main(int argc, char *argv[])
{
    int nr=0;                       // Counter for numbering the nodes while printing
    REGTYPE *act_post , *head=NULL; // Pointer for traversing and head of the list
    srand(time(0));                 // Initialize random number generator with current time as seed
    head = random_list();           // Create the linked list with random values
    act_post = head;                // Set the pointer to the head of the list
    while( act_post != NULL){       // Print the original linked list
        printf("\n Post nr %d : %d" , nr++, act_post->number); // Print the current node's index and value, then increment 'nr'
        act_post = act_post->next; // Move to the next node
    }
    
    printf("\n\nRun add_first() and adding 123...\n"); // Inform the user that a new node with value 123 is being added at the beginning of the list
    head = add_first(head, 123); // Add a new node with value 123 at the beginning
    act_post = head; // Reset pointer to the new head
    nr = 0; // Reset counter

    // Print the updated linked list after adding new node at the beginning
    while( act_post != NULL){
        printf("\n Post nr %d : %d" , nr++, act_post->number); // Print the current node's index and value, then increment 'nr'
        act_post = act_post->next; // Move to the next node
    }

    // --- Free the allocated memory ---
    while((act_post = head) != NULL){ // Loop through the list and free allocated memory
        head = act_post->next; // Move head to the next node
        free(act_post); // Free the memory of the current node
    }

    return 0; // Exit the program with code 0
}
// ==== End of main ======================================


// Function to create a doubly linked list with MAX nodes, each having a random value
REGTYPE* random_list(void){
    int nr, i = 0; // Loop counter
    REGTYPE *top, *old, *item; // Pointers to manage the linked list

    if (MAX == 0){ // If MAX is 0, return NULL to indicate an empty list
        return NULL;
    }

    old = NULL;                                     // Initialize previous pointer as NULL
    for (i = 0; i < MAX; i++){                      // Loop to create MAX nodes
        item = (REGTYPE*)malloc(sizeof(REGTYPE));   // Allocate memory for new node
        if (i == 0) {                               // If this is the first node, assign it as the top (head)
            top = item;                             // Store the first node in 'top' to keep track of the head of the list
        }
        item->number = rand() % (MAX_VALUE+1);      // Assign a random number between 0 and MAX_VALUE
        item->next = NULL;                          // Initially set next pointer to NULL
        item->prev = old;                           // Set previous pointer to the last node
        
        if (old != NULL) {                          // If not the first node, link the previous node to the current node
            old->next = item;                       // Link the previous node ('old') to the newly created node ('item')
        }

        old = item; // Move the old pointer to the newly created node
    }

    return(top); // Return the head of the list
}
//==========================================================

// Function to add a new node at the beginning of the doubly linked list
REGTYPE* add_first(REGTYPE* temp, int data){
    REGTYPE *item = (REGTYPE*) malloc(sizeof(REGTYPE)); // Allocate memory for new node

    item->number = data; // Assign the given data to the new node
    item->next = temp; // Link new node's next to the old head
    item->prev = NULL; // Since it's the first node, prev is NULL

    temp->prev = item; // Update the previous pointer of the old head to the new node

    return item; // Return the new head of the list
}
