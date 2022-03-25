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
  this->recursivelyFill(triangle);

  return this->_fillPoints;
}

void Rasterisation::TriangleFiller::recursivelyFill(
  Geometry::Triangle& triangle)
{
  if (!triangle.hasFlatHorizontalEdge()) {
    auto triangles = triangle.split();
    this->recursivelyFill(triangles.first);
    this->recursivelyFill(triangles.second);
  }

  else {
    Geometry::Edge* edge1;
    Geometry::Edge* edge2;

    if (triangle.hasFlatHorizontalEastEdge()) {    
      *edge1 = triangle.edge("x1", "x2");
      *edge2 = triangle.edge("x1", "x3");

      auto edge1Slope = edge1->slope();
      auto edge2Slope = edge2->slope();

      auto edge1Gradient = edge1Slope.gradient();
      auto edge2Gradient = edge2Slope.gradient();

      auto xLowerBound = triangle.xLowerBound();
      auto xUpperBound = triangle.xUpperBound();

      double yLowerBound = edge1Slope.yLowerBound();
      double yUpperBound = edge2Slope.yUpperBound();

      if (edge1Slope.yUpperBound() > edge2Slope.yUpperBound()) {
        yLowerBound = edge2Slope.yLowerBound();
        yUpperBound = edge1Slope.yUpperBound();
      }
    }

    else if (triangle.hasFlatHorizontalWestEdge()) {
      *edge1 = triangle.edge("x1", "x3");
      *edge2 = triangle.edge("x2", "x3");

      auto edge1Slope = edge1->slope();
      auto edge2Slope = edge2->slope();
    }
  }
}