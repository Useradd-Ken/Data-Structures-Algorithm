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
