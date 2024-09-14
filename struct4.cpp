#include<stdio.h>
#include<stdlib.h>

// Define a structure for the nodes of the linked list
struct node {
    int x;
    struct node *next;
};

// Global pointer variables to maintain the head, current, and tail of the linked list
struct node *head, *curr, *tail;

// Function to add a node to the linked list
void addNode(int value) {
    // Allocate memory for the new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->x = value;
    newNode->next = NULL;

    // If the linked list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        // Otherwise, add the new node to the end of the list
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to convert the linked list values into an array
int* convertToArray(int size) {
    // Allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));

    // Traverse the linked list and copy values to the array
    struct node *temp = head;
    int i = 0;
    while (temp != NULL) {
        array[i++] = temp->x;
        temp = temp->next;
    }

    return array;
}

// Function to print the linked list
void printLinkedList() {
    // If the linked list is empty, print a message
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    // Traverse the linked list and print each value
    struct node *temp = head;
    while (temp != NULL) {
        printf("%3d", temp->x);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the array
void printArray(int *array, int size) {
    // Print the array values
    printf("Array values:\n");
    for (int i = 0; i < size; i++) {
        printf("%3d", array[i]);
    }
    printf("\n");
}

int main() {
    head = curr = tail = NULL;

    // Take input from the user until they enter 0
    int value;
    printf("Enter integer values for the linked list (enter 0 to terminate):\n");
    do {
        printf("Enter a value: ");
        scanf("%d", &value);
        if (value != 0) {
            addNode(value);
        }
    } while (value != 0);

    // Calculate the size of the linked list
    int size = 0;
    struct node *temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    // Convert the linked list values into an array
    int *array = convertToArray(size);

    // Printing the data in the Singly linked list
    printf("\nLinked list data:\n");
    printLinkedList();

    // Printing the array values
    printArray(array, size);

    // Free allocated memory for the array
    free(array);

    return 0;
}

