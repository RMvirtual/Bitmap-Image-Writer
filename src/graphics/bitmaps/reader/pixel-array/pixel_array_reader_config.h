#ifndef PIXEL_ARRAY_READER_CONFIG_H
#define PIXEL_ARRAY_READER_CONFIG_H

#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"

struct PixelArrayReaderConfiguration
{
  static PixelArrayReaderConfiguration fromHeaders(
    BitmapHeaders::FileHeader& fileHeader,
    BitmapHeaders::DibHeader& dibHeader
  );

  enum {RGB, RGBA} pixelFormat;
  int startingByteIndex;
  int rowSizeInBytes;
  int rowPaddingInBytes;
  int widthInPixels;
  int heightInPixels;
};

#endif