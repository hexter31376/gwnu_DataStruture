#include <stdio.h>
#include <stdlib.h>

#define SL_Datatype int // 유연한 코딩을 위한 데이터 타입 정의

typedef struct SLNode {
    SL_Datatype data;
    struct SLNode* next;
} SLNode;

// 동적으로 노드를 생성
SLNode* SL_create_node (SL_Datatype data) {
    SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
    if (!newNode) {
        printf("SL_create_node : 노드 생성에 실패하였습니다!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 연결 리스트의 길이 계산
int SL_count_nodes (SLNode* headNode) {
    int count = 0;
    SLNode* nodeCursor = headNode;
    while (nodeCursor) {
        count++;
        nodeCursor = nodeCursor->next;
    }
    return count;
}

// 연결 리스트의 노드를 탐색
SLNode* SL_search_node (SLNode* startNode, SL_Datatype data) {
    SLNode* nodeCursor = startNode;
    while (!nodeCursor) {
        if (nodeCursor->data == data) {
            break;
        }
        nodeCursor = nodeCursor->next;
    }
    return nodeCursor;
}

// 연결 리스트에 노드를 삽입
void SL_insert_node (SLNode** pointerToHead, SLNode* beforeNode, SLNode* newNode) {
    if (*pointerToHead == NULL || beforeNode == NULL) { // 빈 리스트 혹은 맨 앞에 삽입
        newNode->next = *pointerToHead;
        *pointerToHead = newNode;
    } else { // 중간에 삽입
        newNode->next = beforeNode->next;
        beforeNode->next = newNode;
    }
}

// 연결 리스트에서 노드를 삭제
SLNode* SL_delete_node (SLNode **pointerToHead, SLNode* beforeNode, SLNode* deletedNode) {
    if (*pointerToHead != NULL) {
        if (beforeNode == NULL) {
            *pointerToHead = (*pointerToHead)->next; // 첫 노드 삭제
        } else {
            beforeNode->next = deletedNode->next; // 중간 노드 삭제
        }
        return deletedNode;
    } else {
        printf("SL_delete_node : 빈 연결 리스트입니다.\n");
        return NULL;
    }
}

// 두 연결 리스트의 결합
SLNode* SL_concatenate_lists (SLNode* headNodeFront, SLNode* headNodeRear) {
    SLNode *lastNodeCursor;
    if (headNodeFront == NULL) { // 첫번째 리스트가 비어있다면
        return headNodeRear;
    } else if (headNodeRear == NULL) { // 두번째 리스트가 비어있다면
        return headNodeFront;
    } else { // 일반적인 상황일때
        lastNodeCursor = headNodeFront;
        while (lastNodeCursor->next) {
            lastNodeCursor = lastNodeCursor->next;
        }
        lastNodeCursor->next = headNodeRear;
        return headNodeFront;
    }
}

// 연결 리스트 순서를 반대로 변경
SL_reverse_list (SLNode* headNode) {
    SLNode *new_headNode, *temp_headNode;
    new_headNode = NULL; // new_headNode는 역순 리스트의 헤드 포인터
    while (headNode) {
        //temp_headNode, new_headNode, headNode 순으로 차례로 오른쪽으로 이동
        temp_headNode = new_headNode;
        new_headNode = headNode;
        headNode = headNode->next;
        new_headNode->next = temp_headNode;
    }
    return new_headNode;
}