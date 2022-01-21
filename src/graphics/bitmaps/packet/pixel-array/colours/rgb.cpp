#include <cstdint>
#include <stdexcept>

#include "src/graphics/bitmaps/packet/pixel-array/colours/rgb.h"

Pixels::RGBColours::RGBColours()
{
  this->_red = 0;
  this->_green = 0;
  this->_blue = 0;
}

void Pixels::RGBColours::setRed(uint8_t value)
{
  bool isWithinRange = (value >= 0 && value <= 255);

  if (isWithinRange)
    this->_red = value;

  else
    throw std::invalid_argument("Must be between 0 and 255.");
}

void Pixels::RGBColours::setGreen(uint8_t value)
{
  this->_green = value;
}

void Pixels::RGBColours::setBlue(uint8_t value)
{
  this->_blue = value;
}

uint8_t Pixels::RGBColours::red() const
{
  return this->_red;
}

uint8_t Pixels::RGBColours::green() const
{
  return this->_green;
}

uint8_t Pixels::RGBColours::blue() const
{
  return this->_blue;
}