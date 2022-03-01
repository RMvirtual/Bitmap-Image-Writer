#include <utility>

#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line-plotter/fixture.h"
#include "src/main/cpp/geometry/line/line.h"

TEST_F(LinePlotterTest, ShouldPlotLinePoints)
{
  Geometry::Line line {{1,1}, {11,5}};
  auto plotPoints = this->plotter.plot(line);
  this->compare(plotPoints);
}