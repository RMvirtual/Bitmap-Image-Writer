#include "src/graphics/bitmaps/reader/pixel-array/reader.h"
#include "src/graphics/bitmaps/reader/pixel-array/config.h"
#include "src/containers/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/formats/format.h"
#include "src/graphics/bitmaps/packet/pixel-array/array.h"

BitmapReader::PixelArrayReader::PixelArrayReader(
  const BitmapReader::PixelArrayConfig& config)
{
  this->config = config;
}

Pixels::Array BitmapReader::PixelArrayReader::toPixelArray(
  const ByteArray& bytes)
{
  Pixels::Array pixelArray {this->config.format};
  
  int noOfBytes = bytes.size();
  int sizeOfPixel = this->config.pixelSizeInBytes;

  for (int byteNo = 0; byteNo < noOfBytes; byteNo += sizeOfPixel) {
    int endOfPixelByteNo = byteNo + sizeOfPixel;

    ByteArray pixelBytes = bytes.slice(byteNo, endOfPixelByteNo);
    
    Pixels::Colours colours {this->config.format.colourNames};

    for (int colourNo = 0; colourNo < sizeOfPixel; colourNo++)
      colours[this->config.format.colourNames[colourNo]] = pixelBytes[colourNo];

    int pixelNo = byteNo / sizeOfPixel;
    pixelArray.set(colours, pixelNo);
  }

  return pixelArray;
}