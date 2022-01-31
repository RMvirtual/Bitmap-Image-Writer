#ifndef PIXEL_ARRAY_READER_CONFIG_H
#define PIXEL_ARRAY_READER_CONFIG_H

#include "src/graphics/bitmaps/packet/headers/headers.h"
#include "src/graphics/bitmaps/packet/formats/format.h"

namespace BitmapReader {
struct PixelArrayConfig
{
  static PixelArrayConfig fromHeaders(
    const BitmapHeaders::Headers& headers);

  Pixels::Format format;
  int startingByteIndex;
  int rowSizeInBytes;
  int rowPaddingInBytes;
  int widthInPixels;
  int heightInPixels;
  int pixelSizeInBytes;

private:
  Pixels::Format formatFromHeaders(const BitmapHeaders::Headers& headers);
  
};}

#endif