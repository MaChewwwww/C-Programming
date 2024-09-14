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
    int First_Number, Second_Number, Result;
    char operator_used;

    // To ask for an input and store it in "First_Number" and "Second_Number" variables
    pf("Enter \"First\" Number : ");
    sf("%d", &First_Number);
    pf("Enter \"Second\" Number : ");
    sf("%d", &Second_Number);
    pf("Select (+), (-), (*), (/) : ");
    sf(" %c", &operator_used); // Use %c to read a single character

    // Set of conditional statements to categorize what operation to perform
    switch (operator_used) {
    case '+':
        pf("\nYou have chosen addition");
        Result = First_Number + Second_Number;
        pf("\n%d + %d = %d", First_Number, Second_Number, Result);
        break;
    case '-':
        pf("\nYou have chosen subtraction");
        Result = First_Number - Second_Number;
        pf("\n%d - %d = %d", First_Number, Second_Number, Result);
        break;
    case '*':
        pf("\nYou have chosen multiplication");
        Result = First_Number * Second_Number;
        pf("\n%d * %d = %d", First_Number, Second_Number, Result);
        break;
    case '/':
        pf("\nYou have chosen division");
        Result = First_Number / Second_Number;
        pf("\n%d / %d = %d", First_Number, Second_Number, Result);
        break;       
    default :
    	pf("Please enter an operator");
    }

    getch();    // To pause the program before termination
    return 0;   // To terminate the program
}

	
