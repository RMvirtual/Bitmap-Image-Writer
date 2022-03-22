#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line/line/fixture.h"

TEST_F(LineTest, ShouldTranslateLine)
{
  this->line = {{5,5}, {10, 15}};
  Maths::Vector translation = {10,15};
  this->line.translate(translation);

  Geometry::Line correctLine {{15,20}, {20,30}};

  EXPECT_DOUBLE_EQ(correctLine["x0"], this->line["x0"]);
  EXPECT_DOUBLE_EQ(correctLine["y0"], this->line["y0"]);
  EXPECT_DOUBLE_EQ(correctLine["x1"], this->line["x1"]);
  EXPECT_DOUBLE_EQ(correctLine["y1"], this->line["y1"]);
}

TEST_F(LineTest, ShouldScale)
{
  this->line = {{5,5}, {10, 15}};
  this->line.scale(10);

  Geometry::Line correctLine {{5, 5}, {55, 105}};

  EXPECT_DOUBLE_EQ(correctLine["x0"], this->line["x0"]);
  EXPECT_DOUBLE_EQ(correctLine["y0"], this->line["y0"]);
  EXPECT_DOUBLE_EQ(correctLine["x1"], this->line["x1"]);
  EXPECT_DOUBLE_EQ(correctLine["y1"], this->line["y1"]);
}

TEST_F(LineTest, ShouldScaleAndTranslateLine)
{
  this->line = {{5,5}, {10, 15}};
  this->line.scale(10);
  this->line.translate({10, 20});

  Geometry::Line correctLine {{15,25}, {65, 125}};

  EXPECT_DOUBLE_EQ(correctLine["x0"], this->line["x0"]);
  EXPECT_DOUBLE_EQ(correctLine["y0"], this->line["y0"]);
  EXPECT_DOUBLE_EQ(correctLine["x1"], this->line["x1"]);
  EXPECT_DOUBLE_EQ(correctLine["y1"], this->line["y1"]);
}

TEST_F(LineTest, ShouldSwitchEndpoints)
{
  this->line = {{5,5}, {10, 15}};
  this->line.switchEndpoints();

  Geometry::Line correctLine {{10, 15}, {5, 5}};

  EXPECT_DOUBLE_EQ(correctLine["x0"], this->line["x0"]);
  EXPECT_DOUBLE_EQ(correctLine["y0"], this->line["y0"]);
  EXPECT_DOUBLE_EQ(correctLine["x1"], this->line["x1"]);
  EXPECT_DOUBLE_EQ(correctLine["y1"], this->line["y1"]);
}

TEST_F(LineTest, ShouldSortByXAscending)
{
  this->line = {{5,1}, {2,10}};
  this->line.sortByXAscending();

  Geometry::Line correctLine = {{2,10}, {5,1}};

  EXPECT_DOUBLE_EQ(correctLine["x0"], this->line["x0"]);
  EXPECT_DOUBLE_EQ(correctLine["y0"], this->line["y0"]);
  EXPECT_DOUBLE_EQ(correctLine["x1"], this->line["x1"]);
  EXPECT_DOUBLE_EQ(correctLine["y1"], this->line["y1"]);
}

TEST_F(LineTest, ShouldSortByYAscending)
{
  this->line = {{2,10}, {5,1}};
  this->line.sortByYAscending();

  Geometry::Line correctLine = {{5,1}, {2,10}};

  EXPECT_DOUBLE_EQ(correctLine["x0"], this->line["x0"]);
  EXPECT_DOUBLE_EQ(correctLine["y0"], this->line["y0"]);
  EXPECT_DOUBLE_EQ(correctLine["x1"], this->line["x1"]);
  EXPECT_DOUBLE_EQ(correctLine["y1"], this->line["y1"]);
}