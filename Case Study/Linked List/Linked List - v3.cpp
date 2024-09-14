#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the linked list
struct node {
    int x;              // Value of the node
    struct node *next;  // Pointer to the next node in the list
};

// Declare head, curr, and tail pointers for the linked list
struct node *head, *curr, *tail;

// Function declarations
void CreateList();
void SortList();
void DisplayList();
void InsertNode();
void DeleteNode();
void SearchNode();

int main() {
    int choice;        // Variable to store the user's menu choice
    char input[10];    // Buffer to store the user's input

    while (1) {  // Infinite loop to keep the menu running until the user decides to exit
        system("cls");  // Clear the screen
        printf("Welcome to the Linked List Program\n\n");
        printf("1. Create a Linear Linked List\n");
        printf("2. Display a Linear Linked List\n");
        printf("3. Insert a number in the Linear Linked List\n");
        printf("4. Delete a number in the Linear Linked List\n");
        printf("5. Search a number\n");
        printf("6. Exit\n");

        printf("\nSelect a Choice : ");
        scanf("%s", input);  // Read the user's input

        // Check if the input is a valid single digit
        if (isdigit(input[0]) && strlen(input) == 1) {
            choice = atoi(input);  // Convert input to an integer
        } else {
            printf("Invalid option! Please enter a number between 1 and 6. (Press Any Key to Continue)\n");
            getch();  // Wait for user input before continuing
            continue; // Continue the loop to prompt the user again
        }

        // Switch case to handle the user's menu choice
        switch (choice) {
            case 1:
                CreateList();  // Create a linked list
                break;
            case 2:
                DisplayList();  // Display the linked list
                break;
            case 3:
                InsertNode();  // Insert a node into the linked list
                break;
            case 4:
                DeleteNode();  // Delete a node from the linked list
                break;
            case 5:
                SearchNode();  // Search for a node in the linked list
                break;
            case 6:
                printf("Exiting the program...");
                getch();  // Wait for user input before exiting
                return 0;  // Exit the program
            default:
                printf("\nChoice Error: Please input a valid number! (Press Any Key to Continue)\n");
                getch();  // Wait for user input before continuing
        }
    }
}

// Function to create a linked list
void CreateList() {
    printf("\nEnter 'X' to Exit\n");
    head = curr = tail = NULL;  // Initialize the head, curr, and tail pointers to NULL

    while (1) {  // Infinite loop to continuously accept user input
        int isValid = 0;  // Flag to check if the input is valid
        while (1) {  // Inner loop for input validation
            char input[10];  // Buffer to store the user's input
            printf("\nEnter a value for X: ");
            scanf("%s", input);  // Read the user's input

            // Check if input is 'X' or 'x' to exit
            if (strcasecmp(input, "X") == 0) {
                goto exit_loop;  // Exit both loops if the user enters 'X'
            }

            // Check if input is a valid integer (positive or negative)
            isValid = 1;  // Assume the input is valid
            int startIdx = 0;

            if (input[0] == '-') {
                startIdx = 1;  // Start checking digits from index 1 if there's a negative sign
            }

            for (int i = startIdx; i < strlen(input); i++) {
                if (!isdigit(input[i])) {
                    isValid = 0;  // Set isValid to 0 if any character is not a digit
                    break;
                }
            }

            if (isValid) {
                // Allocate memory for the new node only after validation
                curr = (struct node *)malloc(sizeof(struct node));
                if (curr == NULL) {
                    printf("Memory allocation failed!\n");
                    return;
                }
                curr->x = atoi(input);  // Convert input to an integer and assign to the node
                break;  // Exit the inner loop if a valid integer is entered
            } else {
                printf("\nPlease enter a valid integer!\n");
            }
        }

        // Insert the new node into the linked list
        if (head == NULL) {  // If the list is empty, set the new node as the head
            head = curr;
            head->next = NULL;
            tail = curr;
        } else {  // Otherwise, append the new node to the end of the list
            tail->next = curr;
            curr->next = NULL;
            tail = curr;
        }
    }

exit_loop:
    // If head is NULL, then no data was entered
    if (head == NULL) {
        printf("No record/s entered!");
        goto tapos;
    }

    // Print the data in the linked list
    printf("\n\nLinked list data:\n");
    curr = head;  // Start from the head node
    while (curr != NULL) {
        printf("%3d ", curr->x);
        curr = curr->next;  // Move to the next node
    }

    // Sort the list after creation
    SortList();

    // Print the sorted data in the linked list
    printf("\n\nSorted list data:\n");
    curr = head;  // Start from the head node
    while (curr != NULL) {
        printf("%3d ", curr->x);
        curr = curr->next;  // Move to the next node
    }

    printf("\n\n(Press Any Key to go back to the Menu).");
tapos:
    getch();  // Wait for user input before continuing
}

// Function to sort the linked list in ascending order
void SortList() {
    int temp;  // Temporary variable for swapping values

    if (head == NULL) {  // If the list is empty, print a message and return
        printf("List is empty.\n");
        return;
    }

    curr = head;  // Start from the head node
    while (curr->next != NULL) {
        tail = curr->next;  // Set tail to the next node
        while (tail != NULL) {
            if (curr->x > tail->x) {  // If the current node's value is greater than the next node's value
                // Swap the values of the nodes
                temp = curr->x;
                curr->x = tail->x;
                tail->x = temp;
            }
            tail = tail->next;  // Move to the next node
        }
        curr = curr->next;  // Move to the next node
    }
}

// Function to display the linked list
void DisplayList() {
    printf("\n\nLinked list data:\n");
    curr = head;  // Start from the head node
    while (curr != NULL) {
        printf("%3d ", curr->x);
        curr = curr->next;  // Move to the next node
    }
    getch();  // Wait for user input before continuing
}

// Function to insert a node into the linked list in sorted order
void InsertNode() {
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y') {
        int num;  // Variable to store the number to be inserted
        int isValid = 0;  // Flag to check if the input is valid

        while (1) {  // Inner loop for input validation
            char input[10];  // Buffer to store the user's input
            printf("\nEnter a number to insert: ");
            scanf("%s", input);  // Read the user's input

            // Check if input is a valid integer (positive or negative)
            isValid = 1;  // Assume the input is valid
            int startIdx = 0;

            if (input[0] == '-') {
                startIdx = 1;  // Start checking digits from index 1 if there's a negative sign
            }

            for (int i = startIdx; i < strlen(input); i++) {
                if (!isdigit(input[i])) {
                    isValid = 0;  // Set isValid to 0 if any character is not a digit
                    break;
                }
            }

            if (isValid) {
                num = atoi(input);  // Convert input to an integer
                break;  // Exit the inner loop if a valid integer is entered
            } else {
                printf("\nPlease enter a valid integer!\n");
            }
        }

        // Create a new node
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        new_node->x = num;  // Assign the number to the new node
        new_node->next = NULL;

        // Insert the new node into the linked list in sorted order
        if (head == NULL || head->x >= num) {
            // Insert at the beginning of the list
            new_node->next = head;
            head = new_node;
        } else {
            // Traverse the list to find the insertion position
            struct node *prev = head;
            struct node *curr = head->next;
            while (curr != NULL && curr->x < num) {
                prev = curr;
                curr = curr->next;
            }

            // Insert the new node between prev and curr
            prev->next = new_node;
            new_node->next = curr;
        }

        printf("Number %d inserted into the list.\n", num);
        printf("\nDo you want to insert another number? (Y/N) : ");
        scanf(" %c", &choice);  // Read the user's choice
    }

    printf("\n(Press Any Key to Continue)\n");
    printf("Exiting the Insertion Program...");
    getch();  // Wait for user input before continuing
}

// Function to delete a node from the linked list
void DeleteNode() {
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y') {
        int num;  // Variable to store the number to be deleted
        int isValid = 0;  // Flag to check if the input is valid

        while (!isValid) {  // Inner loop for input validation
            char input[10];  // Buffer to store the user's input
            printf("\nEnter a number to delete: ");
            scanf("%s", input);  // Read the user's input

            // Check if input is a valid integer (positive or negative)
            isValid = 1;  // Assume the input is valid
            int startIdx = 0;

            if (input[0] == '-') {
                startIdx = 1;  // Start checking digits from index 1 if there's a negative sign
            }

            for (int i = startIdx; i < strlen(input); i++) {
                if (!isdigit(input[i])) {
                    isValid = 0;  // Set isValid to 0 if any character is not a digit
                    break;
                }
            }

            if (isValid) {
                num = atoi(input);  // Convert input to an integer
            } else {
                printf("\nPlease enter a valid integer!\n");
            }
        }

        struct node *temp = head;  // Start from the head node
        struct node *prev = NULL;  // Pointer to keep track of the previous node
        int found = 0;  // Flag to indicate whether the number is found in the list

        // Traverse the list to find the node to be deleted
        while (temp != NULL) {
            if (temp->x == num) {
                found = 1;  // Set found to 1 if the number is found
                // If the node to be deleted is the head node
                if (prev == NULL) {
                    head = temp->next;  // Update head to the next node
                    free(temp);  // Free the memory of the deleted node
                    temp = head;  // Update temp to the new head
                } else {
                    prev->next = temp->next;  // Update the previous node's next pointer
                    free(temp);  // Free the memory of the deleted node
                    temp = prev->next;  // Update temp to the next node after deletion
                }
            } else {
                prev = temp;  // Update prev to the current node
                temp = temp->next;  // Move to the next node
            }
        }

        if (!found) {
            printf("Number %d is not in the list. Cannot delete.\n", num);
        } else {
            printf("Number %d deleted from the list.\n", num);
        }

        printf("\nDo you want to delete another number? (Y/N) : ");
        scanf(" %c", &choice);  // Read the user's choice
    }

    printf("\n(Press Any Key to Continue)\n");
    printf("Exiting the Deletion Program...");
    getch();  // Wait for user input before continuing
}

// Function to search for a node in the linked list and count duplicates
void SearchNode() {
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y') {
        int num;  // Variable to store the number to be searched
        int isValid = 0;  // Flag to check if the input is valid

        while (!isValid) {  // Inner loop for input validation
            char input[10];  // Buffer to store the user's input
            printf("\nEnter a number to search: ");
            scanf("%s", input);  // Read the user's input

            // Check if input is a valid integer (positive or negative)
            isValid = 1;  // Assume the input is valid
            int startIdx = 0;

            if (input[0] == '-') {
                startIdx = 1;  // Start checking digits from index 1 if there's a negative sign
            }

            for (int i = startIdx; i < strlen(input); i++) {
                if (!isdigit(input[i])) {
                    isValid = 0;  // Set isValid to 0 if any character is not a digit
                    break;
                }
            }

            if (isValid) {
                num = atoi(input);  // Convert input to an integer
            } else {
                printf("\nPlease enter a valid integer!\n");
            }
        }

        struct node *current_node = head;  // Start from the head node
        int count = 0;  // Counter to count the instances of the number

        // Traverse the list to find the node and count instances
        while (current_node != NULL) {
            if (current_node->x == num) {
                count++;  // Increment the count if the number is found
            }
            current_node = current_node->next;  // Move to the next node
        }

        if (count > 0) {
            printf("%d is in the list %d time(s).\n", num, count);
        } else {
            printf("%d is not in the list.\n", num);
        }

        printf("\nDo you want to search another number? (Y/N) : ");
        scanf(" %c", &choice);  // Read the user's choice
    }

    printf("\n(Press Any Key to Continue)\n");
    printf("Exiting the Search Program...");
    getch();  // Wait for user input before continuing
}

