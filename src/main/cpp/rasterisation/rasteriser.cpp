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
    std::cout << "Line X0: " << line["x0"] << ", y0: " << line["y0"] <<", x1: " << line["x1"] << ", y1: " << line["y1"] << std::endl;
    auto plotPoints = plotter.plot(line);
    
    for (auto point : plotPoints)
      this->image->setPixel(point["x"], point["y"], blackColours);
  }
}