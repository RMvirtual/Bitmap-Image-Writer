#include "src/test/cpp/geometry/gradient/fixture.h"

void GradientTest::setupFromOriginZero(double x, double y)
{
  this->gradient = Geometry::Gradient::fromOriginZero(x, y);
}

void GradientTest::setup(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  this->gradient = {origin, destination};
}
