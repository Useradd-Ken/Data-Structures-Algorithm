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
    if(!isFull(*Q)){
        Q->rear = (Q->rear+1)%MAX;
        Q->arr[Q->rear] = data;
    }
}

void dequeue(Queues*Q){
    if(!isEmpty(*Q)){
        Q->front = (Q->front+1)%MAX;
    }
}

