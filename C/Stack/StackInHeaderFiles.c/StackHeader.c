#include "StackArrayHeader.h"
#include <stdio.h>

// Initialize the stack
void init(Stack *S) {
    S->top = -1;  // Empty stack
}

// Push an element onto the stack
void push(Stack *S, int data) {
    if (S->top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    S->top++;
    S->data[S->top] = data;
}

// Pop an element from the stack
int pop(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;  // Return error value
    }
    int popped = S->data[S->top];
    S->top--;
    return popped;
}

// Display all elements in the stack
void display(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack elements (top to bottom): ");
    for (int i = S->top; i >= 0; i--) {
        printf("%d ", S->data[i]);
    }
    printf("\n");
}

// Peek at the top element without removing it
int peek(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty\n");
        return -1;  // Return error value
    }
    return S->data[S->top];
}

// Check if stack is empty
bool isEmpty(Stack *S) {
    return (S->top == -1);
}