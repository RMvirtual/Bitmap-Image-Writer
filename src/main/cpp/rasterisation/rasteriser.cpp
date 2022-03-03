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

  // 3rd line drawing incorrectly (right to left drawing issue flipping the axis?)
  // x0: 400, y0: 200.
  // x1: 200, y1: 200


  for (auto line : lines) {
    std::cout <<
      "Line\n" <<
      "x0: " << line["x0"] << ", y0: " << line["y0"] << "\n" <<
      "x1: " << line["x1"] << ", y1: " << line["y1"] << "\n\n";

    // Appears to be flipping the plot point axes for some reason.    
    auto plotPoints = plotter.plot(line);
    
    for (auto point : plotPoints) {
      std:: cout << "Point x: " << point["x"] << ", y: " << point["y"] << std::endl;
      this->image->setPixel(point["x"], point["y"], blackColours);
    }
  }
}