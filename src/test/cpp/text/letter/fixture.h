#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/line/line.h"

class LetterTest : public testing::Test
{
public:
  LetterTest();
  ~LetterTest();

protected:
  void compare(Geometry::Line correctLine, Geometry::Line line);

};