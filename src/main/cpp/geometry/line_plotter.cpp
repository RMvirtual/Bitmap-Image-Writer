#include <cmath>

#include "src/main/cpp/geometry/line_plotter.h"

// Bresenham's Line Drawing Algorithm.
/* TODO: THIS NEEDS TIDYING UP AND UNDERSTANDING BETTER */
Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<Maths::Vector> Geometry::LinePlotter::plot(Geometry::Line line)
{
  this->plotPoints.clear();
  this->plotLineBySlope(line);

  return plotPoints;
}

void Geometry::LinePlotter::plotLineBySlope(Geometry::Line line)
{
  if (line.isHorizontallySloped()) 
    this->horizontalPlot(line);
    
  else
    this->verticalPlot(line);
}

void Geometry::LinePlotter::horizontalPlot(Geometry::Line line)
{
  if (!line.isTraversingEast())
    line = line.reverse();

  this->plotLow(line);
}

void Geometry::LinePlotter::verticalPlot(Geometry::Line line)
{
  if (!line.isTraversingNorth())
    line = line.reverse();

  this->plotHigh(line);
}

/* Could merge this and plotLineHigh together using Axis as variable. */
void Geometry::LinePlotter::plotLow(Geometry::Line line)
{
  auto run = line.run();
  auto rise = line.rise();
  double yi = 1;

  if (rise < 0) {
    yi = -1;
    rise = 0 - rise;
  }

  double D = (2 * rise) - run;

  auto x1 = line.destination()["x"];
  double y = line.origin()["y"];

  for (double x = line.origin()["x"]; x <= x1; x++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      y += yi;
      D += 2 * (rise - run);
    }

    else 
      D += 2 * rise;
  }
}

/* Could merge this and plotLineLow together using Axis as variable. */
void Geometry::LinePlotter::plotHigh(Geometry::Line line)
{
  auto run = line.run();
  auto rise = line.rise();
  double xi = 1;

  if (run < 0) {
    xi = -1;
    run = 0 - run;
  }

  double D = (2 * run) - rise;

  double x = line.origin()["x"];
  auto const y1 = line.destination()["y"];
  
  for (double y = line.origin()["y"]; y <= y1; y++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      x += xi;
      D += (2 * (run - rise));
    }

    else
      D += 2 * run;
  }
}