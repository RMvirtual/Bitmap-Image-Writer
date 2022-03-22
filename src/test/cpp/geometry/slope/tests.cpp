#include "src/test/cpp/geometry/slope/fixture.h"

TEST_F(SlopeTest, ShouldGetXLowerBound)
{
  this->slope = {{0.0, 0.0}, {10, 15}};
  double correctBound = 0.0;
  auto bound = this->slope.xLowerBound();

  EXPECT_DOUBLE_EQ(correctBound, bound);
}

TEST_F(SlopeTest, ShouldGetXUpperBound)
{
  this->slope = {{0.0, 0.0}, {10, 15}};
  double correctBound = 10;
  auto bound = this->slope.xUpperBound();
  
  EXPECT_DOUBLE_EQ(correctBound, bound);
}

TEST_F(SlopeTest, ShouldGetYLowerBound)
{
  this->slope = {{0.0, 0.0}, {10, 15}};
  double correctBound = 0;
  auto bound = this->slope.yLowerBound();
  
  EXPECT_DOUBLE_EQ(correctBound, bound);
}

TEST_F(SlopeTest, ShouldGetYUpperBound)
{
  this->slope = {{0.0, 0.0}, {10, 15}};
  double correctBound = 15;
  auto bound = this->slope.yUpperBound();
  
  EXPECT_DOUBLE_EQ(correctBound, bound);
}

TEST_F(SlopeTest, ShouldCalculateGradientFromZeroXEqualToY)
{
  this->slope = {{5, 5}};
  double correctGradient = 1;

  EXPECT_DOUBLE_EQ(correctGradient, this->slope.gradient());
}

TEST_F(SlopeTest, ShouldCalculateGradientFromZeroXGreaterThanY)
{
  this->slope = {{5, 3}};
  double correctGradient = 0.6;

  EXPECT_DOUBLE_EQ(correctGradient, this->slope.gradient());
}

TEST_F(SlopeTest, ShouldCalculateGradientFromZeroXLessThanY)
{
  this->slope = {{5, 8}};
  double correctGradient = 1.6;

  EXPECT_DOUBLE_EQ(correctGradient, this->slope.gradient());
}

TEST_F(SlopeTest, ShouldCalculateGradientBetweenPointsXEqualToY)
{
  this->slope = {{1,2}, {4,5}};
  double correctGradient = 1;

  EXPECT_DOUBLE_EQ(correctGradient, this->slope.gradient());
}

TEST_F(SlopeTest, ShouldCalculateGradientBetweenPointsXLessThanY)
{
  this->slope = {{1,2}, {2,5}};
  double correctGradient = 3;

  EXPECT_DOUBLE_EQ(correctGradient, this->slope.gradient());
}

TEST_F(SlopeTest, ShouldCalculateGradientBetweenPointsXGreaterThanY)
{
  this->slope = {{1,2}, {5,3}};
  double correctGradient = 0.25;

  EXPECT_DOUBLE_EQ(correctGradient, this->slope.gradient());
}

TEST_F(SlopeTest, ShouldCalculateRise)
{
  this->slope = {{1,2}, {2,5}};
  double correctRise = 3;

  EXPECT_DOUBLE_EQ(correctRise, this->slope.rise());
}

TEST_F(SlopeTest, ShouldCalculateRun)
{
  this->slope = {{1,2}, {2,5}};
  double correctRun = 1;

  EXPECT_DOUBLE_EQ(correctRun, this->slope.run());
}

TEST_F(SlopeTest, ShouldDetectVerticallyStraightSlope)
{
  this->slope = {{1,5}, {1,1}};
  EXPECT_FALSE(this->slope.isSloped());
  EXPECT_TRUE(this->slope.isVerticallyStraight());

  this->slope = {{1,1}, {1,5}};
  EXPECT_FALSE(this->slope.isSloped());  
  EXPECT_TRUE(this->slope.isVerticallyStraight());
}

TEST_F(SlopeTest, ShouldDetectHorizontallyStraightSlope)
{
  this->slope = {{1,1}, {5,1}};
  EXPECT_FALSE(this->slope.isSloped());
  EXPECT_TRUE(this->slope.isHorizontallyStraight());
}

TEST_F(SlopeTest, ShouldDetectAsTraversingNorthEast)
{
  this->setupNorthEastSlope();
  EXPECT_TRUE(this->slope.isTraversingNorth());
  EXPECT_TRUE(this->slope.isTraversingEast());
  EXPECT_FALSE(this->slope.isTraversingSouth());
  EXPECT_FALSE(this->slope.isTraversingWest());
}

TEST_F(SlopeTest, ShouldDetectAsTraversingNorthWest)
{
  this->setupNorthWestSlope();
  EXPECT_TRUE(this->slope.isTraversingNorth());
  EXPECT_TRUE(this->slope.isTraversingWest());
  EXPECT_FALSE(this->slope.isTraversingSouth());
  EXPECT_FALSE(this->slope.isTraversingEast());  
}

TEST_F(SlopeTest, ShouldDetectAsTraversingSouthEast)
{
  this->setupSouthEastSlope();
  EXPECT_TRUE(this->slope.isTraversingSouth());
  EXPECT_TRUE(this->slope.isTraversingEast());
  EXPECT_FALSE(this->slope.isTraversingNorth());
  EXPECT_FALSE(this->slope.isTraversingWest());
}

TEST_F(SlopeTest, ShouldDetectAsTraversingSouthWest)
{
  this->setupSouthWestSlope();
  EXPECT_TRUE(this->slope.isTraversingSouth());
  EXPECT_TRUE(this->slope.isTraversingWest());
  EXPECT_FALSE(this->slope.isTraversingNorth());
  EXPECT_FALSE(this->slope.isTraversingEast());  
}