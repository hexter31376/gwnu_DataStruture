#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LD_DataType int // 유연한 코딩을 위한 데이터 타입 정의

// 연결 덱 노드 구조 정의
typedef struct Dnode { // 덱 노드 구조체 선언
    struct Dnode* prev; // 이전 덱 노드를 가리킬 포인터
    LD_DataType data; // 실제 저장할 데이터
    struct Dnode* next; // 다은 덱 도느를 가리킬 포인터
} Dnode; // 덱 노드 구조체 명칭 선언

// 연결 덱의 헤드 노드 구조 정의
typedef struct LinkedDeque { // 덱 구조체 선언
    Dnode* front; // 첫번째 노드를 가리키는 포인터
    int length; // 덱의 길이
    Dnode* rear; // 마지막 노드를 가리키는 포인터
} LinkedDeque; // 덱 구조체 명칭 선언
