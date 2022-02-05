#ifndef PIXEL_ARRAY_BYTE_WRITER_H
#define PIXEL_ARRAY_BYTE_WRITER_H

#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/containers/byte-array/byte_array.h"

namespace Bitmaps {
class PixelArrayByteWriter
{
public:
  PixelArrayByteWriter();
  ByteArray write(const Bitmaps::PixelArray& pixelArray);

private:
  ByteArray byteAccumulator;
  Format format;
  PixelArray pixelArray;

  void writeRowOfPixels(int rowNo);
  void writePixels(int startIndex, int endIndex);
  void write(const Bitmaps::Colours& pixelColours);
  void addRowPadding();
};}

#endif