#include <stdio.h>
#include <conio.h>
#define pf printf   // To shorten printf function
#define sf scanf    // To shorten scanf function

int main() {
    // Set of codes to display the title and ownership
    pf("\"Quadrant Category Program\"");   // Title of my program
    pf("\nBy John Mathew C. Parocha");        // Name of the programmer student
    pf("\nFrom BSIT 1-1\n\n");                // Name of my section for A.Y. 2023-2024

    // Declaration of variables to be used
    int rows;
    
    // Program to display result by using for loop
    printf("Enter the number of desired rows: ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    getch();    // To pause the program before termination
    return 0;   // To terminate the program
}
