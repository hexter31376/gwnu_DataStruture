#include<stdio.h> // 기본이라 넘어가겠습니다.
#include<string.h> //입력값이 stop일때의 문자열 비교를 위한 헤더파일

//문제의 조건에 맞는 구조체 생성
typedef struct student
{
    char name[100];
    int student_number;
    int score;
} student;

int main(){
    //문제의 조건에 맞는 구조체 배열 생성
    student students[1000] = {'\0'};
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
    // 학생 수를 제대로 세었는지 확인하는 출력 구문
    printf("%d", counter);
    return 0;
}