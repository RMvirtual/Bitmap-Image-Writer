#ifndef PIXEL_ARRAY_READER_H
#define PIXEL_ARRAY_READER_H

#include "src/containers/byte-array/byte_array.h"
#include "src/graphics/bitmaps/formats/format.h"
#include "src/graphics/bitmaps/packet/pixel-array/array.h"

namespace BitmapReader {
class PixelArrayReader
{
public:
  PixelArrayReader(const Pixels::Format& format);
  Pixels::Array toPixelArray(const ByteArray& bytes);

private:
  Pixels::Format format;
};}

#endif