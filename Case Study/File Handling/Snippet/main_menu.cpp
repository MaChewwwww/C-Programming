#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>

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
            //AdminMenu();
        } else if (choice == 4) {
            break;
        } else {
            printf("\nChoice Error: Please input a valid number! (Press Any Key to Continue)\n");
            getch(); // Wait for user input before clearing the screen
        }
    }

    return 0;
}
