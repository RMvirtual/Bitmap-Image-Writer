#include "src/graphics/bitmaps/packet/pixel-array/array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/array/values.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/pixel.h"

Pixels::Array::Array()
{
  // pass.
}

Pixels::Array::Array(const Pixels::ArrayValues& values)
{
  this->_format = values.pixelFormat;
  Pixels::Colours defaultColours = {this->_format.colourNames};

  this->pixels = {
    values.widthInPixels, values.heightInPixels, defaultColours};
}

void Pixels::Array::set(const Pixels::Pixel& pixel, int rowNo, int columnNo)
{
  this->pixels.set(pixel, rowNo, columnNo);
}

void Pixels::Array::set(const Pixels::Pixel& pixel, int indexNo)
{
  this->pixels.set(pixel, indexNo);
}

void Pixels::Array::fill(const Pixels::Colours& colours)
{
  // Need matrix traversal fixing to complete this method.
}

Pixels::Pixel Pixels::Array::at(int rowNo, int columnNo) const
{
  return this->pixels.at(rowNo, columnNo);
}

Pixels::Pixel Pixels::Array::at(int indexNo) const
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
