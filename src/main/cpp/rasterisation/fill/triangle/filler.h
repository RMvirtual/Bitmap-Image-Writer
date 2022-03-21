#pragma once

#include <vector>
#include "src/main/cpp/geometry/line/mesh.h"
#include "src/main/cpp/geometry/triangle/triangle.h"
#include "src/main/cpp/maths/vector/vector.h"

namespace Rasterisation {
class TriangleFiller
{
public:
  TriangleFiller();
  std::vector<Maths::Vector> fillPoints(const Geometry::Triangle& triangle);
};}