#include "src/main/cpp/rasterisation/fill/triangle/filler.h"
#include "src/main/cpp/rasterisation/plotters/triangle/plotter.h"

#include <iostream>

Rasterisation::TriangleFiller::TriangleFiller()
{
  // pass.
}

std::vector<Maths::Vector> Rasterisation::TriangleFiller::fillPoints(
  Geometry::Triangle& triangle)
{
  this->_fillPoints.clear();

  if (triangle.shouldSplit()) {
    auto triangles = triangle.split();
    this->fillPoints(triangles.first);
    this->fillPoints(triangles.second);
  }

  else {
    auto xDistance = triangle["x2"] - triangle["x1"];
    
  }

  return {{0.0, 0.0}};
}