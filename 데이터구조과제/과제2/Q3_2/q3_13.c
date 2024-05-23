#include <stdio.h>
#include <stdlib.h>

char* alloctest(){
    char *pc; // char형 포인터 pc 선언

    // pc에 char데이터형 크기 * 100 바이트 크기만큼 동적할당하고
    // 배 동적할당 공간의 시작 주소 반환
    pc = (char*)malloc(100 * sizeof(char));
    scanf("%s", pc);
    return pc;
}

int main(){
    char *pc; // char형 포인터 pc 선언
    pc = alloctest();
    // 여기까지

    printf("%s", pc);
    free(pc); // 동적 메모리 해제

    return 0;
}