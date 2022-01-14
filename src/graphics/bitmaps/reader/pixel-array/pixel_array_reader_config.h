#ifndef PIXEL_ARRAY_READER_CONFIG_H
#define PIXEL_ARRAY_READER_CONFIG_H

#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"

class PixelArrayReaderConfiguration
{
public:
  PixelArrayReaderConfiguration();

  static PixelArrayReaderConfiguration fromHeaders(
    BitmapHeaders::FileHeader& fileHeader,
    BitmapHeaders::DibHeader& dibHeader
  );

  int getStartingByteIndex();
  int getRowSizeInBytes();
  int getRowPaddingInBytes();
  int getWidthInPixels();
  int getHeightInPixels();

private:
  int startingByteIndex;
  int rowSizeInBytes;
  int rowPaddingInBytes;
  int widthInPixels;
  int heightInPixels;
};

#endif