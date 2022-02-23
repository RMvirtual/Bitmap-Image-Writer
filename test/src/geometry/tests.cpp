#include "gtest/gtest.h"
#include "test/src/geometry/fixture.h"

TEST_F(GradientCalculatorTest, ShouldCalculateLineGradientAsOne)
{
  float x = 5;
  float y = 5;

  auto gradient = this->calculator.fromOrigin(x, y);
  float correctGradient = 1;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(GradientCalculatorTest, ShouldCalculateLineGradientAs0_6)
{
  float x = 5;
  float y = 3;

  auto gradient = this->calculator.fromOrigin(x, y);
  float correctGradient = 0.6;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(GradientCalculatorTest, ShouldCalculateLineGradientAs1_6)
{
  float x = 5;
  float y = 8;

  auto gradient = this->calculator.fromOrigin(x, y);
  float correctGradient = 1.6;

  EXPECT_EQ(correctGradient, gradient);
}
