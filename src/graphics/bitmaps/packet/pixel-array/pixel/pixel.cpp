#include "src/graphics/bitmaps/packet/pixel-array/pixel/pixel.h"

Pixels::Pixel::Pixel()
{

}

Pixels::Pixel::Pixel(const Format& format)
{
  this->setFormat(format);
}
  
void Pixels::Pixel::setFormat(const Format& format)
{
  this->_format = format;
}

Pixels::Format Pixels::Pixel::format() const
{
  return this->_format;
}

Pixels::Colours Pixels::Pixel::colours() const
{
  return this->_colours;
}

void Pixels::Pixel::setColour(std::string colourName, int value)
{
  this->_colours[colourName] = value;
}

void Pixels::Pixel::setColours(Pixels::Colours colours)
{
  this->_colours = colours;
}

int& Pixels::Pixel::operator [](std::string colourName)
{
  return this->_colours[colourName];
}