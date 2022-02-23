#pragma once

#include "gtest/gtest.h"
#include "src/geometry/gradient_calculator.h"

class GradientCalculatorTest : public testing::Test
{
public:
  GradientCalculatorTest();
  ~GradientCalculatorTest();

protected:
  Geometry::GradientCalculator calculator;
};