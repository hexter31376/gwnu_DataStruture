#include <stdio.h>
#include <stdlib.h>

int main(){
    char *pc; // char형 포인터 pc 선언
    int *pi; // int형 포인터 pi 선언
    float *pf; // float형 포인터 pf 선언
    double *pd; // double형 포인터 pd 선언

    // pc에 char데이터형 크기 * 100 바이트 크기만큼 동적할당하고
    // 배 동적할당 공간의 시작 주소 반환
    pc = (char*)malloc(100 * sizeof(char));
    // pc에 int데이터형 크기 * 100 바이트 크기만큼 동적할당하고
    // 배 동적할당 공간의 시작 주소 반환
    pi = (int*)malloc(100 * sizeof(int));
    // pc에 float데이터형 크기 * 100 바이트 크기만큼 동적할당하고
    // 배 동적할당 공간의 시작 주소 반환
    pf = (float*)malloc(100 * sizeof(float));
    // pc에 double데이터형 크기 * 100 바이트 크기만큼 동적할당하고
    // 배 동적할당 공간의 시작 주소 반환
    pd = (double*)malloc(100 * sizeof(double));

    printf("pf = %lu\n", pf); // pf의 주소값 출력
    printf("pf+1 = %lu\n", pf+1); // pf에 +1한 주소값 출력
    printf("pf-1 = %lu\n", pf-1); // pf에 -1한 주소값 출력

    printf("pd = %lu\n", pd); // pd의 주소값 출력
    printf("pd+1 = %lu\n", pd+1); // pd에 +1한 주소값 출력
    printf("pd-1 = %lu\n", pd-1); // pd에 -1한 주소값 출력

    free(pc); // 동적 메모리 할당 해제
    free(pi); // 동적 메모리 할당 해제
    free(pf); // 동적 메모리 할당 해제
    free(pd); // 동적 메모리 할당 해제

    return 0;
}