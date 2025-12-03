#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* RC;
    struct node* LC;
}*BST;

void init(BST*T){
    *T=NULL;
}

void insertElem(BST*T,int elem){
    BST *trav;
    for(trav=T;*trav!=NULL;)
    {
        if((*trav)->data < elem){
            trav=&(*trav)->RC;
        }else{
            trav=&(*trav)->LC;
        }
    }
    (*trav) = (BST)malloc(sizeof(struct node));
    (*trav)->data = elem;
    (*trav)->RC = NULL;
    (*trav)->LC =NULL;

}

// int isMember(BST T, int elem){
//     BST trav;
//     for(trav=T;trav!=NULL && trav->data!=elem;){
//         if(trav->data<elem){
//             trav=trav->RC;
//         }else{
//             trav=trav->LC;
//         }
//     }
//     return (trav!=NULL) ? trav->data : -1;
// }
int isMember(BST T, int elem){
    BST trav;
    for(trav=T;trav!=NULL;trav=(trav->data<elem)? trav->RC : trav->LC){}
    return (trav!=NULL) ? trav->data : -1;
}


void main()
{
    BST T;
    init(&T);
    insertElem(&T,9);
    insertElem(&T,10);
    insertElem(&T,2);
    insertElem(&T,5);
    insertElem(&T,6);
    insertElem(&T,8);
    printf("IS\t[%d]\tMEMBER?\t:\t%d\n",5,isMember(T,5));
    printf("IS\t[%d]\tMEMBER?\t:\t%d\n",10,isMember(T,10));
    printf("IS\t[%d]\tMEMBER?\t:\t%d\n",2,isMember(T,2));
    printf("IS\t[%d]\tMEMBER?\t:\t%d\n",8,isMember(T,20));
    
}