#include <gtest/gtest.h>
#include <iostream>
#include "src/maths/binary_ops/binary_ops.h"

using namespace BinaryOps;

TEST(BinaryOpsTests, ShouldAddTwoDoubles)
{
    Addition additionOp = Addition();
    double number = additionOp.perform(1, 1);
    double correctNumber = 2;

    EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldAddTwoNegativeDoubles)
{
    Addition additionOp = Addition();
    double number = additionOp.perform(-5, -5);
    double correctNumber = -10;

    EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldAddNegativeAndPositiveDoubles)
{
    Addition additionOp = Addition();
    double number = additionOp.perform(5, -10);
    double correctNumber = -5;

    EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldSubtractTwoDoubles)
{
    Subtraction subtractionOp = Subtraction();
    double number = subtractionOp.perform(30, 7);
    double correctNumber = 23;

    EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldSubtractTwoNegativeDoubles)
{
    Subtraction subtractionOp = Subtraction();
    double number = subtractionOp.perform(-30, -7);
    double correctNumber = -23;

    EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldMultiplyTwoDoubles)
{
    Multiplication multiplicationOp = Multiplication();
    double number = multiplicationOp.perform(6, 3);
    double correctNumber = 18;

    EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldMultiplyTwoNegativeDoubles)
{
    Multiplication multiplicationOp = Multiplication();
    double number = multiplicationOp.perform(-6, -3);
    double correctNumber = 18;

    EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldDivideTwoDoubles)
{
    Division divisionOp = Division();
    double number = divisionOp.perform(100, 5);
    double correctNumber = 20;

    EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldDivideTwoNegativeDoubles)
{
    Division divisionOp = Division();
    double number = divisionOp.perform(-100, -5);
    double correctNumber = 20;

    EXPECT_DOUBLE_EQ(number, correctNumber);
}
