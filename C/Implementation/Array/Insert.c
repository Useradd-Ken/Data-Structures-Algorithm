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

void insertLast(ArrList*list, int data)
{
    if(list->size<MAX){
        list->Arr[list->size] = data;
        list->size++;
    }
}

void insertPos(ArrList*list, int data, int pos)
{
    if(list->size<MAX && pos>=0 && pos<=list->size){
        int i;
        for(i=list->size-1; i>=pos; i--){
            list->Arr[i+1] = list->Arr[i];
        }
        list->Arr[pos] = data;
        list->size++;
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

}