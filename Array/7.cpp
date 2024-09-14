#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("Second Largest/Lowest Program"); // Title of my program
	pf("\nBy John Mathew C. Parocha");   // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");           // Name of my section for A.Y. 2023-2024
	
	
	int max, temp;
	pf("How many values you would like to store? ");
	sf("%d",&max);
	pf("\n");
	
	int array[max];
	for(int loop=0;loop<max;loop++){
		pf("Enter a number (%d) : ", loop+1);
		sf("%d",&array[loop]);
	}
	
	pf("Array contains : ");
	for(int loop=0;loop<max;loop++){
		pf("%d ", array[loop]);
	}
	
	for(int n1 = 0; n1<max; n1++)
	for(int n2 = 0; n2<max; n2++){
		if (array[n1]<array[n2]){
			temp = array[n1];
			array[n1] = array[n2];
			array[n2] = temp;
		}
	}
	
	pf("\n\n");
	pf("Second Largest Element : %d\n", array[1]);
	pf("Second Smallest Element : %d\n", array[max-2]);

	return 0;
}



