#include <stdio.h>
#include <stdlib.h>

void main(){
    // 반복문 횟수 저장용 i
    int i;
    // 동적으로 할당된 메모리의 주소를 저장하기 위한 char형 포인터 변수
    char *pc;

    // 동적 메모리 할당, 크기는 100바이트로 지정
    pc = (char*)malloc(100);

    // 100번 반복
    for(i = 0; i < 100; i++){
        // pc가 가리키는 동적 메모리에 100할당
        pc[i] = 100;
    }
    // 제대로 할당되었는지와 각각을 10진수 정수와,
    
    // 문자형으로 해석하면 어떻게 되는지 확인하기 위한 printf
    for(i = 0; i < 100; i++){
        printf("정수 출력 : %d 문자 출력 : %c\n", pc[i], pc[i]);
    }
    free(pc);
}