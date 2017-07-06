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


std::pair<int, int> quick_sort_partition(double *arr, int low, int high, Comparator &comparator) {
    std::pair<int, int> bounds;
    if (high - low <= 1) {
        if (arr[high] < arr[low])
            std::swap(arr[high], arr[low]);
        bounds.first = low;
        bounds.second = high;
        return bounds;
    }

    int mid = low;
    double pivot = arr[high];
    while (mid <= high) {
        if (arr[mid] == pivot) {
            mid++;

        } else if (comparator(pivot, arr[mid])) {
            std::swap(arr[low++], arr[mid++]);
        } else {
            std::swap(arr[mid], arr[high--]);
        }
    }

    bounds.first = low;
    bounds.second = mid - 1;
    return bounds;
}

void quick_sort(double *arr, int l, int r, Comparator &comparator) {
    if (l >= r) {
        return;
    }

    int k = (l + r) / 2;
    std::swap(arr[r], arr[k]);
    std::pair<int, int> bounds = quick_sort_partition(arr, l, r, comparator);

    quick_sort(arr, l, bounds.first - 1, comparator);
    quick_sort(arr, bounds.second + 1, r, comparator);
}


void quick_sort(double *arr, int size, bool is_asc) {
    Comparator comparator = is_asc ? larger_than : lower_than;
    quick_sort(arr, 0, size - 1, comparator);
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
