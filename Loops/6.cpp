#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\nBereng Survival Journey Program");   // Title of my program
	pf("\nBy John Mathew C. Parocha");           // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                   // Name of my section for A.Y. 2023-2024
	
    int day, rate = 21, miles = 50;

    
    pf("|\tDay\t|\tRate\t|\tMiles\t|\n");
    pf("|\t---\t|\t----\t|\t-----\t|\n");

    while (miles < 200) {       
        
        day++;
        rate = rate - 1;
        miles = (miles + rate) - 2;      
        
        pf("|\t%2d\t|\t%3d\t|\t%4d\t|\n", day, rate, miles);
                
        }
        
    if ( day < 13 )
    pf("\n\nBareng reached civilization on the %dth day\n", day);
    else
    pf("\n\nBareng died on the %dth day\n",day);

    return 0;
}



