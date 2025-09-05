#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct{
    char LName[16];
    char FName[24];
    char Mi;
}Nametype;

typedef struct{
    Nametype name;
    int age;
    int ID;
    char course[8];
}StudInfo;

typedef struct{
    StudInfo stud[MAX];
    int link;
}virtualHeap;

typedef struct{
    virtualHeap *VH;
    int *cList;
    int Avail;
}List;


void initVirtualHeap(List *L){
    L->Avail = MAX-1;
    L->VH = (virtualHeap*)malloc(sizeof(virtualHeap));
    L->cList = (int*)malloc(sizeof(int));
    int i;
    for(i=L->Avail;i>=0;i--){
        L->VH->link = i-1;
    }  
    L->cList = -1;
}

