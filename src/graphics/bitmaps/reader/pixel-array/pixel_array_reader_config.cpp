#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"


PixelArrayReaderConfiguration PixelArrayReaderConfiguration::fromHeaders(
  BitmapHeaders::FileHeader& fileHeader, BitmapHeaders::DibHeader& dibHeader)
{
  PixelArrayReaderConfiguration config {};

  config.startingByteIndex = fileHeader.pixelDataOffset();
  config.rowPaddingInBytes = 1;
  config.rowSizeInBytes = 1;
  config.heightInPixels = dibHeader.heightInPixels();
  config.widthInPixels = dibHeader.widthInPixels();
  config.pixelFormat = PixelArrayReaderConfiguration::RGB;

  return config;
}