//
// Created by root on 31/01/19.
//

#include <iostream>
#include <stdlib.h>
#include <gtest/gtest.h>
#include "./Stack.h"

Stack<int> *stack;

TEST(TestStackPushAndPop, PositiveNos) {
    stack->push(4);
    stack->push(5);
    stack->push(6);
    stack->push(7);
    stack->push(8);

    EXPECT_TRUE(stack->get_size() == 5);
    EXPECT_TRUE(stack->pop().get_data() == 8);
    EXPECT_TRUE(stack->pop().get_data() == 7);
    EXPECT_TRUE(stack->peek().get_data() == 6);
    EXPECT_TRUE(stack->get_size() == 3);

    stack->pop();
    stack->pop();
    stack->pop();

    stack->push(10);
    EXPECT_TRUE(stack->pop().get_data() == 10);
    EXPECT_TRUE(stack->is_empty());
}

int main(int argc, char **argv) {
    stack = new Stack<int>();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
