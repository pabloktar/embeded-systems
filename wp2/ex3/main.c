#include <stdlib.h> // 
#include <stdio.h> // The I/O header file contains the necessary logic for printing and inputting information
#include <string.h> // 
// -----typedefs -------
typedef struct {
    char firstname[20]; // Define the first value of the person struct as the first name
    char famname[20]; // Define the first value of the person struct as the family name
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.

void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void); // Prints out all persons in the file

void search_by_firstname(char *name); // Prints out the person if in list

void append_file(PERSON *inrecord); // appends a new person to the file

int check_input(char *userinput); // checks the input for common errors such as missing input and out of bounds characters

int main(void){
    PERSON ppost; // Declare a variable for storing the PERSON from userinput.
    int exitProgram = 0; // This variable acts as a boolean
    int selectMenuOption = 0; // Stores the menu option chosen by the user.
    while (exitProgram != 1) { // While the user has not chosen to exit the program, continue.
        display_menu();

        scanf("%d", &selectMenuOption);
        if ((selectMenuOption > 5) || (selectMenuOption < 1)) {
            printf("You didnt choose a value from 1-5, try again.\n");
            continue;
        }
        getchar();
        switch (selectMenuOption) {
        case 1:
            ppost = input_record();
            write_new_file(&ppost);
            break;
        case 2: {
            char firstname[20];
            char famname[20];
            char pers_number[13];

            if ((fopen("personDatabase.dat", "rb")) == NULL) {
                printf("\n Can not read the file.");
                break; 
            }

            printf("\nPlease put in firstname: ");
            fgets(firstname, sizeof(firstname), stdin);
            firstname[strcspn(firstname, "\n")] = 0;
            
            if (check_input(firstname) == 1) {
                break;
            }
            
            printf("\nPlease put in familyname: ");
            fgets(famname, sizeof(famname), stdin);
            famname[strcspn(famname, "\n")] = 0;

            if (check_input(famname) == 1) {
                break;
            }

            printf("\nPlease put in personnumber: ");
            fgets(pers_number, sizeof(pers_number), stdin);
            pers_number[strcspn(pers_number, "\n")] = 0;

            if (check_input(pers_number) == 1) {
                break;
            }

            PERSON temp;
            strcpy(temp.firstname, firstname);
            strcpy(temp.famname, famname);
            strcpy(temp.pers_number, pers_number);
            append_file(&temp);
        }
            break;
        case 3: {
            char firstname[20];

            if ((fopen("personDatabase.dat", "rb")) == NULL) {
                printf("\n Can not read the file.");
                break;
            } 

            printf("Provide name of the user you want get information on: ");
            fgets(firstname, sizeof(firstname), stdin);
            firstname[strcspn(firstname, "\n")] = 0;

            if (check_input(firstname) == 1) {
                break;
            }

            search_by_firstname(firstname);

        }
            break;
        case 4:
            printfile();
            break;
        case 5:
            exitProgram = 1;
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}

void display_menu(void) {
    printf("\n1 Create a new and delete the old file.\n"); 
    printf("2 Add a new person to the file.\n");
    printf("3 Search for a person in the file.\n");
    printf("4 Print out all in the file.\n");
    printf("5 Exit the program.\n");
}

int check_input(char *userinput) {
    int errorFound = 0;
    if (strlen(userinput) == 0) {
        printf("\nError, you did not put in any value.");
        errorFound = 1;
    } else if (strlen(userinput) > 20) {
        printf("\nError, first name is over the character limit (20).");
        errorFound = 1;
    }
    return errorFound;
}

PERSON input_record(void) {
    PERSON ppost;
    strcpy(ppost.firstname, "Danis");
    strcpy(ppost.famname, "Music");
    strcpy(ppost.pers_number, "090909098721");
    return ppost;
}

void write_new_file(PERSON *inrecord) {
    FILE *filePointer;
    if ((filePointer = fopen("personDatabase.dat", "wb")) == NULL) {
        printf("\n Can not create the file");
        return;
    }
    
    fwrite(inrecord, sizeof(PERSON), 1, filePointer);
    
    fclose(filePointer);
}

void printfile(void) {
    FILE *filePointer;
    PERSON temp;
    if ((filePointer=fopen("personDatabase.dat", "rb")) == NULL) {
        printf("\n Can not read the file.");
        return;
    } else {
        while (fread(&temp, sizeof(PERSON), 1, filePointer)) {
            printf("First name: %s\n", temp.firstname);
            printf("Family name: %s\n", temp.famname);
            printf("Person number: %s\n", temp.pers_number);
        }
    }


    fclose(filePointer);
}

void append_file(PERSON *inrecord){
    FILE *filePointer;
    
    filePointer = fopen("personDatabase.dat", "ab");
    fwrite(inrecord, sizeof(PERSON), 1, filePointer);
    
    fclose(filePointer);
}

void search_by_firstname(char *name) {
    FILE *filePointer = fopen("personDatabase.dat", "rb");
    PERSON temp;
    int personFound = 0;
    while (fread(&temp, sizeof(PERSON), 1, filePointer)) {
        if (strcmp(temp.firstname, name) == 0 || strcmp(temp.famname, name) == 0) {
            printf("\nFirst name: %s\n", temp.firstname);
            printf("Family name: %s\n", temp.famname);
            printf("Person number: %s\n", temp.pers_number);
            personFound = 1;
        } 
    }

    if (personFound == 0) {
        printf("No person with the given firstname or familyname exists in the binary file.\n");
    }
    
    fclose(filePointer);
}