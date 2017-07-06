#include <iostream>
#include "fundamentals.h"

int main() {
    long long a[] = {1, 2, 2, 1, 4};
    size_t size = 5;
    std::pair<bool, long long> res = find_majority_element(&a[0], size);
    std::cout << res.first << std::endl;
    std::cout << res.second << std::endl;
    return 0;
}