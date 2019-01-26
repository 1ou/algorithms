//
// Created by root on 25/01/19.
//

int *insertion_sort(int *arr, int N) {
    for (int i = 2; i < N; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}
