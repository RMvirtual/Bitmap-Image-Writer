#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/line_plotter.h"

class LinePlotterTest : public testing::Test
{
public:
  LinePlotterTest();
  ~LinePlotterTest();

protected:
  Geometry::LinePlotter plotter;
  std::vector<Maths::Vector> correctPlotPoints;

  void setupNorthEastPlotPoints();
  void setupNorthWestPlotPoints();
  void setupSouthEastPlotPoints();
  void setupSouthWestPlotPoints();

  void compare(std::vector<Maths::Vector> plotPoints);
};