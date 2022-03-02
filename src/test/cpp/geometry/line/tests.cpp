#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line/fixture.h"

TEST_F(LineTest, ShouldCalculateGradientFromZeroXEqualToY)
{
  this->line = {{5, 5}};
  double correctGradient = 1;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateGradientFromZeroXGreaterThanY)
{
  this->line = {{5, 3}};
  double correctGradient = 0.6;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateGradientFromZeroXLessThanY)
{
  this->line = {{5, 8}};
  double correctGradient = 1.6;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateGradientBetweenPointsXEqualToY)
{
  this->line = {{1,2}, {4,5}};
  double correctGradient = 1;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateGradientBetweenPointsXLessThanY)
{
  this->line = {{1,2}, {2,5}};
  double correctGradient = 3;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateGradientBetweenPointsXGreaterThanY)
{
  this->line = {{1,2}, {5,3}};
  double correctGradient = 0.25;

  EXPECT_EQ(correctGradient, this->line.gradient());
}

TEST_F(LineTest, ShouldCalculateRise)
{
  this->line = {{1,2}, {2,5}};
  double correctRise = 3;

  EXPECT_EQ(correctRise, this->line.rise());
}

TEST_F(LineTest, ShouldCalculateRun)
{
  this->line = {{1,2}, {2,5}};
  double correctRun = 1;

  EXPECT_EQ(correctRun, this->line.run());
}

TEST_F(LineTest, ShouldDetectAsTraversingNorthEast)
{
  this->setupNorthEastLine();
  EXPECT_TRUE(this->line.isTraversingNorth());
  EXPECT_TRUE(this->line.isTraversingEast());
  EXPECT_FALSE(this->line.isTraversingSouth());
  EXPECT_FALSE(this->line.isTraversingWest());
}

TEST_F(LineTest, ShouldDetectAsTraversingNorthWest)
{
  this->setupNorthWestLine();
  EXPECT_TRUE(this->line.isTraversingNorth());
  EXPECT_TRUE(this->line.isTraversingWest());
  EXPECT_FALSE(this->line.isTraversingSouth());
  EXPECT_FALSE(this->line.isTraversingEast());  
}

TEST_F(LineTest, ShouldDetectAsTraversingSouthEast)
{
  this->setupSouthEastLine();
  EXPECT_TRUE(this->line.isTraversingSouth());
  EXPECT_TRUE(this->line.isTraversingEast());
  EXPECT_FALSE(this->line.isTraversingNorth());
  EXPECT_FALSE(this->line.isTraversingWest());
}

TEST_F(LineTest, ShouldDetectAsTraversingSouthWest)
{
  this->setupSouthWestLine();
  EXPECT_TRUE(this->line.isTraversingSouth());
  EXPECT_TRUE(this->line.isTraversingWest());
  EXPECT_FALSE(this->line.isTraversingNorth());
  EXPECT_FALSE(this->line.isTraversingEast());  
}