#ifndef PIXEL_ARRAY_READER_H
#define PIXEL_ARRAY_READER_H

#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours/rgb.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel.h"

namespace BitmapReader {
class PixelArrayReader
{
public:
  PixelArrayReader(const PixelArrayReaderConfig& config);
  Pixels::PixelArray <Pixels::Pixel<Pixels::RGBColours>> bytesToRGBPixels(
    const ByteArray& bytes);

private:
  Pixels::PixelArray<Pixels::Pixel<Pixels::RGBColours>> pixelArray;
  BitmapReader::PixelArrayReaderConfig config;
};}

#endif