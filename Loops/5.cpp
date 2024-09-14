#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Burger Delivery Calculator Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024
	
	// Declaration of variables to be used
    int hours = 0, minutes = 0, burgers = 0, maxloop;
    
    pf("Enter number of burgers you would like to deliver : ");
    sf("%d", &maxloop);
    
    pf("\n\nHours|\tMinutes|\tBurgers|\n");
    while (burgers <= maxloop) 
	{ 
	pf("%5d|\t%7d|\t%7d|\n", hours, minutes, burgers);
	minutes = minutes + 2;
	if (minutes >= 60)
	{
		hours = hours + minutes / 60;
		minutes = minutes % 60;
	}
	burgers = burgers + 12;
    }
    return 0;
}







