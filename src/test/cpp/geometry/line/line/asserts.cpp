#include "src/test/cpp/geometry/line/line/fixture.h"

void LineTest::compare(Geometry::Line& correctLine, Geometry::Line& line)
{
  EXPECT_DOUBLE_EQ(correctLine["x0"], line["x0"]);
  EXPECT_DOUBLE_EQ(correctLine["y0"], line["y0"]);
  EXPECT_DOUBLE_EQ(correctLine["x1"], line["x1"]);
  EXPECT_DOUBLE_EQ(correctLine["y1"], line["y1"]);
}