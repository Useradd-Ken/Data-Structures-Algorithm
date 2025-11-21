#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Hash_table 15


typedef struct node{
    int key;
    struct node* next;
}Node;


void init(Node**table){
    for(int i=0;i<Hash_table;i++){
    table[i] = NULL;
    }
}

int hash(int key){
    return key % Hash_table;
}

void insertDictionary(Node**table,int key)
{
    int index = hash(key);

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key;
    newnode->next = table[index];
    table[index] = newnode; 
}

void display(Node **table){
    int i;
    Node *temp;
    for(i=0;i<Hash_table;i++){
        printf("[%d] -> %d\n",i,0);

        for(temp=table[i];temp!=NULL;temp=temp->next){
            printf("[%d] -> %d\n",i,temp->key);
        }
    }
}

void main(){
    Node** table = malloc(sizeof(Node*)*Hash_table);
    init(table);
    insertDictionary(table,10);
    insertDictionary(table,11);
    insertDictionary(table,12);
    display(table);
}

