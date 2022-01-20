#ifndef PIXEL_ARRAY_READER_H
#define PIXEL_ARRAY_READER_H

#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel_array.h"
#include "src/common/byte-array/byte_array.h"

namespace BitmapReader {
class PixelArrayReader
{
public:
  PixelArrayReader(const PixelArrayReaderConfig& config);
  Pixels::RGBPixelArray convertBytesToRGBPixels(const ByteArray& bytes);

private:
  Pixels::RGBPixelArray pixelArray;
  BitmapReader::PixelArrayReaderConfig config;
};}

#endif