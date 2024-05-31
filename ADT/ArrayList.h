#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>

#define type_name(expr) _Generic((expr), \
    char: "char", \
    short: "short", \
    int: "int", \
    long: "long", \
    long long: "long long", \
    double: "double", \
    char*: "String", \
    default: "unknown")

// # 구조의 정의
typedef struct {
    void** list; // void 포인터형 배열을 가리키는 포인터
    size_t dataSize; // '원소'의 크기
    size_t listsize; // '리스트' 의 크기
    size_t dataLength; // 데이터의 길이
} ArrayList;

// # 동작의 정의

// ## 리스트 생성 및 삭제부
ArrayList* create_AL (ArrayList* AL, char* type) {}; // 배열 리스트 동적 생성 // 매개변수 요소 : ArrayList의 주소, 삽입할 제네릭의 정보, 초기 크기
void free_AL () {}; // 배열 리스트 동적 삭제
// ### 부가 요소
void** create_A () {};

// ## 리스트 원소 

#endif // ARRAYLIST_H