#include <iostream>
#include <sorting.h>

int main() {
    int n = 5;
    double arr[] = {3, 5, -1, 4, -2};
    quick_sort(&arr[0], n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}