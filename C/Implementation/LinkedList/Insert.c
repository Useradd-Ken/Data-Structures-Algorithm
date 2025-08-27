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
    for(trav=L;trav->next!=NULL;trav=trav->next){
        printf("%d->",trav->data);
    }
    printf("%d\n\n",trav->data);
}

void main()
{
    List L = NULL;//Initialize it to NULL before populating.
    insertFirst(&L,10);
    insertFirst(&L,20);
    insertFirst(&L,30);
    display(L);
}