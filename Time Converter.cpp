#include <stdio.h>
#include <conio.h>
#define pf printf // To shorten printf function
#define sf scanf  // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership
    
    pf("\"TIME CONVERSION PROGRAM\""); // Title of my program
	pf("\nBy John Mathew C. Parocha"); // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");         // Name of my section for A.Y. 2023-2024
	
	// Variables to be used to hold value of a certain input
    int hours,hours_to_minutes, minutes, minutes_to_hours, remainder_minutes; 

  		
	// Set of codes for converting hours into minutes	
    pf("Enter Number of Hours : "); // To print and ask for input
    sf("%d",&hours);                // Indicates the variable who will hold the value of the given 1st input
    hours_to_minutes = hours * 60;  // Mathematical formula to convert hourrs into minutes
    pf("%d hours is converted into %d minutes",hours, hours_to_minutes); // To print the converted numbers
    
    
    
    // Set of codes for converting minutes into hours and display remaining minutes
    pf("\n\nEnter Number of Minutes : "); // To print and ask for input
    sf("%d",&minutes);                    // Indicates the variable who will hold the value of the given 2nd input
    minutes_to_hours = minutes / 60;      // Mathematical formula to convert minutes into hours
    remainder_minutes = minutes % 60;     // To get the remaining minutes
    pf("%d minutes is converted into %d hours and %d minutes",minutes, minutes_to_hours, remainder_minutes);
                                          // To print the converted numbers
    

    return 0; // To end the program
}


