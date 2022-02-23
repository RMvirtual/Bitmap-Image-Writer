#pragma once

#include "gtest/gtest.h"
#include "src/geometry/line.h"

class GradientCalculatorTest : public testing::Test
{
public:
  GradientCalculatorTest();
  ~GradientCalculatorTest();

protected:
  Geometry::GradientCalculator calculator;
};