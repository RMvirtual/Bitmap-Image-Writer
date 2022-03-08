#include "src/test/cpp/geometry/line/mesh/fixture.h"

void LineMeshTest::compare()
{
  int noOfLines = this->lineMesh.size();
  ASSERT_EQ(this->correctLineMesh.size(), noOfLines);

  for (int i = 0; i < noOfLines; i++) {
    auto line = this->lineMesh[i];
    auto correctLine = this->correctLineMesh[i];

    this->compare(correctLine, line);
  }
}

void LineMeshTest::compare(Geometry::Line correctLine, Geometry::Line line)
{
  EXPECT_EQ(correctLine["x0"], line["x0"]);
  EXPECT_EQ(correctLine["y0"], line["y0"]);
  EXPECT_EQ(correctLine["x1"], line["x1"]);
  EXPECT_EQ(correctLine["y1"], line["y1"]);
}