#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.

void write_new_file(PERSON *inrecord); // Creates a file and
// writes the first record
void printfile(void); // Prints out all persons in the file

void search_by_firstname(char *name); // Prints out the person if
// in list

void append_file(PERSON *inrecord); // appends a new person to the file

int main(void){
    PERSON ppost;
    int exitProgram = 0;
    int selectMenuOption = 0;
    while (exitProgram != 1) {
        printf("\n1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");

        scanf("%d", &selectMenuOption);
        if ((selectMenuOption > 5) || (selectMenuOption < 1)) {
            printf("You didnt choose a value from 1-5, try again.");
            continue;
        }
        getchar();
        switch (selectMenuOption) {
        case 1:
            strcpy(ppost.famname, "Music");
            strcpy(ppost.firstname, "Danis");
            strcpy(ppost.pers_number, "090909098721");
            write_new_file(&ppost);
            break;
        case 2: {
            char firstname[20];
            char famname[20];
            char pers_number[13];
            printf("\nPlease put in firstname: ");
            fgets(firstname, sizeof(firstname), stdin);
            firstname[strcspn(firstname, "\n")] = 0;

            if (strlen(firstname) == 0) {
                printf("\nError, you did not put in any value.");
                continue;
            } else if (strlen(firstname) > 20) {
                printf("\nError, first name is over the character limit (20).");
                continue;
            }
            
            printf("\nPlease put in familyname: ");
            fgets(famname, sizeof(famname), stdin);
            famname[strcspn(famname, "\n")] = 0;

            if (strlen(famname) == 0) {
                printf("\nError, you did not put in any value.");
                continue;
            } else if (strlen(famname) > 20) {
                printf("\nError, first name is over the character limit (20).");
                continue;
            }

            printf("\nPlease put in personnumber: ");
            fgets(pers_number, sizeof(pers_number), stdin);
            pers_number[strcspn(pers_number, "\n")] = 0;

            if (strlen(pers_number) == 0) {
                printf("\nError, you did not put in any value.");
                continue;
            } else if (strlen(pers_number) > 13) {
                printf("\nError, first name is over the character limit (20).");
                continue;
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
            printf("Provide name of the user you want get information on: ");
            fgets(firstname, sizeof(firstname), stdin);
            firstname[strcspn(firstname, "\n")] = 0;
            if (strlen(firstname) == 0) {
                printf("\nError, you did not put in any value.");
                continue;
            } else if (strlen(firstname) > 20) {
                printf("\nError, first name is over the character limit (20).");
                continue;
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
    


    return(0);
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
    if ((filePointer = fopen("personDatabase.dat", "rb")) == NULL) {
        printf("\n File does not exist");
        return;
    } else {
        filePointer = fopen("personDatabase.dat", "ab");
        fwrite(inrecord, sizeof(PERSON), 1, filePointer);
    }
    
    fclose(filePointer);
}

void search_by_firstname(char *name) {
    FILE *filePointer;
    PERSON temp;
    int personFound = 0;
    if ((filePointer=fopen("personDatabase.dat", "rb")) == NULL) {
        printf("\n Can not read the file.");
        return;
    } else {
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
    }
    fclose(filePointer);
}