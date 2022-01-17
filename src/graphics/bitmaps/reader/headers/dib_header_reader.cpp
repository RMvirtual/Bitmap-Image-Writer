#include "src/common/filesystem/filesystem.h"
#include "src/common/byte-array/byte_conversion.h"
#include "src/graphics/bitmaps/reader/headers/dib_header_reader.h"

BitmapReader::DibHeaderReader::DibHeaderReader()
{
  // pass.
}

BitmapHeaders::DibHeader BitmapReader::DibHeaderReader::convertBytes(
  const ByteArray& bytes)
{
  this->parseWidthInPixels(bytes);
  this->parseHeightInPixels(bytes);
  this->parseNumberOfColourPlanes(bytes);
  this->parseColourDepth(bytes);
  this->parseCompressionMethod(bytes);
  this->parseRawBitmapDataSize(bytes);
  this->parseHorizontalResolution(bytes);
  this->parseVerticalResolution(bytes);
  this->parseColourTableEntries(bytes);
  this->parseImportantColours(bytes);

  return this->header;
}

void BitmapReader::DibHeaderReader::parseWidthInPixels(const ByteArray& bytes)
{
  uint32_t widthInPixels = ByteConversion::convertTo32BitInt(bytes, 4);
  this->header.setWidthInPixels(widthInPixels);
}

void BitmapReader::DibHeaderReader::parseHeightInPixels(const ByteArray& bytes)
{
  int32_t heightInPixels = ByteConversion::convertTo32BitInt(bytes, 8);
  this->header.setHeightInPixels(heightInPixels);
}

void BitmapReader::DibHeaderReader::parseNumberOfColourPlanes(
  const ByteArray& bytes)
{
  uint16_t numberOfColorPlanes = ByteConversion::convertTo16BitInt(bytes, 12);
  this->header.setNumberOfColourPlanes(numberOfColorPlanes);
}

void BitmapReader::DibHeaderReader::parseColourDepth(
  const ByteArray& bytes)
{
  uint16_t colourDepth = ByteConversion::convertTo16BitInt(bytes, 14);
  this->header.setBitsPerPixel(colourDepth);
}

void BitmapReader::DibHeaderReader::parseCompressionMethod(
  const ByteArray& bytes)
{
  uint32_t compressionMethod = ByteConversion::convertTo32BitInt(bytes, 16);
  this->header.setCompressionMethod(compressionMethod);
}

void BitmapReader::DibHeaderReader::parseRawBitmapDataSize(
  const ByteArray& bytes)
{
  uint32_t rawBitmapDataSize = ByteConversion::convertTo32BitInt(bytes, 20);
  this->header.setSizeOfPixelArray(rawBitmapDataSize);
}

void BitmapReader::DibHeaderReader::parseHorizontalResolution(
  const ByteArray& bytes)
{
  int32_t resolution = ByteConversion::convertTo32BitInt(bytes, 24);
  this->header.setHorizontalResolution(resolution);
}

void BitmapReader::DibHeaderReader::parseVerticalResolution(
  const ByteArray& bytes)
{
  int32_t resolution = ByteConversion::convertTo32BitInt(bytes, 28);
  this->header.setVerticalResolution(resolution);
}

void BitmapReader::DibHeaderReader::parseColourTableEntries(
  const ByteArray& bytes)
{
  uint32_t colourTableEntries = ByteConversion::convertTo32BitInt(bytes, 32);
  this->header.setColorTableEntries(colourTableEntries);
}

void BitmapReader::DibHeaderReader::parseImportantColours(
  const ByteArray& bytes)
{
  uint32_t importantColors = ByteConversion::convertTo32BitInt(bytes, 36);
  this->header.setImportantColours(importantColors);
}