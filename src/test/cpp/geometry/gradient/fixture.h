#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/gradient.h"

class GradientTest : public testing::Test
{
public:
  GradientTest();
  ~GradientTest();

protected:
  Geometry::GradientCalculator calculator;
};