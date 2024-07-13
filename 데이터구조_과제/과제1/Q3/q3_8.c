#include <stdio.h>

// 포인터 배열 pa 선언, 배열의 크기는 넣어주는 값에 따라 할당
char* pa[] = {
    "에러 1",
    "에러 2",
    "에러 3",
    "에러 4",
    "에러 5",
    "에러 6"
};

// 파라미터로 int형 정수 err_num을 받는 함수 error를 선언하고
// pa 배열의 index에 err_num을 집어넣고 그 인덱스에 해당하는 값을 출력
void error(int err_num){
    printf(pa[err_num]);
}

// error 함수에 1을 넘겨주며 호출
void main(){
    error(1);
}