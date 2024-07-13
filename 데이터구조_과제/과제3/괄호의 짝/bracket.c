#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Datatype char // [],{},()를 받아들일 것이기에 스택이 받을 데이터를 문자 데이터로 설정한다

typedef struct Node { // 스택 노드의 정의
    Datatype data; // 문자 1개를 받아들일 data
    struct Node* link; // 다음 노드를 가리킬 link
}Node; // Node로 부를것을 선언

typedef struct LinkedStack { // 연결 스택의 정의
    Node* top; // 가장 위쪽 노드를 가리킬 Node 포인터형 top 선언
}LinkedStack; // LinkedStack으로 부를 것을 선언

void init_stack(LinkedStack* LS){ // 스택의 초기화
    LS->top = NULL; // 스택의 top을 NULL로 초기화함으로서 스택이 비었음을 표현
}

Node* create_node(Datatype data){ // 노드의 생성
    Node* newnode = (Node*)malloc(sizeof(Node)); // Node형 포인터 newnode를 선언하고 그 포인터가 동적 생성한 Node를 가리킬수 있게 함
    if(newnode == NULL){ // 동적 할당 실패시
        return NULL; // NULL 반환
    } else { // 동적 할당 성공시
        newnode->data = data; // 파라미터로 받아준 데이터를 새로 동적 할당한 노드의 데이터에 삽입
        newnode->link = NULL; // 새로 동적 할당한 노드의 link가 아무것도 가리키지 않음을 의미하는 NULL로 초기화
    }
    return newnode; // 새로 동적 할당한 노드 반환
}

void push_stack(LinkedStack* LS, Datatype data){ // 스택의 push
    Node* newnode = create_node(data); // 새로운 노드 생성
    if(LS->top == NULL){ // 스택이 비어있다면
        LS->top = newnode; // 스택의 top이 newnode를 가리키게 한다
    } else { // 스택이 비어있지 않으면
        newnode->link = LS->top; // newnode의 link가 top이 가리키는 노드를 가리키게 하고
        LS->top = newnode; // newnode를 새로운 top으로 한다
    }
}

Datatype pop_stack(LinkedStack* LS){ // 스택의 pop
    Node* delNode; // 지울 노드를 가리킬 포인터
    Datatype data; // 반환할 데이터

    if(LS->top == NULL){ // 스택이 비어있다면
        return '0'; // 0 반환
    } else { // 스택이 비어있지 않으면
        delNode = LS->top; // 현재의 top이 pop할 노드이므로 스택의 top을 delNode에 저장
        data = delNode->data; // pop할 노드의 데이터를 data에 저장
        LS->top = LS->top->link; // 링크드 리스트의 top을 링크드 리스트의 top이 가리키는 노드가 가리키는 다음 노드를 가리키게 한다
        free(delNode); // 지울 노드의 동적 할당 해제
        return data; // 저장한 데이터 반환
    }
}

int isleft(char str_i){ // 입력받은 문자가 ( { [ 중 하나인지를 판단해주는 함수
    if(str_i == '(' || str_i == '{' || str_i == '['){ // 이중에 하나라도 해당된다면
        return 1; // 1 반환
    } else { // 거짓이면
        return 0; // 0반환
    }
}

int isRight(char str_i){ // 입력받은 문자가 ) } ] 중 하나인지를 판단해주는 함수
    if(str_i == ')' || str_i == '}' || str_i == ']'){ // 이중에 하나라도 해당된다면
        return 1; // 1 반환
    } else { // 거짓이면
        return 0; // 0반환
    }
}

int isCouple(char left, char right){
    if(left == '(' && right == ')'){ // 소괄호의 짝이 맞다면
        return 1;
    } else if(left == '{' && right == '}'){ // 중괄호의 짝이 맞다면
        return 1;
    } else if(left == '[' && right == ']'){ // 대괄호의 짝이 맞다면
        return 1;
    } else{ // 짝이 안맞거나 이상한값 들어갔으면
        return 0;
    }
}

int isTrue(char input[]){
    int len = strlen(input); // 문자열의 길이 저장

    LinkedStack stack; // 새로운 스택 선언
    init_stack(&stack); // 스택 초기화

    for(int i = 0; i < len; i++){ // 문자열의 길이만큼 반복
        if(isleft(input[i])){ // 왼쪽 기호라면
            push_stack(&stack, input[i]); // 스택에 집어넣기
            printf("push successful\n");
        } else if(stack.top && isRight(input[i]) == 1 && isCouple(stack.top->data, input[i]) == 1){ // 스택이 비어있지 않고 입력 받은값이 오른쪽 닫는 기호이면서 스택의 top이 가리키는 노드의 데이터와 짝이 맞을때
            pop_stack(&stack); // 스택에서 빼내기
            printf("pop successful\n");
        } else { // 조건에 부합하지 않으면
            printf("is not true\n");
            return 0; // 0리턴
        }
    }
    if (stack.top == NULL) { // 모든 문자열 요소가 통과하고 스택이 비어 있으면
        return 1; // 1 반환
    } else {
        return 0; // 스택이 비어있지 않으면 0 반환
    }
}

int main(){
    char input[101]; // 100개까지 받을 수 있는 문자열 선언

    scanf("%s", input); // 문자열 받아들이기

    if(isTrue(input)){ // 만약 조건이 참이면
        printf("true"); // true 출력하기
    } else { // 조건이 거짓이면
        printf("false"); // false 출력하기
    }
    return 0; // 프로그램 정상 종료
}
