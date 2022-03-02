#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/line/line.h"

class LineTest : public testing::Test
{
public:
  LineTest();
  ~LineTest();

protected:
  Geometry::Line line;

  void setupNorthEastLine();
  void setupNorthWestLine();
  void setupSouthEastLine();
  void setupSouthWestLine();
};