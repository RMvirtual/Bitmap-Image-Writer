#include "src/common/filesystem.h"
#include "src/common/bytes_conversion.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

BitmapHeaders::DibHeader BitmapReader::getBitmapDibHeader(std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);
  
  return BitmapReader::parseDibHeader(bytes);
}

BitmapHeaders::DibHeader BitmapReader::parseDibHeader(std::string bytes)
{
  BitmapHeaders::DibHeader dibHeader;

  BitmapReader::parseWidthInPixels(bytes, &dibHeader);
  BitmapReader::parseHeightInPixels(bytes, &dibHeader);
  BitmapReader::parseNumberOfColourPlanes(bytes, &dibHeader);
  BitmapReader::parseColourDepth(bytes, &dibHeader);
  BitmapReader::parseCompressionMethod(bytes, &dibHeader);
  BitmapReader::parseRawBitmapDataSize(bytes, &dibHeader);
  BitmapReader::parseHorizontalPixelsPerMetre(bytes, &dibHeader);
  BitmapReader::parseVerticalPixelsPerMetre(bytes, &dibHeader);
  BitmapReader::parseColourTableEntries(bytes, &dibHeader);
  BitmapReader::parseImportantColours(bytes, &dibHeader);

  return dibHeader;
}

void BitmapReader::parseWidthInPixels(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  uint32_t widthInPixels
    = BytesConversion::getFourBytesFromSubstring(bytes, 18);
  
  dibHeader->setWidthInPixels(widthInPixels);
}

void BitmapReader::parseHeightInPixels(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  int32_t heightInPixels
    = BytesConversion::getFourBytesFromSubstring(bytes, 22);

  dibHeader->setHeightInPixels(heightInPixels);
}

void BitmapReader::parseNumberOfColourPlanes(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  uint16_t numberOfColorPlanes
    = BytesConversion::getTwoBytesFromSubstring(bytes, 26);
  
  dibHeader->setNumberOfColourPlanes(numberOfColorPlanes);
}

void BitmapReader::parseCompressionMethod(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  uint32_t compressionMethod
    = BytesConversion::getFourBytesFromSubstring(bytes, 30);
  
  dibHeader->setCompressionMethod(compressionMethod);
}

void BitmapReader::parseRawBitmapDataSize(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  uint32_t rawBitmapDataSize
    = BytesConversion::getFourBytesFromSubstring(bytes, 34);
  
  dibHeader->setRawBitmapDataSize(rawBitmapDataSize);
}

void BitmapReader::parseColourDepth(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  uint16_t colourDepth = BytesConversion::getTwoBytesFromSubstring(bytes, 28);
  dibHeader->setColorDepth(colourDepth);
}

void BitmapReader::parseHorizontalPixelsPerMetre(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  int32_t horizontalPixelsPerMetre =
    BytesConversion::getFourBytesFromSubstring(bytes, 38);
  
  dibHeader->setHorizontalPixelsPerMetre(horizontalPixelsPerMetre);
}

void BitmapReader::parseVerticalPixelsPerMetre(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  int32_t verticalPixelsPerMetre =
    BytesConversion::getFourBytesFromSubstring(bytes, 42);
  
  dibHeader->setVerticalPixelsPerMetre(verticalPixelsPerMetre);
}

void BitmapReader::parseColourTableEntries(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  uint32_t colourTableEntries =
    BytesConversion::getFourBytesFromSubstring(bytes, 46);
  
  dibHeader->setColorTableEntries(colourTableEntries);
}

void BitmapReader::parseImportantColours(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  uint32_t importantColors =
    BytesConversion::getFourBytesFromSubstring(bytes, 50);
  
  dibHeader->setImportantColours(importantColors);
}