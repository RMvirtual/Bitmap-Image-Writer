#ifndef PIXEL_ARRAY_READER_H
#define PIXEL_ARRAY_READER_H

#include "src/main/cpp/containers/byte-array/byte_array.h"
#include "src/main/cpp/bitmaps/formats/format/format.h"
#include "src/main/cpp/bitmaps/packet/pixel-array/array.h"

namespace Bitmaps {
class PixelArrayReader
{
public:
  PixelArrayReader(const Bitmaps::Format& format);

  Bitmaps::PixelArray convertBytes(const ByteArray& bytes);
  void initialise(const ByteArray& bytes);
  void readRowOfPixels(int rowNo);
  void readPixels(int startIndex, int endIndex, int pixelRowNo);
  Bitmaps::Colours readColours(int index);

private:
  Bitmaps::Format format;
  Bitmaps::PixelArray pixelArray;
  ByteArray bytes;
};}

#endif