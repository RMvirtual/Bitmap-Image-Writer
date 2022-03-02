#include "src/test/cpp/geometry/line/fixture.h"

void LineTest::setupNorthEastLine()
{
  this->line = {{1,1}, {11,5}};
}

void LineTest::setupNorthWestLine()
{
  this->line = {{11,1}, {1,5}};
}

void LineTest::setupSouthEastLine()
{
  this->line = {{1,5}, {11,1}};
}

void LineTest::setupSouthWestLine()
{
  this->line = {{11,5}, {1,1}};  
}