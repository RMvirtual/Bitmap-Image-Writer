#include "gtest/gtest.h"
#include "src/test/cpp/rasterisation/plotters/line/fixture.h"

TEST_F(LinePlotterTest, ShouldPlotNorthVerticalLine)
{
  this->setupNorthwardVerticalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotSouthVerticalLine)
{
  this->setupSouthwardVerticalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotWestHorizontalLine)
{
  this->setupWestHorizontalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotEastHorizontalLine)
{
  this->setupEastwardHorizontalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotShortNorthEastLine)
{
  this->setupNorthEastLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotShortNorthWestLine)
{
  this->setupNorthWestLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotShortSouthEastLine)
{
  this->setupSouthEastLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotShortSouthWestLine)
{
  this->setupSouthWestLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotTranslatedNorthEastDiagonalLine)
{
  this->setupTranslatedNorthEastDiagonalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotTranslatedSouthEastDiagonalLine)
{
  this->setupTranslatedSouthEastDiagonalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}