#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("Water Bucket Calculator Program");   // Title of my program
	pf("\nBy John Mathew C. Parocha");           // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                   // Name of my section for A.Y. 2023-2024
	
    int hour, cat, drops=0;

    
    pf("|\tDay\t|\tRate\t|");
    pf("\n|\t---\t|\t----\t|\n");

    while (drops < 2452) { 
	      
        hour++;
        if (hour % 3 == 0)
        {  
        cat = cat + 28;
        drops = drops + 162 - 28;
        
        
        pf("|\t%d\t|\t%d\t|\n", hour, drops);
		}    
        else
        {       	
		drops = drops + 162;
        pf("|\t%d\t|\t%d\t|\n", hour, drops);	
		}      
       }
        
        pf("\n\nThe cat drank %d drops of wine\n", cat);

    return 0;
}

