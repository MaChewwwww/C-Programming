#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024
	
	// Declaration of variable to be used
    int loop,looptry, input_number, multiplication;
    
    pf("What number would you like to have a multiplication table? : ");
    sf("%d", &input_number);
	
	for (loop=1; loop<=10; loop++)
	{
		multiplication = input_number * loop;
		pf("%d x %d : %d", input_number, loop, multiplication);
		pf("\n");
	
	}
    
    return 0;
}







