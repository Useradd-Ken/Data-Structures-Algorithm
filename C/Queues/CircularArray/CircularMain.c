#include "CircularArray.c"

void main(){
    Queues Q;
    initQueue(&Q);
    enqueue(&Q,10);
    enqueue(&Q,20);
    enqueue(&Q,30);
    enqueue(&Q,40);
    display(Q);
    dequeue(&Q);
    display(Q);
}