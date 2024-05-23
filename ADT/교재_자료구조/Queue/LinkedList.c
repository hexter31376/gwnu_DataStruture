#include <stdio.h>
#include <stdlib.h>

#define Datatype int // 유연한 코딩을 위한 데이터 타입 정의

typedef struct Lnode { // 데이터를 저장할 연결리스트의 노드의 정의
    Datatype data; // 실제 데이터
    struct Lnode* link; // 노드를 가리킬 수 있는 포인터
} Lnode; // 연결리스트의 노드 자료형 정의


typedef struct LinkedList { // 연결리스트 구조체의 정의
    int length; // 연결리스트의 길이
    Lnode* head; // 맨 처음 노드를 가리키는 포인터
} LinkedList; // 연결리스트 자료형 정의

// 리스트 초기화
void LL_init_list (LinkedList* LL) { // 리스트의 주소를 매개변수로 받는다
    LL->length = 0; // 리스트의 길이 초기화
    LL->head = NULL; // 리스트의 헤드 초기화
}

// 리스트 길이 계산
int LL_get_length (LinkedList* LL) { // 리스트의 주소를 매개변수로 받는다
    return LL->length; // 리스트의 길이 카운트 반환
}

// 리스트의 pos번째 항목을 반환
Datatype get_data (LinkedList* LL, int pos) {
    if (pos < 0 || pos >= LL->length) { // 매개변수 인덱스가 0보다 작거나 연결리스트의 길이보다 길다면
        printf("%d 위치에는 항목이 없습니다.", pos);
        exit(1);
    }
}

// 리스트 항목들을 출력

// 리스트에서 항목 data의 위치를 반환

// 리스트의 pos번째 위치에 항목 data를 추가

// 리스트의 pos번째 항목을 제거

// 리스트의 pos번째 항목을 data로 교체


int main () {
    
}