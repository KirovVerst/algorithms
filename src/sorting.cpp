#include "sorting.h"
#include <utility>
#include <cmath>

typedef bool (*Comparator)(const double &, const double &);

bool lower_than(const double &a, const double &b) {
    return a < b;
}

bool larger_than(const double &a, const double &b) {
    return a > b;
}

void quick_sort(double *arr, int l, int r, bool is_asc) {

    Comparator comparator1 = is_asc ? larger_than : lower_than;
    Comparator comparator2 = is_asc ? lower_than : larger_than;
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
        quick_sort(arr, i, r, is_asc);
    }
    if (l < j) {
        quick_sort(arr, l, j, is_asc);
    }
}


void quick_sort(double *arr, int size, bool is_asc) {
    quick_sort(arr, 0, size - 1, is_asc);
}


void insertion_sort(double *arr, int size, bool is_asc) {
    Comparator comparator = is_asc ? larger_than : lower_than;
    for (int i = 1; i < size; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && comparator(key, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(double *arr, int size, bool is_asc) {
    Comparator comparator = is_asc ? larger_than : lower_than;
    for (int i = 0; i < size - 1; i++) {
        int index = i;
        for (int j = i + 1; j < size; j++) {
            if (comparator(arr[index], arr[j])) {
                index = j;
            }
        }
        std::swap(arr[index], arr[i]);
    }
}

void merge(double *arr, int left, int split, int right, Comparator &comparator) {
    int temp_size = right - left;
    double *t = new double[temp_size];
    int pos1 = left, pos2 = split, pos3 = 0;
    while ((pos1 < split) && (pos2 < right)) {
        if (comparator(arr[pos1], arr[pos2])) {
            t[pos3++] = arr[pos1++];
        } else {
            t[pos3++] = arr[pos2++];
        }
    }

    while (pos1 < split) {
        t[pos3++] = arr[pos1++];
    }

    while (pos2 < right) {
        t[pos3++] = arr[pos2++];
    }

    for (pos3 = 0; pos3 < temp_size; pos3++) {
        arr[left + pos3] = t[pos3];
    }

    delete[] t;
}

void merge_sort(double *arr, int l, int r, Comparator &comparator) {
    if (r - l <= 1) {
        return;
    }
    int split = (l + r) / 2;
    merge_sort(arr, l, split, comparator);
    merge_sort(arr, split, r, comparator);
    merge(arr, l, split, r, comparator);
};


void merge_sort(double *arr, int size, bool is_asc) {
    Comparator comparator = is_asc ? lower_than : larger_than;
    merge_sort(arr, 0, size, comparator);
}
