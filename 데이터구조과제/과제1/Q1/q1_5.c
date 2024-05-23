#include <stdio.h>

#define LIST_SIZE 10
int list[LIST_SIZE] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };

int main(){
    int i;

    for(i = 0; i < LIST_SIZE; i++){
        printf("list[%d]의 주소 = %p\n", i, &list[i]);
    }
    return 0;
}
// int 형의 크기가 4이므로 주소도 4칸씩 띄어서 읽는다.