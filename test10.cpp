#include <stdio.h>
#include <stdlib.h>

struct element {
    int val;
    struct element *next;
};

struct element *createNode(int val) {
    struct element *newElem = (struct element *)malloc(sizeof(struct element));
    newElem->val = val;
    newElem->next = NULL;
    return newElem;
}

void addElement(struct element **head, int val) {
    struct element *newElem = createNode(val);
    if (*head == NULL) {
        *head = newElem;
    } else {
        struct element *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newElem;
    }
}

struct element *mergeLists(struct element *lst1, struct element *lst2) {
    struct element *merged = NULL;
    struct element *tail = NULL;

    while (lst1 != NULL && lst2 != NULL) {
        if (lst1->val <= lst2->val) {
            if (merged == NULL) {
                merged = lst1;
                tail = lst1;
            } else {
                tail->next = lst1;
                tail = tail->next;
            }
            lst1 = lst1->next;
        } else {
            if (merged == NULL) {
                merged = lst2;
                tail = lst2;
            } else {
                tail->next = lst2;
                tail = tail->next;
            }
            lst2 = lst2->next;
        }
    }

    if (lst1 != NULL) {
        tail->next = lst1;
    }
    if (lst2 != NULL) {
        tail->next = lst2;
    }

    return merged;
}

void print(struct element *head) {
    while (head != NULL) {
        printf("%3d", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct element *lst1 = NULL;
    struct element *lst2 = NULL;
    int num, i;

    printf("List 1 - Enter 5 Numbers: \n");
    for (i = 0; i < 5; ++i) {
        scanf("%d", &num);
        addElement(&lst1, num);
    }

    printf("List 2 - Enter 5 Numbers: \n");
    for (i = 0; i < 5; ++i) {
        scanf("%d", &num);
        addElement(&lst2, num);
    }

    struct element *merged = mergeLists(lst1, lst2);

    printf("\nMerged Sorted Linked List: ");
    print(merged);

    return 0;
}

