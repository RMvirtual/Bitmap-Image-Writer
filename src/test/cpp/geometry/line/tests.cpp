#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line/fixture.h"

TEST_F(LineTest, ShouldCalculateGradientFromZeroXEqualToY)
{
  this->setupFromOriginZero({5, 5});
  double correctGradient = 1;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateGradientFromZeroXGreaterThanY)
{
  this->setupFromOriginZero({5, 3});
  double correctGradient = 0.6;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateGradientFromZeroXLessThanY)
{
  this->setupFromOriginZero({5, 8});
  double correctGradient = 1.6;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateGradientBetweenPointsXEqualToY)
{
  this->setup({1,2}, {4,5});
  double correctGradient = 1;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateGradientBetweenPointsXLessThanY)
{
  this->setup({1,2}, {2,5});
  double correctGradient = 3;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateGradientBetweenPointsXGreaterThanY)
{
  this->setup({1,2}, {5,3});
  double correctGradient = 0.25;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateRise)
{
  this->setup({1,2}, {2,5});
  double correctRise = 3;

  EXPECT_EQ(correctRise, this->line.rise());
}

TEST_F(LineTest, ShouldCalculateRun)
{
  this->setup({1,2}, {2,5});
  double correctRun = 1;

  EXPECT_EQ(correctRun, this->line.run());
}