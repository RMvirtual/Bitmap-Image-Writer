#include "gtest/gtest.h"
#include "src/test/cpp/rasterisation/plotters/line/fixture.h"

TEST_F(LinePlotterTest, ShouldPlotNorthVerticalLine)
{
  this->setupNorthVerticalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotSouthVerticalLine)
{
  this->setupSouthVerticalLine();
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
  this->setupEastHorizontalLine();
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

TEST_F(LinePlotterTest, ShouldPlotTranslatedNorthEastLine)
{
  this->setupTranslatedNorthEastLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotTranslatedSouthEastLine)
{
  this->setupVerticallySlopedSouthEastLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}

TEST_F(LinePlotterTest, ShouldPlotTranslatedWestHorizontalLine)
{
  this->setupTranslatedWestHorizontalLine();
  auto plotPoints = this->plotter.plot(this->line);

  this->compare(plotPoints);  
}