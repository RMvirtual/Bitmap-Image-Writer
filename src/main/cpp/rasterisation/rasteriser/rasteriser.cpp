#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"
#include "src/main/cpp/rasterisation/plotters/line/plotter.h"
#include "src/main/cpp/bitmaps/formats/formats.h"

Rasterisation::Rasteriser::Rasteriser(
  std::shared_ptr<Bitmaps::Image> writableImage)
{
  this->image = writableImage;
}

void Rasterisation::Rasteriser::draw(const Text::Text2D& text)
{
  for (auto& letter : text) {
    this->draw(letter);
  }
}

void Rasterisation::Rasteriser::draw(const Text::Letter& letter)
{
  for (auto& line : letter)
    this->draw(line);
}

void Rasterisation::Rasteriser::draw(const Geometry::LineMesh& lineMesh)
{
  for (auto& line: lineMesh)
    this->draw(line);
}

void Rasterisation::Rasteriser::draw(const Geometry::Line& line)
{
  auto format = Bitmaps::format("RGB24");
  auto blackColours = format.colours();

  blackColours["red"] = 0;
  blackColours["green"] = 0;
  blackColours["blue"] = 0;

  Geometry::LinePlotter plotter;
  auto plotPoints = plotter.plot(line);
  
  for (auto& point : plotPoints) {
    auto& pixelColumn = point["x"];
    auto& pixelRow = point["y"];

    this->image->setPixel(pixelRow, pixelColumn, blackColours);
  }
}

void Rasterisation::Rasteriser::draw(const Geometry::Triangle& triangle)
{
  this->draw(triangle.toLines());
}