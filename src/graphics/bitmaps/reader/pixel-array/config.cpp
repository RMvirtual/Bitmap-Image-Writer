#include "src/graphics/bitmaps/reader/pixel-array/config.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"
#include "src/graphics/bitmaps/packet/pixel-array/size_calculator.h"
#include "src/graphics/bitmaps/packet/formats/formats.h"

BitmapReader::PixelArrayConfig
BitmapReader::PixelArrayConfig::fromHeaders(
  const BitmapHeaders::Headers& headers)
{
  BitmapReader::PixelArrayConfig config {};

  config.format = config.formatFromHeaders(headers); 
  config.startingByteIndex = headers.fileHeader.pixelArrayOffsetInBytes();

  int widthInPixels = headers.dibHeader.widthInPixels();
  config.rowPaddingInBytes = Pixels::calculateRowPadding(widthInPixels);
  config.rowSizeInBytes = Pixels::calculateRowSizeInBytes(widthInPixels);
  
  config.pixelSizeInBytes = config.format.bitsPerPixel / 8;
  
  return config;
}

Pixels::Format BitmapReader::PixelArrayConfig::formatFromHeaders(
  const BitmapHeaders::Headers& headers)
{
  Pixels::Format format = Pixels::format(headers.dibHeader.bitsPerPixel());
  format.widthInPixels = headers.dibHeader.widthInPixels();
  format.heightInPixels = headers.dibHeader.heightInPixels();

  return format;
}
