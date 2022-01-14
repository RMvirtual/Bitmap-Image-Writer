#include <cstdint>
#include <stdexcept>

#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgb_colours.h"

Pixels::RGBColours::RGBColours()
{
  this->red = 0;
  this->green = 0;
  this->blue = 0;
}

void Pixels::RGBColours::setRed(uint8_t value)
{
  bool isWithinRange = (value >= 0 && value <= 255);

  if (isWithinRange)
    this->red = value;

  else
    throw std::invalid_argument("Must be between 0 and 255.");
}

void Pixels::RGBColours::setGreen(uint8_t value)
{
  this->green = value;
}

void Pixels::RGBColours::setBlue(uint8_t value)
{
  this->blue = value;
}

uint8_t Pixels::RGBColours::getRed()
{
  return this->red;
}

uint8_t Pixels::RGBColours::getGreen()
{
  return this->green;
}

uint8_t Pixels::RGBColours::getBlue()
{
  return this->blue;
}