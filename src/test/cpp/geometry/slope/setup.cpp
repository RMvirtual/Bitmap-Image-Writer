#include "src/test/cpp/geometry/slope/fixture.h"

void SlopeTest::setupNorthEastLine()
{
  this->slope = {{1,1}, {11,5}};
}

void SlopeTest::setupNorthWestLine()
{
  this->slope = {{11,1}, {1,5}};
}

void SlopeTest::setupSouthEastLine()
{
  this->slope = {{1,5}, {11,1}};
}

void SlopeTest::setupSouthWestLine()
{
  this->slope = {{11,5}, {1,1}};  
}