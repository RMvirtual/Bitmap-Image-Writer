#include "src/common/filesystem/filesystem.h"
#include "src/common/byte-array/bytes_conversion.h"
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
  this->parseHorizontalPixelsPerMetre(bytes);
  this->parseVerticalPixelsPerMetre(bytes);
  this->parseColourTableEntries(bytes);
  this->parseImportantColours(bytes);

  return this->header;
}

void BitmapReader::DibHeaderReader::parseWidthInPixels(const ByteArray& bytes)
{
  uint32_t widthInPixels = BytesConversion::get32BitInteger(bytes, 4);
  this->header.setWidthInPixels(widthInPixels);
}

void BitmapReader::DibHeaderReader::parseHeightInPixels(const ByteArray& bytes)
{
  int32_t heightInPixels = BytesConversion::get32BitInteger(bytes, 8);
  this->header.setHeightInPixels(heightInPixels);
}

void BitmapReader::DibHeaderReader::parseNumberOfColourPlanes(
  const ByteArray& bytes)
{
  uint16_t numberOfColorPlanes = BytesConversion::get16BitInteger(bytes, 12);
  this->header.setNumberOfColourPlanes(numberOfColorPlanes);
}

void BitmapReader::DibHeaderReader::parseColourDepth(
  const ByteArray& bytes)
{
  uint16_t colourDepth = BytesConversion::get16BitInteger(bytes, 14);
  this->header.setColorDepth(colourDepth);
}

void BitmapReader::DibHeaderReader::parseCompressionMethod(
  const ByteArray& bytes)
{
  uint32_t compressionMethod = BytesConversion::get32BitInteger(bytes, 16);
  this->header.setCompressionMethod(compressionMethod);
}

void BitmapReader::DibHeaderReader::parseRawBitmapDataSize(
  const ByteArray& bytes)
{
  uint32_t rawBitmapDataSize = BytesConversion::get32BitInteger(bytes, 20);
  this->header.setRawBitmapDataSize(rawBitmapDataSize);
}

void BitmapReader::DibHeaderReader::parseHorizontalPixelsPerMetre(
  const ByteArray& bytes)
{
  int32_t pixelsPerMetre = BytesConversion::get32BitInteger(bytes, 24);
  this->header.setHorizontalPixelsPerMetre(pixelsPerMetre);
}

void BitmapReader::DibHeaderReader::parseVerticalPixelsPerMetre(
  const ByteArray& bytes)
{
  int32_t pixelsPerMetre = BytesConversion::get32BitInteger(bytes, 28);
  this->header.setVerticalPixelsPerMetre(pixelsPerMetre);
}

void BitmapReader::DibHeaderReader::parseColourTableEntries(
  const ByteArray& bytes)
{
  uint32_t colourTableEntries = BytesConversion::get32BitInteger(bytes, 32);
  this->header.setColorTableEntries(colourTableEntries);
}

void BitmapReader::DibHeaderReader::parseImportantColours(
  const ByteArray& bytes)
{
  uint32_t importantColors = BytesConversion::get32BitInteger(bytes, 36);
  this->header.setImportantColours(importantColors);
}