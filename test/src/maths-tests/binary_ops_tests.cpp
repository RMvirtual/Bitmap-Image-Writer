#include <gtest/gtest.h>
#include <iostream>
#include "src/maths/binary_ops/binary_ops.h"

using namespace BinaryOps;

TEST(BinaryOpsTests, ShouldAddTwoDoubles)
{
    Add additionOp = Add(1, 1);
    double number = additionOp.perform(); 

    EXPECT_DOUBLE_EQ(number, 2);
}