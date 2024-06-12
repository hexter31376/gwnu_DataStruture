#include <stdio.h>
#include <stdlib.h>

#define Datatype int // 유연한 코딩을 위한 데이터 타입 정의
#define MAX_SIZE 100 // 배열 리스트의 최대 크기 정의

typedef struct ArrayList { // 배열 리스트 구조체의 정의
    int length; // 길이를 기록할 변수 length
    Datatype list[MAX_SIZE]; // 실제 배열 리스트 정의
} ArrayList; // 배열 리스트 자료명 정의



// 리스트 초기화
void AL_init_list (ArrayList* AL) { // 배열 리스트의 주소를 매개변수로 받는다.
    AL->length = 0; // 리스트의 길이를 0으로
}

// 리스트 길이 계산
int AL_get_length (ArrayList *AL) { // 배열 리스트의 주소를 매개변수로 받는다.
    return AL->length; // 현재 리스트의 길이를 반환
}

// 리스트의 position번째 항목을 반환
Datatype AL_get_data(ArrayList* AL, int position) { // 배열 리스트의 주소와 반환받고자 하는 인덱스를 매개변수로 받는다.
    return AL->list[position]; // 매개변수 인덱스 위치의 값 반환
}

// 리스트 항목들을 출력
void AL_print_list(ArrayList* AL) { // 배열 리스트의 주소를 매개변수로 받는다.
    for (int i = 0; i < AL->length; i++) { // 배열 리스트의 길이만큼 순차적으로
        printf("%d ", AL->list[i]); // 현재 반복자가 가리키는 위치의 값 출력
    }
    printf("\n"); // 개행
}

// 리스트에서 항목 data의 위치 반환
int AL_get_position (ArrayList* AL, Datatype data) { // 배열 리스트의 주소와 반환받고자 하는 data를 매개변수로 받는다.
    for (int i = 0; i < AL->length; i++) { // 배열 리스트의 길이만큼 순차적으로
        if (AL->list[i] == data) { // 만약 선택자의 위치의 원소가 data와 일치한다면
            return i; // 현재 인덱스 반환
        }
    }
}

// 리스트의 position번째 위치에 항목 data를 추가
void AL_insert (ArrayList* AL, int position, Datatype data) { // 배열 리스트의 주소, 추가하고자 하는 위치, 추가하려는 데이터를 매개변수로 받는다.
    if ((AL->length < MAX_SIZE) && (position >= 0) && (position <= AL->length)) { // 현재 길이가 최대 크기보다 작고, 매개변수 위치가 0보다 크고 현재 길이보다 작다면
        for (int i = AL->length - 1; i >= position; i--) { // 리스트의 길이에서 1을 뺀 값부터 하나씩 역순차적으로 매개변수 위치와 같거나 작아질때까지
            AL->list[i + 1] = AL->list[i]; // 현재 위치의 값을 다음 위치에 대입 // 밀어내기
        }
        AL->list[position] = data; // 넣으려는 위치에 매개변수 데이터를 삽입
        AL->length++; // 길이 증가
    } else { // 조건이 성립하지 않으면
        printf("항목 삽입에 실패하였습니다."); // 경고문 출력
        exit(1); // 프로그램 종료
    }
}

// 리스트의  position번째 항목을 제거
Datatype AL_delete (ArrayList* AL, int position) { // 배열 리스트의 주소, 제거하고자 하는 위치를 매개변수로 받는다.
    if (position >= 0 && position < AL->length) { // 매개변수 인덱스의 값이 0보다 크거가 같고, 길이를 넘지 않는다면
        Datatype data = AL->list[position]; // 리턴하고자 하는 data를 선언하고 제거하는 위치의 값을 저장
        for (int i = position; i < AL->length - 1; i++) { // 제거하려는 위치부터 하나씩 순차적으로 리스트의 길이에서 1을 뺀 값까지
            AL->list[i] = AL->list[i + 1];// // 당겨오기
        }
        AL->length--; // 길이 감소
        return data; // 제거한 데이터 반환
    } else { // 조건이 성립하지 않으면
        printf("항목 제거에 실패하였습니다."); // 경고문 출력
        exit(1); // 프로그램 종료
    }
}

void AL_replace (ArrayList* AL, int position, Datatype data) { // 배열 리스트의 주소, 교체하고자 하는 위치 ,교체하고자 하는 데이터를 매개변수로 받는다.
    if (position >= 0 && position < AL->length) { // 매개변수 위치가 0보다 크고 리스트의 길이보다 작다면
        AL->list[position] = data; // 교체하고자 하는 위치에 교체하고자 하는 데이터 집어넣기
    } else { // 조건이 성립하지 않으면
        printf("항목 교체에 실패하였습니다."); // 경고문 출력
        exit(1); // 프로그램 종료
    }
}

int main(){
    ArrayList alist;
    AL_init_list(&alist);
    AL_insert(&alist, 0, 10);
    AL_insert(&alist, AL_get_length(&alist), 30);
    AL_insert(&alist, 1, 20);
    AL_insert(&alist, AL_get_length(&alist), 40);
    AL_print_list(&alist);
    AL_delete(&alist, 0);
    AL_replace(&alist, 2, 50);
    AL_replace(&alist, AL_get_position(&alist, 20), 10);
    AL_print_list(&alist);
}