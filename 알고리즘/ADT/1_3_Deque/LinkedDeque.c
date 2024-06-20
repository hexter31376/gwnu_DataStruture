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

// 연결 덱 초기화
void LD_init_deque (LinkedDeque* LD) { // 연결 덱의 주소를 매개변수로, 반환값 없음
    LD->front = LD->rear = NULL; // 첫번째 노드를 가리키는 포인터와 두번째 노드를 가리키는 포인터를 NULL로 초기화
    LD->length = 0; // 덱의 길이 카운트 초기화
}

// 연결 덱 항목들을 출력
void LD_print_deque (LinkedDeque* LD) { // 연결 덱의 주소를 매개변수로, 반환값 없음
    printf("front <- "); // 데이터의 출구 표시 출력
    for(Dnode* nodeCursor = LD->front; nodeCursor; nodeCursor = nodeCursor->next) { // 노드 커서를 만들고 그 노드 커서가 null 즉, 연결 덱의 끝이 아닐 때까지
        printf("%d <-> ", nodeCursor->data); // 해당 커서 위치의 데이터 출력
    }
    printf("rear\n"); // 데이터의 입구 표시 출력 및 개행
}

// 연결 덱이 포화 상태인지 판단 // 연결 덱은 크기 제한이 없기에 메모리 할당 실패시를 포화 상태로 판단한다
bool LD_is_deque_full (Dnode *node) { // 노드의 주소를 파라미터로, 참, 거짓 반환
    return node == NULL; // 노드 할당 성공 여부 참 거짓 결과 반환
}

// 연결 큐가 공백 상태인지 확인
bool LD_is_deque_empty (LinkedDeque* LD) { // 연결 덱의 주소를 파라미터로, 참, 거짓 반환
    return LD->front == NULL; // front가 공백인지에 대한 참 거짓 결과 반환
}

// 덱의 앞에 삽입
// LS_stack_pop 과 동일한 동작
void LD_push_front (LinkedDeque* LD, LD_DataType data) {
    Dnode* new
}