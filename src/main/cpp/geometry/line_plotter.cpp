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
  line.normaliseEndpoints();
  this->plotGeneric(line);

  /*
  if (line.isHorizontallySloped()) 
    this->plotLow(line);
  
  else
    this->plotHigh(line);
  */
}

/**
 * @brief Uses the x axis as its basis and intermittently increases y.
 * 
 * @param line 
 */
void Geometry::LinePlotter::plotLow(Geometry::Line line)
{
  auto run = line.run();
  auto rise = line.rise();
  double yIncrease = 1;

  if (rise < 0) {
    yIncrease = -1;
    rise = 0 - rise;
  }

  double D = (2 * rise) - run;

  auto x1 = line.destination()["x"];
  double y = line.origin()["y"];

  for (double x = line.origin()["x"]; x <= x1; x++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      y += yIncrease;
      D += 2 * (rise - run);
    }

    else 
      D += 2 * rise;
  }
}

/**
 * @brief Uses the y axis as its basis and intermittently increases x.
 * 
 * @param line 
 */
void Geometry::LinePlotter::plotHigh(Geometry::Line line)
{
  auto run = line.run();
  auto rise = line.rise();
  double xIncrease = 1;

  if (run < 0) {
    xIncrease = -1;
    run = 0 - run;
  }

  double D = (2 * run) - rise;

  double x = line.origin()["x"];
  auto const y1 = line.destination()["y"];
  
  for (double y = line.origin()["y"]; y <= y1; y++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      x += xIncrease;
      D += (2 * (run - rise));
    }

    else
      D += 2 * run;
  }
}

void Geometry::LinePlotter::plotGeneric(Geometry::Line line)
{
  std::string constantAxis = "x";
  std::string variableAxis = "y";

  auto run = line.run();
  auto rise = line.rise();

  bool shouldTiltAxis = line.isVerticallySloped();

  if (shouldTiltAxis) {
    constantAxis = "y";
    variableAxis = "x";

    run = line.rise();
    rise = line.run();
  }

  double variableAxisIncrease = 1;

  if (rise < 0) {
    variableAxisIncrease = -1;
    rise = 0 - rise;
  }

  double D = (2 * rise) - run;

  double x = line.origin()[constantAxis];
  auto x1 = line.destination()[constantAxis];
  double y = line.origin()[variableAxis];

  for (; x <= x1; x++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      y += variableAxisIncrease;
      D += 2 * (rise - run);
    }

    else 
      D += 2 * rise;
  }
}