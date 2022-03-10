#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"
#include "src/main/cpp/rasterisation/plotters/line/plotter.h"
#include "src/main/cpp/bitmaps/formats/formats.h"

Rasterisation::Rasteriser::Rasteriser(
  std::shared_ptr<Bitmaps::Image> writableImage)
{
  this->image = writableImage;

  auto format = Bitmaps::format("RGB24");
  this->lineColour = std::make_shared<Bitmaps::Colours>(format.colours());

  this->lineColour->set("red", 0);
  this->lineColour->set("green", 0);
  this->lineColour->set("blue", 0);
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
  Geometry::LinePlotter plotter;
  auto plotPoints = plotter.plot(line);
  
  for (auto& point : plotPoints) {
    auto& pixelColumn = point["x"];
    auto& pixelRow = point["y"];

    this->image->setPixel(pixelRow, pixelColumn, *this->lineColour);
  }
}

void Rasterisation::Rasteriser::draw(const Geometry::Triangle& triangle)
{
  this->draw(triangle.toLines());
}