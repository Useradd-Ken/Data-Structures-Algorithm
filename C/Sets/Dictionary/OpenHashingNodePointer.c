#include <stdio.h>
#include <stdlib.h>
#define Hash_table 30

typedef struct node{
    char key;
    struct node* next;
}*Node;

typedef Node Hashtable[Hash_table];

void init(Hashtable table){
    for(int i=0;i<Hash_table;i++){
    table[i] = NULL;
    }
}

int hash(int key){
    return key % 65;
}

void display(Hashtable table){
    int i;
    Node trav;
    for(i=0;i<Hash_table;i++){
        printf("[%d]\t->\t%c\n",i,'*');
        for(trav=table[i];trav!=NULL;trav=trav->next){
            printf("[%d]\t->\t%c\n",i,trav->key);
        }
    }
}

void insertDictionary(Hashtable table,char key){
    int index = hash(key);

    Node newNode= (Node)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->next = table[index];
    table[index] = newNode;

}

void main()
{
    Hashtable table;
    init(table);
    insertDictionary(table,'A');
    insertDictionary(table,'B');
    insertDictionary(table,'C');
    insertDictionary(table,'K');
    insertDictionary(table,'E');
    insertDictionary(table,'Z');
    insertDictionary(table,'Y');
    display(table);
}