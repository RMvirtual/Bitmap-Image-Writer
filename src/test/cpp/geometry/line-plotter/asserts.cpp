#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line-plotter/fixture.h"

#include <iostream>

void LinePlotterTest::compare(std::vector<std::pair<int,int>> plotPoints)
{
  int noOfPlotPoints = plotPoints.size();
  int correctNoOfPlotPoints = this->correctPlotPoints.size();

  ASSERT_EQ(correctNoOfPlotPoints, noOfPlotPoints);

  for (int pointNo = 0; pointNo < noOfPlotPoints; pointNo++) {    
    auto point = plotPoints[pointNo];
    auto correctPoint = this->correctPlotPoints[pointNo];

    EXPECT_EQ(correctPoint.first, point.first);
    EXPECT_EQ(correctPoint.second, point.second) << "Failed X: " << pointNo;
  }
}