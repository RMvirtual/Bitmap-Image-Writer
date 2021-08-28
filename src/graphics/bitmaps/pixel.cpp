#include "src/graphics/bitmaps/pixel.h"
#include "src/common/byte_array.h"
#include <stdexcept>

Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue)
{
  this->red = red;
  this->green = green;
  this->blue = blue;
}

char* Pixel::toBytes()
{
  ByteArrayBuilder byteArrayBuilder;

  byteArrayBuilder.addValue(this->blue);
  byteArrayBuilder.addValue(this->green);
  byteArrayBuilder.addValue(this->red);

  char* byteArray = byteArrayBuilder.toBytes();

  return byteArray;
}

void Pixel::setRed(uint8_t value)
{
  bool isWithinRange = (value >= 0 && value <= 255);

  if (isWithinRange)
    this->red = value;

  else
    throw std::invalid_argument("Must be between 0 and 255.");
}

void Pixel::setGreen(uint8_t value)
{
  this->green = value;
}

void Pixel::setBlue(uint8_t value)
{
  this->blue = value;
}

uint8_t Pixel::getRed()
{
  return this->red;
}

uint8_t Pixel::getGreen()
{
  return this->green;
}

uint8_t Pixel::getBlue()
{
  return this->blue;
}