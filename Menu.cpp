#include <stdio.h>
#include <stdlib.h>  // for system() function

// Function prototypes
void option1();
void option2();
void option3();

int main() {
    int choice;

    do {
        // Clear the screen
        #ifdef _WIN32
            system("cls");  // For Windows
        #else
            system("clear");  // For Unix-like systems
        #endif

        // Display the menu
        printf("Menu:\n");
        printf("1. Option 1\n");
        printf("2. Option 2\n");
        printf("3. Option 3\n");
        printf("4. Exit\n");

        // Prompt user for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user's choice
        switch (choice) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);  // Repeat until the user selects the "Exit" option

    return 0;
}

// Function definitions
void option1() {
    int subChoice;
    do {
        // Clear the screen
        #ifdef _WIN32
            system("cls");  // For Windows
        #else
            system("clear");  // For Unix-like systems
        #endif

        // Display Option 1 window
        printf("Option 1 window.\n");
        printf("1. Perform Task\n");
        printf("2. Return to Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &subChoice);

        switch (subChoice) {
            case 1:
                printf("Performing Task for Option 1.\n");
                // Add your code for performing the task
                break;
            case 2:
                printf("Returning to Menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (subChoice != 2);
}

void option2() {
    // Similar structure as option1
    // ...
}

void option3() {
    // Similar structure as option1
    // ...
}
