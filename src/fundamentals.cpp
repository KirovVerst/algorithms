#include <utility>
#include <string>
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

long long levenshtein_edit_distance(const std::string &str1, const std::string &str2) {
    size_t n = str1.size() + 1;
    size_t m = str2.size() + 1;

    auto dist = new int *[n];
    for (int i = 0; i < n; i++) {
        dist[i] = new int[m];
    }
    for (int i = 0; i < n; i++) dist[i][0] = i;
    for (int j = 0; j < m; j++) dist[0][j] = j;


    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int insertion = dist[i][j - 1] + 1, deletion = dist[i - 1][j] + 1;
            int match = dist[i - 1][j - 1], mismatch = dist[i - 1][j - 1] + 1;
            dist[i][j] = std::min(insertion, deletion);
            if (str1[i - 1] == str2[j - 1]) {
                dist[i][j] = std::min(dist[i][j], match);
            } else {
                dist[i][j] = std::min(dist[i][j], mismatch);
            }
        }
    }

    long long result = dist[n - 1][m - 1];

    for (int i = 0; i < n; i++) {
        delete[] dist[i];
    }
    delete[] dist;

    return result;
}

