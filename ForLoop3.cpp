#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Factorial Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024
	
	// Declaration of variable to be used
    int loop, loop2, input_number, multiplication;

    pf("Enter a number : ");
    sf("%d", &input_number);
    
    for (loop = 1; loop <= input_number; loop++)
    {
    	multiplication = loop*multiplication;
    	if (loop<input_number)
    		pf("%d x ", loop);	
    	else
    	pf("%d ", loop);
    	
	}
        pf("\nThe Factorial of %d is : %d", input_number, multiplication);

    return 0;
}







