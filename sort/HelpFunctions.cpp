//
// Created by root on 26/01/19.
//

void b_load(int *arr, int N) {
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void b_print(int *arr, int N) {
    std::string str = "";
    for (int i = 0; i < N; i++) {
        str += std::to_string(arr[i]) + " ";
    }
    std::cout << str << std::endl;
}

int *b_copy(int a[], int N)
{
    int *p;
    p = new int[N];
    for (int i = 0;i < N;i++)
        p[i] = a[i];
    return p;
}

void b_swap(int *f, int *s) {
    int tmp = *f;
    *f = *s;
    *s = tmp;
}