#pragma once

#include <utility>
#include "src/main/cpp/geometry/triangle/triangle.h"

namespace Geometry {
class TriangleSplitter
{
public:
  TriangleSplitter();
  
  std::pair<Geometry::Triangle, Geometry::Triangle> split(
    const Geometry::Triangle& triangle);
};}