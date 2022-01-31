#include "src/containers/byte-array/byte_array.h"
#include "src/graphics/bitmaps/formats/format.h"
#include "src/graphics/bitmaps/packet/pixel-array/array.h"
#include "src/graphics/bitmaps/reader/pixel-array/reader.h"

BitmapReader::PixelArrayReader::PixelArrayReader(const Pixels::Format& format)
{
  this->format = format;
}

Pixels::Array BitmapReader::PixelArrayReader::toPixelArray(
  const ByteArray& bytes)
{
  Pixels::Array pixelArray {this->format};
  
  int noOfBytes = bytes.size();
  int sizeOfPixel = this->format.pixelSizeInBytes();

  for (int byteNo = 0; byteNo < noOfBytes; byteNo += sizeOfPixel) {
    int endOfPixelByteNo = byteNo + sizeOfPixel;

    auto pixelBytes = bytes.slice(byteNo, endOfPixelByteNo);
    auto colourNames = this->format.colourNames();
    Pixels::Colours colours {colourNames};

    for (int colourNo = 0; colourNo < sizeOfPixel; colourNo++)
      colours[colourNames[colourNo]] = pixelBytes[colourNo];

    int pixelNo = byteNo / sizeOfPixel;
    pixelArray.set(colours, pixelNo);
  }

  return pixelArray;
}