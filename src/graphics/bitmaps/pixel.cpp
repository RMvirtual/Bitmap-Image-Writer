#include "src/graphics/bitmaps/pixel.h"
#include "src/common/byte_array.h"

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