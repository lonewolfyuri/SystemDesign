// George Andrew Gabricht
// ggabrich - 56735102



#include "hw0.h"

int main (int argc, char *argv[])
{

	// Comment/Delete this print statement and insert your hw0 code here 
	// printf("Hello ICS53 student!\n"); 
	int i;
	for (i = argc - 1; i >= 0; i--) {
		printArg(argv[i], i);
	}
	return 0;
}

//Function to print out a single arugment to the screen
void printArg(char * arg_str, int pos){

	//Insert your code here
	printf("Argument[%d]: %s\n", pos, arg_str);
	return;
}
