#include "src/test/cpp/geometry/line-plotter/fixture.h"

void LinePlotterTest::setupHorizontalLine()
{
  this->line = {{1,1}, {5,1}};
  this->setupCorrectHorizontalLinePoints();
}

void LinePlotterTest::setupVerticalLine()
{
  this->line = {{1,1}, {1,5}};
  this->setupCorrectVerticalLinePoints();
}

void LinePlotterTest::setupNorthEastLine()
{
  this->line = {{1,1}, {11,5}};
  this->setupCorrectNorthEastSouthWestPoints();
}

void LinePlotterTest::setupNorthWestLine()
{
  this->line = {{11,1}, {1,5}};
  this->setupCorrectNorthWestSouthEastPoints();
}

void LinePlotterTest::setupSouthEastLine()
{
  this->line = {{1,5}, {11,1}};
  this->setupCorrectNorthWestSouthEastPoints();
}

void LinePlotterTest::setupSouthWestLine()
{
  this->line = {{11,5}, {1,1}};  
  this->setupCorrectNorthEastSouthWestPoints();
}

void LinePlotterTest::setupCorrectHorizontalLinePoints()
{
  this->correctPlotPoints = {
    {1,1}, {2,1}, {3,1}, {4,1}, {5,1}
  };
}

void LinePlotterTest::setupCorrectVerticalLinePoints()
{
  this->correctPlotPoints = {
    {1,1}, {1,2}, {1,3}, {1,4}, {1,5}
  };
}

void LinePlotterTest::setupCorrectNorthEastSouthWestPoints()
{
  this->correctPlotPoints = {
    {1,1}, {2,1},
    {3,2}, {4,2},
    {5,3}, {6,3}, {7,3},
    {8,4}, {9,4},
    {10,5}, {11,5}
  };
}
void LinePlotterTest::setupCorrectNorthWestSouthEastPoints()
{
  this->correctPlotPoints = {
    {1,5}, {2,5},
    {3,4}, {4,4},
    {5,3}, {6,3}, {7,3},
    {8,2}, {9,2},
    {10,1}, {11,1}
  };
}