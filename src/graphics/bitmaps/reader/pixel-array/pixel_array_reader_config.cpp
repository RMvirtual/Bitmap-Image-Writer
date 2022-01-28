#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"
#include "src/graphics/bitmaps/packet/headers/file-header/header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"

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

  return config;
}