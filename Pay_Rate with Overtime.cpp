#include <stdio.h> 
#include <conio.h>
#define pf printf // to shorten printf function
#define sf scanf  // to shorten scanf function

int main() {
    
    // Set of codes to display the  title and ownership    
    pf("\"WEEKLY WAGE WITH OVERTIME PROGRAM\"");              // Title of my program
	pf("\nBy John Mathew C. Parocha");                        // Name of the programmer student
	pf("\nFrom BSIT 1-1\n\n");                                // Name of my section for A.Y. 2023-2024
	
    char name[50];
    float h_worked, hour_rate, oh_worked, oh_rate, w_wage, ow_wage, t_wage, n_hours, n_pay;
    
    // Set of codes to ask for inputs
    pf("Enter the employee name : ");
    sf("%[^\n]", &name);
    pf("Enter the rate per hour : ");
    sf("%f", &hour_rate);
    pf("Enter the total hours of worked : ");
    sf("%f", &h_worked);
    
    // Set of conditional statements   
    if (h_worked > 40){   
		
    	w_wage = h_worked * hour_rate;
    	n_hours = h_worked - (h_worked-40);
    	n_pay = n_hours * hour_rate;
    	ow_wage = (h_worked - 40) * (hour_rate*1.5);
    	t_wage = ow_wage + n_pay;
    	pf("\nEmployee Name : %s ", name);
		pf("\nPay per hour : %.2f ", hour_rate);
		pf("\nNormal Hours worked : %.2f ", n_hours);
		pf("\nNormal hours salary : %.2f ", n_pay);
		pf("\nOvertime hours : %.2f ", h_worked - 40);
		pf("\nOvertime hours salary : %.2f ", ow_wage);
		pf("\nTotal Week's Wage : %.2f ", t_wage);
	}
	
	else{
		w_wage = h_worked * hour_rate;
		pf("\nEmployee Name : %s ", name);
		pf("\nPay per hour : %.2f ", hour_rate);
		pf("\nHours worked : %.2f ", h_worked);
		pf("\nWeek's Wage : %.2f ", w_wage);
	}

    getch();
    return 0;
}


	

