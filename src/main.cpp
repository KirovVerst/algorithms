#include <iostream>
#include "fundamentals.h"

using namespace std;

int main() {
    string a = "editing";
    string b = "distance";
    cout << levenshtein_edit_distance(a, b) << endl;
    return 0;
}