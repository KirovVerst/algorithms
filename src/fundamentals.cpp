#include <utility>
#include "fundamentals.h"

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
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
