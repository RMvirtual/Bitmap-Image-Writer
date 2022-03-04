#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/rasterisation/plotters/line/plotter.h"

class LinePlotterTest : public testing::Test
{
public:
  LinePlotterTest();
  ~LinePlotterTest();

protected:
  std::vector<Maths::Vector> correctPlotPoints;
  Geometry::LinePlotter plotter;
  Geometry::Line line;

  void setupEastwardHorizontalLine();
  void setupCorrectEastwardHorizontalLinePoints();

  void setupNorthwardVerticalLine();
  void setupCorrectNorthwardVerticalLinePoints();

  void setupWestwardHorizontalLine();
  void setupCorrectWestwardHorizontalLinePoints();

  void setupSouthwardVerticalLine();
  void setupCorrectSouthwardVerticalLinePoints();

  void setupNorthWestLine();
  void setupSouthEastLine();
  void setupCorrectNorthWestSouthEastPoints();

  void setupNorthEastLine();
  void setupSouthWestLine();
  void setupCorrectNorthEastSouthWestPoints();

  void setupTranslatedNorthEastDiagonalLine();  
  void setupCorrectNorthEastDiagonalLinePoints();

  void setupTranslatedSouthEastDiagonalLine();
  void setupCorrectSouthEastDiagonalLinePoints();

  void setupWestHorizontalLine();
  void setupCorrectWestHorizontalLinePoints();

  void compare(std::vector<Maths::Vector> plotPoints);
};