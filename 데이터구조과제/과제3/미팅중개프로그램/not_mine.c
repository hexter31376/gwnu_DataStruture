#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#define Datatype student

typedef struct student {
    char name[max];
    char gender;
} student;

typedef struct arrayQueue {
    int front;
    int rear;
    Datatype queue[max];
} arrayQueue;

void init(arrayQueue* p) {
    p->front = p->rear = 0;
}

int full(arrayQueue* p) {
    return (p->rear + 1) % max == p->front;
}

int empty(arrayQueue* p) {
    return p->front == p->rear;
}

int enqueue(arrayQueue* p, Datatype data) {
    if (full(p)) {
        return -1; // 큐가 꽉 찼음
    } else {
        p->rear = (p->rear + 1) % max;
        p->queue[p->rear] = data;
    }
    return 0;
}

Datatype dequeue(arrayQueue* p) {
    if (empty(p)) {
        Datatype emptyStudent = {"", '\0'};
        return emptyStudent; // 큐가 비어있으면 빈 학생 반환
    } else {
        p->front = (p->front + 1) % max;
        return p->queue[p->front];
    }
}

void delete(arrayQueue* M, arrayQueue* F) {
    Datatype male = dequeue(M);
    Datatype female = dequeue(F);
    printf("커플이 탄생했습니다! %s과 %s\n\n", male.name, female.name);
}

void meeting(arrayQueue* M, arrayQueue* F) {
    if (!empty(M) && !empty(F)) { // 남자 큐가 비어있지 않고 여자 큐가 비어있지 않으면
        delete(M, F);
    } else {
        printf("아직 대상자가 없습니다. 기다려 주십시요.\n\n");
    }
}

int main(void) {
    arrayQueue M, F;
    student S;
    init(&M);
    init(&F);
    printf("미팅 주선 프로그램입니다.\n\n");
    while (1) {
        printf("고객이름(0을 입력하면 종료) : ");
        scanf("%s", S.name);

        if (strcmp(S.name, "0") == 0) {
            break;
        }

        // 입력 버퍼 비우기
        while (getchar() != '\n');

        printf("성별을 입력하세요(F or M): ");
        scanf("%c", &S.gender);

        // 입력 버퍼 비우기
        while (getchar() != '\n');

        if (S.gender == 'M') {
            if (empty(&F)) {
                enqueue(&M, S);
                printf("아직 대상자가 없습니다. 기다려주십시요.\n\n");
            } else {
                meeting(&M, &F);
            }
        } else if (S.gender == 'F') {
            if (empty(&M)) {
                enqueue(&F, S);
                printf("아직 대상자가 없습니다. 기다려주십시요.\n\n");
            } else {
                meeting(&M, &F);
            }
        } else {
            printf("잘못된 성별 입력입니다. 다시 시도해 주세요.\n");
        }
    }
    return 0;
}