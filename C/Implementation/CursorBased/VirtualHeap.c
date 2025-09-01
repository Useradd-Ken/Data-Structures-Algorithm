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

void insertFirst(VirtualHeap*VH,cList*L,int data){
    int newNodeIndex = realloc(VH); //Get a free node from the virtual heap
    if(newNodeIndex != -1){ //If a free node is available
        VH->nodes[newNodeIndex].data = data; //Set the data
        VH->nodes[newNodeIndex].link = *L; //Link the new node to the current head
        *L = newNodeIndex; //Update the head to the new node
    } else {
        printf("No space available in virtual heap\n");
    }
}

void display(VirtualHeap*VH,cList L){
    int trav = L;
    for(;trav != -1; trav = VH->nodes[trav].link){
        printf("%d -> ", VH->nodes[trav].data);
    }
    printf("NULL\n");
}

void insertLast(VirtualHeap*VH,cList*L,int data){
    int newNodeIndex = realloc(VH); //Get a free node from the virtual heap
    if(newNodeIndex != -1){ //If a free node is available
        VH->nodes[newNodeIndex].data = data; //Set the data
        VH->nodes[newNodeIndex].link = -1; //New node will be the last node, so link to -1
        if(*L == -1){ //If the list is empty
            *L = newNodeIndex; //New node becomes the head
        } else {
            int trav = *L;
            while(VH->nodes[trav].link != -1){ //Traverse to the last node
                trav = VH->nodes[trav].link;
            }
            VH->nodes[trav].link = newNodeIndex; //Link the last node to the new node
        }
    } else {
        printf("No space available in virtual heap\n");
    }
}

void deleteElement(VirtualHeap*VH,cList*L,int data){
    int *trav = L;
    while(*trav != -1 && VH->nodes[*trav].data != data){
        trav = &VH->nodes[*trav].link;
    }
    if(*trav != -1){ //If we found the element
        int temp = *trav; //Store the index of the node to be deleted
        *trav = VH->nodes[*trav].link; //Bypass the node to be deleted
        // Add the deleted node back to the free list
        VH->nodes[temp].link = VH->Avail;
        VH->Avail = temp;
    } else {
        printf("Element not found\n");
    }
}

void deletePos(VirtualHeap*VH,cList*L,int pos){
    int *trav = L;
    int i;
    for(i=0;*trav != -1 && i<pos;i++){
        trav = &VH->nodes[*trav].link;
    }
    if(*trav != -1){ //If we found the position
        int temp = *trav; //Store the index of the node to be deleted
        *trav = VH->nodes[*trav].link; //Bypass the node to be deleted
        // Add the deleted node back to the free list
        VH->nodes[temp].link = VH->Avail;
        VH->Avail = temp;
    } else {
        printf("Position out of bounds\n");
    }
}

void deleteAllOccurrences(VirtualHeap*VH,cList*L,int data){
    int *trav = L;
    while(*trav != -1){
        if(VH->nodes[*trav].data == data){
            int temp = *trav; //Store the index of the node to be deleted
            *trav = VH->nodes[*trav].link; //Bypass the node to be deleted
            // Add the deleted node back to the free list
            VH->nodes[temp].link = VH->Avail;
            VH->Avail = temp;
        } else {
            trav = &VH->nodes[*trav].link; //Only move to next if we didn't delete the current node
        }
    }
}

void deleteLast(VirtualHeap*VH,cList*L){
    int *trav = L;
    if(*trav == -1){
        printf("List is empty\n");
        return;
    }
    while(VH->nodes[*trav].link != -1){
        trav = &VH->nodes[*trav].link;
    }
    int temp = *trav; //Store the index of the node to be deleted
    *trav = -1; //Bypass the last node
    // Add the deleted node back to the free list
    VH->nodes[temp].link = VH->Avail;
    VH->Avail = temp;
}

void deleteAllElements(VirtualHeap*VH,cList*L){
    int trav;
    while(*L != -1){
        trav = *L; //Store the index of the node to be deleted
        *L = VH->nodes[*L].link; //Bypass the node to be deleted
        // Add the deleted node back to the free list
        VH->nodes[trav].link = VH->Avail;
        VH->Avail = trav;
    }
}

int main(){
    VirtualHeap VH;
    cList myList;
    initVirtualHeap(&VH, &myList);
    
    insertFirst(&VH, &myList, 10);
    insertFirst(&VH, &myList, 20);
    insertFirst(&VH, &myList, 30);
    
    display(&VH, myList);
    
    return 0;
}