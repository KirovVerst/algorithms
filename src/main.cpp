#include <iostream>
#include <sorting.h>
#include <searching.h>

int main() {
    unsigned int n = 7;
    double arr[] = {1, 2, 3, 4, 5, 6, 7};
    std::cout << binary_search(arr, n, 4) << std::endl;
    std::cout << binary_search(arr, n, 1) << std::endl;
    std::cout << binary_search(arr, n, 9) << std::endl;
    std::cout << binary_search(arr, n, -1) << std::endl;

    return 0;
}