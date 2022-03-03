#include "src/main/cpp/rasterisation/rasteriser.h"
#include "src/main/cpp/geometry/plotters/line/plotter.h"

Rasterisation::Rasteriser::Rasteriser()
{
  // pass.
}

Rasterisation::Rasteriser::Rasteriser(
  std::shared_ptr<Bitmaps::Image> writableImage)
{
  this->image = writableImage;
}

void Rasterisation::Rasteriser::setWritableImage(
  std::shared_ptr<Bitmaps::Image> writableImage)
{
  this->image = writableImage;
}

void Rasterisation::Rasteriser::draw(Geometry::Triangle triangle)
{
  double startPoint = 10;

  Geometry::LinePlotter plotter;

  // Need to convert vertices to lines.
  
}

