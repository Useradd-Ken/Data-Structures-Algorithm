#include <stdio.h>
#include <stdlib.h>
#define MAX 0xB

typedef struct{
    int data;
    int link;
}Node;

typedef struct{
    Node nodes[MAX];
    int avail;
}virtualHeap;

typedef struct{
    virtualHeap *VH;
    int cList; // index of first element (-1 if empty)
}List;

typedef int dList;

void initVirtualHeap(List*L,dList *d){
    L->VH=(virtualHeap*)malloc(sizeof(virtualHeap));
    if(L->VH!=NULL){
        int i;
        L->VH->avail=MAX-1;
        for(i=L->VH->avail;i>0;i--){
            L->VH->nodes[i].link=i-1;
            L->VH->nodes[i].data= i-1;
            printf("%d\tDATA:\t%d\tLINK:\t%d\n",i,L->VH->nodes[i].data,L->VH->nodes[i].link);
        }
    }
    L->cList=-1; // Initialize the cursor-based list as empty
    *d=-1;
}

void insertFirst(List*L,int data){
    if(L->VH->avail!=-1){
        int temp=L->VH->avail;
        L->VH->avail=L->VH->nodes[temp].link;
        L->VH->nodes[temp].data=data;
        L->VH->nodes[temp].link=L->cList;
        L->cList=temp;
    }
}

// Given the List and the virtualheap, 
// Create another list using dList and get all Even elements 
// and delete it from the original list and insert it into the new list.

void populateEven(List* L, dList *d) {
    int *trav;  // pointer to the link field of the current node
    for (trav = &L->cList; *trav != -1;) {
        int curr = *trav;
        if (L->VH->nodes[curr].data % 2 == 0) {
            // unlink from original list
            *trav = L->VH->nodes[curr].link;

            // move curr node into new list (dList)
            L->VH->nodes[curr].link = *d;
            *d = curr;
        } else {
            // only advance when we don’t delete
            trav = &L->VH->nodes[curr].link;
        }
    }
}

void display(List L,dList d){
    int i=L.cList;
     printf("\n");
    for(;i!=-1;i=L.VH->nodes[i].link){
        printf("%d -> ",L.VH->nodes[i].data);
    }
    printf("\n");
    for(i=d;i!=-1;i=L.VH->nodes[i].link){
        printf("%d -> ",L.VH->nodes[i].data);
    }
    printf("\n");
}

void main(){
    List L;
    dList d;
    initVirtualHeap(&L,&d);
    insertFirst(&L,10);
    insertFirst(&L,21);
    insertFirst(&L,30);
    insertFirst(&L,41);
    insertFirst(&L,50);
    insertFirst(&L,61);
    insertFirst(&L,70);
    populateEven(&L,&d);
    display(L,d);

}