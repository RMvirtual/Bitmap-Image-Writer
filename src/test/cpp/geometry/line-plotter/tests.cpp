#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line-plotter/fixture.h"

TEST_F(LinePlotterTest, ShouldPlotNorthEastLine)
{
  this->setupNorthEastLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotNorthWestLine)
{
  this->setupNorthWestLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotSouthEastLine)
{
  this->setupSouthEastLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotSouthWestLine)
{
  this->setupSouthWestLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}