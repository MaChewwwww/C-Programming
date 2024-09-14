#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Array Summation Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");   // Name of the programmer student
	pf("\nFrom BSIT 1-1\n");             // Name of my section for A.Y. 2023-2024
	
	// Set of codes to declare the table size
	int rowmax, columnmax;
	pf("\nEnter number of rows that you want : ");
    sf("%d", &rowmax);
    pf("Enter number of columns that you want : ");
    sf("%d", &columnmax);
	
	
	// Declaration of variables to be used
	int array[rowmax][columnmax];
	int rowsum[rowmax];
	int columnsum[columnmax];
	int rowtempsum = 0;
	int columntempsum = 0;
	int equal = 0;
	
	pf("\n");
	
	// Set  of codes to make the user input values
	for(int row = 0; row < rowmax; row++)
	{
		for(int column = 0; column < columnmax; column++)
		{
		pf("Enter a number in column %d row %d : ", column+1, row+1);
     	sf("%d", &array[row][column]);
		}
		pf("\n");
	}
	
	// Set of codes to accumulate all the row values and store it on one-dimensional array
		for(int row = 0; row < rowmax; row++)
	{
		for(int column = 0; column < columnmax; column++)
		{
	    rowtempsum = rowtempsum + array[row][column];
     	rowsum[row] = rowtempsum;
		}
		rowtempsum = 0;
	}
	
	// Set of codes to accumulate all the column values and store it on one-dimensional array
		for(int column = 0; column < columnmax; column++)
	{
		for(int row = 0; row < rowmax; row++)
		{
	    columntempsum = columntempsum + array[row][column];
     	columnsum[column] = columntempsum;
		}
		columntempsum = 0;
	}
	
	// Set of codes to show the original table valuess
	pf("\n----------------------------------------------------------------");
	pf("\nTable Representation :\n\n");
	
		for(int row = 0; row < rowmax; row++)
	{
		for(int column = 0; column < columnmax; column++)
		{
		pf("%4d ", array[row][column]);
		}
		pf("\n");
	}
	
	pf("\n----------------------------------------------------------------");
	
	// Set of codes to test if a row is equal to other rows
	for (int row = 0; row < rowmax; row++)
	{
	pf("\nRow %d sum : %d ", row+1, rowsum[row]);
	for (int search = 0; search < rowmax; search++)
	{
		if (rowsum[row] == rowsum[search] && row != search){
			pf("\nRow %d is equal to Row %d", row+1, search+1);
			equal = 0;
		}
		else if (rowsum[row] != rowsum[search] && row != search)
		{
		pf("\nRow %d is not equal to Row %d", row+1, search+1);
		equal = 1;
		}
	}
	pf("\n");
	}
	
	if (equal == 1)
	pf("\nALL ROW SUMS ARE NOT EQUAL\n");
	else 
	pf("\nALL ROW SUMS ARE EQUAL");
	pf("\n----------------------------------------------------------------");
	
	// Set of codes to test if a column is equal to other column
	for (int column = 0; column < columnmax; column++)
	{
	pf("\nColumn %d sum : %d ", column+1, columnsum[column]);	
	for (int search = 0; search < columnmax; search++)
	{
		if (columnsum[column] == columnsum[search] && column != search){
			pf("\nColumn %d is equal to Column %d", column+1, search+1);
		    equal = 0;
		}	
		else if (columnsum[column] != columnsum[search] && column != search)
		{
		pf("\nColumn %d is not equal to Column %d", column+1, search+1);
		equal = 1;
		}
	}
	pf("\n");
	}
	if (equal == 1)
	pf("\nALL COLUMN SUMS ARE NOT EQUAL");
	else
	pf("\nALL COLUMN SUMS ARE EQUAL");
	pf("\n----------------------------------------------------------------");
	pf("\n");
	
	getch();
    return 0;
}





