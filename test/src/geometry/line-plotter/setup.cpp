#include "test/src/geometry/line-plotter/fixture.h"

void LinePlotterTest::setupCorrectPlotPoints()
{
  this->correctPlotPoints = {
    {0, 0}, {1, 0},
    {2, 1}, {3, 1},
    {4, 2},  {5, 2}, {6, 2},
    {7, 3}, {8, 3},
    {9, 4}, {10, 4}
  };
}