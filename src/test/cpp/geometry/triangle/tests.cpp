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

// fails.
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