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