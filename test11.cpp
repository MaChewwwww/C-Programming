#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in a doubly linked list
struct link {
    int data;
    struct link *prev;
    struct link *next;
};

// Function to create a new node
struct link *createNewLink(int value) {
    struct link *newLink = (struct link *)malloc(sizeof(struct link));
    newLink->data = value;
    newLink->prev = NULL;
    newLink->next = NULL;
    return newLink;
}

// Function to insert a node at the end of the list
void insertLink(struct link **headRef, int value) {
    struct link *newLink = createNewLink(value);
    if (*headRef == NULL) {
        *headRef = newLink;
    } else {
        struct link *temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newLink;
        newLink->prev = temp;
    }
}

// Function to check if a doubly linked list is a palindrome
int isListPalindrome(struct link *head) {
    struct link *front = head;
    struct link *rear = head;

    // Move the rear pointer to the end of the list
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
void printLinkedList(struct link *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct link *head = NULL;
    int number, i;

    // Input elements for the doubly linked list
    printf("Enter numbers for the doubly linked list (enter 0 to stop):\n");
    while (1) {
        scanf("%d", &number);
        if (number == 0) break;
        insertLink(&head, number);
    }

    // Check if the doubly linked list is a palindrome
    if (isListPalindrome(head)) {
        printf("The doubly linked list is a palindrome.\n");
    } else {
        printf("The doubly linked list is not a palindrome.\n");
    }

    return 0;
}

