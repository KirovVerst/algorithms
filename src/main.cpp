#include <iostream>
#include "sorting.h"

using namespace std;

int main() {
    double a[] = {1, 2, 2, 1, 4};
    int size = 5;
    quick_sort(&a[0], size, false);
    for (int i = 0; i < size; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}