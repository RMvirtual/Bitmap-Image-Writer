#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader.h"
#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/array/values.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/format.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/array/array.h"

BitmapReader::PixelArrayReader::PixelArrayReader(
  const BitmapReader::PixelArrayReaderConfig& config)
{
  this->config = config;
}

Pixels::Array BitmapReader::PixelArrayReader::toPixelArray(
  const ByteArray& bytes)
{
  Pixels::ArrayValues values {};
  values.heightInPixels = this->config.heightInPixels;
  values.widthInPixels = this->config.widthInPixels;

  Pixels::Array pixelArray = {values};
  
  int noOfBytes = bytes.size();
  int sizeOfPixel = this->config.pixelSizeInBytes;

  for (int byteNo = 0; byteNo < noOfBytes; byteNo += sizeOfPixel) {
    int endOfPixelByteNo = byteNo + sizeOfPixel;
    ByteArray pixelBytes = bytes.slice(byteNo, endOfPixelByteNo);
    
    Pixels::Colours colours {};
    colours["blue"] = pixelBytes[0];
    colours["green"] = pixelBytes[1];
    colours["red"] = pixelBytes[2];

    Pixels::Format format {};
    format.name = "RGB";
    format.colourNames = {"blue", "green", "red"};
    format.bitsPerPixel = 24;

    int pixelNo = byteNo / sizeOfPixel;
    pixelArray.set({format}, pixelNo);
  }

  return pixelArray;
}