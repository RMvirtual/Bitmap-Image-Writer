#include "src/main/cpp/geometry/triangle/splitter.h"

Geometry::TriangleSplitter::TriangleSplitter()
{
  // pass.
}

std::pair<Geometry::Triangle, Geometry::Triangle>
Geometry::TriangleSplitter::split(Geometry::Triangle& triangle)
{
  auto middleVertex = triangle.middleVertex();

  Geometry::Triangle dummyTriangle1 = {{
    {0.0, 0.0}, {3, 6}, {6, 0.0} 
  }};

  Geometry::Triangle dummyTriangle2 = {{
    {0.0, 0.0}, {3, 6}, {6, 0.0} 
  }};

  return {dummyTriangle1, dummyTriangle2};
}