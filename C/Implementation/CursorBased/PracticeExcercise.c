#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// ----------------------
// User-defined Data Types
// ----------------------
typedef struct {
    char LName[16];
    char FName[24];
    char Mi;
} Nametype;

typedef struct {
    Nametype name;
    int age;
    int ID;
    char course[8];
    int link; 
} StudInfo;

typedef struct {
    StudInfo stud[MAX];
    int Avail;   // index of available/free list
} VirtualHeap;

typedef struct {
    VirtualHeap *VH;
    int cList;   // index of first element (-1 if empty)
} List;


void initVirtualHeap(List *L) {
    int i;
    L->VH = (VirtualHeap*) malloc(sizeof(VirtualHeap));
    if(L->VH!=NULL){
        L->VH->Avail = MAX-1;
        for(i=L->VH->Avail; i>0; i--){
            L->VH->stud[i].link = i-1;
        }
        L->cList = -1; // Initialize the cursor-based list as empty
    }
}

int allocSpace(VirtualHeap *VH) {
    int avail = VH->Avail;
    if (avail != -1) {
        VH->Avail = VH->stud[avail].link;
    }
    return avail;
}

void freeSpace(VirtualHeap *VH, int index) {
    VH->stud[index].link = VH->Avail;
    VH->Avail = index;
}

void insertFirst(List *L, StudInfo data) {
    int newNode = allocSpace(L->VH);
    if (newNode != -1) {
        L->VH->stud[newNode] = data;
        L->VH->stud[newNode].link = L->cList;
        L->cList = newNode;
    } else {
        printf("No space available!\n");
    }
}

void display(List L) {
    int trav;
    for (trav = L.cList; trav != -1; trav = L.VH->stud[trav].link) {
        printf("%s\t%s\t%c\t%d\t%d\t%s\n",
            L.VH->stud[trav].name.LName,
            L.VH->stud[trav].name.FName,
            L.VH->stud[trav].name.Mi,
            L.VH->stud[trav].age,
            L.VH->stud[trav].ID,
            L.VH->stud[trav].course
        );
    }
    printf("\n");
}


int main() {
    List L;
    initVirtualHeap(&L);

    StudInfo data1 = {{"Cruz", "Juan", 'D'}, 20, 2021001, "BSIT", -1};
    StudInfo data2 = {{"Santos", "Pedro", 'A'}, 21, 2021002, "BSCS", -1};
    StudInfo data3 = {{"Reyes", "Maria", 'B'}, 19, 2021003, "BSIT", -1};

    insertFirst(&L, data1);
    insertFirst(&L, data2);
    insertFirst(&L, data3);

    display(L);

    return 0;
}
