#include <stdio.h>
#include <conio.h>
#define pf printf // To shorten printf function
#define sf scanf  // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"TEMPERATURE CONVERTER PROGRAM\"");               // Title of my program
	pf("\nBy John Mathew C. Parocha");                     // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                             // Name of my section for A.Y. 2023-2024
	
    float Celsius,Farenheit,C2F,F2C;                       // Variables to be used and store values
	
    // Set of for converting celsius into farenheit
    pf("Enter temperature in Celsius : ");                 // To print and ask for input
    sf("%f",&Celsius);                                     // Indicates the variable who will hold the value of the celsius
    C2F = (Celsius * 9/5) + 32;                            // Mathematical formula to convert celsius into farenheit
    pf("%f Celsius is %.2f Farenheit", Celsius, C2F);      // To display the converted numbers

    // Set of for converting farenheit to celsius
    pf("\n\nEnter temperature in Farenheit : ");           // To print and ask for input
    sf("%f",&Farenheit);                                   // Indicates the variable who will hold the value of the farenheit
    F2C = (Farenheit - 32) * 5/9;                          // Mathematical formula to convert farenheit to celsius
    pf("%f Farenheit is %.2f Celsius", Farenheit, F2C);    // To display the converted numbers

    return 0;                                              // To end the program
}


