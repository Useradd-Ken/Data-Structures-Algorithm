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

