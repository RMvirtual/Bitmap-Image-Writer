#include "src/common/filesystem.h"
#include "src/common/bytes_conversion.h"
#include "src/graphics/bitmaps/reader/headers/dib_header_reader.h"

DibHeaderReader::DibHeaderReader()
{
  // pass.
}

BitmapHeaders::DibHeader DibHeaderReader::convertBytes(ByteArray bytes)
{
  this->parseWidthInPixels(bytes);
  this->parseHeightInPixels(bytes);
  this->parseNumberOfColourPlanes(bytes);
  this->parseColourDepth(bytes);
  this->parseCompressionMethod(bytes);
  this->parseRawBitmapDataSize(bytes);
  this->parseHorizontalPixelsPerMetre(bytes);
  this->parseVerticalPixelsPerMetre(bytes);
  this->parseColourTableEntries(bytes);
  this->parseImportantColours(bytes);

  return this->header;
}

void DibHeaderReader::parseWidthInPixels(ByteArray bytes)
{
  uint32_t widthInPixels = BytesConversion::get32BitInteger(bytes, 4);
  this->header.setWidthInPixels(widthInPixels);
}

void DibHeaderReader::parseHeightInPixels(ByteArray bytes)
{
  int32_t heightInPixels = BytesConversion::get32BitInteger(bytes, 8);
  this->header.setHeightInPixels(heightInPixels);
}

void DibHeaderReader::parseNumberOfColourPlanes(ByteArray bytes)
{
  uint16_t numberOfColorPlanes = BytesConversion::get16BitInteger(bytes, 12);
  this->header.setNumberOfColourPlanes(numberOfColorPlanes);
}

void DibHeaderReader::parseColourDepth(ByteArray bytes)
{
  uint16_t colourDepth = BytesConversion::get16BitInteger(bytes, 14);
  this->header.setColorDepth(colourDepth);
}

void DibHeaderReader::parseCompressionMethod(ByteArray bytes)
{
  uint32_t compressionMethod = BytesConversion::get32BitInteger(bytes, 16);
  this->header.setCompressionMethod(compressionMethod);
}

void DibHeaderReader::parseRawBitmapDataSize(ByteArray bytes)
{
  uint32_t rawBitmapDataSize = BytesConversion::get32BitInteger(bytes, 20);
  this->header.setRawBitmapDataSize(rawBitmapDataSize);
}

void DibHeaderReader::parseHorizontalPixelsPerMetre(ByteArray bytes)
{
  int32_t pixelsPerMetre = BytesConversion::get32BitInteger(bytes, 24);
  this->header.setHorizontalPixelsPerMetre(pixelsPerMetre);
}

void DibHeaderReader::parseVerticalPixelsPerMetre(ByteArray bytes)
{
  int32_t pixelsPerMetre = BytesConversion::get32BitInteger(bytes, 28);
  this->header.setVerticalPixelsPerMetre(pixelsPerMetre);
}

void DibHeaderReader::parseColourTableEntries(ByteArray bytes)
{
  uint32_t colourTableEntries = BytesConversion::get32BitInteger(bytes, 32);
  this->header.setColorTableEntries(colourTableEntries);
}

void DibHeaderReader::parseImportantColours(ByteArray bytes)
{
  uint32_t importantColors = BytesConversion::get32BitInteger(bytes, 36);
  this->header.setImportantColours(importantColors);
}