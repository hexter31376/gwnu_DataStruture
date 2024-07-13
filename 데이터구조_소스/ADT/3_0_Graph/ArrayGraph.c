/**
 * 인접 행렬의 ADT 실제 구현
 */

#include <stdio.h> // 인접 행렬을 이용한 그래프 구현

#define MAX_SIZE 100 // 배열 그래프의 최대 가로 세로 크기 정의

typedef struct ArrayGraph {
    int vertexSize; // 그래프에 있는 정점의 개수
    int adjacendy[MAX_SIZE][MAX_SIZE]; // 인접 행렬
} ArrayGraph;

// 그래프 로직
void AG_init_graph (ArrayGraph*); // 배열 그래프의 초기화
void AG_print_graph (ArrayGraph*); // 그래프 AG를 출력
void AG_add_vertex (ArrayGraph*);
void AG_add_edge ();
void AG_is_adjacent ();
void AG_get_degree();
void AG_get_edge_size ();

// 그래프 초기화
void AG_init_graph (ArrayGraph* AG) {
    AG->vertexSize = 0; // 정점의 개수 모두 초기화

    // MAX_SIZE * MAX_SIZE 배열 초기화
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            AG->adjacendy[i][j] = 0; // 0으로 초기화
        }
    }
}



int main () {
    return 0;
}