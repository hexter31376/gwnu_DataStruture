#define _CRT_SECURE_NO_WARNINGS // scanf_s를 사용하지 않음으로 발생하는 오류 해결

#include <stdio.h> // 기본 입출력을 위한 stdio.h
#include <string.h> // 문자열의 길이 측정 함수 strlen을 사용하기 위한 string.h
#include <ctype.h> // 입력받은 아스키 문자를 대문자든 소문자든 소문자로 변경시켜주는 tolower함수를 사용하기 위한 ctype.h

#define Datatype char // Datatype이라는 글자를 컴파일 전에 전부 char로 치환할 것을 define 전처리기로 선언
#define MAX_SIZE 100 //MAX_SIZE라는 글자를 전부 컴파일 전에 100이라는 상수로 치환할 것을 define 전처리기 선언

typedef enum { // 순서있는 상수 배열 enum 선언
// enum은 C언어의 예약어로서 enum을 통해 상수 배열을 선언 순서대로 0,1,...과 같이 저장,
// FALSE는 0 TRUE는 1과 매칭되며 bool 자료형의 요소로 쓸 수도, FALSE, TRUE 따로 쓸 수도 있다.
    FALSE, TRUE
}Bool; // 이 enum의 이름을 Bool로 부를 것을 선언

typedef struct ArrayStack { // 스택의 정의
    Datatype data[MAX_SIZE]; // 스택을 정의한다
    int top; // 스택의 top 즉 인덱스이다
} ArrayStack; // 스택의 이름을 ArrayStack 자료형으로 부를 것임을 선언

void stack_init(ArrayStack* stack){ // 스택의 초기화 스택의 주소를 매개변수로 가진다 즉, 스택 변수를 포인터로 직접 조작할 것임을 알 수 있다.
    stack->top = -1; //stack의 top을 -1로 설정(stack은 포인터이므로 ->로 접근한다.) -1일때를 스택이 빈 것으로 판단하여 초기화시켜준다
}

int push_stack(ArrayStack* stack, Datatype data){ // 스택의 push 함수, 매개변수로 스택의 주소, 데이터를 매개변수로 받는다.
    if(stack->top < MAX_SIZE){ // 스택의 top이 데이터 사이즈보다 작다면 : 삽입 가능
        stack->data[++stack->top] = data; // stack의 top을 1 증가시키고(전위 연산자) 그걸 인덱스번호로 삽입한곳에 데이터 삽입
        return 1; // 삽입 성공을 의미하는 1 return
    } else { // 그렇지 않다면
        return 0; // stack overflow이므로 그것을 의미하는 0 return
    }
}

Datatype pop_stack(ArrayStack* stack){ // 스택의 pop 함수, 매개변수로 스택의 주소를 받는다.
    if(stack->top > -1){ // 만약 스택이 비어있는 스택의 의미인 top이 -1 보다 크다면
        Datatype data = stack->data[stack->top--]; // stack의 top을 인덱스번호로 삽입한곳의 데이터를 data 변수에 저장하고 top을 1 감소시킨다(후위 연산자)
        return data; // 빼둔 data 반환
    } else { // 스택이 비어있다면
        return '\0'; // stack onderflow를 의미하는 널 문자 반환
    }
}

int palindrome(char in_str[]){ // 배열의 주소를 매개변수로 받는 회문 판단 함수 선언
    ArrayStack s; // 배열 스택 s 선언
    int i; // 반복문 변수 i 선언
    char ch, chs; // 문자열 in_str의 i번째 요소를 저장할 ch, 스택에서 나온 문자를 저장할 chs 선언
    int len = strlen(in_str); // in_str 문자열의 길이를 len에 저장

    ArrayStack stack; // stack형 구조체 stack 선언
    stack_init(&stack); // 스택 초기화 함수 stack_init을 호출하고 stack의 주소 넘겨주기

    for(i = 0; i < len; i++){ // 문자열의 길이만큼 반복
        ch = in_str[i]; // ch에 현재 인덱스의 원소를 집어넣기
        if( // 만약 ch가 스페이스바 혹은 구두점이면
            ch == ' ' || // 스페이스바
            ch == '"' || // 큰따옴표
            ch == '\'' || // 이스케이프 처리로 '를 정상적으로 인식하게 함 // 작은 따옴표
            ch == ',' || // 쉼표
            ch == '.' || // 마침표
            ch == '!' || // 느낌표
            ch == '?' || // 물음표
            ch == '`' || // 악센트
            ch == ':' ||  // 콜론
            ch == ';' // 세미콜론
        ){ // 스페이스이거나 구두점이면
            continue; // 구문 넘기고 계속 반복문 진행
        }
        ch = tolower(ch); // 받아들인 문자를 영문 소문자로 모두 변경
        push_stack(&stack, ch); // ch를 스택에 집어넣기
    }
    for(i = 0; i < len; i++){ // 문자열의 길이만큼 반복
        ch = in_str[i];
        if( // 만약 ch가 스페이스바 혹은 구두점이면
            ch == ' ' || // 스페이스바
            ch == '"' || // 큰따옴표
            ch == '\'' || // 이스케이프 처리로 '를 정상적으로 인식하게 함 // 작은 따옴표
            ch == ',' || // 쉼표
            ch == '.' || // 마침표
            ch == '!' || // 느낌표
            ch == '?' || // 물음표
            ch == '`' || // 악센트
            ch == ':' ||  // 콜론
            ch == ';' // 세미콜론
        ){ // 스페이스이거나 구두점이면
            continue; // 구문 넘기고 계속 반복문 진행
        }
        ch = tolower(ch); // ch를 소문자로 변경
        chs = pop_stack(&stack); // pop한 문자를 순서대로 저장한 문자열
        if(ch != chs){ // 만약 pop한 문자열과 원래 문자열이 한글자라도 일치하지 않으면
            return FALSE; // 거짓 반환후 함수 종료 거짓은 == 0
        }
    }
    return TRUE; // 참 반환후 함수 종료 참은 == 1
}
int main(){
    char array[100]; // 입력받을 문자열의 공간 array를 선언하고 그 크기를 100으로 설정
    scanf("%^\n]*c", array); // 문자열을 array에 입력받기
    if(palindrome(array) == 1){ // 입력받은 문자열의 주소를 파라미터로 넘긴 회문 함수가 참을 반환하면
        printf("True"); // True 출력
    } else { // 거짓이면
        printf("False"); // false 출력
    }
    return 0; // 함수 종료
}