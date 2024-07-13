#include <stdio.h>

void swap1(int i, int j){
    int temp; // i 와 j를 바꾸기 위해 값을 임시로 저장할 temp 선언

    temp = i; // i의 값을 temp에 저장
    i = j; // j의 값을 i에 저장
    j = temp; // temp의 값을 j에 저장
}

void swap2(int *i, int *j){
    int temp; // i 와 j를 바꾸기 위해 값을 임시로 저장할 temp 선언

    temp = *i; // 포인터 i가 가리키는 주소에 할당된 값을 temp에 저장
    *i = *j; // 포인터 i가 가리키는 주소에 할당된 값을 포인터 i가 가리키는 주소에 할당된 값에 저장
    *j = temp; // temp에 저장된 값을 포인터 j가 가리키는 주소에 할당된 값에 저장
}

void main(){
    //바꿀 두 값의 변수 선언
    int num1, num2;

    num1 = 100; // 100 할당
    num2 = 200; // 200 할당

    swap1(num1, num2); // swap1 함수에 '값' 넘겨주기
    printf("num1 : %d num2  %d\n", num1, num2); // 값이 제대로 바뀌었나 확인하는 printf
    swap2(&num1, &num2); // swap2 함수에 값의 '주소' 넘겨주기
    printf("num1 : %d num2  %d\n", num1, num2); // 값이 제대로 바뀌었나 확인하는 printf
}