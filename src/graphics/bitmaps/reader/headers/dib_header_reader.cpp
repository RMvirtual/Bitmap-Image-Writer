#include "src/utilities/filesystem.h"
#include "src/containers/byte-array/byte_conversion.h"
#include "src/graphics/bitmaps/reader/headers/dib_header_reader.h"

Bitmaps::DibHeaderReader::DibHeaderReader()
{
  // pass.
}

Bitmaps::DibHeader Bitmaps::DibHeaderReader::convertBytes(
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

void Bitmaps::DibHeaderReader::parseWidthInPixels(const ByteArray& bytes)
{
  uint32_t widthInPixels = ByteConversion::to32BitInt(bytes, 4);
  this->header.setWidthInPixels(widthInPixels);
}

void Bitmaps::DibHeaderReader::parseHeightInPixels(const ByteArray& bytes)
{
  int32_t heightInPixels = ByteConversion::to32BitInt(bytes, 8);
  this->header.setHeightInPixels(heightInPixels);
}

void Bitmaps::DibHeaderReader::parseNumberOfColourPlanes(
  const ByteArray& bytes)
{
  uint16_t numberOfColorPlanes = ByteConversion::to16BitInt(bytes, 12);
  this->header.setNumberOfColourPlanes(numberOfColorPlanes);
}

void Bitmaps::DibHeaderReader::parseColourDepth(
  const ByteArray& bytes)
{
  uint16_t colourDepth = ByteConversion::to16BitInt(bytes, 14);
  this->header.setBitsPerPixel(colourDepth);
}

void Bitmaps::DibHeaderReader::parseCompressionMethod(
  const ByteArray& bytes)
{
  uint32_t compressionMethod = ByteConversion::to32BitInt(bytes, 16);
  this->header.setCompressionMethod(compressionMethod);
}

void Bitmaps::DibHeaderReader::parseRawBitmapDataSize(
  const ByteArray& bytes)
{
  uint32_t rawBitmapDataSize = ByteConversion::to32BitInt(bytes, 20);
  this->header.setSizeOfPixelArray(rawBitmapDataSize);
}

void Bitmaps::DibHeaderReader::parseHorizontalResolution(
  const ByteArray& bytes)
{
  int32_t resolution = ByteConversion::to32BitInt(bytes, 24);
  this->header.setHorizontalResolution(resolution);
}

void Bitmaps::DibHeaderReader::parseVerticalResolution(
  const ByteArray& bytes)
{
  int32_t resolution = ByteConversion::to32BitInt(bytes, 28);
  this->header.setVerticalResolution(resolution);
}

void Bitmaps::DibHeaderReader::parseColourTableEntries(
  const ByteArray& bytes)
{
  uint32_t colourTableEntries = ByteConversion::to32BitInt(bytes, 32);
  this->header.setColorTableEntries(colourTableEntries);
}

void Bitmaps::DibHeaderReader::parseImportantColours(
  const ByteArray& bytes)
{
  uint32_t importantColors = ByteConversion::to32BitInt(bytes, 36);
  this->header.setImportantColours(importantColors);
}