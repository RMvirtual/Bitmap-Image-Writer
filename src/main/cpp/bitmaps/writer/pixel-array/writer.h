#pragma once

#include "src/main/cpp/bitmaps/packet/pixel-array/array.h"
#include "src/main/cpp/containers/byte-array/byte_array.h"

namespace Bitmaps {
class PixelArrayWriter
{
public:
  PixelArrayWriter();
  ByteArray write(const Bitmaps::PixelArray& pixelArray);

private:
  ByteArray bytes;
  Format format;
  PixelArray pixelArray;

  void initialise(const Bitmaps::PixelArray& pixelArray);
  void writeRowOfPixels(int rowNo);
  void writePixels(int startIndex, int endIndex);
  void write(const Bitmaps::Colours& pixelColours);
  void addRowPadding();
};}