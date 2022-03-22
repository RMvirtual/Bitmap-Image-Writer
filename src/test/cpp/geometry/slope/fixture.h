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

  void setupNorthEastLine();
  void setupNorthWestLine();
  void setupSouthEastLine();
  void setupSouthWestLine();
};