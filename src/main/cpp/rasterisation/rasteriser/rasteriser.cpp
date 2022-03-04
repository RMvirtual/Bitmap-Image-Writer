#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"
#include "src/main/cpp/rasterisation/plotters/line/plotter.h"
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
  std::shared_ptr<Bitmaps::Image> writableImage)
{
  this->image = writableImage;
}

void Rasterisation::Rasteriser::draw(Geometry::Triangle triangle)
{
  auto format = Bitmaps::format("RGB");
  auto blackColours = format.colours();

  blackColours["red"] = 0;
  blackColours["green"] = 0;
  blackColours["blue"] = 0;

  Geometry::LinePlotter plotter;
  auto lines = triangle.toLines();

  for (auto line : lines) {
    // Appears to be flipping the plot point axes for some reason.    
    auto plotPoints = plotter.plot(line);
    
    for (auto point : plotPoints) 
      this->image->setPixel(point["x"], point["y"], blackColours);
  }
}