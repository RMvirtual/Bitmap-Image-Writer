#include "src/main/cpp/geometry/triangle/splitter.h"

Geometry::TriangleSplitter::TriangleSplitter()
{
  // pass.
}

std::pair<Geometry::Triangle, Geometry::Triangle>
Geometry::TriangleSplitter::split(Geometry::Triangle& triangle)
{
  Geometry::Triangle sortedTriangle = {triangle.sortedByX()};
  auto middleVertex = sortedTriangle.middleVertex();
  auto middleInterceptPoint = sortedTriangle.interceptOfMiddleVertex();

  Geometry::Triangle triangle1 = {{
    triangle[0], middleVertex, middleInterceptPoint
  }};

  Geometry::Triangle triangle2 = {{
    middleInterceptPoint, middleVertex, triangle[2] 
  }};

  return {triangle1, triangle2};
}