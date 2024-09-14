#include <stdio.h> 
#include <conio.h>
#define pf printf // to shorten printf function
#define sf scanf  // to shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"OVERWRITING VALUES PROGRAM\"");                    // Title of my program
	pf("\nBy John Mathew C. Parocha");                       // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                               // Name of my section for A.Y. 2023-2024

    int Me = 0; 
	int You = 0; 
	int They = 5; 
	int Them = 7;

    // Set of codes to ask for inputs
    pf("\nEnter a value for Me : ");
    sf("%d", &Me);
    pf("\nEnter a value for You : ");
    sf("%d", &You);     	
    
	// Set of conditional statements   	
	if (Me < 2 && Me > 0){
        Me = You;
        pf("\nThe value of you is : %d", You);
    }
    else if (Me == 5){
    	You = They * Them;
    	pf("\nThe value of you is : %d", You);
	}
	else if (Me == 7){
    	You -= 4;
    	pf("\nThe value of you is : %d", You);
	}
	else {
		pf("\nThe value of you is : %d", You);
	}

    getch();
    return 0;
}



