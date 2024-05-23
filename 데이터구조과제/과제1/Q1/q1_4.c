#include <stdio.h>

// 순서대로 파라미터를 이렇게 받은 이유를 설명하자면
// 1. 배열의 이름(배열의 시작 주소)를 받았으므로 int *형 변수로 받아 포인터로 배열 요소 참조를 가능하게 한다.
// 2. 사용자의 입력 값은 그냥 정수형 '값'을 받았습니다.
// 3. 2중 포인터로 받은 이유는 wantp가 포인터 변수인데 이 값을 이 함수가'직접'바꿔주어야 하므로 포인터 변수를 참조하는 포인터 변수의 의미로서
//    2중 포인터를 사용하였습니다.
void search(int *arr, int input, int** wantp){
    // 배열의 1~10번째 요소까지 스캔
    for(int i = 0; i < 10; i++){
        // 배열의 값이 사용자가 입력한 값과 같으면
        if(arr[i] == input){
            // 해당 인덱스의 주소를 기억할 wantp를 그 인덱스의 주소값으로 변환
            *wantp = &arr[i];
            // 반환값 없이 함수 종료
            return;
        }
    }
}

int main(){
    // 문제에서 주어진 배열
    int iArr[10] = {23, 45, 12, 34, 65, 25, 89, 61, 26, 11};

    // 사용자가 찾고자 하는 값 입력받기
    int input;
    scanf("%d",&input);

    // 위치를 찾았을때 반환할 변수 output 선언
    int output;

    // 찾고자 하는 배열의 위치를 저장하기 위한 포인터 변수
    int* wantp = NULL;
    // 사용자가 입력한 값이 배열내의 몇번째 요소로서 존재하는지 반환할 함수 호출
    // 파라미터로는 배열의 주소, 입력값, 배열의 위치를 저장하는 포인터 변수를 전달
    search(iArr, input, &wantp);

    if(wantp == NULL){
        // 반환한 값이 없으면 wantp가 null이므로 찾는 값이 없다고 출력
        printf("찾는 값이 없습니다...");
    } else{
        // wantp가 null값이 아니면 일치하는 값이 있는 것이므로
        // 배열의 처음 시작 주소인 iArr을 빼주어 ?번째 인덱스임을 정수로 표현
        output = wantp -iArr;
        // 이후 그 값을 출력
        printf("위치는 : %d입니다.", output);
    }
    return 0;
}