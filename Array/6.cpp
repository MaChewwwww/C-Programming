#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Array Search Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");   // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");             // Name of my section for A.Y. 2023-2024
	
	// Set of codes to declare the number of values you would like to store
	int max;
	pf("How many values you would like to store? ");
	sf("%d",&max);
	pf("\n");
	
	// Set  of codes to make the user input values
	int array[max];
	for(int loop=0;loop<max;loop++){
		pf("Enter a number (%d) : ", loop+1);
		sf("%d",&array[loop]);
	}
	
	// Set  of codes to show the table repressentation
	pf("Array contains : ");
	for(int loop=0;loop<max;loop++){
		pf("%d ", array[loop]);
	}
	
	// A control structure to search for the occurences of a certain number
	// and ask again if the usser wants to search another
	int number, decision;
	char answer;
	do{
		pf("\n\nEnter a number that you want to search : ");
		sf("%d", &number);
		
		int search_count = 0;
		for(int loop=0;loop<max;loop++){	
		if (number == array[loop])
		{
	    	search_count++;
		   }
     	}	
    
     	pf("There are %d occurence of the nunmber %d", search_count, number);
     	
     	pf("\n");
     	pf("\nWould you like to search another number? (Y/N) : ");
     	sf("%s", &answer);
     	
     	if (answer == 'Y' || answer == 'y')
     	decision = 1;
     	else if (answer == 'N' || answer == 'n')
     	decision = 0;
     	else
     	{
     		pf("You can only answer using Y or N. ");
     		break;
		 }
	}
	while(decision==1);
	
	pf("\nPROGRAM TERMINATED!\n");
	return 0;
}
