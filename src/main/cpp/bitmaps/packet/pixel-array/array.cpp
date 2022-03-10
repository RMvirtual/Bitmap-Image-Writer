#include "src/main/cpp/bitmaps/packet/pixel-array/array.h"
#include "src/main/cpp/bitmaps/formats/colours/colours.h"
#include "src/main/cpp/bitmaps/formats/format/format.h"

Bitmaps::PixelArray::PixelArray()
{
  // pass.
}

Bitmaps::PixelArray::PixelArray(const Bitmaps::Format& format)
{
  this->setFormat(format);
}

void Bitmaps::PixelArray::setFormat(const Bitmaps::Format& format)
{  
  this->pixels = std::make_unique<Matrix2D<Bitmaps::Colours>>(
    format.widthInPixels(), format.heightInPixels(), format.colourNames());
  
  this->_format = format;
}

void Bitmaps::PixelArray::set(const Bitmaps::Colours& colours, int row, int column)
{
  this->pixels->set(colours, row, column);
}

void Bitmaps::PixelArray::set(const Bitmaps::Colours& colours, int index)
{
  this->pixels->set(colours, index);
}

void Bitmaps::PixelArray::fill(const Bitmaps::Colours& colours)
{
  this->pixels->fill(colours); // This call works.
}

std::shared_ptr<Bitmaps::Colours> Bitmaps::PixelArray::at(int row, int column)
{
  auto& pixel = this->pixels->at(row, column);

  return std::make_shared<Bitmaps::Colours>(pixel);
}

std::shared_ptr<Bitmaps::Colours> Bitmaps::PixelArray::at(int index)
{
  auto& colours = this->pixels->at(index);

  return std::make_shared<Bitmaps::Colours>(colours);
}

Bitmaps::Colours Bitmaps::PixelArray::at(int row, int column) const
{
  return this->pixels->at(row, column);
}

Bitmaps::Colours Bitmaps::PixelArray::at(int index) const
{
  return this->pixels->at(index);
}

int Bitmaps::PixelArray::sizeInPixels() const
{
  return this->pixels->width() * this->pixels->height();
}

Bitmaps::Format Bitmaps::PixelArray::format() const
{
  return this->_format;
}