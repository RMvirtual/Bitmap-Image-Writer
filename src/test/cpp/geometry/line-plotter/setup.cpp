#include "src/test/cpp/geometry/line-plotter/fixture.h"

void LinePlotterTest::setupNorthEastPlotPoints()
{
  this->correctPlotPoints = {
    {1,1}, {2,1},
    {3,2}, {4,2},
    {5,3}, {6,3}, {7,3},
    {8,4}, {9,4},
    {10,5}, {11,5}
  };
}

void LinePlotterTest::setupNorthWestPlotPoints()
{
  this->correctPlotPoints = {
    {1,5}, {2,5},
    {3,4}, {4,4},
    {5,3}, {6,3}, {7,3},
    {8,2}, {9,2},
    {10,1}, {11,1}
  };
}

void LinePlotterTest::setupSouthEastPlotPoints()
{
  this->setupNorthWestPlotPoints();
}

void LinePlotterTest::setupSouthWestPlotPoints()
{
  this->setupNorthEastPlotPoints();
}