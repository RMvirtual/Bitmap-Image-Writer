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

  if (this->config.pixelFormat == this->config.RGB)
    values.defaultPixel = Pixels::RGBPixel {};

  this->pixelArray = Pixels::PixelArray {values};
  
  // Iterate pixels from the bytes.
  int noOfBytes = bytes.size();
  int sizeOfPixel = 4;

  // Need to transpose straight array of bytes to pixel matrix format.
  for (int byteNo = 0; byteNo < noOfBytes; byteNo += 3) {
    ByteArray pixelBytes = bytes.slice(byteNo, byteNo + sizeOfPixel);
    
    Pixels::RGBColours colours {};
    colours.setBlue(pixelBytes[0].value);
    colours.setGreen(pixelBytes[1].value);
    colours.setRed(pixelBytes[2].value);

    Pixels::RGBPixel pixel {colours};

    this->pixelArray.set(pixel, byteNo / 3);
  }

  return this->pixelArray;
}