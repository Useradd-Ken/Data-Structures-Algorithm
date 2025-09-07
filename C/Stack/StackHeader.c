#include "StackHeader.h"

void init(Stack*L);
void push(Stack*S,int data);
int pop(Stack*S);
void display(Stack*S);
int peek(Stack*S);
bool isEmpty(Stack*S);

void init(Stack*L){
    L->top = -1;
}

void push(Stack*S,int data){
if(S->top < MAX) {
        S->data[++S->top] = data;
    } else {
        printf("Stack FULL\n");
    }
}

int pop(Stack*S){
    int retVal = -1;
    return (S->top >= 0) ? (S->data[S->top--]) : retVal;
}

int peek(Stack*S){
    return (S->top >= 0) ? (S->data[S->top]) : -1;
}

void display(Stack*S){
    if(S->top >= 0) {
        for(int i = S->top; i >= 0; i--) {
            printf("%d ", S->data[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}

bool isEmpty(Stack*S){
    return S->top == -1;
}


