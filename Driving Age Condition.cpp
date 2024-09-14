#include <stdio.h> 
#include <conio.h>
#define pf printf // to shorten printf function
#define sf scanf  // to shorten scanf function

int main() {

    // Set of codes to display the  title and ownership    
    pf("\"DRIVING AGE CONDITION PROGRAM\"");              // Title of my program
	pf("\nBy John Mathew C. Parocha");                    // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                            // Name of my section for A.Y. 2023-2024

    int age,more_years;
    char name[50];

    // set of codes that asks for details
    pf("Enter your name : ");
    sf("%[^\n]", &name);
    pf("\nEnter your age : ");
    sf("%d", &age);
       	      	
    // set of conditional statements to determine if the input details is in legal age to drive  	
	if (age >= 16){
        pf("\n\n%s is old enough to drive", name);
    }
    else if (age < 16) {
    	more_years = 16-age;
    	pf("\n\n%s is %d years old, you must wait %d years before you can legally drive", name, age, more_years);
	}	

    getch();
    return 0;
}



