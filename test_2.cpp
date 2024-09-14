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
    // check which x (input) has the highest and lowest value among the others
    else{
        int max = head->x; // allocate max variable to the first memory location for reference
        int min = head->x; // allocate min variable to the first memory location for reference
        while(head != NULL){
            if(head->x > max){
                max = head->x;
            }
            if(head->x < min){
                min = head->x;
            }
            head = head->next;
        }
        printf("Highest value in the linked list: %d\n", max);
        printf("Lowest value in the linked list: %d\n", min);
    }

    return 0;
}


