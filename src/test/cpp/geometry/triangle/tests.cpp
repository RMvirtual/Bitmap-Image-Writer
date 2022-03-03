#include "src/test/cpp/geometry/triangle/fixture.h"

TEST_F(TriangleTest, ShouldTranslate2DTriangle)
{
  Maths::Vector translation {3, 3};

  std::vector<Maths::Vector> v = {
    {0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}
  };

  this->triangle = {v};

  this->triangle.translate(translation);

  std::vector<Maths::Vector> correctVectors = {
    {3,3}, {4,4}, {5,3}
  };

  for (int i = 0; i < 3; i++) {
    auto vector = this->triangle[i];
    auto correctVector = correctVectors[i];

    EXPECT_EQ(correctVector["x"], vector["x"]);
    EXPECT_EQ(correctVector["y"], vector["y"]);
  }
}

TEST_F(TriangleTest, ShouldGetLinesFromTriangle)
{
  std::vector<Maths::Vector> v = {
    {3, 3}, {5, 5}, {7, 3}
  };

  this->triangle = {v};
  auto lines = this->triangle.toLines();

  std::vector<Geometry::Line> correctLines = {
    {{3,3}, {5,5}},
    {{5,5}, {7,3}},
    {{7,3}, {3,3}}
  };

  for (int i = 0; i < 3; i++) {
    auto line = lines[i];
    auto correctLine = correctLines[i];

    EXPECT_EQ(correctLine["x0"], line["x0"]);
    EXPECT_EQ(correctLine["y0"], line["y0"]);
    EXPECT_EQ(correctLine["x1"], line["x1"]);
    EXPECT_EQ(correctLine["y1"], line["y1"]);
  }
}