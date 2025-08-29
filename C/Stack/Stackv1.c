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
    return (S->top >= 0) ? (S->data[S->top--]) : retVal;
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

void main(){
    Stack myStack;
    init(&myStack);
    printf("Stack initialized with top at %d\n", myStack.top);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
      display(&myStack);
    printf("%d popped from stack\n", pop(&myStack));
    printf("%d popped from stack\n", pop(&myStack));
    printf("Stack after pop operation: ");
    display(&myStack);
    
}