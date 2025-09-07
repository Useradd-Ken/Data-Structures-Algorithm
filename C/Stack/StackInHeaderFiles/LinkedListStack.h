#ifndef StackLinkedListHeader_h
#define StackLinkedListHeader_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}*Node;

typedef struct{
    Node Stack;
    int top;
}Stack;

void init(Stack*L);
void push(Stack*S,int data);
int pop(Stack*S);
void display(Stack*S);
int peek(Stack*S);
bool isEmpty(Stack*S);

#endif