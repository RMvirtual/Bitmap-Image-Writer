#include <stdexcept>

#include "src/common/byte_array_builder.h"
#include "src/graphics/colours/colours.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"

Pixels::Pixel::Pixel(Colours colours)
{
  this->colours = colours;
}

unsigned char* Pixels::Pixel::toBytes()
{
  ByteArrayBuilder byteArrayBuilder;

  byteArrayBuilder.addValue(this->colours.blue);
  byteArrayBuilder.addValue(this->colours.green);
  byteArrayBuilder.addValue(this->colours.red);

  return byteArrayBuilder.toBytes();
}

void Pixels::Pixel::setColours(Colours colours)
{
  this->colours = colours;
}

void Pixels::Pixel::setRed(uint8_t value)
{
  bool isWithinRange = (value >= 0 && value <= 255);

  if (isWithinRange)
    this->colours.red = value;

  else
    throw std::invalid_argument("Must be between 0 and 255.");
}

void Pixels::Pixel::setGreen(uint8_t value)
{
  this->colours.green = value;
}

void Pixels::Pixel::setBlue(uint8_t value)
{
  this->colours.blue = value;
}

Colours Pixels::Pixel::getColours()
{
  return this->colours;
}

uint8_t Pixels::Pixel::getRed()
{
  return this->colours.red;
}

uint8_t Pixels::Pixel::getGreen()
{
  return this->colours.green;
}

uint8_t Pixels::Pixel::getBlue()
{
  return this->colours.blue;
}