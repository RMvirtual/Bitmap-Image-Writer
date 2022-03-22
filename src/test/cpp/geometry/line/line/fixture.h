#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/line/line.h"

class LineTest : public testing::Test
{
public:
  LineTest();
  ~LineTest();

protected:
  void compare(Geometry::Line& correctLine, Geometry::Line& line);
};