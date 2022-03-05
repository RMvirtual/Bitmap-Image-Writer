#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"
#include "src/main/cpp/rasterisation/plotters/line/plotter.h"
#include "src/main/cpp/bitmaps/formats/formats.h"

#include <iostream>

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

void Rasterisation::Rasteriser::draw(std::vector<Geometry::Line> lines)
{
  std::cout << "Gets here.\n";

  auto format = Bitmaps::format("RGB");
  auto blackColours = format.colours();

  blackColours["red"] = 0;
  blackColours["green"] = 0;
  blackColours["blue"] = 0;

  Geometry::LinePlotter plotter;

  for (auto line : lines) {
    auto plotPoints = plotter.plot(line);
    
    for (auto point : plotPoints)
      this->image->setPixel(point["x"], point["y"], blackColours);
  }
}

void Rasterisation::Rasteriser::draw(Geometry::Triangle triangle)
{
  this->draw(triangle.toLines());
}