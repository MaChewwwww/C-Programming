#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Odd or Even Categorizer Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024
	
	// Declaration of variable to be used
    int number;

    // To ask for an input and store it on "x" and "y" variable
    pf("Enter a number : ");
    sf("%d", &number);
    
    // Set of conditional statements to categorize if a number is an odd or even.
    if (number == 0){  	
    	    pf("\nThe number you entered is ZERO! ");  	
		}	
		else if (number % 2 == 0){
			pf("\nThe number \"%d\" is an EVEN number. ",number); 
		}
		else if (number % 2 == 1){
			pf("\nThe number \"%d\" is an ODD number. ",number); 
		}
		else {
			pf("Please enter a valid number");
		}

    getch();    // To freeze the program before termination
    return 0;   // To terminate the program
}



