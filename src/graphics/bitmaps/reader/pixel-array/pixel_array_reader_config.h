#ifndef PIXEL_ARRAY_READER_CONFIG_H
#define PIXEL_ARRAY_READER_CONFIG_H

#include "src/graphics/bitmaps/packet/headers/headers.h"

namespace BitmapReader {
struct PixelArrayReaderConfig
{
  static PixelArrayReaderConfig fromHeaders(
    const BitmapHeaders::Headers& headers);

  enum {RGB, RGBA} pixelFormats;
  int startingByteIndex;
  int rowSizeInBytes;
  int rowPaddingInBytes;
  int widthInPixels;
  int heightInPixels;
  int pixelSizeInBytes;
};}

#endif