#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/plotters/line/plotter.h"

class LinePlotterTest : public testing::Test
{
public:
  LinePlotterTest();
  ~LinePlotterTest();

protected:
  std::vector<Maths::Vector> correctPlotPoints;
  Geometry::LinePlotter plotter;
  Geometry::Line line;

  void setupHorizontalLine();
  void setupVerticalLine();
  void setupNorthEastLine();
  void setupNorthWestLine();
  void setupSouthEastLine();
  void setupSouthWestLine();
  void setupCorrectHorizontalLinePoints();
  void setupCorrectVerticalLinePoints();
  void setupCorrectNorthWestSouthEastPoints();
  void setupCorrectNorthEastSouthWestPoints();
  void compare(std::vector<Maths::Vector> plotPoints);
};