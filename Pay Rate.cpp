#include <stdio.h>
#include <conio.h>
#define pf printf // To shorten printf function
#define sf scanf  // To shorten scanf function

int main() {
	
	// Set of codes to display the  title and ownership    
    pf("\"PAY RATE CONVERSION PROGRAM\"");                    // Title of my program
	pf("\nBy John Mathew C. Parocha");                        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                                // Name of my section for A.Y. 2023-2024
	
    int day1,day2,day3,day4,day5,day6,day7,Total_Hours;       // Variables to be used to hold value of a certain input
    float Pay_Rate, Total_Salary;                             // Used float to show decimals of money
    char Name[50];                                            // Variable to be used to hold the employee name
	
    // Set of Codes for asking input and values of certain variables
    pf("\nEnter the employee name : ");
    sf("%[^\n]", Name);                                       // Use %[^\n] to read the whole line including spaces
    pf("\nEnter the pay rate per hour : ");
    sf("%f",&Pay_Rate);    
    pf("\nEnter number of worked hours on day 1 : ");
    sf("%d",&day1);
    pf("Enter number of worked hours on day 2 : ");
    sf("%d",&day2);
    pf("Enter number of worked hours on day 3 : ");
    sf("%d",&day3);
    pf("Enter number of worked hours on day 4 : ");
    sf("%d",&day4);
    pf("Enter number of worked hours on day 5 : ");
    sf("%d",&day5);
    pf("Enter number of worked hours on day 6 : ");
    sf("%d",&day6);
    pf("Enter number of worked hours on day 7 : ");
    sf("%d",&day7);
    
    // Using Arithmetic Operators to calculate the output
    Total_Hours = day1+day2+day3+day4+day5+day6+day7;
    Total_Salary = Pay_Rate * Total_Hours;
    
    // Set of Codes for displaying the final outputs
    pf("\n\nThe pay rate : %.2f Php per hour", Pay_Rate);
    pf("\nThe total hours worked in a week : %d hours", Total_Hours);
    pf("\nThe computation for the salary : %.2f (Pay Rate) * %d (Total Worked Hours)", Pay_Rate, Total_Hours);
    pf("\nThe salary of employee \"%s\" for the week is %.2f Php", Name, Total_Salary);
       
    return 0; // To end the program
}

	
