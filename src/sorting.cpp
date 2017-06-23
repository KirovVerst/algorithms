#include "sorting.h"
#include <utility>
#include <cmath>

typedef bool (*Comparator)(const double &, const double &);

bool is_ascending(const double &a, const double &b) {
    return a < b;
}

bool is_descending(const double &a, const double &b) {
    return a > b;
}

void quick_sort(double *arr, int l, int r, bool reverse) {

    Comparator comparator1 = reverse ? is_descending : is_ascending;
    Comparator comparator2 = reverse ? is_ascending : is_descending;
    double x = arr[l + (r - l) / 2];
    int i = l;
    int j = r;
    while (i < j) {
        while (comparator1(arr[i], x)) i++;

        while (comparator2(arr[j], x)) j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (i < r) {
        quick_sort(arr, i, r, reverse);
    }
    if (l < j) {
        quick_sort(arr, l, j, reverse);
    }
}


void quick_sort(double *arr, int size, bool reverse) {
    quick_sort(arr, 0, size - 1, reverse);
}
