/**
 * 이진 탐색 트리의 ADT 실제 구현
 */

#include <stdio.h>
#include <stdlib.h>

#define Datatype int

typedef struct Tnode
{
    struct Tnode* left;
    Datatype data;
    struct Tnode* right;
}Tnode;