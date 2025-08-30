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

void deleteElement(List *L,int data){
    List *trav;
    for(trav=L;*trav!=NULL && (*trav)->data != data;trav=&(*trav)->next){}
    if(*trav!=NULL){ //If we found the element
        List temp = *trav; //Store the address of the node to be deleted
        *trav = (*trav)->next; //Bypass the node to be deleted
        free(temp); //Free the memory of the deleted node
    } else {
        printf("Element not found\n");
    }
}

