#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {

	// Declaration of variable to be used
    int max_numbers;
    int numbers = 0;
	
	pf("\nEnter Maximum Number : ");
	sf("%d",&max_numbers);

    while (numbers <= max_numbers)
	{
   
    int new_number = numbers % 2;
    if (new_number != 1)
    pf("\n%d", numbers);
    
    numbers++;
	}
    
    return 0;
}



