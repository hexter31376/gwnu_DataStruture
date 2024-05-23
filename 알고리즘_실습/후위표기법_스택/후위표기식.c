#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define Datatype char

typedef struct Node { // 노드의 정의
    struct Node* link; // 노드는 다른 노드를 가리킨다
    Datatype data; // 데이터를 가지고 있다
} Node;

typedef struct Stack { // 스택의 정의
    Node* top; // 스택의 top이 되는 노드를 가리킨다
    int count; // 스택의 개수를 측정한다
} Stack;

int stack_create(Stack** stack) { // 스택의 생성 함수
    *stack = (Stack*)malloc(sizeof(Stack)); // 새로운 스택을 동적 할당 // 직접 할당이므로 포인터로 조작
    if (!*stack) { // 동적 할당을 실패하면
        return 0; // 할당 실패 반환
    }
    else { // 동적 할당을 성공하면
        (*stack)->top = NULL; // 스택의 top을 널값으로 초기화
        (*stack)->count = 0; // 스택의 카운트를 0으로 초기화
        return 1; // 할당 성공 반환
    }
}

int push_stack(Stack* stack, Datatype data) { // push
    Node* newnode = (Node*)malloc(sizeof(Node)); // 노드의 동적 할당
    if (!newnode) { // 노드의 동적 할당을 실패하면
        return 0; // 할당 실패 반환
    }
    else { // 동적 할당을 성공하면
        newnode->data = data; // 받은 데이터를 newnode에 집어넣기
        newnode->link = stack->top; // 스택의 top이 가리키는 포인터를 newnode가 가리키게 하고
        stack->top = newnode; // 스택의 top이 newnode를 가리키게 한다
        stack->count++; // 스택 카운트 증가
        return 1; // 할당 성공 반환
    }
}

Datatype pop_stack(Stack* stack) { // pop
    if (stack->count == 0) { // 스택이 비어있으면
        return '\0'; // 널값 반환
    } else if (stack->count == 1){
        Datatype datasave = stack->top->data; // 반환할 pop data를 미리 빼둔다
        free(stack->top); // 지울 노드의 동적 할당 해제
        stack->top = NULL;
        stack->count--; // 스택 카운트 감소
        return datasave; // pop한 데이터 출력
    } else {
        Datatype datasave = stack->top->data; // 반환할 pop data를 미리 빼둔다
        Node* delnode = stack->top; // 지울 노드는 스택의 top임을 알려준다
        stack->top = stack->top->link; // 스택의 top이 그 이전 노드를 가리키게 한다
        free(delnode); // 지울 노드의 동적 할당 해제
        stack->count--; // 스택 카운트 감소
        return datasave; // pop한 데이터 출력
    }
}

Datatype seeTop_stack(Stack* stack){
    if(!stack->top){ // 스택이 비어있으면
        return '\0'; // 널문자 반환
    } else {
        return stack->top->data;
    }
}

int out_prec(char operater){ // 스택 바깥쪽 연산자 우선순위의 크기 반환
    if(operater == '+' || operater == '-'){
        return 1;
    } else if (operater == '*' || operater == '/'){
        return 2;
    } else if (operater == '('){ // 바깥쪽에서는 우선순위를 제일 크게
        return 3;
    } else {
        return 0;
    }
}

int in_prec(char operater){ // 스택 안쪽 연산자 우선순위의 크기 반환
    if(operater == '+' || operater == '-'){
        return 1;
    } else if (operater == '*' || operater == '/'){
        return 2;
    } else if (operater == '('){ // 안쪽에서는 우선순위를 제일 작게
        return 0;
    } else {
        return 0;
    }
}

Datatype* infix_to_postfix(Stack* stack, Datatype* input){
    char inputValue, operater; // input의 inputCounter번 인덱스의 값을 저장할 변수 inputValue, 

    int inputLen = strlen(input); // input의 길이
    Datatype* output = (Datatype*)malloc(sizeof(Datatype) * (inputLen + 1)); // output 동적 할당

    int outputCounter = 0; // 오직 output에 집어넣었을때만 증가
    int inputCounter = 0; // 오직 input을 스캔할때마다 증가

    while(inputCounter < inputLen){
        inputValue = input[inputCounter++]; // input의 inputCounter인덱스의 값을 invalue에 저장하고 카운터 1 증가

        if('A' <= inputValue && inputValue <= 'Z'){ // invalue가 알파벳 대문자 범위이면 // 그냥 숫자이면
            output[outputCounter++] = inputValue; // invalue를 outputCounter에 집어넣고 카운터 1 증가
        } else if(inputValue == ')'){ // invalue가 )이면 // 오른쪽 괄호
            while((operater = pop_stack(stack)) != '('){ // pop을 하고 그 값을 operater에 집어넣은 다음 그값이 ( 가 아니면
                output[outputCounter++] = operater; // 스택에서 나온 연산자를 저장한 operater 변수를 output에 집어넣고 카운터 1 증가
            }
        } else { // invalue가 operater면 // 연산자이면
            while (!(stack->count == 0) && in_prec(seeTop_stack(stack)) >= out_prec(inputValue)){ // 스택이 비지 않았고 안쪽 오퍼레이터의 우선순위가 바깥쪽 오퍼레이터의 순서보다 더 높다면
                output[outputCounter++] = pop_stack(stack); // 스택을 pop 하고 그 값을 output의 outputCounter에 저장하고 카운터 1 증가
            }
            push_stack(stack, inputValue); // 이후 inputValue 집어넣기
        }
    }
    // 스택에 남아있는 연산자 처리
    while (!(stack->count == 0)){
        output[outputCounter++] = pop_stack(stack);
    }
    output[outputCounter] = '\0';
    return output; // 아웃풋의 주소 리턴
}

int main() {
    Stack* stack;
    stack_create(&stack);

    char input[101];
    scanf("%s", input);
    
    char* output = infix_to_postfix(stack, input);
    printf("%s", output);

    free(output);
    free(stack);
    return 0;
}