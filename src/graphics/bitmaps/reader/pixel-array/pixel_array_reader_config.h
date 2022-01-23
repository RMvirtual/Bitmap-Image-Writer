#ifndef PIXEL_ARRAY_READER_CONFIG_H
#define PIXEL_ARRAY_READER_CONFIG_H

#include "src/graphics/bitmaps/packet/headers/bitmap_headers.h"

namespace BitmapReader {
struct PixelArrayReaderConfig
{
  static PixelArrayReaderConfig fromHeaders(
    const BitmapHeaders::Headers& headers);

  enum {RGB, RGBA} pixelFormat;
  int startingByteIndex;
  int rowSizeInBytes;
  int rowPaddingInBytes;
  int widthInPixels;
  int heightInPixels;
};}

#endif