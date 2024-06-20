#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LQ_DataType int // 유연한 코딩을 위한 데이터 타입 정의

// 연결 큐 노드 구조 정의
typedef struct Qnode { // 연결 큐의 노드 구조체 선언
    LQ_DataType data; // 실제 데이터 저장 공간
    struct Qnode* next; // 다른 노드를 가리킬 포인터
} Qnode; // 연결 큐 노드의 명칭 선언

// 연결 큐의 헤드 노드 정의
typedef struct LinkedQueue { // 연결 큐의 구조체 선언 // 헤드 포인터 겸용
    Qnode* front; // 나갈 데이터를 지정할 포인터 선언
    int length; // 연결 큐의 길이 카운트 변수 선언
    Qnode* rear; // 들어올 데이터를 지정할 포인터 선언
} LinkedQueue;

// 연결 큐 초기화
void LQ_init_queue (LinkedQueue* LQ) { // 연결 큐의 주소를 파라미터로, 반환값 없음
    LQ->front = LQ->rear = NULL;
    LQ->length = 0;
}

// 연결 큐 항목들을 출력
void LQ_print_queue (LinkedQueue* LQ) { // 연결 큐의 주소를 파라미터로, 반환값 없음
    printf("front <-"); // 데이터의 출구 표시 출력
    for(Qnode* nodeCursor = LQ->front; nodeCursor; nodeCursor = nodeCursor->next) { // 노드 커서를 만들고 그 노드 커서가 null 즉, 연결 큐의 끝이 아닐 때까지
        printf("%d <-", nodeCursor->data); // 해당 커서 위치의 데이터 출력
    }
    printf(" rear\n"); // 데이터의 입구 표시 출력 및 개행
}

// 연결 큐가 포화 상태인지 판단 // 연결 큐는 크기 제한이 없기에 메모리 할당 실패시를 포화 상태로 판단한다
bool LQ_is_queue_full (Qnode *node) { // 노드의 주소를 파라미터로, 참, 거짓 반환
    return node == NULL; // 노드 할당 성공 여부 참 거짓 결과 반환
}

// 연결 큐가 공백 상태인지 확인
bool LQ_is_queue_empty (LinkedQueue* LQ) { // 연결 큐의 주소를 파라미터로, 참, 거짓 반환
    return LQ->front == NULL; // front가 공백인지에 대한 참 거짓 결과 반환
}

// 연결 큐에 삽입
void LQ_push (LinkedQueue* LQ, LQ_DataType data) { // 연결 큐의 주소, 삽입할 데이터를 파라미터로, 반환갑 없음
    Qnode *newQnode = (Qnode*)malloc(sizeof(Qnode)); // 연결 큐 노드 동적 할당

    if (LQ_is_queue_full(newQnode)) { // 큐가 가득 차 있다면
        printf("LQ_push : 포화 큐이므로 항목 삽입이 불가능합니다."); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 큐가 가득 차 있지 않다면
        newQnode->data = data; // 파라미터 데이터를 새로운 노드의 데이터에 삽입한다
        newQnode->next = NULL; // 새로운 노드의 next 포인터를 NULL로 한다
        if (LQ_is_queue_empty(LQ)) { // 큐가 비어있다면
            LQ->front = newQnode; // 큐의 출구 포인터가 새로운 노드를 가리키도록 한다
        } else { // 큐가 비어있지 않다면
            LQ->rear->next = newQnode; // 큐의 입구 포인터가 가리키는 노드의 next 포인터가 새로운 노드를 가리키도록 한다
        }
        LQ->length++; // 연결 큐 길이 증가
        LQ->rear = newQnode; // 큐의 입구 포인터가 새로운 노드를 가리키도록 한다
    }
}

// 연결큐에서 삭제
LQ_DataType LQ_pop (LinkedQueue* LQ) { // 연결 큐의 주소를 파라미터로, pop한 데이터 반환
    if (LQ_is_queue_empty(LQ)) { // 큐가 비어있다면
        printf("LQ_pop : 공백 큐이므로 삭제가 불가능합니다."); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 큐가 비어있지 않다면
        Qnode* popedQnode = LQ->front; // pop할 노드 지정 이때 front가 출구이므로 front가 가리키는 노드 지정
        LQ_DataType popedQdata = popedQnode->data; // pop할 노드의 data를 popedQdata에 저장
        LQ->front = LQ->front->next; // 데이터의 출구를 가리키는 포인터가 데이터의 출구가 가리키는 노드의 next포인터가 가리키는 포인터를 가리키게 한다
        if (LQ_is_queue_empty(LQ)) { // 노드를 지우고 난 뒤에 공백 큐가 된다면
            LQ->rear = NULL; // rear의 포인터도 null로 만들어준다
        }
        free(popedQnode); // pop한 노드의 동적 공간 반납하기
        LQ->length--; // 연결 큐 길이 감소
        return popedQdata; // pop한 데이터 반환
    }
}

// 연결 큐에서 front 데이터를 반환
LQ_DataType LQ_get_data (LinkedQueue* LQ) { // 연결 큐의 주소를 파라미터로, front 데이터 반환
    if (LQ_is_queue_empty(LQ)) { // 큐가 비어있다면
        printf("LQ_get_data : 공백 큐이므로 삭제가 불가능합니다."); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 큐가 비어있지 않다면
        return LQ->front->data; // front의 데이터 반환
    }
}

int main () {
    LinkedQueue lqueue;
    LQ_init_queue(&lqueue);
    LQ_push(&lqueue, 10);
    LQ_push(&lqueue, 20);
    LQ_push(&lqueue, 30);
    LQ_print_queue(&lqueue);
    printf("현재 front 항목은 %d\n", LQ_get_data(&lqueue));
    LQ_pop(&lqueue);
    printf("현재 front 항목은 %d\n", LQ_get_data(&lqueue));
    LQ_pop(&lqueue);
    printf("현재 front 항목은 %d\n", LQ_get_data(&lqueue));
    LQ_pop(&lqueue);
    LQ_pop(&lqueue);
    return 0;
}