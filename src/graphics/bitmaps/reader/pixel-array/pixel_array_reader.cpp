#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader.h"
#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array_values.h"

PixelArrayReader::PixelArrayReader(PixelArrayReaderConfiguration config)
{
  this->config = config;
}

Pixels::PixelArray PixelArrayReader::convertBytes(ByteArray& bytes)
{
  Pixels::PixelArrayValues values {};
  values.heightInPixels = this->config.heightInPixels;
  values.widthInPixels = this->config.widthInPixels;
  values.defaultPixel = Pixels::RGBPixel {};

  this->pixelArray = Pixels::PixelArray {values};
  
  return this->pixelArray;
}