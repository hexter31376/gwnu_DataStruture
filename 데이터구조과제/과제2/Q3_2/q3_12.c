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

    printf("pc의 크기 : %d바이트, pi의 크기 : %d바이트, pf의 크기 : %d바이트, pd의 크기 : %d바이트\n",
    sizeof(char)*100, sizeof(int)*100, sizeof(float)*100, sizeof(double)*100);

    for(int i = 0; i < 100; i++){
        pc[i] = i;
        pi[i] = i;
        pf[i] = i;
        pd[i] = i;
    }

    for(int i = 97; i < 107; i++){
        printf("char형 동적할당 결과 : %c\n", pc[i]);
        printf("int형 동적할당 결과 : %d\n", pi[i]);
        printf("float형 동적할당 결과 : %f\n", pc[i]);
        printf("double형 동적할당 결과 : %lf\n\n", pc[i]);
    }

    // 여기까지
    free(pc);
    free(pi);
    free(pf);
    free(pd);

    return 0;
}