#include "src/bitmaps/formats/pixel/format.h"

Bitmaps::PixelFormat::PixelFormat()
{

}

Bitmaps::Colours Bitmaps::PixelFormat::colours() const
{
  return this->_colours;
}

std::vector<std::string> Bitmaps::PixelFormat::colourNames() const
{
  std::vector<std::string> colourNames;

  for (auto colour : this->_colours)
    colourNames.push_back(colour.first);

  return colourNames;
}

int Bitmaps::PixelFormat::bitsPerPixel() const
{
  return this->_bitsPerPixel;
}

int Bitmaps::PixelFormat::bytesPerPixel() const
{
  return this->_bytesPerPixel;
}

void Bitmaps::PixelFormat::setColourNames(std::vector<std::string> colourNames)
{
  this->_colours = {colourNames};
}

void Bitmaps::PixelFormat::setBitsPerPixel(int bitsPerPixel)
{
  this->_bitsPerPixel = bitsPerPixel;
  this->calculateBytesPerPixel();
}

void Bitmaps::PixelFormat::calculateBytesPerPixel()
{
  this->_bytesPerPixel = this->_bitsPerPixel / 8;
}