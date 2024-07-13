#include<stdio.h>
#include<stdlib.h>


// 추론
//sizeof()함수는 해당 자료형의 단순 크기를 바이트 크기로 반환한다
// int형은 4바이트, char형은 1바이트이므로 int 포인터로 읽어들이면
// 25개의 정수형 데이터를 받을수 있는 배열이 생성될 것이다.

// 실제로 그런지 확인해보자.

int main(){
    int *pi; // 원래 조건
    int *rightpi; // 동적 할당의 사이즈를 정상적으로 줄 경우의 수

    int sizepi; // 원래 조건의 할당된 크기를 받을 정수
    int sizerightpi; // 제대로 할당된 배열의 크기를 받을 정수

    sizepi = 100 * sizeof(char);
    sizerightpi = 100 * sizeof(int);

    pi = (int *)malloc(100 * sizeof(char)); // 문제에서 물어보는 조건 할당
    rightpi = (int *)malloc(100 * sizeof(int)); // int로 제대로 할당

    // 배열 인덱스 방식으로 값을 집어넣을때 값이 정상적으로 넣어지고 읽어지는지 확인
    for(int i = 0; i < 25; i++){
        pi[i] = i;
        printf("%d\n", pi[i]);
    }
    free(pi);
    free(rightpi);

    printf("char로 했을때의 크기 : %d int로 했을때의 크기 : %d", sizepi, sizerightpi);

    return 0;
}