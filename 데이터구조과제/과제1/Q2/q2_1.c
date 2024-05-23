#include<stdio.h> // 기본이라 넘어가겠습니다.

//문제의 조건에 맞는 구조체 생성
typedef struct student
{
    char name[100];
    int student_number;
    int score;
} student;

int main(){
    // 제 정보입니다 :) student형 students를 선언하고 구조체 요소에 각각의 자료형에 맞게 값을 집어넣어 주었습니다.
    student students = {"장원영", 20211379, 100};

    // 구조체의 각 요소에 접근하여 출력하고 있습니다.
    printf("%s %d %d", students.name, students.student_number, students.score);
    return 0;
}