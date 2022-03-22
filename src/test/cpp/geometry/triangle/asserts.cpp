#include "src/test/cpp/geometry/triangle/fixture.h"

void TriangleTest::compare(
  Geometry::Triangle& correctTriangle, Geometry::Triangle triangle)
{
  for (int i = 0; i < 3; i++) {
    auto& vector = triangle[i];
    auto& correctVector = correctTriangle[i];

    EXPECT_DOUBLE_EQ(correctVector["x"], vector["x"]);
    EXPECT_DOUBLE_EQ(correctVector["y"], vector["y"]);
  }
}