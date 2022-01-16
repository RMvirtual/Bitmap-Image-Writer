#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader.h"
#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array_values.h"

BitmapReader::PixelArrayReader::PixelArrayReader(
  const BitmapReader::PixelArrayReaderConfig& config)
{
  this->config = config;
}

Pixels::PixelArray BitmapReader::PixelArrayReader::convertBytes(
  const ByteArray& bytes)
{
  Pixels::PixelArrayValues values {};
  values.heightInPixels = this->config.heightInPixels;
  values.widthInPixels = this->config.widthInPixels;

  if (this->config.pixelFormat == this->config.RGB)
    values.defaultPixel = Pixels::RGBPixel {};

  this->pixelArray = Pixels::PixelArray {values};
  
  int noOfBytes = bytes.size();
  int sizeOfPixel = 3;

  for (int byteNo = 0; byteNo < noOfBytes; byteNo += sizeOfPixel) {
    int endOfPixelByteNo = byteNo + sizeOfPixel;
    ByteArray pixelBytes = bytes.slice(byteNo, endOfPixelByteNo);
    
    Pixels::RGBColours colours {};
    colours.setBlue(pixelBytes[0].value);
    colours.setGreen(pixelBytes[1].value);
    colours.setRed(pixelBytes[2].value);

    Pixels::RGBPixel pixel {colours};

    int pixelNo = byteNo / sizeOfPixel;
    this->pixelArray.set(pixel, pixelNo);
  }

  return this->pixelArray;
}