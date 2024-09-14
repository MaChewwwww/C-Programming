#include <stdio.h>
#include <stdlib.h>

// Define structure for doubly linked list node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(struct node **headRef, int data) {
    struct node *newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct node *temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to check if a doubly linked list is a palindrome
int isPalindrome(struct node *head) {
    struct node *front = head;
    struct node *rear = head;

    // Move rear pointer to the end of the list
    while (rear->next != NULL) {
        rear = rear->next;
    }

    // Check if the list is a palindrome
    while (front != NULL && rear != NULL) {
        if (front->data != rear->data) {
            return 0;
        }
        front = front->next;
        rear = rear->prev;
    }

    return 1;
}

// Function to print the doubly linked list
void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int num, i;

    // Input elements for the doubly linked list
    printf("Enter elements for the doubly linked list (enter 0 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        insertNode(&head, num);
    }

    // Check if the doubly linked list is a palindrome
    if (isPalindrome(head)) {
        printf("The doubly linked list is a palindrome.\n");
    } else {
        printf("The doubly linked list is not a palindrome.\n");
    }

    return 0;
}

