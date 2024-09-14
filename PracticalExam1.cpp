#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {

	// Declaration of variable to be used
	int sum,loop,loopmax;
	
	
	pf("How many numbers would you like? ");
	sf("%d", &loopmax);
    int array[3]; 10, 20
    
    for(loop=0;loop<loopmax;loop++)
    {
     pf("Enter a number (%d) : ", loop+1);
	 sf("%d", &array[loop]);
	 sum = sum + array[loop];
	}
	pf("Sum of all numbers : %d ", sum);
    
    return 0;
}



