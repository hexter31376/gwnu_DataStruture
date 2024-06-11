#include <stdio.h>

/**
 * 이진 탐색은 탐색하고자 하는 배열이 순차적으로 정렬되어있다는 것을 가정하고 진행한다.
 * 기본 탐색은 최악의 경우 모든 배열 요소를 다 비교하며 검사해야 하기 때문에 O(n)의 시간복잡도를 가진다.
 * 그러나 이진 탐색은 대소비교를 하면서 요소를 정확히 절반씩 줄여가면서 탐색하기 때문에 O(log_2 n - 1) O(log n)의 시간 복잡도를 가진다.
 * 그 예시를 보여주겠다.
 */

int binary_search(int sortedArr[], int length, int findValue) {
    // 초기값 세팅
    int selectBlockLow = 0;
    int selectBlockMax = length - 1;
    int selectBlockMid;

    while (selectBlockLow <= selectBlockMax) { // 탐색 구간이 유효할 때까지 반복
        selectBlockMid = (selectBlockLow + selectBlockMax) / 2; // 중간값 계산

        if (sortedArr[selectBlockMid] == findValue) { // 중간값과 찾는 값이 일치하면
            return selectBlockMid; // 중간값 리턴하기
        } else if (sortedArr[selectBlockMid] < findValue) { // 중간값이 찾는 값보다 작으면
            selectBlockLow = selectBlockMid + 1; // 최소값을 중간값 다음으로 업데이트
        } else { // 중간값이 찾는 값보다 크면
            selectBlockMax = selectBlockMid - 1; // 최대값을 중간값 이전으로 업데이트
        }
    }
    return -1; // 값을 찾지 못했을 때
}

int main() {
    int arr[20] = {1, 4, 5, 6, 7, 8, 9, 12, 15, 18, 20, 21, 25, 36, 37, 39, 40, 41, 44, 50};
    int index = binary_search(arr, 20, 37);

    if (index != -1) {
        printf("값 %d는 배열의 인덱스 %d에 있습니다.\n", 37, index);
    } else {
        printf("값 %d를 배열에서 찾을 수 없습니다.\n", 37);
    }
    
    return 0;
}
