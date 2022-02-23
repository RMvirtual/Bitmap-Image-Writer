#include "gtest/gtest.h"
#include "src/geometry/line.h"

TEST(GeometryTest, ShouldCalculateLineGradientAsOne)
{
  Geometry::GradientCalculator calculator;
  float x = 5;
  float y = 5;

  auto gradient = calculator.fromOrigin(x, y);
  float correctGradient = 1;

  EXPECT_EQ(correctGradient, gradient);
}

TEST(GeometryTest, ShouldCalculateLineGradientAs0_6)
{
  Geometry::GradientCalculator calculator;
  float x = 5;
  float y = 3;

  auto gradient = calculator.fromOrigin(x, y);
  float correctGradient = 0.6;

  EXPECT_EQ(correctGradient, gradient);
}

TEST(GeometryTest, ShouldCalculateLineGradientAs1_6)
{
  Geometry::GradientCalculator calculator;
  float x = 5;
  float y = 8;

  auto gradient = calculator.fromOrigin(x, y);
  float correctGradient = 1.6;

  EXPECT_EQ(correctGradient, gradient);
}
