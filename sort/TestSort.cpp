//
// Created by root on 25/01/19.
//

#include <iostream>
#include <stdlib.h>
#include <gtest/gtest.h>
#include "./HelpFunctions.cpp"
#include "./BubbleSort.cpp"
#include "./SelectionSort.cpp"
#include "./InsertionSort.cpp"
#include "./MergeSort.cpp"
#include "./QuickSort.cpp"

TEST(SortSelectionTest, PositiveNos) {
    b_load(arr, N);
    int *c = b_copy(arr, N);
    selection_sort(arr, N);
    b_sort(c);

    EXPECT_TRUE(0 == memcmp(arr, c, sizeof(arr)));
}

TEST(SortInsertionTest, PositiveNos) {
    b_load(arr, N);
    int *c = b_copy(arr, N);
    insertion_sort(arr, N);
    b_sort(c);

    EXPECT_TRUE(0 == memcmp(arr, c, sizeof(arr)));
}


TEST(SortQuickTest, PositiveNos) {
    b_load(arr, N);
    int *c = b_copy(arr, N);
    b_print(arr, N);
    quick_sort(arr, 0, N - 1);
    b_print(arr, N);
    b_sort(c);
    EXPECT_TRUE(0 == memcmp(arr, c, sizeof(arr)));
}

TEST(SortMergeTest, PositiveNos) {
    b_load(arr, N);
    int *c = b_copy(arr, N);
    merge_sort(arr, N);
    b_sort(c);

    EXPECT_TRUE(0 == memcmp(arr, c, sizeof(arr)));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
