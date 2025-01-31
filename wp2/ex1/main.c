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

void turn(ROBOT *rob){
    if (rob->dir == N){
        rob->dir = O;
    } else if (rob->dir == O){
        rob->dir = S;
    } else if (rob->dir == S){
        rob->dir = W;
    } else if (rob->dir == W){
        rob->dir = N;
    }
}

void move(ROBOT *rob){
    if (rob->dir == N){
        (rob->ypos)++;
    } else if (rob->dir == O){
        (rob->xpos)++;
    } else if (rob->dir == S){
        (rob->ypos)--;
    } else if (rob->dir == W){
        (rob->xpos)--;
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
        printf("Enter instructions: ");
        scanf("%19s", instructions); 
        status = move_robot(&rob, instructions);
    }


    return 0;                   // exit the program
}

