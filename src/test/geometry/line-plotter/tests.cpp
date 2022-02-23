#include <utility>

#include "gtest/gtest.h"
#include "src/test/geometry/line-plotter/fixture.h"

TEST_F(LinePlotterTest, ShouldPlotLinePoints)
{
  std::pair<double,double> destination {11, 5};
  auto plotPoints = this->plotter.plotPoints(destination);
  this->compare(plotPoints);
}