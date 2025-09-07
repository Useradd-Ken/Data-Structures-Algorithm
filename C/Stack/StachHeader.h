#ifndef StackArrayyHeader_h
#define StackArrayyHeader_h

#include <stdio.h>
#include <stdbool.h>
#define MAX 0xA

typedef struct{
    int data[MAX];
    int top;
}Stack;

void init(Stack*L);
void push(Stack*S,int data);
int pop(Stack*S);
void display(Stack*S);
int peek(Stack*S);
bool isEmpty(Stack*S);

#endif