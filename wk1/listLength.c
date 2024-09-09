#include <stdio.h>
#include <stdlib.h>

// Our optimisation:
struct list {
    struct node *head;
    // any other fields
    int size;
};

struct node {
    int value;
    struct node *next;
};

// return the number of nodes in a linked list, given its head
int listLength(struct node *list);

// use a while loop
int listLength(struct node *list) {
    int res = 0;
    struct node *curr = list;

    while (curr != NULL) {
        res++;
        curr = curr->next;
    }

    return res;
}

// use a for loop
int listLength(struct node *list) {
    int res = 0;

    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        res++;
    }

    return res;
}
