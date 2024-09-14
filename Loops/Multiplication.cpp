
#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {

	// Declaration of variable to be used
    int input_numbers;
    int loop = 1;
	
	pf("\nEnter a Number : ");
	sf("%d", &input_numbers);

    while (loop <= 10)
	{
		int result = input_numbers * loop;
		pf("\n%d x %d is %d", input_numbers, loop, result);
		loop++;
	}
   
    
    
    return 0;
}



