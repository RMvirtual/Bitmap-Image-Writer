#include <gtest/gtest.h>
#include <iostream>
#include "src/maths/binary_ops/binary_ops.h"

TEST(BinaryOpsTests, ShouldAddTwoDoubles)
{
  Maths::Addition additionOp {};
  double number = additionOp.perform(1, 1);
  double correctNumber = 2;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldAddTwoNegativeDoubles)
{
  Maths::Addition additionOp {};
  double number = additionOp.perform(-5, -5);
  double correctNumber = -10;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldAddNegativeAndPositiveDoubles)
{
  Maths::Addition additionOp {};
  double number = additionOp.perform(5, -10);
  double correctNumber = -5;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldSubtractTwoDoubles)
{
  Maths::Subtraction subtractionOp {};
  double number = subtractionOp.perform(30, 7);
  double correctNumber = 23;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldSubtractTwoNegativeDoubles)
{
  Maths::Subtraction subtractionOp {};
  double number = subtractionOp.perform(-30, -7);
  double correctNumber = -23;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldMultiplyTwoDoubles)
{
  Maths::Multiplication multiplicationOp {};
  double number = multiplicationOp.perform(6, 3);
  double correctNumber = 18;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldMultiplyTwoNegativeDoubles)
{
  Maths::Multiplication multiplicationOp {};
  double number = multiplicationOp.perform(-6, -3);
  double correctNumber = 18;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldDivideTwoDoubles)
{
  Maths::Division divisionOp {};
  double number = divisionOp.perform(100, 5);
  double correctNumber = 20;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOpsTests, ShouldDivideTwoNegativeDoubles)
{
  Maths::Division divisionOp {};
  double number = divisionOp.perform(-100, -5);
  double correctNumber = 20;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}