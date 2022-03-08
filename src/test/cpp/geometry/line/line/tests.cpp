#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line/line/fixture.h"

TEST_F(LineTest, ShouldTranslateLine)
{
  this->line = {{5,5}, {10, 15}};
  Maths::Vector translation = {10,15};
  this->line.translate(translation);

  Geometry::Line correctLine {{15,20}, {20,30}};

  EXPECT_EQ(correctLine["x0"], this->line["x0"]);
  EXPECT_EQ(correctLine["y0"], this->line["y0"]);
  EXPECT_EQ(correctLine["x1"], this->line["x1"]);
  EXPECT_EQ(correctLine["y1"], this->line["y1"]);
}

TEST_F(LineTest, ShouldScaleLine)
{
  this->line = {{5,5}, {10, 15}};
  this->line.scale(10);

  Geometry::Line correctLine {{5,5}, {55,105}};

  EXPECT_EQ(correctLine["x0"], this->line["x0"]);
  EXPECT_EQ(correctLine["y0"], this->line["y0"]);
  EXPECT_EQ(correctLine["x1"], this->line["x1"]);
  EXPECT_EQ(correctLine["y1"], this->line["y1"]);
}

TEST_F(LineTest, ShouldScaleAndTranslateLine)
{
  this->line = {{5,5}, {10, 15}};
  this->line.scale(10);
  this->line.translate({10, 20});

  Geometry::Line correctLine {{15,25}, {65,125}};

  EXPECT_EQ(correctLine["x0"], this->line["x0"]);
  EXPECT_EQ(correctLine["y0"], this->line["y0"]);
  EXPECT_EQ(correctLine["x1"], this->line["x1"]);
  EXPECT_EQ(correctLine["y1"], this->line["y1"]);
}

TEST_F(LineTest, ShouldGetXMinimumAfterScaling)
{
  this->line = {{5,5}, {10, 15}};
  this->line.scale(10);
  double correctMinimum = 5;

  EXPECT_EQ(correctMinimum, this->line.xMinimum());
}

TEST_F(LineTest, ShouldGetXMaximumfterScaling)
{
  this->line = {{5,5}, {10, 15}};
  this->line.scale(10);
  double correctMaximum = 55;

  EXPECT_EQ(correctMaximum, this->line.xMaximum());
}

TEST_F(LineTest, ShouldGetYMinimumAfterScaling)
{
  this->line = {{5,10}, {10, 15}};
  this->line.scale(10);
  double correctMinimum = 10;

  EXPECT_EQ(correctMinimum, this->line.yMinimum());
}

TEST_F(LineTest, ShouldGetYMaximumfterScaling)
{
  this->line = {{5,5}, {10, 15}};
  this->line.scale(10);
  double correctMaximum = 105;

  EXPECT_EQ(correctMaximum, this->line.yMaximum());
}

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

TEST_F(LineTest, ShouldSortByXAscending)
{
  this->line = {{5,1}, {2,10}};
  this->line.sortByXAscending();

  EXPECT_EQ(2, this->line["x0"]);
  EXPECT_EQ(10, this->line["y0"]);
  EXPECT_EQ(5, this->line["x1"]);
  EXPECT_EQ(1, this->line["y1"]);
}

TEST_F(LineTest, ShouldDetectVerticalLine)
{
  this->line = {{1,5}, {1,1}};
  EXPECT_FALSE(this->line.isSloped());  
  EXPECT_TRUE(this->line.isVerticalLine());

  this->line = {{1,1}, {1,5}};
  EXPECT_FALSE(this->line.isSloped());  
  EXPECT_TRUE(this->line.isVerticalLine());
}

TEST_F(LineTest, ShouldDetectHorizontalLine)
{
  this->line = {{1,1}, {5,1}};
  EXPECT_FALSE(this->line.isSloped());
  EXPECT_TRUE(this->line.isHorizontalLine());
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

