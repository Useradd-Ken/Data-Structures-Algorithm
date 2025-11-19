#include <stdio.h>
#define MAX 10

typedef struct{
    int arr[MAX];
    int lastNdx;
}Tree;

void initTree(Tree *t){
    t->lastNdx=-1;
}

void insertElem(Tree*t,int elem){
    if(t->lastNdx<MAX){
        t->arr[++t->lastNdx]=elem;
    }
}

void display(Tree t){
    int i;
    for(i=0; i<=t.lastNdx;i++){
        printf(" %d",t.arr[i]);
    }
}

void main(){
    Tree t;
    initTree(&t);
    insertElem(&t,5);
        //printf("%d ",t.arr[t.lastNdx-1]);
    insertElem(&t,10);
        //printf("%d ",t.arr[t.lastNdx-1]);
    insertElem(&t,15);
        //printf("%d ",t.arr[t.lastNdx-1]);
   
    display(t);

}