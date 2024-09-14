#include<stdio.h>
#include<stdlib.h>

// Define a structure for the nodes of the linked list
struct Node {
    int value;
    struct Node *next;
};

// Global pointer variables to maintain the head, current, and tail of the linked list
struct Node *start, *currentNode, *endNode;

// Function to add a node to the linked list
void insertNode(int data) {
    // Allocate memory for the new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = data;
    newNode->next = NULL;

    // If the linked list is empty, make the new node the start
    if (start == NULL) {
        start = newNode;
        endNode = newNode;
    } else {
        // Otherwise, add the new node to the end of the list
        endNode->next = newNode;
        endNode = newNode;
    }
}

// Function to convert the linked list values into an array
int* convertToArray(int listSize) {
    // Allocate memory for the array
    int *arr = (int *)malloc(listSize * sizeof(int));

    // Traverse the linked list and copy values to the array
    struct Node *temp = start;
    int i = 0;
    while (temp != NULL) {
        arr[i++] = temp->value;
        temp = temp->next;
    }

    return arr;
}

// Function to display the linked list
void displayLinkedList() {
    // If the linked list is empty, display a message
    if (start == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    // Traverse the linked list and display each value
    struct Node *temp = start;
    printf("Linked List Data:\n");
    while (temp != NULL) {
        printf("%3d", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Function to display the array
void displayArray(int *arr, int listSize) {
    // Display the array values
    printf("Array Values:\n");
    for (int i = 0; i < listSize; i++) {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

int main() {
    start = currentNode = endNode = NULL;

    // Take input from the user until they enter 0
    int inputValue;
    printf("Enter integer values for the linked list (Enter 0 to finish):\n");
    do {
        printf("Enter a value: ");
        scanf("%d", &inputValue);
        if (inputValue != 0) {
            insertNode(inputValue);
        }
    } while (inputValue != 0);

    // Calculate the size of the linked list
    int listSize = 0;
    struct Node *tempNode = start;
    while (tempNode != NULL) {
        listSize++;
        tempNode = tempNode->next;
    }

    // Convert the linked list values into an array
    int *arrayValues = convertToArray(listSize);

    // Print the linked list data
    displayLinkedList();

    // Print the array values
    displayArray(arrayValues, listSize);

    // Free memory allocated for the array
    free(arrayValues);

    return 0;
}

