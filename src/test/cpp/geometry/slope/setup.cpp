#include "src/test/cpp/geometry/slope/fixture.h"

void SlopeTest::setupNorthEastSlope()
{
  this->slope = {{1,1}, {11,5}};
}

void SlopeTest::setupNorthWestSlope()
{
  this->slope = {{11,1}, {1,5}};
}

void SlopeTest::setupSouthEastSlope()
{
  this->slope = {{1,5}, {11,1}};
}

void SlopeTest::setupSouthWestSlope()
{
  this->slope = {{11,5}, {1,1}};  
}