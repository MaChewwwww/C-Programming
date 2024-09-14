#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
    int day, rate = 21, miles = 50;

    pf("Bereng Survival\n\n");
    
    pf("| Day | Rate | Miles |");
    pf("\n|-------|--------|-----------|\n");

    while (miles < 200) {       
        
        day++;
        rate = rate - 1;
        miles = (miles + rate) - 2;      
        
        pf("|   %d   |   %d   |   %d   |\n", day, rate, miles);
                
        }
        
    if ( day < 13 )
    pf("\n\nBareng reached civilization on the %dth day", day);
    else
    pf("\n\nBareng died on the %dth day",day);

    return 0;
}


