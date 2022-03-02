#include "src/test/cpp/geometry/line/fixture.h"

void LineTest::setupFromOriginZero(Maths::Vector destination)
{
  this->line = {destination};
}

void LineTest::setup(Maths::Vector origin, Maths::Vector destination)
{
  this->line = {origin, destination};
}
