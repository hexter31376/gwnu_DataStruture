#include <stdio.h>
#include <stdlib.h>

#define DataType int // 유연한 코딩을 위한 데이터 타입 정의

/**
 * node 정의
 */
// 연결 리스트의 node 정의
typedef struct Lnode { // 연결 리스트 노드 구조체의 정의
    struct Lnode* prev; // 이전 노드를 가리킬 수 있는 링크
    DataType data; // 노드의 실제 데이터
    struct Lnode* next; // 다음 노드를 가리킬 수 있는 링크
} Lnode; // 단일 연결 리스트 노드의 명칭 정의

/**
 * 연결 리스트 정의
 */
// 단일 연결 리스트 정의
typedef struct SingleLinkedList { // 단일 연결 리스트
    Lnode* head; // 단일 연결 리스트의 시작을 가리키는 포인터
    Lnode* tail; // 단일 연결 리스트의 끝을 가리키는 포인터
    int length; // 단일 연결 리스트 요소의 개수를 측정하는 count 변수 선언
} SingleLinkedList; // 단일 연결 리스트의 명칭 정의

// 이중 연결 리스트 정의
typedef struct DoubleLinkedList { // 이중 연결 리스트
    Lnode* head; // 이중 연결 리스트의 시작을 가리키는 포인터
    int length; // 이중 연결 리스트 요소의 개수를 측정하는 length 변수 선언
} DoubleLinkedList; // 이중 연결 리스트의 명칭 정의


/**
 * 초기화
 */
// 단일 연결 리스트 초기화
void SLL_init_list (SingleLinkedList* LL) { // 단일 연결 리스트 포인터를 매개변수로, 반환값 없음
    LL->head = LL->tail = NULL; // 단일 연결 리스트의 포인터 초기화
    LL->length = 0; // 단일 연결 리스트의 카운트 초기화
}

// 이중 연결 리스트 초기화
void DLL_init_list (DoubleLinkedList* LL) { // 이중 연결 리스트 포인터를 매개변수로, 반환값 없음
    LL->head = NULL; // 이중 연결 리스트의 포인터 초기화
    LL->length = 0; // 이중 연결 리스트의 카운트 초기화
}
/**
 * 리스트 길이 반환
 */
// 단일 연결 리스트 길이 반환
int SLL_get_length (SingleLinkedList* LL) { // 단일 연결 리스트 포인터를 매개변수로, 리스트 길이 반환
    return LL->length; // 해당 리스트의 길이 반환
}

// 이중 연결 리스트 길이 반환
int DLL_get_length (DoubleLinkedList* LL) { // 이중 연결 리스트 포인트를 매개변수로, 리스트 길이 반환
    return LL->length; // 해당 리스트의 길이 반환
}

/**
 * 항목에 해당하는 특정 위치 반환 -> 종속 함수
 */
// 단일 연결 리스트에서 특정 위치의 노드에 대한 포인터를 반환
Lnode* SLL_get_ith_node(SingleLinkedList* LL, int position) { // 이중 연결 리스트 포인터, 찾고자 하는 위치를 매개변수로, 해당 노드 반환
    Lnode* cursorNode = LL->head; // 일단 헤드 포인터로 선택할 특정 위치의 노드 커서 탐색 조정하기
    if(position < 0) { // 선택한 위치가 0보다 작다면
        return NULL; // 널 포인터 반환
    }
    for (int n = 0; n < position; n++) { // 첫번째 노드부터 찾는 위치까지
        cursorNode = cursorNode->next; // 선택한 노드의 다음 노드를 새로운 선택 노드로
    }
    return cursorNode; // 선택한 노드 반환
}

// 이중 연결 리스트에서 특정 위치의 노드에 대한 포인터를 반환
Lnode* DLL_get_ith_node(DoubleLinkedList* LL, int position) { // 이중 연결 리스트 포인터, 찾고자 하는 위치를 매개변수로, 해당 노드 반환
    Lnode* sellectNode = LL->head; // 일단 헤드 포인터로 선택할 특정 위치의 노드 커서 탐색 조정하기
    if(position < 0) { // 선택한 위치가 0보다 작다면
        return NULL; // 널 포인터 반환
    }
    for (int n = 0; n < position; n++) { // 첫번째 노드부터 찾는 위치까지
        sellectNode = sellectNode->next; // 선택한 노드의 다음 노드를 새로운 선택 노드로
    }
    return sellectNode; // 선택한 노드 반환
}

/**
 * 특정 위치에 해당하는 항목 반환
 */
// 단일 연결 리스트의 position번째 항목을 반환
DataType SLL_get_data (SingleLinkedList* LL, int position) { // 단일 연결 리스트 포인터, 찾고자 하는 위치를 매개변수로, 해당 데이터 반환
    if (position < 0 || position >= LL->length) { // 찾고자 하는 위치가 0보다 작고 리스트의 길이보다 크다면
        printf("SLL_get_data : %d 위치에는 항목이 없습니다.", position); // 해당 위치에 항목이 없음을 출력하고
        exit(1); // 프로그램 종료
    }
    Lnode *cursorNode = SLL_get_ith_node(LL, position); // 단일 연결 리스트의 position에 해당하는 위치의 노드를 얻고
    return cursorNode->data; // 선택된 노드의 데이터 반환
}

// 이중 연결 리스트의 position번째 항목을 반환
DataType DLL_get_data (DoubleLinkedList* LL, int position) { // 이중 연결 리스트 포인터, 찾고자 하는 위치를 매개변수로, 해당 데이터 반환
    if (position < 0 || position >= LL->length) { // 찾고자 하는 위치가 0보다 작고 리스트의 길이보다 크다면
        printf("DLL_get_data : %d 위치에는 항목이 없습니다.", position); // 해당 위치에 항목이 없음을 출력하고
        exit(1); // 프로그램 종료
    }
    Lnode *cursorNode = DLL_get_ith_node(LL, position); // 단일 연결 리스트의 position에 해당하는 위치의 노드를 얻고
    return cursorNode->data; // 선택된 노드의 데이터 반환
}

/**
 * 연결 리스트 출력
 */
// 단일 연결리스트 항목들을 출력
void SLL_print_list (SingleLinkedList* LL) { // 단일 연결 리스트 포인터를 매개변수로, 반환값 없음
    Lnode* cursorNode = LL->head; // 일단 헤드 포인터로 선택할 특정 위치의 노드 커서 탐색 조정하기
    printf("head"); // head 노드라는 의미의 출력
    for (int i = 0; i < LL->length; i++) { // 맨 처음 데이터부터 리스트의 길이만큼 반복
        printf("->%d", cursorNode->data); // 해당 데이터를 출력
        cursorNode = cursorNode->next; // 선택한 노드의 다음 노드를 새로운 선택 노드로
    }
    printf("\n"); // 개행
}

// 이중 연결리스트 항목들을 출력
void DLL_print_list (DoubleLinkedList* LL) { // 이중 연결 리스트 포인터를 매개변수로, 반환값 없음
    Lnode* cursorNode = LL->head; // 일단 헤드 포인터로 선택할 특정 위치의 노드 커서 탐색 조정하기
    printf("head"); // head 노드라는 의미의 출력
    for (int i = 0; i < LL->length; i++) { // 맨 처음 데이터부터 리스트의 길이만큼 반복
        printf("<->%d", cursorNode->data); // 해당 데이터를 출력
        cursorNode = cursorNode->next; // 선택한 노드의 다음 노드를 새로운 선택 노드로
    }
    printf("\n"); // 개행
}

/**
 * 항목에 해당하는 특정 위치 반환
 */
// 단일 연결리스트에서 항목 data의 위치를 반환
int SLL_get_position (SingleLinkedList* LL, DataType data) { // 단일 연결 리스트 포인터, 찾고자 하는 데이터를 매개변수로, 찾고자 하는 위치의 인덱스 반환
    Lnode* cursorNode = LL->head; // 일단 헤드 포인터로 선택할 특정 위치의 노드 커서 탐색 조정하기
    for (int i = 0; i < LL->length; i++) { // 맨 처음 데이터부터 리스트의 길이만큼 반복
        if (cursorNode->data == data) { // 만약 찾고자 하는 데이터와 현재 노드의 데이터가 일치하면
            return i; // 해당 데이터의 인덱스 반환
        }
        cursorNode = cursorNode->next; // 선택한 노드의 다음 노드를 새로운 선택 노드로
    }
}

// 이중 연결리스트에서 항목 data의 위치를 반환
int DLL_get_position (DoubleLinkedList* LL, DataType data) { // 이중 연결 리스트 포인터, 찾고자 하는 데이터를 매개변수로, 찾고자 하는 위치의 인덱스 반환
    Lnode* cursorNode = LL->head; // 일단 헤드 포인터로 선택할 특정 위치의 노드 커서 탐색 조정하기
    for (int i = 0; i < LL->length; i++) { // 맨 처음 데이터부터 리스트의 길이만큼 반복
        if (cursorNode->data == data) { // 만약 찾고자 하는 데이터와 현재 노드의 데이터가 일치하면
            return i; // 해당 데이터의 인덱스 반환
        }
        cursorNode = cursorNode->next; // 선택한 노드의 다음 노드를 새로운 선택 노드로
    }
}

/**
 * 노드 삽입 -> 종속적인 함수
 */
// 노드 생성 함수
Lnode* create_Lnode (DataType data) { // 노드에 삽입하고자 하는 데이터를 매개변수로, 동적 생성하여 데이터를 래핑한 node의 주소 반환
    Lnode* newLnode = (Lnode*)malloc(sizeof(Lnode)); // 새로운 연결 리스트 노드 동적 할당
    if(!newLnode) { // 노드 할당 실패시
        printf("create_Lnode : 노드 할당에 실패했습니다.\n"); // 할당 실패 메세지 출력
    } else { // 노드 할당 성공시
        newLnode->data = data; // 매개변수 데이터 새로운 노드에 집어넣기
        newLnode->next = newLnode->prev = NULL; // 새로운 노드의 링크들 초기화
    }
    return newLnode; // 해당 노드의 포인터 반환
}


/**
 * 노드 삽입
 */
void SLL_insert_Lnode (Lnode** pointerToHead, Lnode* beforeLnode, Lnode* newLnode) { // 단일 연결 리스트 포인터 직접 조작을 위한 포인터, 이전 노드의 주소, 새로운 노드의 주소를 매개변수로, 반환값 없음
    if(*pointerToHead == NULL) { // 연결 리스트가 비어있을때
        newLnode->next = NULL; // 새로운 노드의 next 를 NULL로
        *pointerToHead = newLnode; // 단일 연결 리스트 포인터가 newLnode를 가리키도록 조작
    } else if (beforeLnode == NULL) { // 맨 앞에 삽입하려고 beforeLnode를 일부러 비워놓았을때
        newLnode->next = *pointerToHead; // 새로운 노드의 next가 단일 연결 리스트 포인터가 가리키는 노드를 가리키도록 조작
        *pointerToHead = newLnode; // 단일 연결 리스트 포인터가 새로운 노드를 가리기제 조작
    } else { // 일반적인 상황일때
        newLnode->next = beforeLnode->next; // 새로운 노드의 링크가 이전 노드의 다음 노드를 가리키게 설정
        beforeLnode->next = newLnode; // 이전 노드의 링크가 새로운 노드를 가리키게 함
    }
}


// 여기 구현해야 함
void DLL_insert_Lnode (Lnode** pointerToHead, Lnode* beforeLnode, Lnode* newLnode) { // 이중 연결 리스트 포인터 직접 조작을 위한 포인터, 이전 노드의 주소, 새로운 노드의 주소를 매개변수로, 반환값 없음
    if(*pointerToHead == NULL) { // 연결 리스트가 비어있을때
        newLnode->next = newLnode->prev = NULL; // 연결 리스트의 next와 prev 초기화
        *pointerToHead = newLnode; // 단일 연결 리스트 포인터가 newLnode를 가리키도록 조작
    } else if (beforeLnode == NULL) { // 맨 앞에 삽입하려고 beforeLnode를 일부러 비워놓았을때
        newLnode->next = *pointerToHead; // 새로운 노드의 next가 단일 연결 리스트 포인터가 가리키는 노드를 가리키도록 조작
    } else { // 일반적인 상황일때

    }
}

// 단일 연결리스트의 pos번째 위치에 항목 data를 추가
void SLL_insert(SingleLinkedList* LL, int position, DataType data) { // 단일 연결 리스트 포인터, 삽입하고자 하는 위치(순번), 삽입하고자 하는 데이터를 매개변수로, 반환값 없음
    if(position >= 0 && position < LL->length) { // 입력받은 포지션이 0과 리스트의 길이 사이라면
        Lnode *beforeLnode, *newLnode = create_Lnode(data); // 삽입할 노드의 이전 노드를 저장할 포인터 와 새로 삽입할 데이터의 노드 생성
        beforeLnode = SLL_get_ith_node(LL, position - 1); // 삽입할 노드의 이전 노드의 주소를 구해서 이전 노드 포인터에 삽입하기
        SLL_insert_Lnode(&(LL->head), beforeLnode, newLnode); // 단일 연결 리스트 삽입 진행
        LL->length++; // 연결 리스트의 길이 증가
    } else { // 입력받은 포지션이 범위 밖이라면
        printf("SLL_insert : 항목 삽입에 실패하였습니다."); // 항목 삽입 실패 메세지 출력
    }
}

// 이중 연결리스트의 pos번째 위치에 항목 data를 추가
int DLL_insert(DoubleLinkedList* LL, int position, DataType data) {  // 이중 연결 리스트 포인터, 삽입하고자 하는 위치(순번), 삽입하고자 하는 데이터를 매개변수로, 반환값 없음
    if(position >= 0 && position < LL->length) { // 입력받은 포지션이 0과 리스트의 길이 사이라면
        Lnode *beforeLnode, *newLnode = create_Lnode(data); // 삽입할 노드의 이전 노드를 저장할 포인터 와 새로 삽입할 데이터의 노드 생성
        beforeLnode = SLL_get_ith_node(LL, position - 1); // 삽입할 노드의 이전 노드의 주소를 구해서 이전 노드 포인터에 삽입하기
        DLL_insert_Lnode(&(LL->head), beforeLnode, newLnode); // 이중 연결 리스트 삽입 진행
        LL->length++; // 연결 리스트의 길이 증가
    }
}