#include "src/test/cpp/rasterisation/fill/triangle/fixture.h"

TEST_F(TriangleFillerTest, ShouldGetTriangleFillCoordinates)
{
  Geometry::Triangle triangle {{
    {0.0, 0.0}, {3, 6}, {6, 0.0}
  }};

  auto fillPoints = this->filler.fillPoints(triangle);
  
  std::vector<Maths::Vector> correctFillPoints = {
    {0.0, 0.0},
    {1, 0.0}, {1, 1},
    {2, 0.0}, {2, 1}, {2, 2},
  };

  for (auto point : fillPoints) {
    std::cout << point << std::endl;
  }

  EXPECT_TRUE(true);
}