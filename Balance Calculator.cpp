#include <stdio.h>
#include <conio.h>
#define pf printf // To shorten printf function
#define sf scanf  // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"BALANCE CALCULATOR PROGRAM\"");                                     // Title of my program
	pf("\nBy John Mathew C. Parocha");                                        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                                                // Name of my section for A.Y. 2023-2024
	
    float Starting_Balance, Total_Deposit, Total_Withdraws, Current_Balance;  // Used float to show decimals of money
    char Name[50];                                                            // Variable to be used to hold the account's name
	
    // Set of Codes for asking input and values of certain variables
    pf("\nEnter the account's name : ");
    sf("%[^\n]", Name);                                                       // Use %[^\n] to read the whole line including spaces
    pf("Enter the starting balance : ");
    sf("%f",&Starting_Balance);
	pf("Enter the total deposit : ");
    sf("%f",&Total_Deposit);    
	pf("Enter the total withdrawals : ");
    sf("%f",&Total_Withdraws);     

    // Using Arithmetic Operators to calculate the output
    Current_Balance = (Starting_Balance + Total_Deposit) - Total_Withdraws;
    
    // Set of Codes for displaying the final outputs
    pf("\n\nAccount's Name : %s ", Name);
    pf("\nStarting balance : %.2f Php", Starting_Balance);
    pf("\nTotal Deposit : %.2f Php", Total_Deposit);
    pf("\nTotal Withdrawals : %.2f Php", Total_Withdraws);
    pf("\nCurrent Balnce : %.2f Php", Current_Balance);

    return 0;                                                                 // To end the program
}


