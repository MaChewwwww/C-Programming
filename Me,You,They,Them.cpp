#include <stdio.h>
#include <conio.h>
#define pf printf
#define sf scanf

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"OVERWRITING VALUES PROGRAM\"");                                     // Title of my program
	pf("\nBy John Mathew C. Parocha");                                        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");         

    int Me = 0; 
	int You = 0; 
	int They = 5; 
	int Them = 7;

    pf("\nEnter a value for Me : ");
    sf("%d", &Me);
    pf("\nEnter a value for You : ");
    sf("%d", &You);     	
       	
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



