#include "gtest/gtest.h"
#include "src/test/cpp/rasterisation/plotters/line/fixture.h"

TEST_F(LinePlotterTest, ShouldPlotNorthVerticallyStraightLine)
{
  this->setupNorthVerticallyStraightLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotSouthVerticallyStraightLine)
{
  this->setupSouthVerticallyStraightLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotWestHorizontallyStraightLine)
{
  this->setupWestHorizontallyStraightLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotEastHorizontallyStraightLine)
{
  this->setupEastHorizontallyStraightLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotNorthEastSlopedLine)
{
  this->setupNorthEastSlopedLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotNorthWestSlopedLine)
{
  this->setupNorthWestSlopedLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotSouthEastSlopedLine)
{
  this->setupSouthEastSlopedLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotSouthWestSlopedLine)
{
  this->setupSouthWestSlopedLine();
  auto plotPoints = this->plotter.plot(this->line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotTranslatedNorthEastSlopedLine)
{
  this->setupTranslatedNorthEastSlopedLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotTranslatedSouthEastSlopedLine)
{
  this->setupTranslatedSouthEastSlopedLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotTranslatedWestHorizontallyStraightLine)
{
  this->setupTranslatedWestHorizontallyStraightLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}