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