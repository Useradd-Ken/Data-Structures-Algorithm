#include <stdio.h>
#include <stdlib.h>
#define MAX 0xA

typedef struct{
    int Arr[MAX];
    int size;
}ArrList;

void insertFirst(ArrList*list, int data)
{
    if(list->size<MAX){
        int i;
        for(i=list->size-1; i>=0; i--){
            list->Arr[i+1] = list->Arr[i];
        }
        list->Arr[0] = data;
        list->size++;
    }
}

void insertLast(ArrList*list, int data)
{
    if(list->size<MAX){
        list->Arr[list->size] = data;
        list->size++;
    }
}

void insertPos(ArrList*list, int data, int pos)
{
    if(list->size<MAX && pos>=0 && pos<=list->size){ //CHECK FOR SPACE & CHECK IF POSITION IS VALID
        int i;
        for(i=list->size-1; i>=pos; i--){ //START SHIFTING FROM THE LAST ELEMENT TO THE RIGHT UNTIL ITS IN THE RIGHT POSITION
            list->Arr[i+1] = list->Arr[i];
        }
        list->Arr[pos] = data; // LOOP STOPS TO THE RIGHT POSITION AND EXITS PLACE THE DATA IN THE INDEX OF ITS POSITION
        list->size++; // INCREMENT THE SIZE;
    }
}

void display(ArrList list)
{
    if(list.size==0){
        printf("List is Empty\n");
    }else{
        for(int i=0; i<list.size-1; i++){
            printf("%d->", list.Arr[i]);
        }
        printf("%d", list.Arr[list.size-1]);
        printf("\n\n");
    }
}

void insertUnique(ArrList*L,int x,int pos){
    if(L->size<MAX && pos>=0 && pos<=L->size){
        int i;
        for(i=0;i<L->size && L->Arr[i]!=x;i++){}
        if(i==L->size){
        for(i=L->size-1; i>=pos; i--){ //START SHIFTING FROM THE LAST ELEMENT TO THE RIGHT UNTIL ITS IN THE RIGHT POSITION
            L->Arr[i+1] = L->Arr[i];
        }
        L->Arr[pos] = x; // LOOP STOPS TO THE RIGHT POSITION AND EXITS PLACE THE DATA IN THE INDEX OF ITS POSITION
        L->size++; 
        }else{
            printf("Not Unique\n");
        }
    }
}

void main()
{
    ArrList list;
    list.size = 0; // Initialize size to 0 Always
    insertFirst(&list, 10);
    insertFirst(&list, 20);
    display(list);
    insertLast(&list, 50);
    insertLast(&list, 60);      
    display(list);  
    insertPos(&list, 25, 2);
    display(list);
    insertPos(&list, 5, 0);
    insertUnique(&list,11,1);
    insertUnique(&list,12,1);
    display(list);
}