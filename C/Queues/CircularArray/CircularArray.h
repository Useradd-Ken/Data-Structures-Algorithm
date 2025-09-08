#ifndef CircularArray_h
#define CircularArray_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 0xA10

typedef struct{
    int arr[MAX];
    int front;
    int rear;
}Queues;

void initQueue(Queues *Q);
bool isFull(Queues Q);
bool isEmpty(Queues Q);
void enqueue(Queues *Q,int data);
int dequeue(Queues *Q);
void display(Queues Q);

#endif