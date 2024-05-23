#include <stdio.h>

void main(){
	char* pc; // char형 포인터 선언
	int* pi; // int형 포인터 선언
	float pf; // float형 포인터 선언
	double pd; // double형 포인터 선언
	  
	char c; // char형 변수
	int i; // i형 변수
	float f; // float형 변수
	double d; // double형 변수
	
	printf("초기화 하기 전의 pc = %lu\n", pc); // char형 포인터를 unsigned long 형 데이터로 출력
    pc = &c;
    printf("초기화 한 후의 pc = %lu\n", pc); // 이하 동일 및 초기화 여부 확인
    *pc = 100; // pc가 가리키는 c의 값을 100으로 설정
    printf("c = %d\n", c); // c 출력
}