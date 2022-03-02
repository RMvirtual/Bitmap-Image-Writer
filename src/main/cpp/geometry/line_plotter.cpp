#include <cmath>

#include "src/main/cpp/geometry/line_plotter.h"
#include "src/main/cpp/geometry/line/line.h"

// Bresenham's Line Drawing Algorithm.
/* TODO: THIS NEEDS TIDYING UP AND UNDERSTANDING BETTER */
Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<Maths::Vector> Geometry::LinePlotter::plot(Geometry::Line line)
{
  this->plotPoints.clear();

  if (line.gradient().isHorizontallySloped())
    this->horizontalPlot(line);
  
  else
    this->verticalPlot(line);

  return plotPoints;
}

void Geometry::LinePlotter::horizontalPlot(Line line)
{
  if (line.gradient().isTraversingLeftToRight())
    this->plotLow(line.origin(), line.destination());

  else
    this->plotLow(line.destination(), line.origin());
}

void Geometry::LinePlotter::verticalPlot(Line line)
{
  if (line.gradient().isTraversingUpwards())
    this->plotHigh(line.origin(), line.destination());

  else
    this->plotHigh(line.destination(), line.origin());
}

/* Could merge this and plotLineHigh together using Axis as variable. */
void Geometry::LinePlotter::plotLow(
  Maths::Vector origin, Maths::Vector destination)
{
  Gradient gradient {origin, destination};
  auto run = gradient.run();
  auto rise = gradient.rise();
  double yi = 1;

  if (rise < 0) {
    yi = -1;
    rise = 0 - rise;
  }

  double D = (2 * rise) - run;

  auto x1 = destination["x"];
  double y = origin["y"];

  for (double x = origin["x"]; x <= x1; x++) {
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
void Geometry::LinePlotter::plotHigh(
  Maths::Vector origin, Maths::Vector destination)
{
  Gradient gradient {origin, destination};
  auto run = gradient.run();
  auto rise = gradient.rise();
  double xi = 1;

  if (run < 0) {
    xi = -1;
    run = 0 - run;
  }

  double D = (2 * run) - rise;

  double x = origin["x"];
  auto const y1 = destination["y"];
  
  std::vector<Maths::Vector> plotPoints {};

  for (double y = origin["y"]; y <= y1; y++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      x += xi;
      D += (2 * (run - rise));
    }

    else
      D += 2 * run;
  }
}