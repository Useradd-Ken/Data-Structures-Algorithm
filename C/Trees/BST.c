#include <stdio.h>
#include <stdlib.h>
#define MAX 10


typedef struct node{
    int arr[MAX];
    int lastNdx;
}BST;


void initBST(BST*t){
    t->lastNdx=-1;
}

void insertElem(BST*t,int elem){
    if(t->lastNdx<MAX)
    {
        t->arr[++t->lastNdx]=elem;
    }
}

// Insert in the Partially Ordered Tree from the BST
//LEFT-CHILD = (NODE_INDEX * 2) +1
//RIGHT-CHILD = (NODE_INDEX * 2) +2
//PARENT = (NODE_INDEX -1) /2

// MAX HEAP (PARENT > CHILDREN NODES)
// MIN HEAP (PARENT < CHILDREN NODES)

void insertPOT(BST*T,BST*POT){


}

void main()
{
    BST t,POT;
    initBST(&t);
    initBST(&POT);
    insertElem(&t,9);
    insertElem(&t,10);
    insertElem(&t,2);
    insertElem(&t,5);
    insertElem(&t,6);
    insertElem(&t,8);
    insertElem(&t,11);
    insertElem(&t,15);
    insertElem(&t,16);
    insertElem(&t,3);
    for(int i=0;i<=t.lastNdx;i++){
        printf("[%d]\t",t.arr[i]);
    }

}

