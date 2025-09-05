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

void display(List L){
    int trav;
    for(trav=L.cList;trav!=-1;trav=L.VH->link){
        printf("%s, %s %c\t\t%d\t\t%d\t\t%s\n", L.VH->stud[trav].name.LName, L.VH->stud[trav].name.FName, L.VH->stud[trav].name.Mi, L.VH->stud[trav].age, L.VH->stud[trav].ID, L.VH->stud[trav].course);
    }
    printf("\n");
}

void insertFirst(List *L, StudInfo data){
    if(L->Avail!=-1){
        int newNode = L->Avail;
        L->Avail = L->VH->link;
        L->VH->stud[newNode] = data;
        L->VH->link = L->cList;
        L->cList = newNode;
    }
}

int main(){
    List L;
    initVirtualHeap(&L);
    StudInfo data1 = {{"Cruz", "Juan", 'D'}, 20, 2021001, "BSIT"};
    StudInfo data2 = {{"Santos", "Pedro", 'A'}, 21, 2021002, "BSCS"};
    StudInfo data3 = {{"Reyes", "Maria", 'B'}, 19, 2021003, "BSIT"};
    insertFirst(&L, data1);
    insertFirst(&L, data2);
    insertFirst(&L, data3);
    display(L);
    return 0;
}


