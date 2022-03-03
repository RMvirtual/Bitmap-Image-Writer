#include "src/test/cpp/geometry/triangle/fixture.h"

TEST_F(TriangleTest, ShouldTranslate2DTriangle)
{
  Maths::Vector translation {3, 3};

  std::vector<Maths::Vector> v = {
    {0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}
  };
    
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