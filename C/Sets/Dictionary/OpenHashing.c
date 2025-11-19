#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Hash_table 30


typedef struct node{
    char *value;
    struct node* next;
}Node;

typedef struct{
    Node *tables;
};

void init(Node*table){
    for(int i=0;i<Hash_table;i++){
       table[i] = NULL;
    }
}

int hash(char *key){
    return key % 65;
}

void insertDictionary(Node*table,char key)
{
    int key = hash(key);
    Node *newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->value,key);

    newnode->next = &table[key];
    table[key].next = newnode;
}

void display(Node *table){
    int i;
    Node *temp;
    for(i=0;i<Hash_table;i++){
        for(temp=&table[i];temp!=NULL;temp=temp->next){
            printf("[%d] -> %s\n",i,temp->value);
        }
    }
}

void main(){
    Node* table = (Node*)malloc(sizeof(Node)*Hash_table);
    init(table);
    insertDictionary(table,'A');
    insertDictionary(table,'B');
    insertDictionary(table,'T');
    display(table);
}

