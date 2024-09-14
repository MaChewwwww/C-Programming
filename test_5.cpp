#include <stdio.h>
#include <stdlib.h>

struct node{ // define node structure
    int x;
    struct node *next;
};
struct node *head, *curr, *tail; // declare pointer variables

int main(){
    int ctr;
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
            ctr++; // for the size of array
        }
        else{ // reallocate curr and tail to its new memory allocation each interation
            tail->next = curr;
            curr->next = NULL;
            tail = curr;
            ctr++; // for the size of array
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
        int array[ctr] = {0}; // create one dimensional array
        int i = 0;
        struct node *temp = head; // create a temporary ptr variable to not destroy the original list
        // loop for insertion of linked list values into array
        while(temp != NULL){
            array[i] = temp->x;
            temp = temp->next;
            i++;
        }
        // print linked list values
        printf("Linked List Values: ");
        struct node *print = head; // create a temporary ptr variable to not destroy the original list
        while(print != NULL){
            printf("%3d", print->x);
            print = print->next;
        }
        printf("\n");
        // print array values
        printf("Array Values: ");
        for(int i = 0; i<ctr; i++){
            printf("%3d", array[i]);
        }
    }

    return 0;
}
