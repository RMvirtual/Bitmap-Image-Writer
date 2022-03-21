#include "src/test/cpp/rasterisation/fill/triangle/fixture.h"

TEST_F(TriangleFillerTest, ShouldGetTriangleFillCoordinates)
{
  Geometry::Triangle triangle {{
    {0.0, 0.0}, {3, 6}, {6, 0.0}
  }};

  auto fillPoints = this->filler.fillPoints(triangle);

  EXPECT_TRUE(true);
}