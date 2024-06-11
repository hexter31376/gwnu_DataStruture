#ifndef CMPDATA_H
#define CMPDATA_H

#include <stdio.h>
#include <stdbool.h>

// 데이터 타입 열거형 정의
typedef enum {
    TYPE_BOOLEAN,   // 1비트 정수 : 0
    TYPE_SHORT,     // 2바이트 정수 : 1
    TYPE_INT,       // 4바이트 정수 : 2
    TYPE_LONG,      // 윈도우는 4, 나머지는 8 바이트 정수 : 3
    TYPE_LONG_LONG, // 8바이트 정수 : 4
    TYPE_FLOAT,     // 4바이트 실수 : 5
    TYPE_DOUBLE,    // 8바이트 실수 : 6
    TYPE_CHAR,      // 1바이트 데이터 : 7
    TYPE_STRUCT     // 사용자 임의의 구조체 : 8
} DataType;

// 일반적인 구조체 멤버를 정의하는 함수 포인터 타입
typedef bool (*MemberCompareFunc)(const void*, const void*);

// 구조체 멤버를 비교하는 함수들
bool compareBool(const void* a, const void* b) {
    return *(bool*)a == *(bool*)b;
}

bool compareInt(const void* a, const void* b) { // 정수형의 비교
    return *(int*)a == *(int*)b;
}

bool compareFloat(const void* a, const void* b) { // float형의 비교
    return *(float*)a == *(float*)b;
}

bool compareChar(const void* a, const void* b) { // char형의 비교
    return *(char*)a == *(char*)b;
}

typedef struct {
    size_t offset; // 멤버 변수의 오프셋
    DataType type; // 멤버 변수의 타입
    MemberCompareFunc compareFunc; // 멤버 비교 함수 포인터
} StructMemberInfo;

typedef struct {
    StructMemberInfo *members; // 멤버 정보 배열
    size_t memberCount; // 멤버 수
} StructInfo;
#endif // CMPDATA_H