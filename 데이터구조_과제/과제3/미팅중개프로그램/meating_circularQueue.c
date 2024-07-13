#include <stdio.h> // 기본 입출력을 위한 헤더파일
#include <stdlib.h> // 노드의 동적 할당을 위한 malloc을 사용하기 위한 헤더파일
#include <stdbool.h> // is_queue_empty 함수의 반환값을 bool형으로 하기 위한 헤더파일
#include <string.h> // 입력한 문자열이 stop인지 확인하기 위해 비교를 위한 strcmp를 사용하기 위한 헤더파일

#define Datatype People // Datatype이라는 글자를 모두 People로 바꿔서 컴파일 할 것을 선언하는 전처리기
#define MAX_SIZE 100

typedef struct People { // 입력받을 사람에 대한 구조체 선언
    char name[31]; // 그 사람의 이름
    char gender; // 그 사람의 성별
} People; // People형 자료형으로 부를 것을 정의

typedef struct{ // 원형 큐의 정의
    People data[MAX_SIZE]; // peaple의 데이터의 포인터를 저장할 포인터 배열을 가진다 최대 큐의 크기는 MAX_SIZE를 따라간다
    int front; // 데이터의 출구를 표시할 인덱스 번호 저장
    int rear; // 데이터의 입구를 표시할 인덱스 번호 저장
}Queue; // 이름을 Queue로 할 것을 정의

void init_queue(Queue* queue){ // 원형 큐의 초기화
    queue->front = queue->rear = 0; // 큐의 front와 rear를 모두 0으로 초기화
}

bool is_queue_full(Queue* queue){ // 큐가 가득 차있는지 검사하는 로직
    return ((queue->rear + 1) % MAX_SIZE) == queue->front; // 가장끝쪽인 입구에 +1을 한 값이 front와 동일하다면 +1을 해 준 값에  % 연산을 해 준 이유는 최대값 초과 방지이다. 
}

bool is_queue_empty(Queue* queue){ // 큐가 비었는지 검사하는 로직
    return queue->front == queue->rear; // 큐의 시작과 끝이 같다면
}

void push_queue(Queue* queue, Datatype data){ // queue의 push
    if(is_queue_full(queue)){ // 만약 큐가 가득 차 있다면
        printf("포화 큐입니다! 삽입이 불가능합니다."); // 삽입 불가 메세지 출력
        exit(1); // 프로그램 종료
    } else { // 만약 큐가 가득 차 있지 않다면
        queue->rear = (queue->rear + 1) % MAX_SIZE; // 큐의 rear(출구)의 인덱스 값을 1늘리고 최대값 초과 방지를 위한 MAX_SIZE 모듈러 연산 진행
        queue->data[queue->rear] = data; // 매개변수 데이터를 queue의 데이터에 삽입
    }
}

Datatype pop_queue(Queue* queue){ // queue의 pop
    if(is_queue_empty(queue)){ // 만약 큐가 비어있다면
        printf("공백 큐입니다! 삭제가 불가능합니다."); // 삭제 불가 메세지 출력
        exit(1); // 프로그램 종료
    } else { // 큐가 비어있지 않다면
        queue->front = (queue->front + 1) % MAX_SIZE; // 큐의 front(입구)의 인덱스 값을 1늘리고 최대값 초과 방지를 위한 MAX_SIZE 모듈러 연산 진행
        return queue->data[queue->front]; // 해당 front(출구) 위치 인덱스의 값을 리턴
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
            if(is_queue_empty(&queueMale)){ // 남자 대기 큐가 비었다면
                push_queue(&queueFemale, people); // 여자 대기 큐에 해당 사람 집어넣기
            } else { // 남자 대기 큐가 비지 않았다면
                People male =  pop_queue(&queueMale); // 남자 대기 큐에서 사람을 pop해서 저장하기
                printf("커플이 탄생했습니다! %s와 %s\n", people.name, male.name); // 그 사람과 매칭되었음을 출력
            }
        } else if(people.gender == 'm') { // 입력받은 사람의 성별이 남자라면
            // 여자 큐 확인
            if(is_queue_empty(&queueFemale)){ // 여자 대기 큐가 비었다면
                push_queue(&queueMale, people); // 남자 대기 큐에 해당 사람 집어넣기
            } else { // 여자 대기 큐가 비지 않았다면
                People female =  pop_queue(&queueFemale); // 여자 대기 큐에서 사람을 pop해서 저장하기
                printf("커플이 탄생했습니다! %s와 %s\n", people.name, female.name); // 그 사람과 매칭되었음을 출력
            }
        } else {
            printf("성별을 제대로 입력해 주십시오\n");
        }
    }
}

int main(){
    meeting(); // meeting 함수 실행
    return 0; // 프로그램 종료
}