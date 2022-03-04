#pragma once

#include <memory>
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/main/cpp/geometry/triangle/triangle.h"

namespace Rasterisation {
class Rasteriser
{
public:
  Rasteriser();
  Rasteriser(std::shared_ptr<Bitmaps::Image> writableImage);

  void setWritableImage(std::shared_ptr<Bitmaps::Image> writableImage);
  void draw(Geometry::Triangle triangle);

private:
  std::shared_ptr<Bitmaps::Image> image;
};}