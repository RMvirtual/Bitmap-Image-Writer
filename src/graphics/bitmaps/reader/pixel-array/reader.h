#ifndef PIXEL_ARRAY_READER_H
#define PIXEL_ARRAY_READER_H

#include "src/containers/byte-array/byte_array.h"
#include "src/graphics/bitmaps/formats/format.h"
#include "src/graphics/bitmaps/packet/pixel-array/array.h"

namespace Bitmaps {
class PixelArrayReader
{
public:
  PixelArrayReader(const Bitmaps::Format& format);
  Bitmaps::PixelArray toPixelArray(const ByteArray& bytes);

private:
  Bitmaps::Format format;
};}

#endif