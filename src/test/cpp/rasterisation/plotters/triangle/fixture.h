#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/rasterisation/plotters/triangle/plotter.h"

class TrianglePlotterTest : public testing::Test
{
public:
  TrianglePlotterTest();
  ~TrianglePlotterTest();

protected:
  std::vector<Maths::Vector> correctPlotPoints;
  Rasterisation::TrianglePlotter plotter;
};