#include <utility>

#include "gtest/gtest.h"
#include "test/src/geometry/fixture.h"

TEST_F(GradientCalculatorTest,
  ShouldCalculateLineGradientFromZeroXEqualToY)
{
  float x = 5;
  float y = 5;

  auto gradient = this->calculator.fromZero(x, y);
  float correctGradient = 1;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(
  GradientCalculatorTest, ShouldCalculateLineGradientFromZeroXGreaterThanY)
{
  float x = 5;
  float y = 3;

  auto gradient = this->calculator.fromZero(x, y);
  float correctGradient = 0.6;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(
  GradientCalculatorTest, ShouldCalculateLineGradientFromZeroXLessThanY)
{
  float x = 5;
  float y = 8;

  auto gradient = this->calculator.fromZero(x, y);
  float correctGradient = 1.6;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(
  GradientCalculatorTest, ShouldCalculateLineGradientBetweenPointsXEqualToY)
{
  std::pair<double,double> origin {1, 2};
  std::pair<double,double> destination {4, 5};

  auto gradient = this->calculator.gradient(origin, destination);
  float correctGradient = 1;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(
  GradientCalculatorTest, ShouldCalculateLineGradientBetweenPointsXLessThanY)
{
  std::pair<double,double> origin {1, 2};
  std::pair<double,double> destination {2, 5};

  auto gradient = this->calculator.gradient(origin, destination);
  float correctGradient = 3;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(
  GradientCalculatorTest,
  ShouldCalculateLineGradientBetweenPointsXGreaterThanY)
{
  std::pair<double,double> origin {1, 2};
  std::pair<double,double> destination {5, 3};

  auto gradient = this->calculator.gradient(origin, destination);
  float correctGradient = 0.25;

  EXPECT_EQ(correctGradient, gradient);
}