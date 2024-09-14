#include <stdio.h>
#include <stdlib.h>

// Define structure for singly linked list node
struct node {
    int x;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->x = data;
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
    }
}

// Function to merge two sorted linked lists
struct node *mergeSortedLists(struct node *list1, struct node *list2) {
    struct node *mergedList = NULL;
    struct node *tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->x <= list2->x) {
            if (mergedList == NULL) {
                mergedList = list1;
                tail = list1;
            } else {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        } else {
            if (mergedList == NULL) {
                mergedList = list2;
                tail = list2;
            } else {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL) {
        tail->next = list1;
    }
    if (list2 != NULL) {
        tail->next = list2;
    }

    return mergedList;
}


// Function to print the linked list
void printList(struct node *head) {
    while (head != NULL) {
        printf("%3d", head->x);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    int num, i;

    // Input elements for list1
    printf("Enter 5 numbers for list1:\n");
    for (i = 0; i < 5; ++i) {
        scanf("%d", &num);
        insertNode(&list1, num);
    }

    // Input elements for list2
    printf("Enter 5 numbers for list2:\n");
    for (i = 0; i < 5; ++i) {
        scanf("%d", &num);
        insertNode(&list2, num);
    }

    // Merge the two lists into one sorted list
    struct node *mergedList = mergeSortedLists(list1, list2);

    // Print the merged list
    printf("\nMerged Sorted Linked List: ");
    printList(mergedList);

    return 0;
}

