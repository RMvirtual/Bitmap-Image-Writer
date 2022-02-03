#include "src/containers/byte-array/byte_array.h"
#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/reader/pixel-array/reader.h"

Bitmaps::PixelArrayReader::PixelArrayReader(const Bitmaps::Format& format)
{
  this->format = format;
}

Bitmaps::PixelArray Bitmaps::PixelArrayReader::toPixelArray(
  const ByteArray& bytes)
{
  Bitmaps::PixelArray pixelArray {this->format};
  
  int noOfBytes = bytes.size();
  int sizeOfPixel = this->format.pixelSizeInBytes();

  for (int byteNo = 0; byteNo < noOfBytes; byteNo += sizeOfPixel) {
    int endOfPixelByteNo = byteNo + sizeOfPixel;

    auto pixelBytes = bytes.slice(byteNo, endOfPixelByteNo);
    auto colourNames = this->format.colourNames();
    Bitmaps::Colours colours {colourNames};

    for (int colourNo = 0; colourNo < sizeOfPixel; colourNo++)
      colours[colourNames[colourNo]] = pixelBytes[colourNo];

    int pixelNo = byteNo / sizeOfPixel;
    pixelArray.set(colours, pixelNo);
  }

  return pixelArray;
}