#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Leap Year Calculator Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024
	
	char newvar[50] = "p";
		char negvar[50] = "-";
        		strcat(negvar, newvar);
    pf("\%50s", negvar);    
    return 0;
}



