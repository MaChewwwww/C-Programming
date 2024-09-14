#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
    int hour, cat, drops=0;

    pf("Bereng Survival\n\n");
    
    pf("| Day | Rate |");
    pf("\n|-------|--------|\n");

    while (drops < 2452) { 
	      
        hour++;
        if (hour % 3 == 0)
        {  
        cat = cat + 28;
        drops = drops + 162 - 28;
        
        
        pf("|   %d   |   %d   |\n", hour, drops);
		}    
        else
        {       	
		drops = drops + 162;
        pf("|   %d   |   %d   |\n", hour, drops);	
		}      
       }
        
        pf("\n\nThe cat drank %d drops of wine",cat);

    return 0;
}


