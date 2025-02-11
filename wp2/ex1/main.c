#include "stdio.h"
#include "string.h"

#define END_CHAR 'q'            // set macro for end character;
#define MOVE 'm'                // set macro for move character;
#define TURN 't'                // set macro for turn character;
#define MAX_INST_SIZE 20        // set macro for maximum instructions size;
#define RUNNING 1               // set macro for boolean value of program running;
#define ENDED 0                 // set macro for boolean value of program ending;

enum DIRECTION {N,O,S,W};       // enum to represent robots directions;

typedef struct {                // structure to store robot;
    int xpos;                   // robot's x position;
    int ypos;                   // robot's y position;
    enum DIRECTION dir;         // robot's direction;
} ROBOT;


// --------------functions declaration-----------------
// Moves and turns given ROBOT rob according to the given set of instructions.
// Returns ENDED if end character was encountered and RUNNING otherwise.
int move_robot(ROBOT *rob, char *instructions);

// Turns given ROBOT rob clockwise;
void turn(ROBOT *rob);

// Moves given ROBOT rob 1 step in the direction its facing;
void move(ROBOT *rob);

// --------------functions defjnition------------------

int move_robot(ROBOT *rob, char *instructions){
    for (int i = 0; i < strlen(instructions); i++){                 // iterate over instructions;
        char command = instructions[i];                             // store current command in a var;
        if(command == MOVE){                                        // if command is MOVE ...
            move(rob);                                              // move robot;
        } else if (command == TURN){                                // else if command is TURN ...
            turn(rob);                                              // turn robot;
        } else if (command == END_CHAR){                            // else if command is END_CHAR ...
            printf("Closing the program. Have a nice day...");      // print exit message;
            return ENDED;                                           // exit fucntion with end code;
        } else {                                                    // for every other character encountered ...
            printf("ERROR: unknown command, try again.\n");         // print error message;
            return RUNNING;                                         // exit function with repeat code;
        }
    }
    printf("New robot position: %d, %d. \n", rob->xpos, rob->ypos); // print new robot coordinates;
    return RUNNING;                                                 // exit function with repeat code;
}


void turn(ROBOT *rob){
    switch (rob->dir){      // switch robot's direction
        case N:             // on North...
            rob->dir = O;   // turn to East;
            break;          // break;
        case O:             // on East...
            rob->dir = S;   // turn to South;
            break;          // break;
        case S:             // on South...
            rob->dir = W;   // turn to West;
            break;          // break;
        case W:             // on West...
            rob->dir = N;   // turn to North;
            break;          // break;
    }
}
// Updates the robot position based on the direction its facing
void move(ROBOT *rob){
    switch (rob->dir) {     // switch robot's direction;
        case N:             // on North...
            (rob->ypos)++;  // move up 1;
            break;          // break;
        case O:             // on East...
            (rob->xpos)++;  // move right 1;
            break;          // break;
        case S:             // on South...
            (rob->ypos)--;  // move down 1;
            break;          // break;
        case W:             // on West;
            (rob->xpos)--;  // move left 1;
            break;          // break;
    }

}


int main(){
    ROBOT rob;                                      // declare robot variable;
    char instructions[MAX_INST_SIZE];               // declare instructin String;
    int status = RUNNING;                           // declare bool for the main program loop;
    
    while (status == RUNNING){                      // loop program while stuatus is RUNNING;
        rob.dir = N;                                // initialise robot direction as North;
        rob.xpos = 0;                               // initialize robot x position as 0
        rob.ypos = 0;                               // initialize robot y position as 0
        printf("Enter starting position(x y) or enter 'q' to quit: ");   // print prompt for coordinates;
        scanf("%d %d", &rob.xpos, &rob.ypos);       // scan coordinates;
        if (rob.xpos < 0 || rob.xpos > 99 || rob.ypos < 0 || rob.ypos > 99) { // validate coordinates
            printf("ERROR: starting position coordinates must be in range 0..99");// print error message;
            continue;                               // repeat the loop
        }

        printf("Enter instructions: ");             // prompt instructions;
        scanf("%19s", instructions);                // scan instructions;
        status = move_robot(&rob, instructions);    // move robot or end the loop if end character is encountered;
    }


    return 0;                                       // exit the program
}

