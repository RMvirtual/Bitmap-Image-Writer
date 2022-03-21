#include "src/main/cpp/rasterisation/fill/triangle/filler.h"
#include "src/main/cpp/rasterisation/plotters/triangle/plotter.h"

#include <iostream>

Rasterisation::TriangleFiller::TriangleFiller()
{
  // pass.
}

std::vector<Maths::Vector> Rasterisation::TriangleFiller::fillPoints(
  const Geometry::Triangle& triangle)
{
  Rasterisation::TrianglePlotter trianglePlotter;
  auto outline = trianglePlotter.plotToLineMesh(triangle);

  return {{0.0, 0.0}};
}