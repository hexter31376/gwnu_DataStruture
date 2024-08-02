#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 삽입 정렬의 기본적인 아이디어는 다음과 같습니다.
 * 정렬되지 않은 레코드에서 정렬된 레코드로 끼워넣는 행위를 통해 정렬을 진행합니다.
 * 정렬된 레코드는 순차적인 배열임을 보장하며 이 사이에 정렬되지 않은 원소를 끼워 넣음으로서 정렬을 진행하는 것입니다.
 * 기본적으로 O(n^2)의 시간 복잡도를 가지고 있습니다.
 * 어느 정도 정렬되어 있고 짧은 길이의 배열에서 매우 높은 성능을 보여줍니다.
 */

#define Datatype int

void insertion_sort (Datatype list[], int length) {
    int i, j, next;
    for (i = 1; i < length; i++) {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--) {
            list[j + 1] = list[j];
        }
        list[j + 1] = next;
    }
}