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

// 연결 리스트에서 특정 위치의 노드에 대한 포인터를 반환
Lnode* LL_get_ith_node (LinkedList* LL, int pos) { // 리스트의 주소와 i번째 노드를 가리킬 정수 pos를 매개변수로 받는다.
    Lnode* ptr = LL->head; // 시작 노드의 포인터 복사
    if (pos < 0) { // i번째 노드가 0보다 작다면
        return NULL; // 널 포인터 반환
    }
    for (int n = 1; n <= pos; n++) { // 1번째 항목부터 찾고자 하는 노드까지
        ptr = ptr->link; // 링크를 업데이터
    }
    return ptr; // 업데이트된 pos번째 node 반환
}

// 노드 생성
Lnode* LL_create_node (Datatype data) { // 노드에 들어갈 데이터를 매개변수로 받는다.
    Lnode* new = (Lnode*)malloc(sizeof(Lnode)); // 노드 공간을 동적 할당하고 주소 new에 넘기기
    if(!new) { // 할당에 실패하였다면
        printf("노드 생성에 실패하였습니다."); // 할당 실패 메세지
        exit(1); // 프로그램 종료
    }
    new->data = data; // 새로운 노드의 data를 new로
    new->link = NULL; // 
    return new;
}



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
Datatype LL_get_data (LinkedList* LL, int pos) { // 리스트의 주소와 구하려는 위치 pos를 매개변수로 받는다.
    if (pos < 0 || pos >= LL->length) { // 매개변수 인덱스가 0보다 작거나 연결리스트의 길이보다 길다면
        printf("%d 위치에는 항목이 없습니다.", pos); // 경고문 출력
        exit(1); // 프로그램 종료
    }
    Lnode *node = get_ith_node(LL, pos); // pos번째 노드의 포인터를 새로 선언한 Lnode형 포인터에 저장
    return node->data; // 해당 포인터의 데이터 반환
}

// 리스트 항목들을 출력
void LL_print_list (LinkedList* LL) { // 리스트의 주소를 매개변수로 받는다
    Lnode* ptr = LL->head; // 시작 노드의 포인터 복사
    printf("head"); // 헤드 노드를 의미하는 출력
    for (int i = 1; i <= LL->length i++) { // 처음 시작 노드부터 끝까지
        printf("->%d", ptr->data); // 현재 위치의 노드의 data를 출력하고
        ptr = ptr->link; // 링크 업데이트
    }
    printf("\n"); // 개행
}

// 리스트에서 항목 data의 위치를 반환
int LL_get_pos (LinkedList *LL, Datatype data) { // 리스트의 주소와 찾고자 하는 위치의 데이터를 매개변수로 받는다.
    Lnode* ptr = LL->head; // 시작 노드의 포인터 복사
    for (int i = 0; i < LL->length; i++) { // 시작부터 끝까지 돌면서
        if (ptr->data == data) { // 현재 위치의 데이터가 매개변수 데이터와 일치한다면
            return i; // 현재 위치 반환
        }
        ptr = ptr->link; // 링크 업데이트
    }
}

// 리스트의 pos번째 위치에 항목 data를 추가
void LL_insert (LinkedList* LL, int pos, Datatype data) { // 리스트의 주소와 넣으려는 위치, 넣으려는 데이터를 매개변수로 받는다.
    if (pos >= 0 && pos < LL->length) { // 입력받은 위치가 0보다 크고 연결 리스트의 길이와 같거나 작다면
        Lnode* before, * new = LL_create_node();
    }
}

// 리스트의 pos번째 항목을 제거

// 리스트의 pos번째 항목을 data로 교체


int main () {
    
}