#include <utility>

#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line-plotter/fixture.h"

TEST_F(LinePlotterTest, ShouldPlotLinePoints)
{
  std::pair<double,double> origin {1,1};
  std::pair<double,double> destination {11, 5};
  auto plotPoints = this->plotter.plotPoints(origin, destination);
  this->compare(plotPoints);
}