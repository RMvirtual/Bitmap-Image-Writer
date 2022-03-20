#include "src/test/cpp/rasterisation/plotters/triangle/fixture.h"
#include "src/main/cpp/geometry/line/mesh.h"

TEST_F(TrianglePlotterTest, ShouldPlotLinesFromTriangle)
{
  Geometry::Triangle triangle = {{{3, 3}, {5, 5}, {7, 3}}};
  auto mesh = this->plotter.plotToLineMesh(triangle);

  Geometry::LineMesh correctMesh = {{
    {{3,3}, {5,5}},
    {{5,5}, {7,3}},
    {{7,3}, {3,3}}
  }};

  for (int i = 0; i < 3; i++) {
    auto& line = mesh[i];
    auto& correctLine = correctMesh[i];

    EXPECT_DOUBLE_EQ(correctLine["x0"], line["x0"]);
    EXPECT_DOUBLE_EQ(correctLine["y0"], line["y0"]);
    EXPECT_DOUBLE_EQ(correctLine["x1"], line["x1"]);
    EXPECT_DOUBLE_EQ(correctLine["y1"], line["y1"]);
  }
}