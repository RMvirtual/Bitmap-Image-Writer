#ifndef BITMAP_PIXEL_ARRAY_WRITER_H
#define BITMAP_PIXEL_ARRAY_WRITER_H

#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/containers/byte-array/byte_array.h"

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

#endif