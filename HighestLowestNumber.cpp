#include <stdio.h>
#include <conio.h>
#define pf printf
#define sf scanf

int main() {

    // Set of codes to display the  title and ownership    
    pf("\"DRIVING AGE CONDITION PROGRAM\"");              // Title of my program
	pf("\nBy John Mathew C. Parocha");                    // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                            // Name of my section for A.Y. 2023-2024

    int N_1,N_2,N_3,Highest,Lowest;

    pf("Enter the first number : ");
    sf("%d", &N_1);
    pf("Enter the second number : ");
    sf("%d", &N_2);
    pf("Enter the third number : ");
    sf("%d", &N_3);
       	
	if (N_1 > N_2 && N_1 > N_3){		
		Highest = N_1;
        pf("\n\nHighest number is: %d", Highest);
        
        if (N_2 < N_3)
        {
        pf("\nLowest number is : %d", N_2);			
		}
		else if (N_3 < N_2)
        {
        pf("\nLowest number is : %d", N_3);
		}	
	}
		else if (N_2 > N_1 && N_2 > N_3){		
		Highest = N_2;
        pf("\n\nHighest number is: %d", Highest);
        
        if (N_1 < N_3)
        {
        pf("\nLowest number is : %d", N_1);			
		}
		else if (N_3 < N_1)
        {
        pf("\nLowest number is : %d", N_3);
		}	
	}
        else if (N_3 > N_2 && N_3 > N_1){		
		Highest = N_3;
        pf("\n\nHighest number is: %d", Highest);
        
        if (N_1 < N_2)
        {    
        pf("\nLowest number is : %d", N_1);			
		}
		else if (N_2 < N_1)	
        {     
        pf("\nLowest number is : %d", N_2);
		}
	}
	
    getch();
    return 0;
    
}



