#include <stdio.h>
#include <stdlib.h>

// define the node struct
typedef struct node {
    int val;
    struct node *following;
} node;

void append(node** headPtr, int val) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = val;
    newNode->following = NULL;

    if (*headPtr == NULL) {
        *headPtr = newNode;
    } else {
        node* current = *headPtr;
        while (current->following != NULL) {
            current = current->following;
        }
        current->following = newNode;
    }
}

void delete(node** headPtr, int val) {
    node* current = *headPtr;
    node* previous = NULL;

    while (current != NULL) {
        if (current->data == val) {
            if (previous == NULL) {
                *headPtr = current->following;
            } else {
                previous->following= current->following;
            }
            free(current);
            current = NULL;
        } else {
            previous = current;
            current = current->following;
        }
    }
}

