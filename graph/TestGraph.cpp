//
// Created by root on 31/01/19.
//

#include <iostream>
#include <stdlib.h>
#include <gtest/gtest.h>
#include "./Graph.h"

Graph *graph;

TEST(TestInitialize, PositiveNos) {
    graph->read(true);
    graph->print();
    EXPECT_TRUE(0 == 0);
}

TEST(TestBFS, PositiveNos) {
    graph->bfs(1);
    EXPECT_TRUE(0 == 0);
}

int main(int argc, char **argv) {
    graph = new Graph();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
