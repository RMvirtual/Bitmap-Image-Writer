#include "src/graphics/bitmaps/packet/pixel-array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours.h"
#include "src/graphics/bitmaps/packet/formats/format.h"

Pixels::Array::Array()
{
  // pass.
}

Pixels::Array::Array(const Pixels::Format& format)
{
  Pixels::Colours defaultColours {format.colourNames};
  this->pixels = {format.widthInPixels, format.heightInPixels, defaultColours};
  this->_format = format;
}

void Pixels::Array::set(
  const Pixels::Colours& colours, int rowNo, int columnNo)
{
  this->pixels.set(colours, rowNo, columnNo);
}

void Pixels::Array::set(const Pixels::Colours& colours, int indexNo)
{
  this->pixels.set(colours, indexNo);
}

void Pixels::Array::fill(const Pixels::Colours& colours)
{
  this->pixels.fill(colours);
}

Pixels::Colours& Pixels::Array::at(int rowNo, int columnNo)
{
  return this->pixels.at(rowNo, columnNo);
}

Pixels::Colours& Pixels::Array::at(int indexNo)
{
  return this->pixels.at(indexNo);
}

Pixels::Colours Pixels::Array::at(int rowNo, int columnNo) const
{
  return this->pixels.at(rowNo, columnNo);
}

Pixels::Colours Pixels::Array::at(int indexNo) const
{
  return this->pixels.at(indexNo);
}

int Pixels::Array::sizeInPixels() const
{
  return this->pixels.width() * this->pixels.height();
}

void Pixels::Array::setFormat(const Pixels::Format& format)
{
  this->_format = format;
}

Pixels::Format Pixels::Array::format() const
{
  return this->_format;
}