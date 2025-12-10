#include <stdio.h>
#define MAX 10 

typedef struct {
    int List[MAX];
    int lastNdx;
}POT;

void init(POT*P){
    P->lastNdx = -1;
}

// ( leftChild = (2 * root) + 1, rightChild = leftChild + 1 ;
// leftChild <= P->lastNdx && P->list[root] > P->list[smallestChild = (rightChild <= P->lastNdx && P->list[rightChild] < P->list[leftChild]) ? rightChild : leftChild];
//  root = smallestChild, leftChild = (2 * root) + 1, rightChild = leftChild + 1 )

// for(leftChild = (2 * root) + 1, rightChild = leftChild + 1; leftChild <= P->lastNdx && P->list[root] > P->list[smallestChild = (rightChild <= P->lastNdx && P->list[rightChild] < P->list[leftChild]) ? rightChild : leftChild]; root = smallestChild, leftChild = (2 * root) + 1, rightChild = leftChild + 1){
//         swap(&P->list[root], &P->list[smallestChild]);
//     }
// }

void insertMin(POT*P,int x){
    int ndx,parent;
    if(P->lastNdx<MAX-1){
        ndx = ++P->lastNdx;
        parent = (ndx-1)/2;
        while(ndx > 0 && P->List[parent] > x){
            P->List[ndx] = P->List[parent];
            ndx = parent;
            parent = (ndx -1) /2;
        }
        P->List[ndx]=x;
    }
}

void insertMax(POT*P,int x){
    int ndx,parent;
    if(P->lastNdx<MAX-1){
        ndx = ++P->lastNdx;
        parent = (ndx-1)/2;
        while(ndx > 0 && P->List[parent] < x){
            P->List[ndx] = P->List[parent];
            ndx = parent;
            parent = (ndx -1) /2;
        }
        P->List[ndx]=x;
    }
}


void display(POT P){
    int i;
    printf("\n");
    printf("Value:\t");
    for(i=0;i<=P.lastNdx;i++){
        printf("%d\t",P.List[i]);
    }
    printf("\nIndex:\t");
    for(i=0;i<=P.lastNdx;i++){
        printf("%d\t",i);
    }
}

void main(){
    POT P;
    init(&P);
    insertMin(&P,10);
    insertMin(&P,2);
    insertMin(&P,3);
    insertMin(&P,11);
    insertMin(&P,12);
    insertMin(&P,1);
    display(P);
    
}