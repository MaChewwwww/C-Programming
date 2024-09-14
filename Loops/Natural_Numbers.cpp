#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {

	// Declaration of variable to be used
    int numbers;
    int start = 0;
	
	pf("\nEnter Maximum Number : ");
	sf("%d",&numbers);

    while (start <= numbers)
	{
    pf("\n%d", start);
    start++;	
	}
    
    return 0;
}



