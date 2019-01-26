//
// Created by root on 25/01/19.
//

int *sort(int *up, int *down, unsigned int l, unsigned int r) {
    if (l == r) {
        down[l] = up[r];
        return down;
    }

    unsigned int m = (l + r) / 2;

    int *l_buff = sort(up, down, l, m);
    int *r_buff = sort(up, down, m + 1, r);

    int *target = l_buff == up ? down : up;

    int l_cur = l, r_cur = m + 1;
    for (int i = l; i <= r; i++) {
        if (l_cur <= m && r_cur <= r)
        {
            if (l_buff[l_cur] < r_buff[r_cur])
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= m)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}

void merge_sort(int *arr, int N) {
    arr = sort(arr, new int[N], 0, N);
}