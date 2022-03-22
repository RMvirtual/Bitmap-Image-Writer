#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line/line/fixture.h"

TEST_F(LineTest, ShouldTranslateLine)
{
  Geometry::Line line = {{5,5}, {10, 15}};
  Maths::Vector translation = {10,15};
  line.translate(translation);

  Geometry::Line correctLine {{15,20}, {20,30}};
  this->compare(correctLine, line);
}

TEST_F(LineTest, ShouldScale)
{
  Geometry::Line line = {{5,5}, {10, 15}};
  line.scale(10);

  Geometry::Line correctLine {{5, 5}, {55, 105}};
  this->compare(correctLine, line);
}

TEST_F(LineTest, ShouldScaleAndTranslateLine)
{
  Geometry::Line line = {{5,5}, {10, 15}};
  line.scale(10);
  line.translate({10, 20});

  Geometry::Line correctLine {{15,25}, {65, 125}};
  this->compare(correctLine, line);
}

TEST_F(LineTest, ShouldSwitchEndpoints)
{
  Geometry::Line line = {{5,5}, {10, 15}};
  line.switchEndpoints();

  Geometry::Line correctLine {{10, 15}, {5, 5}};
  this->compare(correctLine, line);
}

TEST_F(LineTest, ShouldSortByXAscending)
{
  Geometry::Line line = {{5,1}, {2,10}};
  line.sortByXAscending();

  Geometry::Line correctLine = {{2,10}, {5,1}};
  this->compare(correctLine, line);
}

TEST_F(LineTest, ShouldSortByYAscending)
{
  Geometry::Line line = {{2,10}, {5,1}};
  line.sortByYAscending();

  Geometry::Line correctLine = {{5,1}, {2,10}};
  this->compare(correctLine, line);
}