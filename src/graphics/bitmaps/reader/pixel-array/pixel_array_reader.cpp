#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader.h"
#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array_values.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours/rgb_colours.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel.h"

BitmapReader::PixelArrayReader::PixelArrayReader(
  const BitmapReader::PixelArrayReaderConfig& config)
{
  this->config = config;
}

Pixels::PixelArray <Pixels::Pixel<Pixels::RGBColours>>
BitmapReader::PixelArrayReader::bytesToRGBPixels(const ByteArray& bytes)
{
  Pixels::PixelArrayValues<Pixels::Pixel<Pixels::RGBColours>> values {};
  values.heightInPixels = this->config.heightInPixels;
  values.widthInPixels = this->config.widthInPixels;

  this->pixelArray = {values};
  
  int noOfBytes = bytes.size();
  int sizeOfPixel = 3;

  for (int byteNo = 0; byteNo < noOfBytes; byteNo += sizeOfPixel) {
    int endOfPixelByteNo = byteNo + sizeOfPixel;
    ByteArray pixelBytes = bytes.slice(byteNo, endOfPixelByteNo);
    
    Pixels::RGBColours colours {};
    colours.setBlue(pixelBytes[0]);
    colours.setGreen(pixelBytes[1]);
    colours.setRed(pixelBytes[2]);

    Pixels::Pixel pixel {colours};

    int pixelNo = byteNo / sizeOfPixel;
    this->pixelArray.set(pixel, pixelNo);
  }

  return this->pixelArray;
}