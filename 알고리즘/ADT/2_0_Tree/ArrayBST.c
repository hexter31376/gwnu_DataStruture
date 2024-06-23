#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ABST_Datatype // 유연한 코딩을 위한 데이터 타입 선언
#define ABST_MAX_SIZE 100 // 트리 배열의 최대 크기 정의

typedef struct ArrayBST { // 배열 이진 탐색 트리 구조체의 정의
    ABST_Datatype nodeArray [ABST_MAX_SIZE];
} ArrayBST; // 배열 이진 탐색 트리 구조체의 명칭 정의

// 배열 이진 탐색 트리 초기화
ABST_init_BST () {
    
}