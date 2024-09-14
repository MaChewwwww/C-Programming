#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int x;
    struct node *next;
};

struct node *head, *curr, *tail;

void CreateList();
void SortList();
void DisplayList();
void InsertNode();
void DeleteNode();
void SearchNode();

int main() {
    int choice;
    char input[10];

    while (1) {
        system("cls");
        printf("Welcome to the Linked List Program\n\n");
        printf("1. Create a Linear Linked List\n");
        printf("2. Display a Linear Linked List\n");
        printf("3. Insert a number in the Linear Linked List\n");
        printf("4. Delete a number in the Linear Linked List\n");
        printf("5. Search a number\n");
        printf("6. Exit\n");

        printf("\nSelect a Choice : ");
        scanf("%s", input);

        // Check if the input is a valid digit
        if (isdigit(input[0]) && strlen(input) == 1) {
            choice = atoi(input);
        } else {
            printf("Invalid option! Please enter a number between 1 and 6. (Press Any Key to Continue)\n");
            getch();
            continue;
        }

        switch (choice) {
            case 1:
                CreateList();
                break;
            case 2:
                DisplayList();
                break;
            case 3:
                InsertNode();
                break;
            case 4:
                DeleteNode();
                break;
            case 5:
                SearchNode();
                break;
            case 6:
                printf("Exiting the program...");
                getch();
                return 0;
            default:
                printf("\nChoice Error: Please input a valid number! (Press Any Key to Continue)\n");
                getch(); // Wait for user input before clearing the screen
        }
    }
}

void CreateList() {
    printf("\nEnter 'X' to Exit\n");
    head = curr = tail = NULL; // Initialize pointer variables to NULL

    while (1) {
        int isValid = 0;
        while (1) {
            char input[10];
            printf("\nEnter a value for X: ");
            scanf("%s", input);

            // Check if input is 'X' or 'x' to exit
            if (strcasecmp(input, "X") == 0) {
                goto exit_loop; // Exit both loops
            }

            // Check if input is a valid integer (positive or negative)
            isValid = 1; // Assume the input is valid
            int startIdx = 0;

            if (input[0] == '-') {
                startIdx = 1; // Start checking digits from index 1 if there's a negative sign
            }

            for (int i = startIdx; i < strlen(input); i++) {
                if (!isdigit(input[i])) {
                    isValid = 0;
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
                curr->x = atoi(input);
                break; // Exit the inner loop if a valid integer is entered
            } else {
                printf("\nPlease enter a valid integer!\n");
            }
        }

        if (head == NULL) { // If true, then the current node (curr) will be the head node
            head = curr;
            head->next = NULL;
            tail = curr;
        } else { // If false, then the current node (curr) will be linked to the previous node
            tail->next = curr;
            curr->next = NULL;
            tail = curr;
        }
    }

exit_loop:
    // If head is NULL, then there were no data entered
    if (head == NULL) {
        printf("No record/s entered!");
        goto tapos;
    }

    // Printing the data in the Singly linked list
    printf("\n\nLinked list data:\n");
    curr = head; // Assign the address pointed to by head to the pointer variable curr
    while (curr != NULL) {
        printf("%3d ", curr->x);
        curr = curr->next;
    }

    // Sort the list after creation
    SortList();

    // Printing the data in the Singly linked list
    printf("\n\nSorted list data:\n");
    curr = head; // Assign the address pointed to by head to the pointer variable curr
    while (curr != NULL) {
        printf("%3d ", curr->x);
        curr = curr->next;
    }

    printf("\n\n(Press Any Key to go back to the Menu).");
tapos:
    getch();
}

void SortList() {
    int temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    curr = head;
    while (curr->next != NULL) {
        tail = curr->next;
        while (tail != NULL) {
            if (curr->x > tail->x) {
                temp = curr->x;
                curr->x = tail->x;
                tail->x = temp;
            }
            tail = tail->next;
        }
        curr = curr->next;
    }
}


void DisplayList() {
    // Printing the data in the Singly linked list
    printf("\n\nLinked list data:\n");
    curr = head; // Assign the address pointed to by head to the pointer variable curr
    while (curr != NULL){
        printf("%3d", curr->x);
        curr = curr->next;
    }
    getch();
}


void InsertNode() {
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y') {
        int num;
        int isValid = 0;

        while (1) {
            char input[10];
            printf("\nEnter a number to insert: ");
            scanf("%s", input);

            // Check if input is a valid integer (positive or negative)
            isValid = 1; // Assume the input is valid
            int startIdx = 0;

            if (input[0] == '-') {
                startIdx = 1; // Start checking digits from index 1 if there's a negative sign
            }

            for (int i = startIdx; i < strlen(input); i++) {
                if (!isdigit(input[i])) {
                    isValid = 0;
                    break;
                }
            }

            if (isValid) {
                num = atoi(input);
                break; // Exit the inner loop if a valid integer is entered
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
        new_node->x = num;
        new_node->next = NULL;

        if (head == NULL || head->x >= num) {
            // Insert at the beginning of the list
            new_node->next = head;
            head = new_node;
        } else {
            // Traverse the list to find insertion position
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
        scanf(" %c", &choice); // Corrected to read a single character
    }

    printf("\n(Press Any Key to Continue)\n");
    printf("Exiting the Insertion Program...");
    getch();
}


void DeleteNode() {
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y') {
        int num;
        int isValid = 0;

        while (!isValid) {
            char input[10];
            printf("\nEnter a number to delete: ");
            scanf("%s", input);

            // Check if input is a valid integer (positive or negative)
            isValid = 1; // Assume the input is valid
            int startIdx = 0;

            if (input[0] == '-') {
                startIdx = 1; // Start checking digits from index 1 if there's a negative sign
            }

            for (int i = startIdx; i < strlen(input); i++) {
                if (!isdigit(input[i])) {
                    isValid = 0;
                    break;
                }
            }

            if (isValid) {
                num = atoi(input);
            } else {
                printf("\nPlease enter a valid integer!\n");
            }
        }

        struct node *temp = head;
        struct node *prev = NULL;
        int found = 0; // Flag to indicate whether the number is found in the list

        while (temp != NULL) {
            if (temp->x == num) {
                found = 1;
                // If the node to be deleted is the head node
                if (prev == NULL) {
                    head = temp->next;
                    free(temp);
                    temp = head; // Update temp to the new head
                } else {
                    prev->next = temp->next;
                    free(temp);
                    temp = prev->next; // Update temp to the next node after deletion
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        if (!found) {
            printf("Number %d is not in the list. Cannot delete.\n", num);
        } else {
            printf("Number %d deleted from the list.\n", num);
        }

        printf("\nDo you want to delete another number? (Y/N) : ");
        scanf(" %c", &choice); // Corrected to read a single character
    }

    printf("\n(Press Any Key to Continue)\n");
    printf("Exiting the Deletion Program...");
    getch();
}


void SearchNode() {
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y') {
        int num;
        int isValid = 0;

        while (!isValid) {
            char input[10];
            printf("\nEnter a number to search: ");
            scanf("%s", input);

            // Check if input is a valid integer (positive or negative)
            isValid = 1; // Assume the input is valid
            int startIdx = 0;

            if (input[0] == '-') {
                startIdx = 1; // Start checking digits from index 1 if there's a negative sign
            }

            for (int i = startIdx; i < strlen(input); i++) {
                if (!isdigit(input[i])) {
                    isValid = 0;
                    break;
                }
            }

            if (isValid) {
                num = atoi(input);
            } else {
                printf("\nPlease enter a valid integer!\n");
            }
        }

        struct node *current_node = head;
        int found = 0;

        while (current_node != NULL) {
            if (current_node->x == num) {
                found = 1;
                break;
            }
            current_node = current_node->next;
        }

        if (found) {
            printf("%d is in the list.\n", num);
        } else {
            printf("%d is not in the list.\n", num);
        }

        printf("\nDo you want to search another number? (Y/N) : ");
        scanf(" %c", &choice); // Corrected to read a single character
    }

    printf("\n(Press Any Key to Continue)\n");
    printf("Exiting the Search Program...");
    getch();
}

	

