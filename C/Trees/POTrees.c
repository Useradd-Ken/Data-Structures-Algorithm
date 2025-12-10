#include <stdlib.h>
#include <stdio.h>
#define MAX 10

typedef struct {
    int list[MAX];
    int lastNdx;
}POT;


void init(POT*P){
    P->lastNdx = -1;
}

void main(){
    POT P;
    init(&P);
}