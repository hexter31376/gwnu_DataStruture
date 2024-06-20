#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 이진 탐색 트리 노드 구조체 정의
typedef struct TreeNode {
    char* word; // 단어를 저장할 문자열 포인터
    int count; // 단어의 등장 횟수
    int* lines; // 단어가 등장한 줄 번호를 저장할 배열
    int line_count; // 단어가 등장한 줄 번호의 개수
    struct TreeNode* left; // 왼쪽 자식 노드
    struct TreeNode* right; // 오른쪽 자식 노드
} TreeNode;

// 새로운 노드 생성 함수
TreeNode* create_node(char* word, int line) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode)); // 새로운 노드 메모리 할당
    new_node->word = strdup(word); // 단어를 복사하여 저장
    new_node->count = 1; // 등장 횟수를 1로 초기화
    new_node->lines = (int*)malloc(sizeof(int)); // 줄 번호 배열 메모리 할당
    new_node->lines[0] = line; // 첫 번째 줄 번호 저장
    new_node->line_count = 1; // 줄 번호 개수를 1로 초기화
    new_node->left = new_node->right = NULL; // 자식 노드들을 NULL로 초기화
    return new_node;
}

// 트리에 단어 삽입 함수
TreeNode* insert(TreeNode* root, const char* word, int line) {
    if (root == NULL) {
        return create_node(word, line); // 루트 노드가 없으면 새로운 노드 반환
    }
    int cmp = strcmp(word, root->word);
    if (cmp == 0) {
        root->count++;
        root->lines = (int*)realloc(root->lines, (root->line_count + 1) * sizeof(int)); // 줄 번호 배열 크기 재할당
        root->lines[root->line_count++] = line; // 새로운 줄 번호 저장
    } else if (cmp < 0) {
        root->left = insert(root->left, word, line); // 왼쪽 서브트리에 삽입
    } else {
        root->right = insert(root->right, word, line); // 오른쪽 서브트리에 삽입
    }
    return root;
}

// 트리를 중위 순회하며 출력 함수
void inorder_print(TreeNode* root) {
    if (root != NULL) {
        inorder_print(root->left); // 왼쪽 서브트리 순회
        printf("단어: %s, 횟수: %d, 줄: ", root->word, root->count); // 단어, 횟수 출력
        for (int i = 0; i < root->line_count; i++) {
            printf("%d ", root->lines[i]); // 줄 번호 출력
        }
        printf("\n");
        inorder_print(root->right); // 오른쪽 서브트리 순회
    }
}

// 트리 메모리 해제 함수
void free_tree(TreeNode* root) {
    if (root != NULL) {
        free_tree(root->left); // 왼쪽 서브트리 메모리 해제
        free_tree(root->right); // 오른쪽 서브트리 메모리 해제
        free(root->word); // 단어 메모리 해제
        free(root->lines); // 줄 번호 배열 메모리 해제
        free(root); // 노드 메모리 해제
    }
}

// 메인 함수
int main() {
    FILE* fp = fopen("sample.txt", "r"); // 파일을 읽기 모드로 엽니다.
    if (fp == NULL) { // 파일 포인터가 비어있다면
        printf("파일을 찾을 수 없습니다\n"); // 파일을 찾을 수 없다는 경고문 표시
        exit(1); // 프로그램 종료
    }

    TreeNode* root = NULL; // 이진 탐색 트리의 루트 노드 초기화
    char input_string[100]; // 충분히 큰 문자열 버퍼를 선언합니다.
    int line_num = 1; // 현재 줄 번호
    int count = 0; // 총 단어 개수를 저장할 count 변수

    while (fgets(input_string, sizeof(input_string), fp) != NULL) { // 파일에서 한 줄씩 읽기
        char* token = strtok(input_string, " \t\n\r?");
        while (token != NULL) { // 현재 줄에서 더 이상 분리할 토큰이 없을 때까지 반복
            root = insert(root, token, line_num); // 단어를 트리에 삽입
            token = strtok(NULL, " \t\n\r?"); // strtok로 문자열 분리 기준 문자를 구분합니다. 탭, 개행, 캐리지 리턴 ?를 문자열 토큰 기준으로 사용합니다.
            count++; // 총합 카운트 증가
        }
        line_num++; // 다음 줄 번호로 증가, 각 단어가 어느 줄에서 나왔는지 기록하기 위함
    }

    inorder_print(root); // 트리를 중위 순회하며 출력
    printf("계 : %d", count); // 총합 출력
    free_tree(root); // 트리 메모리 해제

    fclose(fp); // 파일 닫기

    return 0; // 프로그램 종료
}