#include <stdio.h>
#include <stdlib.h>

struct node{ // define node structure
    int x;
    struct node *next;
};

struct node *head, *curr, *tail; // declare pointer variables

int main(){
    // make head, curr, and tail's value equals to NULL
    head = curr = tail = NULL;
    // allocate the first memory to curr
    curr = (struct node*)malloc(sizeof(struct node));
    // ask input
    printf("Enter an integer value (0) for exit: ");
    scanf("%d", &curr->x);

    // loop for value entry and create memory allocation for curr each iteration
    while(curr-> x != 0){
        if(head == NULL){ // point head, curr, and tail into one memory allocation (1 time)
            head = curr;
            head->next = NULL;
            tail = curr;
        }
        else{ // reallocate curr and tail to its new memory allocation each interation
            tail->next = curr;
            curr->next = NULL;
            tail = curr;
        }
        // create a new memory allocation for curr
        curr = (struct node*)malloc(sizeof(struct node));

        printf("Enter an integer value (0) for exit: ");
        scanf("%d", &curr->x);
    }
    // check if there's no input from user at all
    if(head == NULL){
        printf("No data entered!");
    }
        struct node *originalHead = head; // creates a copy of original list for printing
        struct node *temp, *current;
        int tempValue;

        current = head;
        // print original list first before the list gets sorted
        printf("Original List:");
        while(originalHead != NULL){
            printf("%3d", originalHead->x);
            originalHead = originalHead->next;
        }
        printf("\n");
        // sort using Balloon sorting technique
        while (current != NULL) {
            temp = current->next;
            while (temp != NULL) {
                if (current->x > temp->x) {
                    tempValue = current->x;
                    current->x = temp->x;
                    temp->x = tempValue;
                }
                temp = temp->next;
            }
            current = current->next;
        }
        // print the sorted list
        printf("Sorted List:");
        while(head != NULL){
            printf("%3d", head->x);
            head = head->next;
        }
        

    return 0;
}

