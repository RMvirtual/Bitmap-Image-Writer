#pragma once

#include "src/main/cpp/geometry/line/mesh.h"
#include "src/main/cpp/geometry/triangle/triangle.h"

namespace Rasterisation {
class TrianglePlotter
{
public:
  TrianglePlotter();
  Geometry::LineMesh plotToLineMesh(const Geometry::Triangle& triangle);
};}