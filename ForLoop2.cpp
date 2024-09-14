#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"Star Mover Program\"");   // Title of my program
	pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024
	
	// Declaration of variable to be used
    int loop, move;

    loop = 1;
    while (loop <= 3) {
        move = 1;
        while (move <= 5) {
            if (loop == move || loop + move == 6)
                printf("*");
            else
                printf(" ");
            move++;
        }
        printf("\n");
        loop++;
    }

    for (loop = 1; loop < 3; loop++)
        printf("  *\n");

    return 0;
}







