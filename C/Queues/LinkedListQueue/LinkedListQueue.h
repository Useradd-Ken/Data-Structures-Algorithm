#ifndef LinkedListQueue_h
#define LinkedListQueue_h

#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}*Nodeptr;

typedef struct{
    Nodeptr front;
    Nodeptr rear;
}Queue;

void initQueue(Queue* Q);
void enqueue(Queue* Q, int x);
void dequeue(Queue* Q);
void display(Queue Q);

#endif