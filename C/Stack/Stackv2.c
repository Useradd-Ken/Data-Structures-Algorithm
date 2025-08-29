#include <stdio.h>
#define MAX 0xA

typedef struct{
    int data[MAX];
    int top;
}Stack;


void init(Stack*L){
    L->top = MAX - 1;
}

int isFull(Stack*S) {
    return S->top == -1;
}

int isEmpty(Stack*S) {
    return S->top == MAX - 1;
}

void push(Stack*S,int data){
    if(!isFull(S)) {
        S->data[S->top--] = data;
    } else {
        printf("Stack FULL\n");
    }
}

int pop(Stack*S){
    int retVal = -1;
    return (!isEmpty(S)) ? (S->data[++S->top]) : retVal;
}

void display(Stack*S){
    if(!isEmpty(S)) {
        for(int i = S->top + 1; i < MAX; i++) {
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

