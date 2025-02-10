#include <stdio.h>
#include <string.h>

#define END_CHARACTER 'x'

enum DIRECTION {N,E,S,W};

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

// --- Prototypes ---

void move(ROBOT *robot);
void turn(ROBOT *robot);
void cleanstdin(void);

// -------------------

int main(int argc, char **argv) {
    int y = 0;
    int x = 0;
    int xFound = 0;
    char robotInstruction[100];
    ROBOT robot;

    while (xFound == 0) {
        printf("Robot starting position: ");
        if (scanf("%d %d", &y, &x) == 0) {
            printf("The input is not valid, try again.\n");
            cleanstdin();
            continue;
        } 
        cleanstdin();

        if ((x < 0 || x > 99) || (y < 0 || y > 99)) {
            printf("The starting coordinates of the robot must be within the 0-99 range.");
            continue;
        }

        robot.ypos = y;
        robot.xpos = x;
        robot.dir = N;

        printf("Please put in the instructions for the robot: ");
        if (fgets(robotInstruction, sizeof(robotInstruction), stdin) == NULL) {
            printf("Could not read the input provided, try again.");
            continue;
        }

        for (int i = 0; i < strlen(robotInstruction); i++) {
            switch (robotInstruction[i]) {
                case 't':
                    turn(&robot);
                    break;
                case 'm':
                    move(&robot);
                    break;
                case END_CHARACTER:
                    xFound = 1;
                    break;
                case '\n': 
                    printf("Y position: %d\n", robot.ypos);
                    printf("X position: %d\n", robot.xpos);
                    break;
                default:
                    printf("The input has forbidden characters.");
                    break;
            }
        }
    
    }
    
}

// Clears the buffer of characters 
void cleanstdin(void) {
    char temp; 
    while ((temp = getchar()) != '\n' && temp != EOF); // As long as the character is not a return character or an end of file character, iterate.
}

void turn(ROBOT *robot) {
    switch (robot->dir) {
        case N:
            robot->dir = E;
            break;
        case E:
            robot->dir = S;
            break;
        case S:
            robot->dir = W;
            break;
        case W:
            robot->dir = N;
            break;    
        default:
            break;
    }
}

void move(ROBOT *robot) {

    switch (robot->dir) {
        case N:
            robot->ypos++;
            break;
        case E:
            robot->xpos++;
            break;
        case S:
            robot->ypos--;
            break;
        case W:
            robot->xpos--;
            break;    
        default:
            break;
    }

}