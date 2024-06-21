#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LD_DataType int // 유연한 코딩을 위한 데이터 타입 정의

// 연결 덱 노드 구조 정의
typedef struct Dnode { // 덱 노드 구조체 선언
    struct Dnode* prev; // 이전 덱 노드를 가리킬 포인터
    LD_DataType data; // 실제 저장할 데이터
    struct Dnode* next; // 다음 덱 노드를 가리킬 포인터
} Dnode; // 덱 노드 구조체 명칭 선언

// 연결 덱의 헤드 노드 구조 정의
typedef struct LinkedDeque { // 덱 구조체 선언
    Dnode* front; // 첫 번째 노드를 가리키는 포인터
    int length; // 덱의 길이
    Dnode* rear; // 마지막 노드를 가리키는 포인터
} LinkedDeque; // 덱 구조체 명칭 선언

// 연결 덱 초기화
void LD_init_deque(LinkedDeque* LD) { // 연결 덱의 주소를 매개변수로, 반환값 없음
    LD->front = LD->rear = NULL; // 첫 번째 노드를 가리키는 포인터와 마지막 노드를 가리키는 포인터를 NULL로 초기화
    LD->length = 0; // 덱의 길이 카운트 초기화
}

// 연결 덱 항목들을 출력
void LD_print_deque(LinkedDeque* LD) { // 연결 덱의 주소를 매개변수로, 반환값 없음
    printf("front <-> "); // 데이터의 출구 표시 출력
    for (Dnode* nodeCursor = LD->front; nodeCursor; nodeCursor = nodeCursor->next) { // 노드 커서를 만들고 그 노드 커서가 null 즉, 연결 덱의 끝이 아닐 때까지
        printf("%d <-> ", nodeCursor->data); // 해당 커서 위치의 데이터 출력
    }
    printf("rear\n"); // 데이터의 입구 표시 출력 및 개행
}

// 연결 덱이 포화 상태인지 판단 // 연결 덱은 크기 제한이 없기에 메모리 할당 실패시를 포화 상태로 판단한다
bool LD_is_deque_full(Dnode* node) { // 노드의 주소를 파라미터로, 참, 거짓 반환
    return node == NULL; // 노드 할당 성공 여부 참 거짓 결과 반환
}

// 연결 큐가 공백 상태인지 확인
bool LD_is_deque_empty(LinkedDeque* LD) { // 연결 덱의 주소를 파라미터로, 참, 거짓 반환
    return LD->front == NULL; // front가 공백인지에 대한 참 거짓 결과 반환
}

// 연결 덱의 앞에 삽입
void LD_push_front(LinkedDeque* LD, LD_DataType data) { // 연결 덱의 주소, 삽입할 데이터를 매개변수로, 반환값 없음
    Dnode* newDnode = (Dnode*)malloc(sizeof(Dnode)); // 연결 덱 노드 동적 할당
    if (LD_is_deque_full(newDnode)) { // 연결 덱이 가득 차 있다면
        printf("LD_push_front : 포화 덱이므로 항목 삽입이 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 연결 덱이 가득 차 있지 않다면
        newDnode->prev = NULL; // 새 노드의 이전 노드를 가리키는 포인터 초기화
        newDnode->data = data; // 파라미터의 데이터를 새 노드의 데이터에 삽입
        newDnode->next = LD->front; // 연결 덱의 첫 번째가 가리켰던 포인터를 새로운 노드의 next가 가리키게 함
        if (LD_is_deque_empty(LD)) { // 만약 덱이 비어있다면
            LD->rear = newDnode; // 덱의 마지막의 포인터가 새로운 노드를 가리키게 함
        } else { // 만약 덱이 비어있지 않다면
            LD->front->prev = newDnode; // 연결 덱의 첫 번째가 가리키는 노드의 이전 노드를 가리키는 prev가 새로운 노드를 가리키게 함
        }
        LD->front = newDnode; // 연결 덱의 첫 번째 요소로 새로운 노드를 가리기게 함
        LD->length++; // 연결 덱의 길이 증가
    }
}

// 연결 덱의 뒤에 삽입
void LD_push_rear(LinkedDeque* LD, LD_DataType data) { // 연결 덱의 주소, 삽입할 데이터를 매개변수로, 반환값 없음
    Dnode* newDnode = (Dnode*)malloc(sizeof(Dnode)); // 연결 덱 노드 동적 할당
    if (LD_is_deque_full(newDnode)) { // 연결 덱이 가득 차 있다면
        printf("LD_push_rear : 포화 덱이므로 항목 삽입이 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 연결 덱이 가득 차 있지 않다면
        newDnode->prev = LD->rear; // 연결 덱의 마지막 부분이 가리키는 주소의 값을 새로운 노드의 prev가 가리키게 함
        newDnode->data = data; // 파라미터의 데이터를 새 노드의 데이터에 삽입
        newDnode->next = NULL; // 새로운 노드의 next를 가리키는 포인터 초기화
        if (LD_is_deque_empty(LD)) { // 만약 덱이 비어있다면
            LD->front = newDnode; // 덱의 시작부의 포인터가 새로운 노드를 가리키게 함
        } else { // 만약 덱이 비어있지 않다면
            LD->rear->next = newDnode; // 연결 덱의 마지막이 가리키는 노드의 다음 노드를 가리키는 next가 새로운 노드를 가리키게 함
        }
        LD->rear = newDnode; // 연결 덱의 마지막 요소로 새로운 노드를 가리기게 함
        LD->length++; // 연결 덱의 길이 증가
    }
}

// 연결 덱의 맨 앞 데이터를 삭제
LD_DataType LD_pop_front(LinkedDeque* LD) { // 연결 덱의 주소를 매개변수로, pop한 데이터 반환
    if (LD_is_deque_empty(LD)) { // 만약 큐가 비어있다면
        printf("LD_pop_front : 공백 덱이므로 항목 삭제가 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 큐가 비어있지 않다면
        Dnode* popedDnode = LD->front; // pop할 노드를 선택, pop할 노드는 front가 가리키는 노드이다.
        LD_DataType popedDdata = popedDnode->data; // pop할 데이터를 미리 popedDdata에 저장
        LD->front = popedDnode->next; // front가 pop할 노드의 다음 노드를 가리키게 한다.
        if (!LD->front) { // 삭제 후에 공백 덱이 되었다면
            LD->rear = NULL; // rear도 null로
        } else { // 삭제 후에도 공백 덱이 아니라면
            LD->front->prev = NULL; // 지울 노드의 prev를 NULL로 설정
        }
        free(popedDnode); // pop한 노드 동적 할당 해제
        LD->length--; // 연결 덱의 길이 감소
        return popedDdata; // pop한 데이터 반환
    }
}

// 연결 덱의 맨 뒤 데이터를 삭제
LD_DataType LD_pop_rear(LinkedDeque* LD) { // 연결 덱의 주소를 매개변수로, pop한 데이터 반환
    if (LD_is_deque_empty(LD)) { // 만약 큐가 비어있다면
        printf("LD_pop_rear : 공백 덱이므로 항목 삭제가 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 큐가 비어있지 않다면
        Dnode* popedDnode = LD->rear; // pop할 노드를 선택, pop할 노드는 rear가 가리키는 노드이다.
        LD_DataType popedDdata = popedDnode->data; // pop할 데이터를 미리 popedDdata에 저장
        LD->rear = popedDnode->prev; // rear가 pop할 노드의 이전 노드를 가리키게 한다.
        if (!LD->rear) { // 삭제 후에 공백 덱이 되었다면
            LD->front = NULL; // front도 null로
        } else { // 삭제 후에도 공백 덱이 아니라면
            LD->rear->next = NULL; // 지울 노드의 next를 NULL로 설정
        }
        free(popedDnode); // pop한 노드 동적 할당 해제
        LD->length--; // 연결 덱의 길이 감소
        return popedDdata; // pop한 데이터 반환
    }
}

// 연결 덱에서 맨 처음 데이터를 반환
LD_DataType LD_get_data_front(LinkedDeque* LD) { // 연결 덱의 주소를 파라미터로, 맨 처음 데이터를 반환
    if (LD_is_deque_empty(LD)) { // 덱이 비어있다면
        printf("LD_get_data_front : 공백 덱이므로 데이터가 없습니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 덱이 비어있지 않다면
        return LD->front->data; // front의 데이터 반환
    }
}

// 연결 덱에서 맨 뒤 데이터를 반환
LD_DataType LD_get_data_rear(LinkedDeque* LD) { // 연결 덱의 주소를 파라미터로, 맨 마지막 데이터를 반환
    if (LD_is_deque_empty(LD)) { // 덱이 비어있다면
        printf("LD_get_data_rear : 공백 덱이므로 데이터가 없습니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 덱이 비어있지 않다면
        return LD->rear->data; // rear의 데이터 반환
    }
}

int main() {
    LinkedDeque ldeque;
    LD_init_deque(&ldeque);
    LD_push_front(&ldeque, 20);
    LD_push_rear(&ldeque, 30);
    LD_push_front(&ldeque, 10);
    LD_print_deque(&ldeque);
    printf("현재 맨 앞 항목은 %d\n", LD_get_data_front(&ldeque));
    LD_pop_front(&ldeque);
    printf("현재 front 항목은 %d\n", LD_get_data_front(&ldeque));
    LD_pop_rear(&ldeque);
    printf("현재 front 항목은 %d\n", LD_get_data_front(&ldeque));
    LD_pop_front(&ldeque);
    return 0;
}