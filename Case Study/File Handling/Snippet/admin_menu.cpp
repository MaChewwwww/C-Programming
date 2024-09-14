#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>

void AdminMenu();

int main() {

    while (1) {
        system("cls");
        printf("Welcome to the Bank\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Admin\n");
        printf("4. Exit\n");  

        printf("\nSelect a Choice: ");
        char input[10];
		int choice;	
		scanf("%s",&input);
		
		// Check if the input is a valid digit
        if (isdigit(input[0]) && strlen(input) == 1) {
            choice = atoi(input);
        } else {
            printf("Invalid option! Please enter a number between 1 and 4. (Press Any Key to Continue)\n");
            getch();
            continue;
        }
		
		
	         
        if (choice == 1) {
            //LoginUser();
        } else if (choice == 2) {
            //RegisterUser();
        } else if (choice == 3) {
            AdminMenu();
        } else if (choice == 4) {
            break;
        } else {
            printf("\nChoice Error: Please input a valid number! (Press Any Key to Continue)\n");
            getch(); // Wait for user input before clearing the screen
        }
    }

    return 0;
}

void AdminMenu(){
	
	char choice[50];
    int choice2;

    while (1) { // Infinite loop until correct password is entered or 'x' is entered
        printf("\nEnter Admin Passcode ('x' to exit): ");
        scanf("%s", choice);

        if (strcmp(choice, "pass12345") == 0) {
        	system("cls");   
            printf("Admin Menu\n");
            printf("1. Approve Pending User\n");
            printf("2. Deny Pending User\n");
            printf("3. List Registered User\n");
            printf("4. List of all Transactions\n");
            printf("\nSelect a Choice: ");
            scanf("%d", &choice2);

            if (choice2 == 1)
             	printf("Success...\n");
                //ApprovePendingUser();
            else if (choice2 == 2)
            	printf("Success...\n");
                //DenyPendingUser();
            else if (choice2 == 3)
            	printf("Success...\n");
            	//ListRegisteredUser();
            else if (choice2 == 4)
            	printf("Success...\n");
            	//ListTransact();
            else
                printf("Invalid choice. Returning to main menu...\n");

            break; // Exit the loop after successful login
        } else if (strcmp(choice, "x") == 0) {
            printf("Exiting...\n");
            getch();
            break;
        } else {
            printf("Wrong password. Try again.\n");
        }
    }
    
}
