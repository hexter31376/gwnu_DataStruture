#include <stdio.h>
#include <stdlib.h>

#define Datatype int

typedef struct Tnode
{
    struct Tnode* left;
    Datatype data;
    struct Tnode* right;
}Tnode;