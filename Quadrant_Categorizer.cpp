#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Quadrant Category Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024
	
	// Declaration of variable to be used
    int x,y;

    // To ask for an input and store it on "x" and "y" variable
    pf("Enter \"X\" Value : ");
    sf("%d", &x);
     pf("Enter \"Y\" Value : ");
    sf("%d", &y);

    // Set of conditional statements to categorize what quadrant does the coordinates belong to
    if (x==0 && y==0){  	
    	    pf("\nThe coordinates %d and %d is in origin. ", x, y);  	
		}	
    	else if (x>=0 && y>=0){
    		pf("\nThe coordinates %d and %d is in QUADRANT 1. ", x, y);
		}
    	
        else if (x<=0 && y>=0){
        	pf ("\nThe coordinates %d and %d is in QUADRANT 2. ", x, y);
		}
		else if (x<=0 && y<=0){
        	pf ("\nThe coordinates %d and %d is in QUADRANT 3. ", x, y);
		}
		else if (x>=0 && y<=0){
        	pf ("\nThe coordinates %d and %d is in QUADRANT 4. ", x, y);
		}
    
    getch();    // To freeze the program before termination
    return 0;   // To terminate the program
}



