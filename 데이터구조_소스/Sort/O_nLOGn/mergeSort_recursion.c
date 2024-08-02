void merge(int list[], int low, int mid, int high) {
    int n1 = low, n2 = mid + 1, s = low, sorted[MAX], i; // 나중에 sorted[MAX]의 의미를 알아볼 것

    while (n1 <= mid && n2 <= high) {
        if (list[n1] <= list [n2]) {
            sorted[s++] = list[n1++];
        } else {
            sorted[s++] = list[n2++];
        }
    }

    if (n1 > mid) {
        while (n2 <= high) {
            sorted[s++] = list[n1++];
        }
    } else {
        while (n1 <= mid) {
            sorted[s++] = list[n1++];
        }
    }

    for (i = low; i <= high; i++) {
        list[i] = sorted[i];
    }
}

void recursive_merge_sort (int list[], int low, int high) {
    int middle; // 가운데 인덱스를 지정할 변수 선언
    if (low < high) { // low가 high 보다 작다면
        middle = (low + high) / 2; // 가운데 인덱스를 가장 낮은 인덱스와 높은 인덱스의 합의 절반으로 지정
        recursive_merge_sort(list, low, middle); // 쪼갠 배열중 앞쪽 재귀
        resursive_merge_sort(list, middle + 1, high); // 쪼갠 배열중 뒤쪽 재귀
        merge(list, low, middle, high); // return 하는 부분에서 해당 배열 병합
    }
}