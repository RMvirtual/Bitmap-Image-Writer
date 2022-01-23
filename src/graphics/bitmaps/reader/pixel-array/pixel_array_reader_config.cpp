#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/graphics/bitmaps/packet/headers/bitmap_headers.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"

BitmapReader::PixelArrayReaderConfig
BitmapReader::PixelArrayReaderConfig::fromHeaders(
  const BitmapHeaders::Headers& headers)
{
  BitmapReader::PixelArrayReaderConfig config {};

  config.startingByteIndex = headers.fileHeader.pixelArrayOffsetInBytes();
  config.rowPaddingInBytes = 1;
  config.rowSizeInBytes = 1;
  config.heightInPixels = headers.dibHeader.heightInPixels();
  config.widthInPixels = headers.dibHeader.widthInPixels();
  config.pixelFormat = BitmapReader::PixelArrayReaderConfig::RGB;

  return config;
}