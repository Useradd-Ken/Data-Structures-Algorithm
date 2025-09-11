#include "LinkedListQueue.h"

void initQueue(Queue*Q){
    Q->front = Q->rear = NULL;
}

void enqueue(Queue*Q,int data){
    Nodeptr newNode = (Nodeptr)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(Q->front!=NULL){
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    else{
        Q->front = Q->rear = newNode;
    }
}

void dequeue(Queue*Q){
    if(Q->front!=NULL){
        Nodeptr temp = Q->front;
        Q->front = temp->next;
        free(temp);
        if(Q->front==NULL){
            Q->rear = NULL;
        }
    }
}

void display(Queue Q){
    Nodeptr temp = Q.front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

