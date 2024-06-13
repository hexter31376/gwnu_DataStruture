#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // 원형 큐의 최대 크기 정의
#define Datatype int // 유연한 코딩을 위한 데이터 타입 정의

// 원형 큐 구조 정의
typedef struct CircularQueue { // 원형 큐의 구조체 선언
    int rear; // 큐의 입구 인덱스
    Datatype queue[MAX_SIZE]; // 실제 원형 큐의 공간
    int front; // 큐의 출구 인덱스
    int length; // 연결 스택의 길이, 즉 데이터의 개수 정의
} CircularQueue; // 원형 큐의 명칭 선언

// 원형 큐 초기화
void CQ_init_queue (CircularQueue* CQ) { // 원형 큐의 주소를 파라미터로, 반환값 없음
    CQ->front = CQ->rear = 0; // front와 rear 다 초기 위치를 0으로 초기화
}

// 원형 큐 항목들을 출력
void CQ_print_queue (CircularQueue* CQ) { // 원형 큐의 주소를 파라미터로, 반환값 없음
    printf("front <-"); // 데이터의 출구 표시 출력
    for(int i = CQ->front; i != CQ->rear;) { // front를 i로 하고 i가 rear가 아닐 때까지
        i = (i + 1) % MAX_SIZE; // i를 1씩 증가시키는데 원형 큐이므로 MAX_SIZE를 넘지 않도록 모듈러 연산
        printf("%d <-", CQ->queue[i]); // 해당 인덱스 위치의 데이터 출력
    }
    printf(" rear\n"); // 데이터의 입구 표시 출력 및 개행
}

// 원형 큐가 포화 상태인지 판단
bool CQ_is_queue_full (CircularQueue* CQ) { // 원형 큐의 주소를 파라미터로, 참 거짓 반환
    return ((CQ->rear + 1) % MAX_SIZE) == CQ->front; // 큐의 길이 숫자에 1을 더하고 모듈러 연산을 한 값이 front와 같다면 큐가 포화 상태인 것으로 판단
}

// 원형 큐가 공백 상태인지 판단
bool CQ_is_queue_empty (CircularQueue* CQ) { // 원형 큐의 주소를 파라미터로, 참 거짓 반환
    return CQ->front == CQ->rear; // 큐의 front와 큐의 rear 값이 같다면 큐가 공백 상태인 것으로 판단
}

// 원형 큐에 삽입
void CQ_push (CircularQueue* CQ, Datatype data) { // 원형 큐의 주소를 파라미터로, 반환값 없음
    if (CQ_is_queue_full(CQ)) { // 큐가 가득 차 있다면
        printf("CQ_push : 포화 큐이므로 항목 삽입이 불가능합니다."); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 큐에 삽입할 수 있는 공간이 있다면
        CQ->rear = (CQ->rear + 1) % MAX_SIZE; // rear(입구)의 
        CQ->queue[CQ->rear] = data; // 
    }
}

int main () {
    return 0;
}