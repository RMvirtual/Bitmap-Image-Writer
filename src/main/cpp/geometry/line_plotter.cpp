#include <cmath>

#include "src/main/cpp/geometry/line_plotter.h"
#include "src/main/cpp/geometry/line/line.h"
#include "src/main/cpp/geometry/line/gradient.h"

// Bresenham's Line Drawing Algorithm.
/* TODO: THIS NEEDS TIDYING UP AND UNDERSTANDING BETTER */
Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<Maths::Vector> Geometry::LinePlotter::plot(Geometry::Line line)
{
  std::vector<Maths::Vector> plotPoints;

  if (line.gradient().isHorizontallySloped())
    plotPoints = this->horizontalPlot(line);
  
  else
    plotPoints = this->verticalPlot(line);

  return plotPoints;
}

std::vector<Maths::Vector> Geometry::LinePlotter::horizontalPlot(Line line)
{
  std::vector<Maths::Vector> plotPoints;

  if (line.gradient().isTraversingLeftToRight())
    plotPoints = this->plotLow(line.origin(), line.destination());

  else
    plotPoints = this->plotLow(line.destination(), line.origin());

  return plotPoints;
}

std::vector<Maths::Vector> Geometry::LinePlotter::verticalPlot(Line line)
{
  std::vector<Maths::Vector> plotPoints;

  if (line.gradient().isTraversingUpwards())
    plotPoints = this->plotHigh(line.origin(), line.destination());

  else
    plotPoints = this->plotHigh(line.destination(), line.origin());

  return plotPoints;
}

/* Could merge this and plotLineHigh together using Axis as variable. */
std::vector<Maths::Vector> Geometry::LinePlotter::plotLow(
  Maths::Vector origin, Maths::Vector destination)
{
  auto x0 = origin["x"];
  auto y0 = origin["y"];

  auto x1 = destination["x"];
  auto y1 = destination["y"];

  Gradient gradient {origin, destination};
  auto run = gradient.run();
  auto rise = gradient.rise();
  double yi = 1;

  if (rise < 0) {
    yi = -1;
    rise = 0 - rise;
  }

  double D = (2 * rise) - run;
  double y = y0;

  std::vector<Maths::Vector> plotPoints {};

  for (double x = x0; x <= x1; x++) {
    plotPoints.push_back({x, y});

    if (D > 0) {
      y += yi;
      D += 2 * (rise - run);
    }

    else 
      D += 2 * rise;
  }

  return plotPoints;
}

/* Could merge this and plotLineLow together using Axis as variable. */
std::vector<Maths::Vector> Geometry::LinePlotter::plotHigh(
  Maths::Vector origin, Maths::Vector destination)
{
  auto x0 = origin["x"];
  auto y0 = origin["y"];

  auto x1 = destination["x"];
  auto y1 = destination["y"];

  Gradient gradient {origin, destination};
  auto run = gradient.run();
  auto rise = gradient.rise();
  double xi = 1;

  if (run < 0) {
    xi = -1;
    run = 0 - run;
  }

  double D = (2 * run) - rise;
  double x = x0;

  std::vector<Maths::Vector> plotPoints {};

  for (double y = y0; y <= y1; y++) {
    plotPoints.push_back({x, y});

    if (D > 0) {
      x += xi;
      D += (2 * (run - rise));
    }

    else
      D += 2 * run;
  }

  return plotPoints;
}