#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/gradient.h"

class GradientCalculatorTest : public testing::Test
{
public:
  GradientCalculatorTest();
  ~GradientCalculatorTest();

protected:
  Geometry::GradientCalculator calculator;
};