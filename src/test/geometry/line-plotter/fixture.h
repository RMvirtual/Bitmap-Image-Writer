#pragma once

#include "gtest/gtest.h"
#include "src/main/geometry/line_plotter.h"

class LinePlotterTest : public testing::Test
{
public:
  LinePlotterTest();
  ~LinePlotterTest();

protected:
  Geometry::LinePlotter plotter;
  std::vector<std::pair<int,int>> correctPlotPoints;

  void setupCorrectPlotPoints();
  void compare(std::vector<std::pair<int,int>> plotPoints);
};