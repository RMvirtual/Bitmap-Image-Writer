#include "src/geometry/line.h"

Geometry::GradientCalculator::GradientCalculator()
{
  // pass.
}

float Geometry::GradientCalculator::fromOrigin(float x, float y)
{
  return y / x;
}