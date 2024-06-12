#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DataType int // 유연한 코딩을 위한 데이터 타입 정의

// 연결 스택 노드 구조 정의
typedef struct Snode { // 연결 스택 노드의 구조체 선언
    DataType data; // 실제 데이터를 저장하는 공간 정의
    struct Snode* next; // 다른 노드를 가리킬 수 있는 링크 정의
} Snode; // 연결 스택 노드의 명칭 선언

// 연결 스택의 헤드 노드 구조 정의
typedef struct LinkedStack { // 연결 스택의 구조체 선언
    Snode *top; // 스택의 top이자 연결 스택의 head 역할을 할 포인터 정의
    int length; // 연결 스택의 길이, 즉 데이터의 개수 정의
} LinkedStack; // 연결 스택의 명칭 선언

// 연결 스택 초기화
void LS_init_stack (LinkedStack* LS) { // 연결 스택의 주소를 매개변수로, 반환값 없음
    LS->top = NULL; // 연결 스택의 top을 null로
}

// 연결 스택 항목들을 출력
void LS_print_stack (LinkedStack* LS) { // 연결 스택의 주소를 매개변수로, 반환값 없음
    printf("top-> "); // 스택의 top이라는 의미의 출력
    for (Snode *cursorNode = LS->top; cursorNode; cursorNode = cursorNode->next) { // 커서가 널값이 아닐동안 계속
        printf("%d| ", cursorNode->data); // 연결 스택 커서 노드의 데이터 출력
    }
    printf("\n"); // 개행
}

// 연결 스택이 포화 상태인지 판단 // 할당 실패를 의미
bool LS_is_stack_full (Snode *node) { // 할당하려는 노드의 주소를 매개변수로, 참 거짓 반환
    return node == NULL; // 노드 할당 성공 여부를 판단하는 참 거짓의 결과를 리턴
}

// 연결 스택이 공백 상태인지 판단
bool LS_is_stack_empty (LinkedStack* LS) { // 연결 스택의 주소를 매개변수로, 참 거짓 반환
    return LS->top == NULL; // top이 node를 가리키는지 판단하는 참 거짓의 결과를 리턴
}

// 연결 스택에 삽입
void LS_push (LinkedStack* LS, DataType data) { // 연결 스택의 주소, 삽입하려는 데이터를 매개변수로, 반환값 없음
    Snode *newNode = (Snode*)malloc(sizeof(Snode)); // 새로운 노드를 동적 생성
    if (LS_is_stack_full(newNode)) { // 스택이 가득 차있다면
        printf("LS_push : 포화 스택이거나 할당 오류이므로 항목 삽입이 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else {
        newNode->data = data; // 파라미터 데이터를 동적 생성한 노드에 삽입
        newNode->next = LS->top; // 동적 생성한 노드의 링크가 연결 스택의 top이 가리키는 노드를 가리키게 한다 // null이면 당연히 아무것도 가리키지 않겠다.
        LS->top = newNode; // 연결 리스트의 top이 동적 생성한 노드를 가리키게 한다
        LS->length++; // 연결 리스트 카운트를 1 증가
    }
}

// 연결 스택에서 삭제
DataType LS_pop (LinkedStack* LS) { // 연결 스택의 주소를 매개변수로, pop 한 데이터 반환
    if (LS_is_stack_empty(LS)) { // 스택이 비어있다면
        printf("LS_pop : 공백 스택이므로 항목 삭제가 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 스택이 비어있지 않다면
        Snode* deletedNode = LS->top; // 연결 스택의 탑을 지울 노드로 지정
        DataType popedData = deletedNode->data; // 지울 노드에서 데이터 추출해서 저장
        LS->top = LS->top->next; // 지울 노드의 다음 노드를 새로운 top으로 지정 // LS->top = deletedNode->link와 동일하다
        free(deletedNode); // 지울 노드를 동적 할당 해제하기
        return popedData; // 추출한 데이터 반환
    }
}

// 연결 스택에서 top 데이터를 반환
DataType LS_get_top (LinkedStack* LS) { // 연결 스택의 주소를 매개변수로, top 데이터 반환
    if (LS_is_stack_empty(LS)) { // 스택이 비어있다면
        printf("LS_get_top : 공백 스택이므로 데이터가 없습니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 스택이 비어있지 않다면
        return LS->top->data; // 연결 스택의 top의 데이터를 반환
    }
}

int main () {
    LinkedStack stackSample;
    LS_init_stack(&stackSample);
    LS_push(&stackSample, 10);
    LS_push(&stackSample, 20);
    LS_push(&stackSample, 30);
    LS_print_stack(&stackSample);
    printf("현재 top 항목은 %d\n", LS_get_top(&stackSample));
    LS_pop(&stackSample);
    printf("현재 top 항목은 %d\n", LS_get_top(&stackSample));
    LS_pop(&stackSample);
    printf("현재 top 항목은 %d\n", LS_get_top(&stackSample));
    LS_pop(&stackSample);
    LS_pop(&stackSample);
    return 0;
}