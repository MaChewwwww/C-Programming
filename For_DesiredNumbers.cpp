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
    int loop,looptry, input_number, number, sum, average;
    
    pf("How Many Numbers Would You Like to Add? : ");
    sf("%d", &input_number);
	
	for (loop=1; loop<=input_number; loop++, looptry++)
	{
		pf("(%d) Please Enter a Number : ", looptry);
		sf("%d", &number);
		sum = sum + number; 	
	}
	
	average = sum / 10;
	
	pf("\nThe Sum of All Number is : %d", sum);
	pf("\nThe Average of All Number is : %0.2f", (float)average);
    
    return 0;
}







