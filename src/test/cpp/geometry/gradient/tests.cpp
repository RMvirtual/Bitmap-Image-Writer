#include <utility>

#include "gtest/gtest.h"
#include "src/test/cpp/geometry/gradient/fixture.h"

TEST_F(GradientTest, ShouldCalculateLineGradientFromZeroXEqualToY)
{
  double x = 5;
  double y = 5;

  auto gradient = this->calculator.fromOriginZero(x, y);
  double correctGradient = 1;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(
  GradientTest, ShouldCalculateLineGradientFromZeroXGreaterThanY)
{
  double x = 5;
  double y = 3;

  auto gradient = this->calculator.fromOriginZero(x, y);
  double correctGradient = 0.6;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(
  GradientTest, ShouldCalculateLineGradientFromZeroXLessThanY)
{
  double x = 5;
  double y = 8;

  auto gradient = this->calculator.fromOriginZero(x, y);
  double correctGradient = 1.6;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(
  GradientTest, ShouldCalculateLineGradientBetweenPointsXEqualToY)
{
  std::pair<double,double> origin {1, 2};
  std::pair<double,double> destination {4, 5};

  auto gradient = this->calculator.gradient(origin, destination);
  double correctGradient = 1;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(
  GradientTest, ShouldCalculateLineGradientBetweenPointsXLessThanY)
{
  std::pair<double,double> origin {1, 2};
  std::pair<double,double> destination {2, 5};

  auto gradient = this->calculator.gradient(origin, destination);
  double correctGradient = 3;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(
  GradientTest,
  ShouldCalculateLineGradientBetweenPointsXGreaterThanY)
{
  std::pair<double,double> origin {1, 2};
  std::pair<double,double> destination {5, 3};

  auto gradient = this->calculator.gradient(origin, destination);
  double correctGradient = 0.25;

  EXPECT_EQ(correctGradient, gradient);
}

TEST_F(GradientTest, ShouldCalculateRise)
{
  std::pair<double,double> origin {1, 2};
  std::pair<double,double> destination {2, 5};

  auto rise = this->calculator.rise(origin, destination);
  double correctRise = 3;

  EXPECT_EQ(correctRise, rise);
}

TEST_F(GradientTest, ShouldCalculateRun)
{
  std::pair<double,double> origin {1, 2};
  std::pair<double,double> destination {2, 5};

  auto run = this->calculator.run(origin, destination);
  double correctRun = 1;

  EXPECT_EQ(correctRun, run);
}