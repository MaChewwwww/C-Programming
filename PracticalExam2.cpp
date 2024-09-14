#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
    // Declaration of variable to be used
    int loop = 0, loopmax;
    
    pf("How many numbers would you like? ");
    sf("%d", &loopmax);
    int array[loopmax];
    int positive[loopmax],c2,c3,c4;
    
    while(loop < loopmax)  {
        pf("Enter a number : ");       
        sf("%d", &array[loop]);
        
        if(array[loop]>0)
        {
        	positive[loop] = array[loop];
		}
        loop++;
    }
    
    pf("All positive numbers : ");   
    for(loop=0;loop<loopmax;loop++)
    {
    pf("%d", positive[loop]);
    }
    
    return 0;
}
