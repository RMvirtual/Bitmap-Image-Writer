#include "src/test/cpp/rasterisation/plotters/line/fixture.h"

void LinePlotterTest::setupNorthEastLine()
{
  this->line = {{1,1}, {11,5}};
  this->setupCorrectNorthEastSouthWestPoints();
}

void LinePlotterTest::setupSouthWestLine()
{
  this->line = {{11,5}, {1,1}};  
  this->setupCorrectNorthEastSouthWestPoints();
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

void LinePlotterTest::setupEastwardHorizontalLine()
{
  this->line = {{1,1}, {5,1}};
  this->setupCorrectEastwardHorizontalLinePoints();
}

void LinePlotterTest::setupCorrectEastwardHorizontalLinePoints()
{
  this->correctPlotPoints = {
    {1,1}, {2,1}, {3,1}, {4,1}, {5,1}
  };
}

void LinePlotterTest::setupWestwardHorizontalLine()
{
  this->line = {{5,1}, {1,1}};
  this->setupCorrectEastwardHorizontalLinePoints();
}

void LinePlotterTest::setupCorrectWestwardHorizontalLinePoints()
{
  this->correctPlotPoints = {
    {1,1}, {2,1}, {3,1}, {4,1}, {5,1}
  };
}

void LinePlotterTest::setupNorthwardVerticalLine()
{
  this->line = {{1,1}, {1,5}};
  this->setupCorrectNorthwardVerticalLinePoints();
}

void LinePlotterTest::setupCorrectNorthwardVerticalLinePoints()
{
  this->correctPlotPoints = {
    {1,1}, {1,2}, {1,3}, {1,4}, {1,5}
  };
}

void LinePlotterTest::setupSouthwardVerticalLine()
{
  this->line = {{1,5}, {1,1}};
  this->setupCorrectSouthwardVerticalLinePoints();
}

void LinePlotterTest::setupCorrectSouthwardVerticalLinePoints()
{
  this->correctPlotPoints = {
    {1,1}, {1,2}, {1,3}, {1,4}, {1,5}
  };
}

// Triangle functions start here.

void LinePlotterTest::setupNorthEastDiagonalLine()
{
  this->line = {{200,200}, {205,210}};
  this->setupCorrectNorthEastDiagonalLinePoints();
}

void LinePlotterTest::setupCorrectNorthEastDiagonalLinePoints()
{
  this->correctPlotPoints = {
    {200, 200}, {200, 201},
    {201, 202}, {201, 203},
    {202, 204}, {202, 205},
    {203, 206}, {203, 207},
    {204, 208}, {204, 209},
    {205, 210}
  };
}

void LinePlotterTest::setupSouthEastDiagonalLine()
{
  this->line = {{205,210}, {210,200}};
  this->setupCorrectSouthEastDiagonalLinePoints();
}

void LinePlotterTest::setupCorrectSouthEastDiagonalLinePoints()
{
  this->correctPlotPoints = {
    {205, 210}, {205, 209},
    {206, 208}, {206, 207},
    {207, 206}, {207, 205},
    {208, 204}, {208, 203},
    {209, 202}, {209, 201},
    {210, 200}
  };
}

void LinePlotterTest::setupWestHorizontalLine()
{
  this->line = {{210,200}, {200,200}};
  this->setupCorrectWestHorizontalLinePoints();
}

void LinePlotterTest::setupCorrectWestHorizontalLinePoints()
{
  // Orders them in ascending order of x rather than reverse.
  // Maybe ridding ourselves of the ordering would work?

  this->correctPlotPoints = {
    {200, 200},
    {201, 200}, {202, 200}, {203, 200}, {204, 200}, {205, 200},    
    {206, 200}, {207, 200}, {208, 200}, {209, 200}, {210, 200}    
  };
}