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

  void setupEastHorizontalLine();
  void setupCorrectEastHorizontalPlots();

  void setupNorthVerticalLine();
  void setupCorrectNorthVerticalPlots();

  void setupWestHorizontalLine();
  void setupCorrectWestHorizontalPlots();

  void setupSouthVerticalLine();
  void setupCorrectSouthVerticalPlots();

  void setupNorthWestLine();
  void setupSouthEastLine();
  void setupCorrectNorthWestSouthEastPlots();

  void setupNorthEastLine();
  void setupSouthWestLine();
  void setupCorrectNorthEastSouthWestPlots();

  void setupTranslatedNorthEastLine();  
  void setupCorrectTranslatedNorthEastPlots();

  void setupTranslatedSouthEastLine();
  void setupCorrectTranslatedSouthEastPlots();

  void setupTranslatedWestHorizontalLine();
  void setupCorrectTranslatedWestHorizontalPlots();

  void compare(std::vector<Maths::Vector> plotPoints);
};