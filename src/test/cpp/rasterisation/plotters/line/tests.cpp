#include "gtest/gtest.h"
#include "src/test/cpp/rasterisation/plotters/line/fixture.h"

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

TEST_F(LinePlotterTest, ShouldPlotSlopelessHorizontalLineEastwards)
{
  this->setupEastwardHorizontalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotSlopelessVerticalLineNorthwards)
{
  this->setupNorthwardVerticalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotSlopelessHorizontalLineWestwards)
{
  this->setupWestwardHorizontalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotSlopelessVerticalLineSouthwards)
{
  this->setupSouthwardVerticalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotNorthEastDiagonalLine)
{
  this->setupNorthEastDiagonalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotSouthEastDiagonalLine)
{
  this->setupSouthEastDiagonalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotWestHorizontalLine)
{
  this->setupWestHorizontalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}
