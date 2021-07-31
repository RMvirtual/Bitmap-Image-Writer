#include <gtest/gtest.h>
#include <iostream>
#include "src/maths/binary_ops/binary_ops.h"

using namespace BinaryOps;

TEST(BinaryOpsTests, ShouldAddTwoDoubles)
{
    Add additionOp = Add();
    double number = additionOp.perform(1, 1);

    EXPECT_DOUBLE_EQ(number, 2);
}

TEST(BinaryOpsTests, ShouldSubtractTwoDoubles)
{
    Subtract subtractionOp = Subtract();
    double number = subtractionOp.perform(5, 3);

    EXPECT_DOUBLE_EQ(number, 2);
}