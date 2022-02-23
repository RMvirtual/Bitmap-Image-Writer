#include "gtest/gtest.h"
#include "test/src/geometry/line-plotter/fixture.h"

void LinePlotterTest::compare(std::vector<std::pair<int,int>> plotPoints)
{
  int noOfPlotPoints = plotPoints.size();
  int correctNoOfPlotPoints = this->correctPlotPoints.size();

  ASSERT_EQ(correctNoOfPlotPoints, noOfPlotPoints);

  for (int pointNo = 0; pointNo < noOfPlotPoints; pointNo++) {
    auto point = plotPoints[pointNo];
    auto correctPoint = this->correctPlotPoints[pointNo];

    EXPECT_EQ(correctPoint.first, point.first);
    EXPECT_EQ(correctPoint.second, point.second);
  }
}