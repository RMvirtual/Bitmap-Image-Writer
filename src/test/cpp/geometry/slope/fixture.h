#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/slope/slope.h"

class SlopeTest : public testing::Test
{
public:
  SlopeTest();
  ~SlopeTest();

protected:
  Geometry::Slope slope;

  void setupNorthEastSlope();
  void setupNorthWestSlope();
  void setupSouthEastSlope();
  void setupSouthWestSlope();
};