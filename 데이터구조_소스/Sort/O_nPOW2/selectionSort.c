#include <stdio.h>

/**
 * 선택 정렬의 기본적인 아이디어는 다음과 같습니다.
 * 정렬되지 않은 레코드에서 가장 작은 수를 고르고 정렬된 레코드 뒤에 이어 붙입니다.
 * 정렬된 레코드는 하나씩 늘어나고 정렬되지 않은 레코드는 하나씩 줄어듭니다.
 * 기본적으로 O(n^2)의 시간 복잡도를 가지고 있습니다.
 */

#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void selection_sort (int list[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        SWAP(list[i], list[min], temp);
    }
}