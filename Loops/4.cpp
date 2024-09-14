#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Factors Entered Number Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024
	
	// Declaration of variab5le to be used
    int input_number, loop;

    pf("Enter a number : ");
    sf("%d", &input_number);
    
    pf("\nFactors of %d is \n", input_number);
    
    loop = 1;
    while (loop <= input_number) 
	{ 
    if (input_number % loop == 0)
    {
    	pf("%d ", loop);
	}
	loop++;
    }


    return 0;
}







