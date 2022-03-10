#pragma once

#include <memory>
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/main/cpp/geometry/line/line.h"
#include "src/main/cpp/geometry/triangle/triangle.h"
#include "src/main/cpp/geometry/line/mesh.h"
#include "src/main/cpp/text/2d/textbox/text.h"
#include "src/main/cpp/text/2d/letter/letter.h"

namespace Rasterisation {
class Rasteriser
{
public:
  Rasteriser(std::shared_ptr<Bitmaps::Image> writableImage);

  void draw(const Geometry::Line& line);
  void draw(const Geometry::LineMesh& lineMesh);
  void draw(const Text::Text2D& text);
  void draw(const Text::Letter& letter);
  void draw(const Geometry::Triangle& triangle);
  
private:
  std::shared_ptr<Bitmaps::Image> image;
};}