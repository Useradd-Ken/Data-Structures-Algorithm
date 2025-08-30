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

void deletePos(List *L,int pos){
    List *trav;
    int i;
    for(trav=L,i=0;*trav!=NULL && i<pos;trav=&(*trav)->next,i++){}
    if(*trav!=NULL){ //If we found the position
        List temp = *trav; //Store the address of the node to be deleted
        *trav = (*trav)->next; //Bypass the node to be deleted
        free(temp); //Free the memory of the deleted node
    } else {
        printf("Position out of bounds\n");
    }
}

void deleteAllOccurences(List*L,int data){
    List *trav;
    for(trav=L;*trav!=NULL;){
        if((*trav)->data == data){
            List temp = *trav; //Store the address of the node to be deleted
            *trav = (*trav)->next; //Bypass the node to be deleted
            free(temp); //Free the memory of the deleted node
        } else {
            trav = &(*trav)->next; //Only move to next if we didn't delete the current node
        }
    }
}

void main()
{
    List L = NULL;//Initialize it to NULL before populating.
    insertFirst(&L,10);
    insertFirst(&L,20);
    insertFirst(&L,30);
     insertFirst(&L,30);
      insertFirst(&L,30);
       insertFirst(&L,30);
    display(L);
    deleteElement(&L,20); //Delete element 20
    display(L);
    deleteAllOccurences(&L,30); //Delete all occurences of 30
    display(L);
    deleteElement(&L,100); //Try to delete an element not in the list
    deletePos(&L,2); //Delete element at position 2
    display(L);
    deletePos(&L,10); //Try to delete at a position out of bounds
}

