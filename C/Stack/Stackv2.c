#include <stdio.h>
#define MAX 0xA

typedef struct{
    int data[MAX];
    int top;
}Stack;


void init(Stack*L){
    L->top = -1;
}
