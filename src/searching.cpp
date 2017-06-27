//
// Created by Kirov on 27/06/2017.
//

int binary_search(double *arr, unsigned int size, double key) {
    int l = -1, r = size;
    int m = (l + r) / 2;
    while (l < r - 1) {
        if (arr[m] > key) {
            r = m;
        } else {
            if (arr[m] < key) {
                l = m;
            } else {
                return m;
            }
        }
        m = (l + r) / 2;
    }
    return -1;
}