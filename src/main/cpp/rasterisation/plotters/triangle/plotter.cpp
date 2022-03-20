#include "src/main/cpp/rasterisation/plotters/triangle/plotter.h"
#include "src/main/cpp/rasterisation/plotters/line/plotter.h"

Rasterisation::TrianglePlotter::TrianglePlotter()
{
  // pass.
}

Geometry::LineMesh Rasterisation::TrianglePlotter::plotToLineMesh(
  const Geometry::Triangle& triangle)
{
  std::vector<Geometry::Line> lines {};
  int noOfVertices = 3;

  for (int i = 0; i < noOfVertices - 1; i++) {
    auto& vertex1 = triangle[i];
    auto& vertex2 = triangle[i+1];

    lines.push_back({{vertex1}, {vertex2}});
  }

  auto& originVertex = triangle[0];
  auto& lastVertex = triangle[noOfVertices-1];

  lines.push_back({{lastVertex}, {originVertex}});

  return {lines};
}