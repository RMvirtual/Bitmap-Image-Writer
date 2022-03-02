#include <utility>

#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line-plotter/fixture.h"
#include "src/main/cpp/geometry/line/line.h"

TEST_F(LinePlotterTest, ShouldPlotNorthEastLine)
{
  this->setupNorthEastPlotPoints();

  Geometry::Line line {{1,1}, {11,5}};
  auto plotPoints = this->plotter.plot(line);
  this->compare(plotPoints);
}

// Fails.
TEST_F(LinePlotterTest, ShouldPlotNorthWestLine)
{
  this->setupNorthWestPlotPoints();
  
  Geometry::Line line {{11,1}, {1,5}};
  auto plotPoints = this->plotter.plot(line);
  
  this->compare(plotPoints);
}

// Fails.
TEST_F(LinePlotterTest, ShouldPlotSouthEastLine)
{
  this->setupSouthEastPlotPoints();
  
  Geometry::Line line {{1,5}, {11,1}};
  auto plotPoints = this->plotter.plot(line);
  
  this->compare(plotPoints);
}

TEST_F(LinePlotterTest, ShouldPlotSouthWestLine)
{
  this->setupSouthWestPlotPoints();
  
  Geometry::Line line {{11,5}, {1,1}};
  auto plotPoints = this->plotter.plot(line);
  
  this->compare(plotPoints);
}