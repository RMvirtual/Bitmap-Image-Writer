#include "gtest/gtest.h"
#include "src/test/cpp/rasterisation/plotters/line/fixture.h"

void LinePlotterTest::compare(std::vector<Maths::Vector> plotPoints)
{
  int noOfPlotPoints = plotPoints.size();
  int correctNoOfPlotPoints = this->correctPlotPoints.size();

  ASSERT_EQ(correctNoOfPlotPoints, noOfPlotPoints);

  for (int pointNo = 0; pointNo < noOfPlotPoints; pointNo++) {    
    auto point = plotPoints[pointNo];
    auto correctPoint = this->correctPlotPoints[pointNo];

    EXPECT_EQ(correctPoint["x"], point["x"]);
    EXPECT_EQ(correctPoint["y"], point["y"]) << "Failed X: " << pointNo;
  }
}