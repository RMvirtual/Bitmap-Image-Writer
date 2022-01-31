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

  config.format = config.formatFromHeaders(headers); 
  config.startingByteIndex = headers.fileHeader.pixelArrayOffsetInBytes();

  int widthInPixels = headers.dibHeader.widthInPixels();
  config.rowPaddingInBytes = Pixels::calculateRowPadding(widthInPixels);
  config.rowSizeInBytes = Pixels::calculateRowSizeInBytes(widthInPixels);
  
  config.pixelSizeInBytes = config.format.bitsPerPixel / 4;
  
  return config;
}

Pixels::Format BitmapReader::PixelArrayConfig::formatFromHeaders(
  const BitmapHeaders::Headers& headers)
{
  Pixels::Format format {};
  format.name = "lol";
  format.bitsPerPixel = 32;
  format.colourNames = {"none here."};
  format.widthInPixels = headers.dibHeader.widthInPixels();
  format.heightInPixels = headers.dibHeader.heightInPixels();

  return format;
}
