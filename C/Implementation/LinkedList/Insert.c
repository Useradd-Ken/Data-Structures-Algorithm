#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}*List;

void insertFirst(List *L,int data){
    List temp = (List) malloc(sizeof(struct node));
    temp->data =data;
    temp->next= *L;
    *L= temp;
}

void display(List L){
    List trav;
    for(trav=L;trav->next!=NULL;trav=trav->next){ //TRAVERSE TILL THE SECOND LAST NODE
        printf("%d->",trav->data);
    }
    printf("%d\n\n",trav->data); //PRINT THE LAST NODE DATA
}

void insertLast(List *L,int data){
    List *trav;
    for(trav=L;*trav!=NULL;trav=&(*trav)->next){}
    (*trav) = (List) malloc(sizeof(struct node)); //Since trav is a pointer to pointer we need to dereference it first to allocate memory to the node and then assign the data and next to NULL
    (*trav)->data = data; //Now dereference trav to access the node and assign data
    (*trav)->next = NULL; //Set next to NULL since its the last node
}

void insertPos(List *L,int data,int pos){
    List *trav;
    int i;
    for(trav=L,i=0;*trav!=NULL && i<pos-1;trav=&(*trav)->next,i++){}
    if(i==pos-1){ //If we have reached the desired position
        List temp = (List) malloc(sizeof(struct node));
        temp->data = data;
        temp->next = *trav;
        *trav = temp;
    } else {
        printf("Position out of bounds\n");
    }
}


void main()
{
    List L = NULL;//Initialize it to NULL before populating.
    insertFirst(&L,10);
    insertFirst(&L,20);
    insertFirst(&L,30);
    display(L);
    insertLast(&L,40);
    insertLast(&L,50);
    insertLast(&L,60);
    display(L);
    insertPos(&L,25,3);
    display(L);
    insertPos(&L,5,1);
    display(L);
    insertPos(&L,70,10); //This should give position out of bounds
}