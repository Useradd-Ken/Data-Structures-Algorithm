#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char SET;

SET findElem(SET A, int elem)
{
    return (A & (1 << elem)) != 0;
}

void main(){

}

