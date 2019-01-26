//
// Created by root on 25/01/19.
//

#include <iostream>
#include <stdlib.h>

int N = 50;
int *arr = new int[N];

int *b_sort(int *arr) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i] < arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                continue;
            }
        }
    }
    return arr;
}
