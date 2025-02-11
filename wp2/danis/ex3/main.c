#include <stdio.h> // The I/O header file contains the necessary logic for printing and inputting information
#include <string.h> // This header file contains the necessary logic for handling strings

#define MAX_NAME_SIZE 20 // Define maximum size allowed for family name and first name
#define MAX_PERS_NUM_SIZE 13 // Define maximum size allowed for personal number

// -----typedefs -------
typedef struct {
    char firstname[MAX_NAME_SIZE]; // Define the first value of the person struct as the first name
    char famname[MAX_NAME_SIZE]; // Define the first value of the person struct as the family name
    char pers_number[MAX_PERS_NUM_SIZE]; // yyyymmddnnnc
} PERSON;

// ----- Function declaration ---- (to be extend)
PERSON input_record(void); // Reads a person’s record.

void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void); // Prints out all persons in the file

void search_by_firstname(char *name); // Prints out the person if in list

void append_file(PERSON *inrecord); // appends a new person to the file

int check_input(char *userinput); // checks the input for common errors such as missing input and out of bounds characters

void display_menu(void); // Displays the menu for the user.

void clearstdin(void); // Clears the buffer of remaining characters

int has_digits(char *string); // Checks string for any numbers present

void get_input(char *printMessage, char *userInput, int maxInput, int allowDigits); // Gets the users input and validates it



int main(void){
    PERSON ppost; // Declare a variable for storing the PERSON from userinput.
    int exitProgram = 0; // This variable acts as a boolean
    int selectMenuOption = 0; // Stores the menu option chosen by the user.
    while (exitProgram != 1) { // While the user has not chosen to exit the program, continue.
        display_menu(); // Call method to display menu for user.

        int result = scanf("%d", &selectMenuOption); // Save the user input 
        if (result != 1 || (selectMenuOption > 5) || (selectMenuOption < 1)) { // Check to ensure that the user follows input restrictions.
            printf("You didnt choose a value from 1-5, try again.\n"); // Show the user error message if the input did not follow restrictions.
            clearstdin();
            continue; // Exit the program.
        }

        getchar(); // Consume the new line character.
        switch (selectMenuOption) { // Check the value of the selected menu option.
        case 1: // If the user choose option 1
            ppost = input_record(); // Initialize the hardcoded PERSON instance and assign it to the variable
            write_new_file(&ppost); // Create a new file and store the hardcoded person instance
            break; // Exit the switch case
        case 2: { // If the user choose option 1
            char firstname[MAX_NAME_SIZE]; // Declare the method that is used to store the first name from the users input
            char famname[MAX_NAME_SIZE]; // Declare the method that is used to store the family name from the users input
            char pers_number[MAX_PERS_NUM_SIZE]; // Declare the method that is used to store the personalnumeber from the users input

            if ((fopen("personDatabase.dat", "rb")) == NULL) { // Check if the file does not exist
                printf("Can not read the file.\n"); // Show the user the error message
                break; // Exit the case
            }

            get_input("Please put in firstname: \n", firstname, MAX_NAME_SIZE, 0); // Get the firstname from the user input and validate it
            get_input("Please put in family name: \n", famname, MAX_NAME_SIZE, 0); // Get the family name from the user input and validate it
            get_input("Please put in personalnummber: \n", pers_number, MAX_PERS_NUM_SIZE, 1); // Get the personalnumber from the user input and validate it

            PERSON temp; // Declare a temporary person variable
            strcpy(temp.firstname, firstname); // Copy the validated user input into the person instances first name field
            strcpy(temp.famname, famname); // Copy the validated user input into the person instances family name field
            strcpy(temp.pers_number, pers_number); // Copy the validated user input into the person instances personalnumber field
            append_file(&temp); // Add the person into the file
        }
            break;
        case 3: { // If the user choose option 3
            char identifier[MAX_NAME_SIZE]; // Declare the variable that is going to store the string used to identify person instance

            if ((fopen("personDatabase.dat", "rb")) == NULL) { // Check if the file does not exist
                printf("\n Can not read the file."); // Show the user an error message
                break; // Exit the case
            } 

            get_input("Provide name of the user you want get information on: ", identifier, MAX_NAME_SIZE, 0); // Get the user input and validate it

            search_by_firstname(identifier); // Search for a person instance in the file that matches the given string and print their information

        }
            break; // Exiting the switch
        case 4: // If the user choose option 4
            printfile(); // Show the user the contents of the personDatabse file
            break; // Exiting the switch
        case 5: // If the user choose option 5
            exitProgram = 1; // Make the while condition false, exiting the program
            break; // Exiting the switch
        
        default:
            break; // Exiting the switch
        }
    }
    
    return 0;
}

void get_input(char *printMessage, char *userInput, int maxInput, int allowDigits) {
    while (1) { // While noting explicitly ends loop
        printf("%s", printMessage); // Show the user the message as given by the parameter
        if (fgets(userInput, maxInput, stdin) == NULL) { // Checks if the users input is not able to be handled
            printf("Error occured when trying to get user input."); // Informs the user that an error occured.
            clearstdin(); // Clean the buffer from any remaining characters
            continue; // Continue with the loop
        }

        if (check_input(userInput) == 1) { // Check if there is a problem with the input
            continue; // Continue from the beginning of the loop
        }

        if (allowDigits == 0 && has_digits(userInput) == 1) { // Checks if the input is not allowed numbers and they have shown up in the string
            printf("Invalid input, numbers are not allowed. \n"); // Inform the user that the input was invalid
            continue; // Continue from the beginning of the loop
        }

        if (allowDigits == 1 && has_digits(userInput) == 0) { // Checks if the input is allowed numbers and there are letters in the string
            printf("Invalid input, letters are not allowed. \n"); // Inform the user that the input was invalid
            continue; // Continue from the beginning of the loop
        }

        break; // End the loop when valid input is found
    }
}

int has_digits(char *string) { 
    while(*string) { // While the string pointer has a value
        if (*string >= '0' && *string <= '9') { // Check if its a number
            return 1; // Return integer indicating that its true
        }
        string++; // Increment the pointer
    }
    return 0; // Otherwise, return an integer indicating no numbers were found
}

// Clears the buffer of characters 
void clearstdin(void) {
    char temp; // Declare the variable that is going to store a character from the buffer
    while ((temp = getchar()) != '\n' && temp != EOF); // As long as the character is not a return character or an end of file character, iterate.   
}

void display_menu(void) {
    printf("\n1 Create a new and delete the old file.\n"); // Show the user the necessary input deleting the old file and creating a new one
    printf("2 Add a new person to the file.\n"); // Show the user the necessary input for adding a new perosn to the file
    printf("3 Search for a person in the file.\n"); // Show the user the necessary input for printing out the content of a person specified by the user
    printf("4 Print out all in the file.\n"); // Show the user the necessary input for printing the contents of the file
    printf("5 Exit the program.\n"); // Show the user the necessary input for exiting the program
}

int check_input(char *userinput) {
    int errorFound = 0; // Declare and initialize a variable indidacting the error status of input 

    if (strchr(userinput, '\n') == NULL) { // Checks if the user input has a newline character 
        printf("Error, input is over the character limit.\n"); // Shows user error message indicating that the input has to many characters
        clearstdin(); // Clean the buffer
        errorFound = 1; // Indicate an error occurred by assigning the value one to variable
    }

    if (userinput[0] == '\n') { // Checks if user input only has the newline character
        printf("Error, you did not put in any value.\n"); // Shows user error message indicating no 'real' values were put in input
        errorFound = 1; // Indicate an error occurred by assigning the value one to variable
    }
    
    userinput[strcspn(userinput, "\n")] = 0; // Replace newline character with empty character to reset input buffer
    return errorFound; // Return the status of the input
}

PERSON input_record(void) {
    PERSON ppost; // Declare a variable for storing the hardcoded values in the struct fields
    strcpy(ppost.firstname, "Danis"); // Assign the firstname field with the hardcoded value 
    strcpy(ppost.famname, "Music"); // Assign the firstname field with the hardcoded value 
    strcpy(ppost.pers_number, "090909098721"); // Assign the firstname field with the hardcoded value 
    return ppost; // Return the person struct
}

void write_new_file(PERSON *inrecord) {
    FILE *filePointer; // Declare a file pointer that is going to be used to store file
    if ((filePointer = fopen("personDatabase.dat", "wb")) == NULL) {
        printf("Can not create the file.\n"); // Show the user a error message
        return; // Exit function
    }
    
    fwrite(inrecord, sizeof(PERSON), 1, filePointer); // Write the hardcoded person into the newly created file
    
    fclose(filePointer); // Close file
}

void printfile(void) {
    FILE *filePointer; // Declare a file pointer that is going to be used to store file
    PERSON temp; // Declare a variable for temprarily storing the person information from the file
    if ((filePointer=fopen("personDatabase.dat", "rb")) == NULL) { // Checks to see if file does not exist
        printf("Can not read the file.\n"); // Shows user an error message indicating that the file cannot be read
        return; // Exit function
    } else {
        while (fread(&temp, sizeof(PERSON), 1, filePointer)) { // Iterate over all person values in the binary file
            printf("First name: %s\n", temp.firstname); // Show the user the persons firstname
            printf("Family name: %s\n", temp.famname); // Show the user the persons family name
            printf("Person number: %s\n", temp.pers_number); // Show the user the persons personalnumber
        }
    }


    fclose(filePointer); // Close file
}

void append_file(PERSON *inrecord){
    FILE *filePointer; // Declare a file pointer that is going to be used to store file
    
    filePointer = fopen("personDatabase.dat", "ab"); // Open the file with appending access
    fwrite(inrecord, sizeof(PERSON), 1, filePointer); // Add the specified person to the specified file
    
    fclose(filePointer); // Close file
}

void search_by_firstname(char *name) {
    FILE *filePointer = fopen("personDatabase.dat", "rb"); // Declare and intialize a file pointer pointing to the file specified
    PERSON temp; // Declare a variable for temprarily storing the person information from the file
    int personFound = 0; // Declare and initialize a variable used to check if the specified person was found
    while (fread(&temp, sizeof(PERSON), 1, filePointer)) { // While a person value can be read from the file, iterate
        if (strcmp(temp.firstname, name) == 0 || strcmp(temp.famname, name) == 0) { // If the firstname or familyname field matches the input from the user
            printf("First name: %s\n", temp.firstname); // Show the user the persons firstname
            printf("Family name: %s\n", temp.famname); // Show the user the persons familyname
            printf("Person number: %s\n", temp.pers_number); // Show the user the persons personalnumber
            personFound = 1; // Assign one to variable indicating the person was found
        } 
    }

    if (personFound == 0) { // Checks if the person was not found
        printf("No person with the given firstname or familyname exists in the binary file.\n"); // Show a message indicating that no person with the given input can be found in the file
    }
    
    fclose(filePointer); // Close file
}