#include "src/graphics/bitmaps/reader/pixel-array/config.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"
#include "src/graphics/bitmaps/packet/headers/file-header/header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"
#include "src/graphics/bitmaps/packet/pixel-array/size_calculator.h"

BitmapReader::PixelArrayConfig
BitmapReader::PixelArrayConfig::fromHeaders(
  const BitmapHeaders::Headers& headers)
{
  BitmapReader::PixelArrayConfig config {};

  int widthInPixels = headers.dibHeader.widthInPixels();

  config.startingByteIndex = headers.fileHeader.pixelArrayOffsetInBytes();
  config.format.widthInPixels = widthInPixels;
  config.format.heightInPixels = headers.dibHeader.heightInPixels();
  config.rowPaddingInBytes = Pixels::calculateRowPadding(widthInPixels);
  config.rowSizeInBytes = Pixels::calculateRowSizeInBytes(widthInPixels);
  config.pixelSizeInBytes = config.format.bitsPerPixel / 4;
  
  return config;
}