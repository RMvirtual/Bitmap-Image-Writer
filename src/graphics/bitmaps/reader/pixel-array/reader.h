#ifndef PIXEL_ARRAY_READER_H
#define PIXEL_ARRAY_READER_H

#include "src/graphics/bitmaps/reader/pixel-array/config.h"
#include "src/graphics/bitmaps/packet/pixel-array/array.h"
#include "src/containers/byte-array/byte_array.h"

namespace BitmapReader {
class PixelArrayReader
{
public:
  PixelArrayReader(const PixelArrayConfig& config);
  Pixels::Array toPixelArray(const ByteArray& bytes);

private:
  BitmapReader::PixelArrayConfig config;
};}

#endif