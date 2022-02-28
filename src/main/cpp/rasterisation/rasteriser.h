#pragma once

#include "src/main/cpp/bitmaps/image/image.h"
#include "src/main/cpp/geometry/triangle/triangle.h"

namespace Rasterisation {
class Rasteriser
{
public:
  Rasteriser();

  void draw(Geometry::Triangle triangle);

private:
  Bitmaps::Image image;

};}