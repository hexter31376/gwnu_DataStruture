#include<stdio.h>
#include<stdlib.h>

int main(){
    int input[10];

    for(int i = 0; i < 10; i++){ // input 배열에 random숫자 채워넣기
        input[i] = rand();
        printf("%d\n", input[i]);
        // 값이 제대로 할당되고 큰 수와 작은 수를 제대로 골랐는지 비교하기 위한 printf
    }

    int max = input[0]; // 배열 요소내에서의 비교를 위해 임의의 배열 요소값 부여
    int min = input[0]; // 위와 동

    for(int i = 0; i < 10; i++){
        //max와 min을 찾는 반복문 각 배열 요소의 값을
        //max로서 한번 min으로서 한번 비교하고 해당하면 바꾸는 알고리즘이다.
        int value = input[i];
        if(min > value){
            min = value;
        }
        if(max < value){
            max = value;
        }
    }
    printf("max : %d, min : %d\n", max, min);

    return 0;
}