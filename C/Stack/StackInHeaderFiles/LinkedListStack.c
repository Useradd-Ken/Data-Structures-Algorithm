#include "LinkedListStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void init(Stack *S) {
    S->Stack = NULL;  // Initialize the top of the stack to NULL
    S->top = -1;     // Initialize top index
}

void push(Stack *S, int data) {
    Node newNode = (Node)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed! Cannot push %d\n", data);
        return;
    }
    newNode->data = data;
    newNode->next = S->Stack; // Point new node to the current top
    S->Stack = newNode;       // Update top to the new node
    S->top++;                 // Increment top index
}

int pop(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;  // Return error value
    }
    Node temp = S->Stack;
    int popped = temp->data;
    S->Stack = S->Stack->next; // Update top to the next node
    free(temp);                // Free the old top node
    S->top--;                  // Decrement top index
    return popped;
}

void display(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack elements (top to bottom): ");
    Node current = S->Stack;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int peek(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty\n");
        return -1;  // Return error value
    }
    return S->Stack->data;
}

bool isEmpty(Stack *S) {
    return (S->top == -1);
}

