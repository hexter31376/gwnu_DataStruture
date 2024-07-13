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
	  
	printf("pc = %lu\n", pc); // char형 포인터를 unsigned long 형 데이터로 출력
    *pc = 100;
}