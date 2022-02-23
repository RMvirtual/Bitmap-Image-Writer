#pragma once

#include "gtest/gtest.h"
#include "src/geometry/line_plotter.h"

class LinePlotterTest : public testing::Test
{
public:
  LinePlotterTest();
  ~LinePlotterTest();

protected:
  Geometry::LinePlotter plotter;
};