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
  Rasterisation::LinePlotter plotter;
  Geometry::Line line;

  void setupEastHorizontallyStraightLine();
  void setupCorrectEastHorizontallyStraightPlots();

  void setupNorthVerticallyStraightLine();
  void setupCorrectNorthVerticallyStraightPlots();

  void setupWestHorizontallyStraightLine();
  void setupCorrectWestHorizontallyStraightPlots();

  void setupSouthVerticallyStraightLine();
  void setupCorrectSouthVerticallyStraightPlots();

  void setupNorthWestSlopedLine();
  void setupSouthEastSlopedLine();
  void setupCorrectNorthWestSouthEastSlopedPlots();

  void setupNorthEastSlopedLine();
  void setupSouthWestSlopedLine();
  void setupCorrectNorthEastSouthWestSlopedPlots();

  void setupTranslatedNorthEastSlopedLine();  
  void setupCorrectTranslatedNorthEastSlopedPlots();

  void setupTranslatedSouthEastSlopedLine();
  void setupCorrectTranslatedSouthEastSlopedPlots();

  void setupTranslatedWestHorizontallyStraightLine();
  void setupCorrectTranslatedWestHorizontallyStraightPlots();

  void compare(std::vector<Maths::Vector> plotPoints);
};