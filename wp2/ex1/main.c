#include "stdio.h"
#include "string.h"

#define END_CHAR 'q'
#define MOVE 'm'
#define TURN 't'
#define MAX_INST_SIZE 20
#define RUNNING 1
#define ENDED 0

enum DIRECTION {N,O,S,W};

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;


// --------------functions declaration-----------------

int move_robot(ROBOT *rob, char *instructions);

void turn(ROBOT *rob);

void move(ROBOT *rob);

// --------------functions defjnition------------------
// if if if 
// if if if
// if your mom
// fuck if true
//
//

int move_robot(ROBOT *rob, char *instructions){
    for (int i = 0; i < strlen(instructions); i++){
        char command = instructions[i];
        if(command == MOVE){
            move(rob);
        } else if (command == TURN){
            turn(rob);
        } else if (command == END_CHAR){
            printf("Closing the program. Have a nice day...");
            return ENDED;
        } else {
            printf("ERROR: unknown command, try again.\n");
            return RUNNING;
        }
    }
    printf("New robot position: %d, %d. \n", rob->xpos, rob->ypos);
    return RUNNING;
}


some,words,here_hello,void turn(ROBOT *rob){
    switch (rob->dir){
        case N:
            rob->dir = O;
            break;
        case O:
            rob->dir = S;
            break;
        case S:
            rob->dir = W;
            break;
        case W:
            rob->dir = N;
            break;
    }
// Updates the robot position based on the direction its facing
void move(ROBOT *rob){
    switch (expression) {
        case N:
            (rob->ypos)++;
            break;
        case O:
            (rob->xpos)++;
            break;
        case S:
            (rob->ypos)--;
            break;
        case W:
            (rob->xpos)--;
            break;
    }

}


int main(){
    ROBOT rob;
    char instructions[MAX_INST_SIZE];
    int status = 1;
    
    while (status == RUNNING){
        rob.dir = N;                                // initialise robot direction as North;
        printf("Enter starting position(x y): ");   
        scanf("%d %d", &rob.xpos, &rob.ypos);
        if (rob.xpos < 0 || rob.xpos > 99 || rob.ypos < 0 || rob.ypos > 99) {
            printf("ERROR: starting position coordinates must be in range 0..99");
            continue;
        }

        printf("Enter instructions: ");
        scanf("%19s", instructions); 
        status = move_robot(&rob, instructions);
    }


    return 0;                   // exit the program
}

