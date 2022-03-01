#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/line/gradient.h"

class GradientTest : public testing::Test
{
public:
  GradientTest();
  ~GradientTest();

protected:
  Geometry::Gradient gradient;

  void setupFromOriginZero(double x, double y);
  void setup(
    std::pair<double,double> origin, std::pair<double,double> destination);
};