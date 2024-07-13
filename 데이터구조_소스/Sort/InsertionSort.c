#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Datatype int

void insertion_sort(Datatype list[], int length) {
    int i, j, next;
    for (i = 1; i < length; i++) {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--) {
            list[j + 1] = list[j];
        }
        list[j + 1] = next;
    }
}