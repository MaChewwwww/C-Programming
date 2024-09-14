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
            head->next = head;
            tail = curr;
        }
        else{ // reallocate curr and tail to its new memory allocation each interation
            tail->next = curr;
            curr->next = head; // point curr->next into the memory allocation of head to make a circular linked list
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
    else{
        int sum;
        struct node *temp = head; // create a temporary ptr variable for incrementation and movement throughout list
        do{
            sum += temp->x; // sum every data inside the linked list
            temp = temp->next;
        }while(temp != head); // check if temp completes the whole loop and gets back to the starting point (head)
        printf("Sum of the values of linked list: %d", sum);
    }

    return 0;
}


