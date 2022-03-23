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
  if (triangle.shouldSplit()) {
    auto triangles = triangle.split();
    this->recursivelyFill(triangles.first);
    this->recursivelyFill(triangles.second);
  }

  else {
    // Determine top and bottom y edges.
    auto edges = triangle.edges();

    auto topEdge = edges[0];
    auto bottomEdge = edges[0];

    for (auto edge : edges) {
      if (edge.yLowerBound() < bottomEdge.yLowerBound())
        bottomEdge = edge;

      if (edge.yUpperBound() > topEdge.yUpperBound())
        topEdge = edge;
    }

    auto topSlope = topEdge.slope();
    auto bottomSlope = bottomEdge.slope();

    std::cout << "Top slope: " << topSlope.toString() << std::endl;
    std::cout << "Bottom slope: " << bottomSlope.toString() << std::endl;


    auto constantEdge = edges[0];
    auto constantSlope = constantEdge.slope();

    auto xStart = constantEdge.xLowerBound();
    auto xEnd = constantEdge.xUpperBound();

    for (auto x = xStart; x < xEnd; x++) {
      auto yLowerBound = constantEdge[0]["y"] + bottomSlope.gradient() * x;
      auto yUpperBound = constantEdge[0]["y"] + topSlope.gradient() * x;
  
      for (auto y = yLowerBound; y < yUpperBound; y++) {
        this->_fillPoints.push_back({x, y});
      }
    }
  }
}