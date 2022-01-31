#include "src/graphics/bitmaps/packet/pixel-array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours.h"
#include "src/graphics/bitmaps/formats/format.h"

Pixels::Array::Array()
{
  // pass.
}

Pixels::Array::Array(const Pixels::Format& format)
{
  this->setFormat(format);
}

void Pixels::Array::set(const Pixels::Colours& colours, int row, int column)
{
  this->pixels.set(colours, row, column);
}

void Pixels::Array::set(const Pixels::Colours& colours, int index)
{
  this->pixels.set(colours, index);
}

void Pixels::Array::fill(const Pixels::Colours& colours)
{
  this->pixels.fill(colours);
}

Pixels::Colours& Pixels::Array::at(int row, int column)
{
  return this->pixels.at(row, column);
}

Pixels::Colours& Pixels::Array::at(int index)
{
  return this->pixels.at(index);
}

Pixels::Colours Pixels::Array::at(int row, int column) const
{
  return this->pixels.at(row, column);
}

Pixels::Colours Pixels::Array::at(int index) const
{
  return this->pixels.at(index);
}

int Pixels::Array::sizeInPixels() const
{
  return this->pixels.width() * this->pixels.height();
}

void Pixels::Array::setFormat(const Pixels::Format& format)
{  
  this->pixels = {
    format.widthInPixels(), format.heightInPixels(), {format.colourNames()}};
  
  this->_format = format;
}

Pixels::Format Pixels::Array::format() const
{
  return this->_format;
}