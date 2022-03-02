#include "src/test/cpp/geometry/line/fixture.h"

void GradientTest::setupFromOriginZero(Maths::Vector destination)
{
  this->gradient = Geometry::Gradient::fromOriginZero(destination);
}

void GradientTest::setup(Maths::Vector origin, Maths::Vector destination)
{
  this->gradient = {origin, destination};
}
