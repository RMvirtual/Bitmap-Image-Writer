#include "src/test/cpp/geometry/triangle/fixture.h"

TEST_F(TriangleTest, ShouldTranslateTrianglePositiveFromZeroOrigin)
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

TEST_F(TriangleTest, ShouldTranslateTriangleNegativeFromZeroOrigin)
{
  Maths::Vector translation {-3, -3};

  std::vector<Maths::Vector> v = {
    {0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}
  };

  this->triangle = {v};

  this->triangle.translate(translation);

  std::vector<Maths::Vector> correctVectors = {
    {-3,-3}, {-2,-2}, {-1,-3}
  };

  for (int i = 0; i < 3; i++) {
    auto vector = this->triangle[i];
    auto correctVector = correctVectors[i];

    EXPECT_EQ(correctVector["x"], vector["x"]);
    EXPECT_EQ(correctVector["y"], vector["y"]);
  }
}

TEST_F(TriangleTest, ShouldTranslateTriangleFromNonZero)
{
  Maths::Vector translation {3, 3};

  std::vector<Maths::Vector> v = {
    {5, 5}, {10, 15}, {15, 7}
  };

  this->triangle = {v};
  this->triangle.translate(translation);

  std::vector<Maths::Vector> correctVectors = {
    {8,8}, {13,18}, {18,10}
  };

  for (int i = 0; i < 3; i++) {
    auto vector = this->triangle[i];
    auto correctVector = correctVectors[i];

    EXPECT_EQ(correctVector["x"], vector["x"]);
    EXPECT_EQ(correctVector["y"], vector["y"]);
  }
}

TEST_F(TriangleTest, ShouldTranslateTriangleNegativeFromNonZero)
{
  Maths::Vector translation {-3, -3};

  std::vector<Maths::Vector> v = {
    {5, 5}, {10, 15}, {15, 7}
  };

  this->triangle = {v};
  this->triangle.translate(translation);

  std::vector<Maths::Vector> correctVectors = {
    {2,2}, {7,12}, {12,4}
  };

  for (int i = 0; i < 3; i++) {
    auto vector = this->triangle[i];
    auto correctVector = correctVectors[i];

    EXPECT_EQ(correctVector["x"], vector["x"]);
    EXPECT_EQ(correctVector["y"], vector["y"]);
  }
}

TEST_F(TriangleTest, ShouldScaleTriangle)
{
  std::vector<Maths::Vector> v = {
    {0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}
  };

  this->triangle = {v};
  this->triangle.scale(4);

  std::vector<Maths::Vector> correctVectors = {
    {0.0, 0.0}, {4, 4}, {8, 0.0}
  };

  for (int i = 0; i < 3; i++) {
    auto vector = this->triangle[i];
    auto correctVector = correctVectors[i];

    EXPECT_EQ(correctVector["x"], vector["x"]);
    EXPECT_EQ(correctVector["y"], vector["y"]);
  }
}

TEST_F(TriangleTest, ShouldScaleTriangleFromNonZeroOrigin)
{
  Maths::Vector translation {3, 3};

  std::vector<Maths::Vector> v = {
    {5, 5}, {10, 15}, {15, 7}
  };

  this->triangle = {v};
  this->triangle.scale(2);

  std::vector<Maths::Vector> correctVectors = {
    {5,5}, {5,20}, {20,9}
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