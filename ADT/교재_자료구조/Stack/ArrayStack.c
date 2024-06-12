#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define DataType int

// 배열 스택 정의
typedef struct ArrayStack {
    int top; // 스택의 입/출구 인덱스 지정용 top
    DataType stack[MAX_SIZE]; // 실제 값을 저장하는 스택
} ArrayStack; // 배열 스택의 명칭 정의

// 스택 초기화
void AS_init_stack (ArrayStack* AS) {
    AS->top = -1; // 비어있는 상태를 -1로 정의
}

void AS_print_stack (ArrayStack* AS) {
    printf("top->");
    for (int i = AS->top; i>=0; i--) {

    }
}

int main () {

}