#include "src/test/cpp/rasterisation/plotters/line/fixture.h"

void LinePlotterTest::setupNorthVerticallyStraightLine()
{
  this->line = {{1,1}, {1,5}};
  this->setupCorrectNorthVerticallyStraightPlots();
}

void LinePlotterTest::setupCorrectNorthVerticallyStraightPlots()
{
  this->correctPlotPoints = {
    {1,1}, {1,2}, {1,3}, {1,4}, {1,5}
  };
}

void LinePlotterTest::setupEastHorizontallyStraightLine()
{
  this->line = {{1,1}, {5,1}};
  this->setupCorrectEastHorizontallyStraightPlots();
}

void LinePlotterTest::setupCorrectEastHorizontallyStraightPlots()
{
  this->correctPlotPoints = {
    {1,1}, {2,1}, {3,1}, {4,1}, {5,1}
  };
}

void LinePlotterTest::setupWestHorizontallyStraightLine()
{
  this->line = {{5,1}, {1,1}};
  this->setupCorrectEastHorizontallyStraightPlots();
}

void LinePlotterTest::setupCorrectWestHorizontallyStraightPlots()
{
  this->correctPlotPoints = {
    {1,1}, {2,1}, {3,1}, {4,1}, {5,1}
  };
}

void LinePlotterTest::setupSouthVerticallyStraightLine()
{
  this->line = {{1,5}, {1,1}};
  this->setupCorrectSouthVerticallyStraightPlots();
}

void LinePlotterTest::setupCorrectSouthVerticallyStraightPlots()
{
  this->correctPlotPoints = {
    {1,1}, {1,2}, {1,3}, {1,4}, {1,5}
  };
}

void LinePlotterTest::setupNorthEastSlopedLine()
{
  this->line = {{1,1}, {11,5}};
  this->setupCorrectNorthEastSouthWestSlopedPlots();
}

void LinePlotterTest::setupSouthWestSlopedLine()
{
  this->line = {{11,5}, {1,1}};  
  this->setupCorrectNorthEastSouthWestSlopedPlots();
}

void LinePlotterTest::setupCorrectNorthEastSouthWestSlopedPlots()
{
  this->correctPlotPoints = {
    {1,1}, {2,1},
    {3,2}, {4,2},
    {5,3}, {6,3}, {7,3},
    {8,4}, {9,4},
    {10,5}, {11,5}
  };
}

void LinePlotterTest::setupNorthWestSlopedLine()
{
  this->line = {{11,1}, {1,5}};
  this->setupCorrectNorthWestSouthEastSlopedPlots();
}

void LinePlotterTest::setupSouthEastSlopedLine()
{
  this->line = {{1,5}, {11,1}};
  this->setupCorrectNorthWestSouthEastSlopedPlots();
}

void LinePlotterTest::setupCorrectNorthWestSouthEastSlopedPlots()
{
  this->correctPlotPoints = {
    {1,5}, {2,5},
    {3,4}, {4,4},
    {5,3}, {6,3}, {7,3},
    {8,2}, {9,2},
    {10,1}, {11,1}
  };
}

void LinePlotterTest::setupTranslatedNorthEastSlopedLine()
{
  this->line = {{200,200}, {205,210}};
  this->setupCorrectTranslatedNorthEastSlopedPlots();
}

void LinePlotterTest::setupCorrectTranslatedNorthEastSlopedPlots()
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

void LinePlotterTest::setupTranslatedSouthEastSlopedLine()
{
  this->line = {{205,210}, {210,200}};
  this->setupCorrectTranslatedSouthEastSlopedPlots();
}

void LinePlotterTest::setupCorrectTranslatedSouthEastSlopedPlots()
{
  this->correctPlotPoints = {
    {210, 200}, {210, 201},
    {209, 202}, {209, 203},
    {208, 204}, {208, 205},
    {207, 206}, {207, 207},
    {206, 208}, {206, 209},
    {205, 210}
  };
}

void LinePlotterTest::setupTranslatedWestHorizontallyStraightLine()
{
  this->line = {{210,200}, {200,200}};
  this->setupCorrectTranslatedWestHorizontallyStraightPlots();
}

void LinePlotterTest::setupCorrectTranslatedWestHorizontallyStraightPlots()
{
  this->correctPlotPoints = {
    {200, 200},
    {201, 200}, {202, 200}, {203, 200}, {204, 200}, {205, 200},    
    {206, 200}, {207, 200}, {208, 200}, {209, 200}, {210, 200}    
  };
}