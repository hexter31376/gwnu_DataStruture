#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define AS_MAX_SIZE 100 // 배열 스택의 최대 크기 정의
#define AS_DataType int // 유연한 코딩을 위한 데이터 타입 정의

// 배열 스택 정의
typedef struct ArrayStack { // 배열 스택의 구조체 정의
    int top; // 스택의 입/출구 인덱스 지정용 top
    int length; // 스택의 길이 저장 변수;
    AS_DataType stack[AS_MAX_SIZE]; // 실제 값을 저장하는 스택
} ArrayStack; // 배열 스택의 명칭 정의



// 배열 스택 초기화
void AS_init_stack (ArrayStack* AS) { // 배열 스택의 주소를 매개변수로, 반환값 없음
    AS->top = -1; // 비어있는 상태를 -1로 정의
    AS->length = 0; // 배열 스택 길이 초기화
}

// 배열 스택 항목들을 출력
void AS_print_stack (ArrayStack* AS) { // 배열 스택의 주소를 매개변수로, 반환값 없음
    printf("top-> "); // 스택의 top이라는 의미의 출력
    for (int i = AS->top; i>=0; i--) { // 스택의 top에 해당하는 인덱스부터 0번 인덱스까지
        printf("%d | ", AS->stack[i]); // 스택의 i번째 항목을 출력
    }
    printf("\n"); // 개행
}

// 배열 스택이 포화 상태인지 판단
bool AS_is_stack_full (ArrayStack* AS) { // 배열 스택의 주소를 매개변수로, 참 거짓 반환
    return AS->top == AS_MAX_SIZE - 1; // top이 배열의 최대 크기를 초과하는지에 대한 참 거짓을 반환
}

// 배열 스택이 공백 상태인지 판단
bool AS_is_stack_empty (ArrayStack* AS) { // 배열 스택의 주소를 매개변수로, 참 거짓 반환
    return AS->top == -1; // top이 -1(비어있는 상태)인지 판단하고 참 거짓을 반환 
}

// 배열 스택에 삽입
void AS_push (ArrayStack* AS, AS_DataType data) { // 배열 스택의 주소, 삽입할 데이터를 매개변수로, 반환값 없음
    if (AS_is_stack_full(AS)) { // 스택이 가득 차 있다면
        printf("AS_push : 포화 스택이므로 항목 삽입이 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 스택이 가득 차있지 않다면
        AS->stack[++AS->top] = data; // 스택의 top을 1증가시킨 후, 그 인덱스 값에 해당하는 위치에 data를 삽입
        AS->length++; // 스택의 길이 증가
    }
}

// 배열 스택에서 삭제
AS_DataType AS_pop (ArrayStack* AS) { // 배열 스택의 주소를 매개변수로, pop한 데이터 반환
    if (AS_is_stack_empty(AS)) { // 스택이 비어 있다면
        printf("AS_pop : 공백 스택이므로 항목 삭제가 불가능합니다.\n"); // 경고문 출력
        exit(1); // 프로그램 종료
    } else { // 스택이 가득 차있지 않다면
        AS->length--; // 스택의 길이 감소
        return AS->stack[AS->top--]; // 스택의 인덱스 값에 해당하는 위치에 인덱스 값을 대입한 후 스택의 top을 1감소시킨 후, 대입한 위치의 값을 리턴
    }
}

// 배열 스택에서 top 데이터를 반환
AS_DataType AS_get_data (ArrayStack* AS) { // 배열 스택의 주소를 매개변수로, top 인덱스의 데이터 반환
    if (AS_is_stack_empty(AS)) { // 스택이 비어 있다면
        printf("AS_get_data : 공백 스택이므로 데이터가 없습니다.");
        exit(1); // 프로그램 종료
    } else { // 스택이 가득 차있지 않다면
        return AS->stack[AS->top]; // 스택의 top의 인덱스에 해당하는 위치의 값을 반환
    }
}
int main () {
    ArrayStack stackSample;
    AS_init_stack(&stackSample);
    AS_push(&stackSample, 10);
    AS_push(&stackSample, 20);
    AS_push(&stackSample, 30);
    AS_print_stack(&stackSample);
    printf("현재 top 항목은 %d\n", AS_get_data(&stackSample));
    AS_pop(&stackSample);
    printf("현재 top 항목은 %d\n", AS_get_data(&stackSample));
    AS_pop(&stackSample);
    printf("현재 top 항목은 %d\n", AS_get_data(&stackSample));
    AS_pop(&stackSample);
    AS_pop(&stackSample);
    return 0;
}