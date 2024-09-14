#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("Arrray Addition Program");       // Title of my program
	pf("\nBy John Mathew C. Parocha");   // Name of the programmer student
	pf("\nFrom BSIT 1-1\n");           // Name of my section for A.Y. 2023-2024
	
	int rowmax, columnmax, loop;
	
	pf("\nEnter number of rows that you want : ");
    sf("%d", &rowmax);
    
    pf("Enter number of columns that you want : ");
    sf("%d", &columnmax);
	
	pf("\n");
	
	int array1[rowmax][columnmax];
	int array2[rowmax][columnmax];
	int array3[rowmax][columnmax];
	
	loop = 1;
	
	// input
	for(int row = 0; row<rowmax; row++){
		for(int column = 0; column<columnmax; column++){
			pf("Array1 (%d) = Enter a number in column %d row %d : ", loop, row+1, column+1);
		    sf("%d", &array1[row][column]);
	     	loop++;
		}
	}
	
	pf("\n");
	loop = 1;
	for(int row = 0; row<rowmax; row++){
		for(int column = 0; column<columnmax; column++){
			pf("Array2 (%d) = Enter a number in column %d row %d : ", loop, row+1, column+1);
		    sf("%d", &array2[row][column]);
	     	loop++;
		}
	}
	
	// process
	for(int row = 0; row<rowmax; row++){
		for(int column = 0; column<columnmax; column++){
			array3[row][column] = array1[row][column] + array2[row][column];
		}
	}
	
	// output 
	
	// table 1
	pf("\n");
	pf("First Table : \n");
	for(int row = 0; row<rowmax; row++){
		for(int column = 0; column<columnmax; column++){
			pf("%4d ", array1[row][column]);
		}
		pf("\n");
	}
	
	// table 2
	pf("\n");
	pf("Second Table : \n");
	for(int row = 0; row<rowmax; row++){
		for(int column = 0; column<columnmax; column++){
			pf("%4d ", array2[row][column]);
		}
		pf("\n");
	}
	
	// table 3
	pf("\n");
	pf("Third Table : \n");
	for(int row = 0; row<rowmax; row++){
		for(int column = 0; column<columnmax; column++){
			pf("%4d ", array3[row][column]);
		}
		pf("\n");
	}
	
	return 0;
}
