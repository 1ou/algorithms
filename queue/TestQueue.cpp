//
// Created by root on 31/01/19.
//

#include <iostream>
#include <stdlib.h>
#include <gtest/gtest.h>
#include "./Queue.h"

Queue<int> *queue;

TEST(TestQueueAddAndGet, PositiveNos) {
    queue->add(4);
    queue->add(5);
    queue->add(6);
    queue->add(7);
    queue->get();

    EXPECT_TRUE(queue->get().get_data() == 5);
    EXPECT_TRUE(queue->get_size() == 2);

    queue->get();
    queue->get();

    EXPECT_TRUE(queue->is_empty());
}

int main(int argc, char **argv) {
    queue = new Queue<int>();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
