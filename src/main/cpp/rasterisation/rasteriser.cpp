#include "src/main/cpp/rasterisation/rasteriser.h"
#include "src/main/cpp/geometry/plotters/line/plotter.h"
#include "src/main/cpp/bitmaps/formats/formats.h"

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
  std::shared_ptr<Bitmaps::Image>& writableImage)
{
  this->image = writableImage;
}

void Rasterisation::Rasteriser::draw(Geometry::Triangle triangle)
{
  double startPoint = 10;
  auto format = Bitmaps::format("RGB");
  auto blackColours = format.colours();

  blackColours["red"] = 0;
  blackColours["green"] = 0;
  blackColours["blue"] = 0;

  Geometry::LinePlotter plotter;
  triangle.translate({200, 200});
  auto lines = triangle.toLines();

  for (auto line : lines) {
    auto plotPoints = plotter.plot(line);
    
    for (auto point : plotPoints)
      this->image.get()->setPixel(point["x"], point["y"], blackColours);
  }
}