#include <stdio.h>

void main(){
	char* pc; // char형 포인터 선언
	int* pi; // int형 포인터 선언
	float *pf; // float형 포인터 선언
	double *pd; // double형 포인터 선언
	  
	char c; // char형 변수
	int i; // i형 변수
	float f; // float형 변수
	double d; // double형 변수
	
	printf("초기화 하기 전의 pc = %lu\n", pc); // char형 포인터를 unsigned long 형 데이터로 출력
    pc = &c;
    printf("초기화 한 후의 pc = %lu\n", pc); // 이하 동일 및 초기화 여부 확인
    *pc = 100; // pc가 가리키는 c의 값을 100으로 설정
    printf("c = %d\n", c); // c 출력

    printf("초기화 하기 전의 pi = %lu\n", pi); // int형 포인터를 unsigned long 형 데이터로 출력
    pi = &i;
    printf("초기화 한 후의 pi = %lu\n", pi); // 이하 동일 및 초기화 여부 확인
    *pi = 100; // pi가 가리키는 c의 값을 100으로 설정
    printf("i = %d\n", i); // i 출력

    printf("초기화 하기 전의 pf = %lu\n", pf); // float형 포인터를 unsigned long 형 데이터로 출력
    pf = &f;
    printf("초기화 한 후의 pf = %lu\n", pf); // 이하 동일 및 초기화 여부 확인
    *pf = 100; // pf가 가리키는 f의 값을 100으로 설정
    printf("f = %f\n", f); // f 출력

    printf("초기화 하기 전의 pd = %lu\n", pd); // double형 포인터를 unsigned long 형 데이터로 출력
    pd = &d;
    printf("초기화 한 후의 pc = %lu\n", pd); // 이하 동일 및 초기화 여부 확인
    *pd = 100; // pd가 가리키는 d의 값을 100으로 설정
    printf("d = %lf\n", d); // d 출력
}