#include "gtest/gtest.h"
#include "src/test/cpp/geometry/gradient/fixture.h"

TEST_F(GradientTest, ShouldCalculateLineGradientFromZeroXEqualToY)
{
  this->setupFromOriginZero(5, 5);
  double correctGradient = 1;

  EXPECT_EQ(correctGradient, this->gradient.gradient());
}

TEST_F(
  GradientTest, ShouldCalculateLineGradientFromZeroXGreaterThanY)
{
  this->setupFromOriginZero(5, 3);
  double correctGradient = 0.6;

  EXPECT_EQ(correctGradient, this->gradient.gradient());
}

TEST_F(GradientTest, ShouldCalculateLineGradientFromZeroXLessThanY)
{
  this->setupFromOriginZero(5, 8);
  double correctGradient = 1.6;

  EXPECT_EQ(correctGradient, this->gradient.gradient());
}

TEST_F(GradientTest, ShouldCalculateLineGradientBetweenPointsXEqualToY)
{
  this->setup({1,2}, {4,5});
  double correctGradient = 1;

  EXPECT_EQ(correctGradient, this->gradient.gradient());
}

TEST_F(GradientTest, ShouldCalculateLineGradientBetweenPointsXLessThanY)
{
  this->setup({1,2}, {2,5});
  double correctGradient = 3;

  EXPECT_EQ(correctGradient, this->gradient.gradient());
}

TEST_F(GradientTest, ShouldCalculateLineGradientBetweenPointsXGreaterThanY)
{
  this->setup({1,2}, {5,3});
  double correctGradient = 0.25;

  EXPECT_EQ(correctGradient, this->gradient.gradient());
}

TEST_F(GradientTest, ShouldCalculateRise)
{
  this->setup({1,2}, {2,5});
  double correctRise = 3;

  EXPECT_EQ(correctRise, this->gradient.rise());
}

TEST_F(GradientTest, ShouldCalculateRun)
{
  this->setup({1,2}, {2,5});
  double correctRun = 1;

  EXPECT_EQ(correctRun, this->gradient.run());
}