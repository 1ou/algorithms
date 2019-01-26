//
// Created by root on 25/01/19.
//

int *selection_sort(int *arr, int N) {
    for (int i = 0; i < N - 1; i++) {
        int min_idx = i;
        for (int j = min_idx + 1; j < N; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int tmp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = tmp;
        }
    }
    return arr;
}