#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/line/line.h"

class GradientTest : public testing::Test
{
public:
  GradientTest();
  ~GradientTest();

protected:
  Geometry::Gradient gradient;

  void setupFromOriginZero(Maths::Vector destination);
  void setup(Maths::Vector origin, Maths::Vector destination);
};