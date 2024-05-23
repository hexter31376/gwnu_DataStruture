#include <stdio.h>

void main(void){
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *p;

    p = a; // p에 a의 시작 주소를 치환한다.
    //이 문장은 포인터를 사용하여 배열 a의 첫째, 둘째, 셋째 원소들을 출력한다.
    printf("%d %d %d\n", *p, *(p+1), *(p+2));

    //이 문장은 배열 이름을 포인터처럼 사용하여 배열 a의 첫째, 둘째, 셋째 원소들을 출력한다.
    printf("%d %d %d\n", *a, *(a+1), *(a+2));

    //이 문장은 배열 a를 사용하여 같은 것을 출력한다.
    printf("%d %d %d\n", a[0], a[1], a[2]);
}