#include <stdio.h>
#define MAX 10

typedef struct{
    int arr[MAX];
    int lastNdx;
}Tree;

void initTree(Tree *t){
    t->lastNdx=1;
}

void insertElem(Tree*t,int elem){
    if(t->lastNdx<MAX){
        t->arr[t->lastNdx]=elem;
        t->lastNdx++;
    }
}

void main(){
    Tree t;
    initTree(&t);
    insertElem(&t,5);
    insertElem(&t,10);
    insertElem(&t,15);

}