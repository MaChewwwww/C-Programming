#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node {
    int x;
    struct node *next;
};

struct node *head, *curr, *tail;

void sortLinkedList(struct node *head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct node *current = head;
    struct node *index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->x > index->x) {
                temp = current->x;
                current->x = index->x;
                index->x = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void displayLinkedList(struct node *head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%3d", temp->x);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = curr = tail = NULL;

    curr = (struct node *) malloc(sizeof(struct node));

    printf("Enter a value for x: ");
    scanf("%d", &curr->x);

    while (curr->x != 0) {
        if (head == NULL) {
            head = curr;
            head->next = NULL;
            tail = curr;
        } else {
            tail->next = curr;
            curr->next = NULL;
            tail = curr;
        }

        curr = (struct node *) malloc(sizeof(struct node));

        printf("Enter a value for x: ");
        scanf("%d", &curr->x);
    }

    if (head == NULL) {
        printf("No record/s entered!");
        goto tapos;
    }

    printf("\nOriginal linked list data:\n");
    displayLinkedList(head);

    sortLinkedList(head);

    printf("\nSorted linked list data:\n");
    displayLinkedList(head);

tapos:
    getch();
    return 0;
}

