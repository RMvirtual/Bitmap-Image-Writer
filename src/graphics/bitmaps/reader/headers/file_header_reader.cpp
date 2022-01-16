#include "src/common/filesystem/filesystem.h"
#include "src/common/byte-array/byte_conversion.h"
#include "src/graphics/bitmaps/reader/headers/file_header_reader.h"

BitmapReader::FileHeaderReader::FileHeaderReader()
{
  // pass.
}

BitmapHeaders::FileHeader BitmapReader::FileHeaderReader::convertBytes(
  const ByteArray& bytes)
{
  this->parseSignatureBytes(bytes);
  this->parseSizeOfBitmapFile(bytes);
  this->parseReservedBytes(bytes);
  this->parsePixelDataOffset(bytes);

  return this->fileHeader;
}

void BitmapReader::FileHeaderReader::parseSignatureBytes(
  const ByteArray& bytes)
{
  this->fileHeader.setSignatureBytes(bytes[0].value, bytes[1].value);
}

void BitmapReader::FileHeaderReader::parseSizeOfBitmapFile(
  const ByteArray& bytes)
{
  uint32_t sizeOfBitmapFile = ByteConversion::convertTo32BitInt(bytes, 2);
  this->fileHeader.setFileSizeInBytes(sizeOfBitmapFile);
}

void BitmapReader::FileHeaderReader::parseReservedBytes(
  const ByteArray& bytes)
{
  uint32_t reservedBytes = ByteConversion::convertTo32BitInt(bytes, 6);
  this->fileHeader.setReservedBytes(reservedBytes);
}

void BitmapReader::FileHeaderReader::parsePixelDataOffset(
  const ByteArray& bytes)
{
  uint32_t pixelDataOffset = ByteConversion::convertTo32BitInt(bytes, 10);
  this->fileHeader.setPixelArrayOffsetInBytes(pixelDataOffset);
}