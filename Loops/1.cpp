#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Star Adder Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024
	
	// Declaration of variable to be used
    int loop,star,loopmax;
    
    // Statements to ask for input
    pf("Enter the number of stars that you want : ");
    sf("%d", &loopmax);
    pf("\n");
	
	// Looping 
	for (loop=1; loop<=loopmax; loop++)
	{
		for (star=1; star<=loop; star++)
		pf("*");
		pf("\n");
	
	}
    
    return 0;
}







