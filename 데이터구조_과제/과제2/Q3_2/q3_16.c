#include <stdio.h>
#include <stdlib.h>

typedef struct test { // 구조체를 test라는 이름으로 생성하고
    int data; // int형 데이터 선언
    struct test* link; // test를 가리킬 수 있는 포인터 link선언
} test_str; // 이 구조체를 test_str이라는 자료형 이름으로 쓸것을 명시

void main(){
    int i; // 인덱스를 지정할 반복문 변수 i
    test_str* ptest; // test_str형 구조체를 가리킬 수 있는 포인터 ptest

    ptest = (test_str*)malloc(sizeof(test_str)); // ptest에 test_str 크기만큼의 메모리를 동적 할당하고 double형 포인터를 넘겨주기

    ptest->data = 2147483647; // int에서 할당 가능한 최대한의 데이터 크기 할당
    ptest->link = ptest; // ptest의 링크가 자기 자신을 가리키게 할것
    
    printf("%d %d", ptest->data, ptest->link->data);
    // 동적 할당한 구조체의 데이터와 그 링크가 자신을 가리켜서 데이터를 정상적으로 출력하는지 확인하는 코드

    free(ptest); // 동적 메모리 해제
}
