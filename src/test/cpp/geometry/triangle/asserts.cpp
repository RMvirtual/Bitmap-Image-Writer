#include "src/test/cpp/geometry/triangle/fixture.h"

void TriangleTest::compare(
  Geometry::Triangle& correctTriangle, Geometry::Triangle triangle)
{
  for (int i = 0; i < 3; i++) {
    auto& vector = triangle[i];
    auto& correctVector = correctTriangle[i];

    this->compare(correctVector, vector);
  }
}

void TriangleTest::compare(Geometry::Edge& correctEdge, Geometry::Edge& edge)
{
  this->compare(correctEdge[0], edge[0]);
  this->compare(correctEdge[1], edge[1]);
}

void TriangleTest::compare(
  Maths::Vector& correctVector, Maths::Vector& vector)
{
  EXPECT_DOUBLE_EQ(correctVector["x"], vector["x"]);
  EXPECT_DOUBLE_EQ(correctVector["y"], vector["y"]);
}