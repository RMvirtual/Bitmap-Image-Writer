#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader.h"
#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel_array_values.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/colours.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel_array.h"

template <class PixelArrayType>
BitmapReader::PixelArrayReader <class PixelArrayType>
::PixelArrayReader(const BitmapReader::PixelArrayReaderConfig& config)
{
  this->config = config;
}

template <class PixelArrayType>
PixelArrayType BitmapReader::PixelArrayReader <class PixelArrayType>
::toPixelArray(const ByteArray& bytes)
{
  Pixels::RGBPixelArrayValues values {};
  values.heightInPixels = this->config.heightInPixels;
  values.widthInPixels = this->config.widthInPixels;

  PixelArrayType pixelArray = {values};
  
  int noOfBytes = bytes.size();
  int sizeOfPixel = this->config.pixelSizeInBytes;

  for (int byteNo = 0; byteNo < noOfBytes; byteNo += sizeOfPixel) {
    int endOfPixelByteNo = byteNo + sizeOfPixel;
    ByteArray pixelBytes = bytes.slice(byteNo, endOfPixelByteNo);
    
    Pixels::RGBAColours colours {};
    colours.blue = pixelBytes[0];
    colours.green = pixelBytes[1];
    colours.red = pixelBytes[2];

    int pixelNo = byteNo / sizeOfPixel;
    this->pixelArray.set({colours}, pixelNo);
  }

  return this->pixelArray;
}