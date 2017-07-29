#include <iostream>
#include "fundamentals.h"

using namespace std;

int main() {
    double a[] = {7, 2, 2, 1, 4};
    size_t size = 5;
    cout << get_number_of_inversions(&a[0], 0, size);
    return 0;
}