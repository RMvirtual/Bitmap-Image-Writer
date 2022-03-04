#include "gtest/gtest.h"
#include "src/test/cpp/rasterisation/plotters/line/fixture.h"

void LinePlotterTest::compare(std::vector<Maths::Vector> plotPoints)
{
  int noOfPlotPoints = plotPoints.size();
  int correctNoOfPlotPoints = this->correctPlotPoints.size();

  ASSERT_EQ(correctNoOfPlotPoints, noOfPlotPoints);

  auto failureDetails = [](int pointNo, Maths::Vector correctPoint, Maths::Vector point) {
    std::string failure = {
      "Failed point No:" + std::to_string(pointNo)
      + ". Received x:" + std::to_string(point["x"])
      + " y:" + std::to_string(point["y"])
      + ". Expected x:" + std::to_string(correctPoint["x"])
      + " y:" + std::to_string(correctPoint["y"]) + "\n"
    };

    return failure;
  };

  for (int pointNo = 0; pointNo < noOfPlotPoints; pointNo++) {    
    auto point = plotPoints[pointNo];
    auto correctPoint = this->correctPlotPoints[pointNo];

    ASSERT_EQ(correctPoint["x"], point["x"]) << 
      failureDetails(pointNo, correctPoint, point);
    
    ASSERT_EQ(correctPoint["y"], point["y"]) << 
      failureDetails(pointNo, correctPoint, point);
  }
}