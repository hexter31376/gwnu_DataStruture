#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CQ_MAX_SIZE 100 // 원형 큐의 최대 크기 정의
#define CQ_DataType int // 유연한 코딩을 위한 데이터 타입 정의

// 원형 큐 구조 정의
typedef struct CircularQueue { // 원형 큐의 구조체 선언
    int rear; // 큐의 입구 인덱스
    CQ_DataType queue[CQ_MAX_SIZE]; // 실제 원형 큐의 공간
    int front; // 큐의 출구 인덱스
    int length; // 연결 스택의 길이, 즉 데이터의 개수 정의
} CircularQueue; // 원형 큐의 명칭 선언

// 원형 큐 초기화
void CQ_init_queue (CircularQueue* CQ) { // 원형 큐의 주소를 파라미터로, 반환값 없음
    CQ->front = CQ->rear = 0; // front와 rear 다 초기 위치를 0으로 초기화
    CQ->length = 0; // 카운터 초기화
}

// 원형 큐 항목들을 출력
void CQ_print_queue (CircularQueue* CQ) { // 원형 큐의 주소를 파라미터로, 반환값 없음
    printf("front <-"); // 데이터의 출구 표시 출력
    for(int i = CQ->front; i != CQ->rear;) { // front를 i로 하고 i가 rear가 아닐 때까지
        i = (i + 1) % CQ_MAX_SIZE; // i를 1씩 증가시키는데 원형 큐이므로 CQ_MAX_SIZE를 넘지 않도록 모듈러 연산
        printf("%d <-", CQ->queue[i]); // 해당 인덱스 위치의 데이터 출력
    }
    printf(" rear\n"); // 데이터의 입구 표시 출력 및 개행
}

// 원형 큐가 포화 상태인지 판단
bool CQ_is_queue_full (CircularQueue* CQ) { // 원형 큐의 주소를 파라미터로, 참 거짓 반환
    return ((CQ->rear + 1) % CQ_MAX_SIZE) == CQ->front; // 큐의 길이 숫자에 1을 더하고 모듈러 연산을 한 값이 front와 같다면 큐가 포화 상태인 것으로 판단
}

// 원형 큐가 공백 상태인지 판단
bool CQ_is_queue_empty (CircularQueue* CQ) { // 원형 큐의 주소를 파라미터로, 참 거짓 반환
    return CQ->front == CQ->rear; // 큐의 front와 큐의 rear 값이 같다면 큐가 공백 상태인 것으로 판단
}

// 원형 큐에 삽입
void CQ_push (CircularQueue* CQ, CQ_DataType data) { // 원형 큐의 주소를 파라미터로, 반환값 없음
    if (CQ_is_queue_full(CQ)) { // 큐가 가득 차 있다면
        printf("CQ_push : 포화 큐이므로 항목 삽입이 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 큐에 삽입할 수 있는 공간이 있다면
        CQ->rear = (CQ->rear + 1) % CQ_MAX_SIZE; // rear(입구)의 인덱스를 1증가시킨다, 범위 초과 방지를 위해 CQ_MAX_SIZE로 모듈러 연산
        CQ->queue[CQ->rear] = data; // 큐의 해당 rear위치에 data를 삽입
        CQ->length++; // 카운터 증가
    }
}

// 원형 큐에서 삭제
CQ_DataType CQ_pop (CircularQueue* CQ) { // 원형 큐의 주소를 파라미터로, pop한 데이터 반환
    if (CQ_is_queue_empty(CQ)) { // 큐가 비었다면
        printf("CQ_pop : 공백 큐이므로 항목 삭제가 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 큐가 비어있지 않다면
        CQ->front = (CQ->front + 1) % CQ_MAX_SIZE; // front(출구)의 인덱스를 1증가시킨다, 범위 초과 방지를 위해 CQ_MAX_SIZE로 모듈러 연산
        CQ->length--; // 카운터 감소
        return CQ->queue[CQ->front]; // 큐의 해당 front위치의 데이터를 반환
    }
}

// 원형 큐에서 front 데이터 반환
CQ_DataType CQ_get_data (CircularQueue* CQ) { // 원형 큐의 주소를 파라미터로, front 데이터 반환
    if (CQ_is_queue_empty(CQ)) { // 큐가 비었다면
        printf("CQ_get_data : 공백 큐이므로 항목 삭제가 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 큐가 비어있지 않다면
        return CQ->queue[CQ->front + 1]; // 큐의 해당 front위치의 데이터를 반환
    }
}

int main () {
    CircularQueue cqueue;
    CQ_init_queue(&cqueue);
    CQ_push(&cqueue, 10);
    CQ_push(&cqueue, 20);
    CQ_push(&cqueue, 30);
    CQ_print_queue(&cqueue);
    printf("현재 front 항목은 %d\n", CQ_get_data(&cqueue));
    CQ_pop(&cqueue);
    printf("현재 front 항목은 %d\n", CQ_get_data(&cqueue));
    CQ_pop(&cqueue);
    printf("현재 front 항목은 %d\n", CQ_get_data(&cqueue));
    CQ_pop(&cqueue);
    CQ_pop(&cqueue);
    return 0;
}