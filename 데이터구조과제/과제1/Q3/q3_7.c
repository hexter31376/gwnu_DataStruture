#include <stdio.h>

void main(void){
    // 문자열 str을 선언하고 문자열 안에 What is Pointer?의 크기만큼 공간 확보
    // 이후 해당 문자열 삽입
    char str[] = "What is Pointer?";
    // 문자열을 지정할 char형 포인터 p선언
    char* p;
    // 반복문 전용 i선언
    int i;

    // 배열의 첫번째 주소를 p에 할당
    p = str;
    // 널 문자가 발견될 때까지 반복
    for(i = 0; p[i] != NULL; i++){
        printf("%c", p[i]);
    }
}