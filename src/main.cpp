#include <iostream>
#include <sorting.h>

int main() {
    unsigned int n = 5;
    double arr[] = {7, 6, 9, -1, 9999};
    merge_sort(arr, n, false);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}