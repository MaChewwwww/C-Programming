#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char strings[50][10] = {"p","q","-p","-q"}; // Array of strings
int values[15][4] = {{1,1,0,0}, 
                     {1,0,1,0}, 
					 {0,0,1,1}, 
					 {0,1,0,1}};
int var_count = 4;
int answer;
char newvar[50];
char negvar[50] = "-";
char tempvar;
char decision;
char newstring[50];
int choice;

void showtable()
{	
    //Display strings
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
    printf("\tTable Representation :\n\n");
    for (int loop = 0; loop < var_count; loop++) {
        printf("%3s\t", strings[loop]);
    }
    
    printf("\n");
    
    //Display values
    for (int column = 0; column < 4; column++) 	
	{	
    	for (int row = 0; row < var_count; row++) 
		{
			//printf("%d\t", values[row][column]);
    		if (values[row][column] == 1)
		  	printf("True\t");
    		else if (values[row][column] == 0)
    	 	printf("False\t");
    	}
   	printf("\n");
	}
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
}

void listvariables()
{
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	printf("List of Current Variables : \n");
	for (int loop = 0; loop< var_count; loop++) {
        printf("\n%d. %3s", loop+1, strings[loop]);
    }
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
}

int main() {
	
	
	do {
	system("cls");
	showtable();
	printf("\n\"PROPOSITIONAL LOGIC CALCULATOR\" \nBy John Mathew C. Parocha\nFrom BSIT 1-1 \n");
	printf("\n1. Update table values");
	printf("\n2. Add a variable");
	printf("\n3. Calculate two variables");
	printf("\n4. End program\n");
	printf("\nSelect a number : ");
	scanf("%d", &answer);
	
		if (answer == 1){
		system("cls");
		showtable();
		}	
			else if (answer == 2){
		
				do {
						system("cls");
						listvariables();
						printf("\n(Enter any digit to exit) ");
						printf("\nEnter a letter for new variable : ");
						scanf("%s", &newvar);
						printf("\nAdding Data for Variable \"%s\"", newvar);
					 	if (isdigit(newvar[0]))
						 	{
		   			 			system("cls");
        					}
       					 // Check if the input is a single alphabetic character
       					 if (isalpha(newvar[0]) && newvar[1] == '\0') 
							{
        						printf("\nEnter (P) if the variable is positive. Press (N) if that variable is negative.\nEnter your answer : ");
        						scanf("%s", &decision);
        						if (decision == 'N' || decision == 'n')
								{
									strcat(negvar, newvar);
		        						var_count++;
		        							strcpy(strings[var_count-1], negvar);
		        							char answer2;
		        							int cut = 0;
		        									  do{
		        											printf("\nEnter (T) if the value is True. Enter (F) if the value is False.\n");
		        											for (int loop = 0; loop < 4; loop++)
															{
		        												printf("(%d) Enter a value : ", loop+1);
		        												scanf("%s", &answer2);
		        												if (answer2 == 'F' || answer2 == 'f')
																{
		        													values[var_count-1][loop] = 0;
																	if (loop > 3)
																	cut = 1;	
																}
																else if (answer2 == 'T' || answer2 == 't')
																{
        															values[var_count-1][loop] = 1;
																	if (loop > 3)
																	cut = 1;	
																}
																
		        												else
																{
		        													printf("Invalid input. You did not enter 'F' or 'F'.\n\n");
		        													loop--;
		        												}
															}
														} while (cut = 0);				
								}
            					else if (decision == 'P' || decision == 'p')
								{
        							var_count++;
        							strcpy(strings[var_count-1], newvar);
        							char answer2;
        							int cut = 0;
        									  do{
        											printf("\nEnter (T) if the value is True. Enter (F) if the value is False.\n");
        											for (int loop = 0; loop < 4; loop++)
													{
        												printf("(%d) Enter a value : ", loop+1);
        												scanf("%s", &answer2);
        												if (answer2 == 'T' || answer2 == 't')
														{
        													values[var_count-1][loop] = 1;
															if (loop > 3)
															cut = 1;	
														}
														else if (answer2 == 'F' || answer2 == 'f')
																{
		        													values[var_count-1][loop] = 0;
																	if (loop > 3)
																	cut = 1;	
																}		        												
        												else
														{
        													printf("Invalid input. You did not enter 'T' or 'F'.\n\n");
        													loop--;
        												}
													}
												} while (cut = 0);											
								}
           						else 
									{
            						 printf("\nPlease only enter \"P\" and \"N\"!\n");
          							 getch();
           							 system("cls");
           							 break;	
									}
							}
						else
            			printf("Invalid input. Please enter a single letter.\n");
            		} // end of do

    while (isalpha(newvar[0]) && newvar[1] == '\0');

	}
	else if (answer == 3){
		int number1, number2;
		int op_number;
    	bool validInput;
		system("cls");
		do 
		{
			showtable();
			listvariables();
        	printf("\nEnter a number for your first variable : ");
        	if (scanf("%d", &number1) == 1) // Input is a valid number
			{ 
           		validInput = true;
           		printf("\nEnter a number for your second variable : ");
        		scanf("%d", &number2);
        		printf("\n----------------------------------------------------------------------------------------------------------------------\n");
        		printf("\nSelect an operator. ");
        		printf("\n1. Conjunction \"^\" ");
        		printf("\n2. Disjunction \"v\" ");
        		printf("\n3. Exclusive Or \"(+)\" ");
        		printf("\n4. Implication \"->\" ");
        		printf("\n5. Bi-implications \"<->\" ");
        		printf("\n\nEnter your operator using the number assigned to them : ");
    			scanf("%d", &op_number);
    			char op_choice[50];
    			switch(op_number)
    			{
    				case 1: 
    					strcpy(op_choice, "^");
    					break;
    				case 2: 
    					strcpy(op_choice, "v");
    					break;
    				case 3: 
    					strcpy(op_choice, "(+)");
    					break;
    				case 4: 
    					strcpy(op_choice, "->");
    					break;
    				case 5: 
    					strcpy(op_choice, "<->")	;
						break;
					default :
						printf("Invalid input number! Going back to menu.\n");
						break;
				}
    			printf("\nProceed to calculate : %s %s %s ?", strings[number1-1],op_choice,strings[number2-1]);
    			printf("\nPress (1) if YES or Press (2) if NO : ");
    			scanf("%d", &choice);
    			if (choice == 1)
    			{
    				var_count++;
    				strcpy(newstring, strings[number1-1]);
    				strcat(newstring, op_choice);
    				strcat(newstring, strings[number2-1]);
    				strcpy(strings[var_count-1], newstring);
    				
    						for (int loop = 0; loop < 4; loop++)
							{
								if (op_number == 1)
								{
									if (values[number1-1][loop] == 1 && values[number2-1][loop] == 1)
									values[var_count-1][loop] = 1;
									else
									values[var_count-1][loop] = 0;
								}
								else if (op_number == 2)
								{
									if (values[number1-1][loop] == 1 || values[number2-1][loop] == 1)
									values[var_count-1][loop] = 1;
									else
									values[var_count-1][loop] = 0;
								}
								else if (op_number == 3)
								{
									if (values[number1-1][loop] == 1 && values[number2-1][loop] == 1 || values[number1-1][loop] == 0 && values[number2-1][loop] == 0)
									values[var_count-1][loop] = 0;
									else
									values[var_count-1][loop] = 1;
								}
								else if (op_number == 4)
								{
									if (values[number1-1][loop] == 1 && values[number2-1][loop] == 0)
									values[var_count-1][loop] = 0;
									else
									values[var_count-1][loop] = 1;
								}
								else if (op_number == 5)
								{
									if (values[number1-1][loop] == 1 && values[number2-1][loop] == 1 || values[number1-1][loop] == 0 && values[number2-1][loop] == 0)
									values[var_count-1][loop] = 1;
									else
									values[var_count-1][loop] = 0;
								}
							} // end of loop
					printf("\nSuccessfully Calculated! Result has been saved.\n");					
				}
    				else if (choice == 2)
    				{
    					printf("\nGoing back to Menu.");
    					getch();
    					break;
					}
    					else
    					{
    						printf("Please only enter 1 and 2.");
    						getch;
    						break;
						}
        		printf("\n----------------------------------------------------------------------------------------------------------------------\n");
        		getch();
			} 
				else  // Input is not a number, clear input buffer
				{
					system("cls");
            		printf("Invalid input. Please enter a valid number.\n");
					validInput = false;
            		while (getchar() != '\n'); // Clear input buffer
            		printf("Press any key to go back to the menu.\n");
            		getch();
            		break;
                }
    	} 
	while (!validInput);
		
	}
	else
		break;	
		
    } // end of do
    while (answer >= 1 && answer <= 3);
	
	printf("\nProgram  Terminated");
	
    return 0;
}





