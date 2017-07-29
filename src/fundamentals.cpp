#include <utility>
#include "fundamentals.h"

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}


long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

long long fibonacci(long long n) {
    long long first = 0;
    long long second = 1;
    if (n <= 1) {
        return n;
    }
    for (long long i = 2; i <= n; i++) {
        second = first + second;
        first = second - first;
    }

    return second;
}

std::pair<bool, long long> find_majority_element(long long *a, size_t size) {
    long long major = a[0];
    int count = 1;
    size_t i = 1;
    while (i < size) {
        if (count == 0) {
            major = a[i];
            count = 1;
        } else if (a[i] == major) {
            count++;
        } else {
            count--;
        }
        i++;
    }
    int check_count = 0;
    for (i = 0; i < size; i++) {
        if (major == a[i]) check_count++;
    }
    return std::make_pair(check_count > size / 2, major);
};

long long merge(double *a, size_t l, size_t m, size_t r) {
    long long inversions = 0;
    auto *buffer = new double[r - l];
    size_t pos_1 = l;
    size_t pos_2 = m;
    size_t pos_buffer = 0;

    while ((pos_1 < m) && (pos_2 < r)) {
        if (a[pos_1] <= a[pos_2]) {
            buffer[pos_buffer++] = a[pos_1++];
        } else {
            buffer[pos_buffer++] = a[pos_2++];
            inversions += m - pos_1;
        }
    }

    while (pos_1 < m) {
        buffer[pos_buffer++] = a[pos_1++];
    }
    while (pos_2 < r) {
        buffer[pos_buffer++] = a[pos_2++];
    }
    for (size_t i = l; i < r; i++) {
        a[i] = buffer[i - l];
    }
    delete[] buffer;
    return inversions;
}

long long get_number_of_inversions(double *a, size_t left, size_t right) {
    long long inversions = 0;
    if (right <= left + 1) {
        return inversions;
    }
    size_t m = (left + right) / 2;
    inversions += get_number_of_inversions(a, left, m);
    inversions += get_number_of_inversions(a, m, right);
    inversions += merge(a, left, m, right);
    return inversions;
}