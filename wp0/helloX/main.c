// import standard input/output library
#include <stdio.h>
// import string library
#include <string.h>

// declare main function. The parameters are the command line arguments.
int main(int args, char **argv){
	// check if the name was passed as a parameter. Because the execute file name counts as 1 of the parameters, we check if there are at least 2 parameters.
	if(args < 2){
		// if no name is passed, output error message
		printf("%s", "No command line argument provided, please provide a name.");
		// exit the program
		return 0;
	}

	// declare name variable storing user's name 
	char *name = argv[1];
	// declare nameLength variable storing user's name's length
	int nameLength = strlen(name);

	// check if the name is long enough
	if(nameLength < 3){
		// the name is too short, output the error message
		printf("%s", "Name too short, min 3 characters");
		// exit the program
		return 0;
	}

	// check if the name is short enough
	if(nameLength > 50){
		// the name is too long, output the error message
		printf("%s", "Name too long, max 50 characters");
		// exit the program
		return 0;
	}
	
	// output greeting message
	printf("Hello %s, how is your day today?", name);


	// exit the program
	return 0;
}
