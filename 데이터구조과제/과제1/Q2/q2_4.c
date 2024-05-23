#include<stdio.h> // 기본이라 넘어가겠습니다.
#include<string.h> //입력값이 stop일때의 문자열 비교를 위한 헤더파일
#include<math.h> // 제곱과 루트를 사용하기 위한 헤더파일

//문제의 조건에 맞는 구조체 생성
typedef struct student
{
    char name[100];
    int student_number;
    int score;
} student;

int get_mean(student *ptr, int counter){
    // 점수의 합을 더할 float형 변수 total 선언
    float total = 0.0;
    // 학생의 수 만큼 반복
    for(int i = 0; i < counter; i++){
        // i번째의 요소의 score항목을 total에 더하기
        total += ptr[i].score;
    }
    // 평균값을 구해야 하므로 total을 학생의 수로 나누고 mean에 그 값을 저장
    float mean = total / counter;
    // mean 반환
    return mean; 
}

// 학생 정보가 저장된 student형 배열의 포인터, 학생의 수의 값을 받는다
float get_deviation(student *ptr, int counter){
    // 분산의 합을 더할 float형 변수 total 선언
    float total = 0;
    // get_mean 함수를 호출하여 평균값을 구하고 mean에 그 값을 저장
    float mean = get_mean(ptr, counter);
    // 학생의 수만큼 반복
    for(int i = 0; i < counter; i++){
        // 각 학생의 점수에 평균값을 빼고 제곱을 취해줘 분산으로 만든 다음
        // 그 분산의 값을 total에 더해준다
        total += pow(ptr[i].score - mean, 2);
    }
    // 표준편차 계산을 위해 지금까지 나온 분산의 합을 학생의 수로 나누어주고
    // 그 값에 루트 취하고 deviation변수에 표준편차 반환
    float deviation = sqrt(total / counter);
    // 표준 편차 반환
    return deviation;
}

int main(){
    //문제의 조건에 맞는 구조체 배열 생성
    student students[1000] = {'\0'};
    // 문제 조건에 맞는 포인터 배정
    student* ptr = students;
    // 간단한 안내 멘트
    printf("값을 입력해주세요... stop을 입력하면 입력받기가 종료됩니다.\n");
    // 몇명의 학생이 입력되었는지 측정할 카운터
    int counter = 0;
    // counter의 크기가 1000을 넘어가지 않도록 계속 입력 받으나
    for (; counter < 1000; counter++) {
        // 1. 학생의 이름 입력을 받기 2. stop을 입력받고 반복문 탈출하기를 위해서 먼저 따로 입력받기
        scanf("%s", students[counter].name);
        // 개행 문자가 들어있는 버퍼 메모리 초기화를 위한 getchar()
        getchar();
        // 입력받은 값이 stop이면 반복문 탈출
        if (strcmp(students[counter].name, "stop") == 0)
            break;
        // 이후 나머지 정보를 받고
        scanf("%d %d", &students[counter].student_number, &students[counter].score);
        // 제대로 입력되었는지 확인할 printf함수 출력
        printf("이름 : %s 학번 : %d 성적 : %d\n", students[counter].name, students[counter].student_number, students[counter].score);
    }

    // 문제의 요구 사항에 맞게 소수점 연산자 %f로 연산을 진행하였고
    // 그 안에 들어갈 값은 get_deviation함수를 사용하여 표준 편차를 구해주어
    // 그 값을 %f에 집어넣어 주었습니다.
    printf("%f", get_deviation(ptr, counter));
    return 0;
}
// p.s) 표본 수가 작을때를 대비해 n-1로 접근하는 것이 정확하나
// 문제에서 그것을 요구하지 않았으므로 일부러 사용하지 않았습니다...