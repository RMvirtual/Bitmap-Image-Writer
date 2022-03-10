#include "gtest/gtest.h"
#include "src/test/cpp/rasterisation/plotters/line/fixture.h"

void LinePlotterTest::compare(std::vector<Maths::Vector> plotPoints)
{
  int noOfPlotPoints = plotPoints.size();
  ASSERT_EQ(this->correctPlotPoints.size(), noOfPlotPoints);

  for (int pointNo = 0; pointNo < noOfPlotPoints; pointNo++) {    
    auto& point = plotPoints[pointNo];
    auto& correctPoint = this->correctPlotPoints[pointNo];

    EXPECT_DOUBLE_EQ(correctPoint["x"], point["x"]);    
    EXPECT_DOUBLE_EQ(correctPoint["y"], point["y"]);
  }
}