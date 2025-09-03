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
    StudInfo stud;
    int link;
}virtualHeap;

typedef struct{
    virtualHeap *VH;
    int *cList;
}List;


