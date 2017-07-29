#ifndef ALGORITHMS_FUNDAMENTALS_H
#define ALGORITHMS_FUNDAMENTALS_H

long long gcd(long long a, long long b);

long long lcm(long long a, long long b);

long long fibonacci(long long n);

std::pair<bool, long long> find_majority_element(long long *a, size_t size);

long long get_number_of_inversions(double *a, size_t left, size_t right);

#endif //ALGORITHMS_FUNDAMENTALS_H
