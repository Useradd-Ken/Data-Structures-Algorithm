#include <stdio.h>
#define MAX 0xA

typedef struct{
    int data[MAX];
    int top;
}Stack;

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
    return (S->top >= 0) ? S->data[S->top--] : retVal;
}



void main(){
    Stack myStack;
    printf("Stack initialized with top at %d\n", myStack.top);
    init(&myStack);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    
}