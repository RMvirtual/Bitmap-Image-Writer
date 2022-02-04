#include "src/containers/byte-array/byte_array.h"
#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/reader/pixel-array/reader.h"

#include <iostream>

Bitmaps::PixelArrayReader::PixelArrayReader(const Bitmaps::Format& format)
{
  this->format = format;
}

Bitmaps::PixelArray Bitmaps::PixelArrayReader::convertBytes(
  const ByteArray& bytes)
{
  Bitmaps::PixelArray pixelArray {this->format};

  int noOfBytes = bytes.size();
  int bytesPerPixel = this->format.pixelSizeInBytes();

  // Spazzes out at this section.

  for (int byteNo = 0; byteNo < noOfBytes; byteNo += bytesPerPixel) {
    int endOfPixelByteNo = byteNo + bytesPerPixel;

    auto pixelBytes = bytes.slice(byteNo, endOfPixelByteNo);
    auto colourNames = this->format.colourNames();
    Bitmaps::Colours colours {colourNames};

    for (int colourNo = 0; colourNo < bytesPerPixel; colourNo++)
      colours[colourNames[colourNo]] = pixelBytes[colourNo];

    int pixelNo = byteNo / bytesPerPixel;
    pixelArray.set(colours, pixelNo);
  }

  return pixelArray;
}