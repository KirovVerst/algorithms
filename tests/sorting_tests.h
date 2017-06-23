//
// Created by Kirov on 07/04/2017.
//

#ifndef DATA_STRUCTURES_ALGORITHMS_SORTING_TESTS_H
#define DATA_STRUCTURES_ALGORITHMS_SORTING_TESTS_H

#include "sorting.h"
#include "gtest/gtest.h"


template<typename T>
::testing::AssertionResult ArraysMatch(const T expected[], const T actual[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (expected[i] != actual[i]) {
            return ::testing::AssertionFailure() << "array[" << i
                                                 << "] (" << actual[i] << ") != expected[" << i
                                                 << "] (" << expected[i] << ")";
        }
    }

    return ::testing::AssertionSuccess();
};

TEST(Quicksort, ascending) {
    int n = 5;
    double truth[] = {-2, -1, 3, 4, 5};
    double expected[] = {3, 5, -1, 4, -2};
    quick_sort(&expected[0], n);
    EXPECT_TRUE(ArraysMatch(expected, truth, n));

};

#endif //DATA_STRUCTURES_ALGORITHMS_SORTING_TESTS_H
