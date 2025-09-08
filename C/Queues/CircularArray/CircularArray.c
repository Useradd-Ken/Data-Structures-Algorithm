#include "CircularArray.h"

void initQueue(Queues *Q){
    Q->front = 0;
    Q->rear = -1;
}

bool isFull(Queues Q){
    return (Q.rear + 1) % MAX == Q.front;
}

bool isEmpty(Queues Q){
    return Q.rear == -1;
}

void enqueue(Queues *Q,int data){
    if(isFull(*Q)){
        printf("Queue Overflow\n");
        return;
    }
    Q->rear = (Q->rear + 1) % MAX;
    Q->arr[Q->rear] = data;
    if(Q->front == 0 && Q->rear == 0){
        Q->front = 0; // If the first element is added, set front to 0
    }
}