#include <gtest/gtest.h>
#include "src/main/maths/binary-ops/binary_ops.h"

TEST(BinaryOperations, ShouldAddTwoDoubles)
{
  Maths::Addition additionOp {};
  double number = additionOp.perform(1, 1);
  double correctNumber = 2;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOperations, ShouldAddTwoNegativeDoubles)
{
  Maths::Addition additionOp {};
  double number = additionOp.perform(-5, -5);
  double correctNumber = -10;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOperations, ShouldAddNegativeAndPositiveDoubles)
{
  Maths::Addition additionOp {};
  double number = additionOp.perform(5, -10);
  double correctNumber = -5;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOperations, ShouldSubtractTwoDoubles)
{
  Maths::Subtraction subtractionOp {};
  double number = subtractionOp.perform(30, 7);
  double correctNumber = 23;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOperations, ShouldSubtractTwoNegativeDoubles)
{
  Maths::Subtraction subtractionOp {};
  double number = subtractionOp.perform(-30, -7);
  double correctNumber = -23;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOperations, ShouldMultiplyTwoDoubles)
{
  Maths::Multiplication multiplicationOp {};
  double number = multiplicationOp.perform(6, 3);
  double correctNumber = 18;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOperations, ShouldMultiplyTwoNegativeDoubles)
{
  Maths::Multiplication multiplicationOp {};
  double number = multiplicationOp.perform(-6, -3);
  double correctNumber = 18;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOperations, ShouldDivideTwoDoubles)
{
  Maths::Division divisionOp {};
  double number = divisionOp.perform(100, 5);
  double correctNumber = 20;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}

TEST(BinaryOperations, ShouldDivideTwoNegativeDoubles)
{
  Maths::Division divisionOp {};
  double number = divisionOp.perform(-100, -5);
  double correctNumber = 20;

  EXPECT_DOUBLE_EQ(number, correctNumber);
}