#include <stdio.h>
#define MAX 10

typedef struct{
    int data;
    int link; //Index of the next element in the virtual heap
}Node;

typedef struct{
    Node nodes[MAX];
    int Avail;
}VirtualHeap;

typedef int cList; //Cursor-based list represented by an index

void initVirtualHeap(VirtualHeap*VH,cList *L){
    VH->Avail = 0;
    int i,limit= MAX - 1;
    for(i=0;i<limit;i++){
        VH->nodes[i].link = i + 1; //Link each node to the next
        printf("Node %d linked to %d\n", i, VH->nodes[i].link);
    }
    printf("Node %d linked to %d\n", limit, -1); //Last node points to -1
    VH->nodes[limit].link = -1; //Last node points to -1 indicating end of free list
    *L = -1; //Initialize the list as empty
}

int realloc(VirtualHeap*VH){
    int temp = VH->Avail; //Get the index of the first free node
    if(temp != -1){ //If there is a free node
        VH->Avail = VH->nodes[temp].link; //Update Avail to the next free node
    }
    return temp; //Return the index of the allocated node or -1 if none available
}
