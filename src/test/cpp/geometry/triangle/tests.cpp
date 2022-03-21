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
    auto& vector = this->triangle[i];
    auto& correctVector = correctVectors[i];

    EXPECT_DOUBLE_EQ(correctVector["x"], vector["x"]);
    EXPECT_DOUBLE_EQ(correctVector["y"], vector["y"]);
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
    auto& vector = this->triangle[i];
    auto& correctVector = correctVectors[i];

    EXPECT_DOUBLE_EQ(correctVector["x"], vector["x"]);
    EXPECT_DOUBLE_EQ(correctVector["y"], vector["y"]);
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
    auto& vector = this->triangle[i];
    auto& correctVector = correctVectors[i];

    EXPECT_DOUBLE_EQ(correctVector["x"], vector["x"]);
    EXPECT_DOUBLE_EQ(correctVector["y"], vector["y"]);
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
    auto& vector = this->triangle[i];
    auto& correctVector = correctVectors[i];

    EXPECT_DOUBLE_EQ(correctVector["x"], vector["x"]);
    EXPECT_DOUBLE_EQ(correctVector["y"], vector["y"]);
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
    auto& vector = this->triangle[i];
    auto& correctVector = correctVectors[i];

    EXPECT_DOUBLE_EQ(correctVector["x"], vector["x"]);
    EXPECT_DOUBLE_EQ(correctVector["y"], vector["y"]);
  }
}

TEST_F(TriangleTest, ShouldScaleTriangleFromNonZeroOrigin)
{
  this->triangle = {{
    {5, 5}, {10, 15}, {15, 7}}};

  this->triangle.scale(2);

  std::vector<Maths::Vector> correctVectors = {
    {5, 5}, {15, 25}, {25, 9}
  };

  for (int i = 0; i < 3; i++) {
    auto& vector = this->triangle[i];
    auto& correctVector = correctVectors[i];

    EXPECT_DOUBLE_EQ(correctVector["x"], vector["x"]);
    EXPECT_DOUBLE_EQ(correctVector["y"], vector["y"]);
  }
}

TEST_F(TriangleTest, ShouldIndexTriangleWithVerticeSubscriptOperator)
{
  this->triangle = {{
    {0.0, 0.0}, {3, 6}, {6, 0.0}}};

  auto y1 = triangle["y1"];
  auto x2 = triangle["x2"];

  double correctY1 = 6;
  double correctX2 = 6;

  EXPECT_DOUBLE_EQ(correctY1, y1);
  EXPECT_DOUBLE_EQ(correctX2, x2);
}

TEST_F(TriangleTest, ShouldGetMiddleXOfTriangle)
{
  this->triangle = {{
    {0.0, 0.0}, {3, 6}, {6, 0.0}}};

  auto point = triangle.middleX();
  Maths::Vector correctPoint = {3, 6};

  EXPECT_DOUBLE_EQ(correctPoint["x"], point["x"]);
  EXPECT_DOUBLE_EQ(correctPoint["y"], point["y"]);
}

TEST_F(TriangleTest, ShouldSplitTriangle)
{
  this->triangle = {{
    {0.0, 0.0}, {3, 6}, {6, 0.0}}};

  auto triangles = this->triangle.split();

  Geometry::Triangle correctTriangle1 {{{0.0, 0.0}, {3, 6}, {3, 0.0}}};
  Geometry::Triangle correctTriangle2 {{{3, 0.0}, {3, 6}, {6, 0.0}}};

  auto triangle1 = triangles.first;

  for (int i = 0; i < 3; i++) {
    auto& vector = triangle1[i];
    auto& correctVector = correctTriangle1[i];

    EXPECT_DOUBLE_EQ(correctVector["x"], vector["x"]);
    EXPECT_DOUBLE_EQ(correctVector["y"], vector["y"]);
  }

  auto triangle2 = triangles.second;

  for (int i = 0; i < 3; i++) {
    auto& vector = triangle2[i];
    auto& correctVector = correctTriangle2[i];

    EXPECT_DOUBLE_EQ(correctVector["x"], vector["x"]);
    EXPECT_DOUBLE_EQ(correctVector["y"], vector["y"]);
  }
}