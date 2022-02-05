#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/formats/colours/colours.h"
#include "src/bitmaps/formats/bitmap/format.h"

Bitmaps::PixelArray::PixelArray()
{
  // pass.
}

Bitmaps::PixelArray::PixelArray(const Bitmaps::Format& format)
{
  this->setFormat(format);
}

void Bitmaps::PixelArray::set(const Bitmaps::Colours& colours, int row, int column)
{
  this->pixels.set(colours, row, column);
}

void Bitmaps::PixelArray::set(const Bitmaps::Colours& colours, int index)
{
  this->pixels.set(colours, index);
}

void Bitmaps::PixelArray::fill(const Bitmaps::Colours& colours)
{
  this->pixels.fill(colours);
}

Bitmaps::Colours& Bitmaps::PixelArray::at(int row, int column)
{
  return this->pixels.at(row, column);
}

Bitmaps::Colours& Bitmaps::PixelArray::at(int index)
{
  return this->pixels.at(index);
}

Bitmaps::Colours Bitmaps::PixelArray::at(int row, int column) const
{
  return this->pixels.at(row, column);
}

Bitmaps::Colours Bitmaps::PixelArray::at(int index) const
{
  return this->pixels.at(index);
}

int Bitmaps::PixelArray::sizeInPixels() const
{
  return this->pixels.width() * this->pixels.height();
}

void Bitmaps::PixelArray::setFormat(const Bitmaps::Format& format)
{  
  this->pixels = {
    format.widthInPixels(), format.heightInPixels(), {format.colourNames()}};
  
  this->_format = format;
}

Bitmaps::Format Bitmaps::PixelArray::format() const
{
  return this->_format;
}