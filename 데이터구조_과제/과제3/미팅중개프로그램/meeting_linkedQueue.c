#include <stdio.h> // 기본 입출력을 위한 헤더파일
#include <stdlib.h> // 노드의 동적 할당을 위한 malloc을 사용하기 위한 헤더파일
#include <stdbool.h> // is_queue_empty 함수의 반환값을 bool형으로 하기 위한 헤더파일
#include <string.h> // 입력한 문자열이 stop인지 확인하기 위해 비교를 위한 strcmp를 사용하기 위한 헤더파일

#define Datatype People // Datatype이라는 글자를 모두 People로 바꿔서 컴파일 할 것을 선언하는 전처리기

typedef struct People { // 입력받을 사람에 대한 구조체 선언
    char name[31]; // 그 사람의 이름
    char gender; // 그 사람의 성별
} People; // People형 자료형으로 부를 것을 정의

typedef struct Node { // 노드의 정의
    Datatype data; // 데이터
    struct Node* link; // 다음 노드
} Node; // Node형 자료형으로 부를 것을 정의

typedef struct { // 큐의 정의
    Node* front; // 출구
    Node* rear; // 입구
    int count; // 큐의 개수
} Queue; // Queue형 자료형으로 부를 것을 정의

void init_queue(Queue* queue) { // 큐의 초기화 함수 큐의 주소를 매개변수로 받는다
    queue->front = queue->rear = NULL; // 해당 큐의 front(데이터의 출구)와 rear(데이터의 입구)가 될 노드를 가리키는 포인터를 초기화
    queue->count = 0; // 큐가 비어있음을 의미하는 0으로 카운트 초기화
}

bool is_queue_empty(Queue* queue) { // 해당 큐가 차있으면 true 차있지 않으면 false를 리턴하는 함수
    return queue->count == 0; // count가 0이면 true 그렇지 않으면 false를 리턴
}

Node* create_node(Datatype data) { // 새로운 노드 생성
    Node* newnode = (Node*)malloc(sizeof(Node)); // Node형 newnode에 Node형 데이터를 동적 할당
    if (!newnode) { // 동적 할당 실패시
        return NULL; // 널 포인터 반환
    }
    newnode->data = data; // 파라미터로 받은 데이터를 newnode의 데이터에 집어넣기
    newnode->link = NULL; // newnode의 link를 널포인터로 초기화
    return newnode; // 새로 동적 할당한 노드 리턴
}

void push_queue(Queue* queue, Datatype data) {
    Node* newnode = create_node(data);
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    if (is_queue_empty(queue)) {
        queue->front = newnode;
    } else {
        queue->rear->link = newnode;
    }
    queue->rear = newnode;
    queue->count++;
}

Datatype pop_queue(Queue* queue) {
    Node* popNode;
    Datatype popData;
    if (is_queue_empty(queue)) {
        printf("queue underflow\n");
        exit(1); // 프로그램 종료
    } else {
        popNode = queue->front;
        popData = popNode->data;
        queue->front = popNode->link;
        free(popNode);
        queue->count--;
        return popData;
    }
}

int meeting(){
    Queue queueMale; // 남자 큐 생성
    init_queue(&queueMale); // 해당 큐 초기화

    Queue queueFemale; // 여자 큐 생성
    init_queue(&queueFemale); // 해당 큐 초기화

    People people; // 입력받을 사람의 데이터

    while (1) { // 무한 반복
        printf("이름을 입력하세요 ('stop'을 입력하면 종료): "); // 안내 멘트
        scanf("%s", people.name); // 이름 입력받기

        if (strcmp(people.name, "stop") == 0) { // 입력받은 이름이 stop이라면
            break; // 반복문 탈출
        }
        getchar(); // 개행 문자 제거

        printf("성별을 입력하세요 (f or m): "); // 안내 멘트
        scanf("%c", &people.gender); // 성별 입력받기
        getchar(); // 개행 문자 제거

        // 성별 매칭 로직
        if(people.gender == 'f'){ // 입력받은 사람의 성별이 여자라면
            // 남자 큐 확인
            if(queueMale.front == NULL){ // 남자 대기 큐가 비었다면
                push_queue(&queueFemale, people); // 여자 대기 큐에 해당 사람 집어넣기
            } else { // 남자 대기 큐가 비지 않았다면
                People male =  pop_queue(&queueMale); // 남자 대기 큐에서 사람을 pop해서 저장하기
                printf("커플이 탄생했습니다! %s와 %s\n", people.name, male.name); // 그 사람과 매칭되었음을 출력
            }
        } else if(people.gender == 'm') { // 입력받은 사람의 성별이 남자라면
            // 여자 큐 확인
            if(queueFemale.front == NULL){ // 여자 대기 큐가 비었다면
                push_queue(&queueMale, people); // 남자 대기 큐에 해당 사람 집어넣기
            } else { // 여자 대기 큐가 비지 않았다면
                People female =  pop_queue(&queueFemale); // 여자 대기 큐에서 사람을 pop해서 저장하기
                printf("커플이 탄생했습니다! %s와 %s\n", people.name, female.name); // 그 사람과 매칭되었음을 출력
            }
        }
    }
}

int main(){
    meeting(); // meeting 함수 실행
    return 0; // 프로그램 종료
}