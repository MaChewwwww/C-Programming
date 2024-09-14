#include<stdio.h>
#include<conio.h>
#include<stdlib.h> // Include for malloc

struct Node {
    int data;
    struct Node *next;
};

struct Node *head, *current, *tail;

void findExtremeValues(struct Node *head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    int highest = head->data;
    int lowest = head->data;
    struct Node *temp = head->next;

    while (temp != NULL) {
        if (temp->data > highest)
            highest = temp->data;
        if (temp->data < lowest)
            lowest = temp->data;
        temp = temp->next;
    }

    printf("The highest value in the linked list: %d\n", highest);
    printf("The lowest value in the linked list: %d\n", lowest);
}

int main() {
    head = current = tail = NULL;

    current = (struct Node *) malloc(sizeof(struct Node));

    printf("Enter a value for the first node: ");
    scanf("%d", &current->data);

    while (current->data != 0) {
        if (head == NULL) {
            head = current;
            head->next = NULL;
            tail = current;
        } else {
            tail->next = current;
            current->next = NULL;
            tail = current;
        }

        current = (struct Node *) malloc(sizeof(struct Node));

        printf("Enter a value for the next node (Enter 0 to terminate): ");
        scanf("%d", &current->data);
    }

    if (head == NULL) {
        printf("No records entered.\n");
        goto end;
    }

    printf("\n\nLinked list data:\n\n");
    current = head;
    while (current != NULL) {
        printf("%3d", current->data);
        current = current->next;
    }

    printf("\n\n");
    findExtremeValues(head);

end:
    getch();
    return 0;
}

