#include "src/utilities/filesystem.h"
#include "src/containers/byte-array/byte_conversion.h"
#include "src/bitmaps/reader/headers/file_header_reader.h"

Bitmaps::FileHeaderReader::FileHeaderReader()
{
  // pass.
}

Bitmaps::FileHeader Bitmaps::FileHeaderReader::convertBytes(
  const ByteArray& bytes)
{
  this->parseSignatureBytes(bytes);
  this->parseSizeOfBitmapFile(bytes);
  this->parseReservedBytes(bytes);
  this->parsePixelDataOffset(bytes);

  return this->fileHeader;
}

void Bitmaps::FileHeaderReader::parseSignatureBytes(
  const ByteArray& bytes)
{
  this->fileHeader.setSignatureBytes(bytes[0], bytes[1]);
}

void Bitmaps::FileHeaderReader::parseSizeOfBitmapFile(
  const ByteArray& bytes)
{
  uint32_t sizeOfBitmapFile = ByteConversion::to32BitInt(bytes, 2);
  this->fileHeader.setFileSizeInBytes(sizeOfBitmapFile);
}

void Bitmaps::FileHeaderReader::parseReservedBytes(
  const ByteArray& bytes)
{
  uint32_t reservedBytes = ByteConversion::to32BitInt(bytes, 6);
  this->fileHeader.setReservedBytes(reservedBytes);
}

void Bitmaps::FileHeaderReader::parsePixelDataOffset(
  const ByteArray& bytes)
{
  uint32_t pixelDataOffset = ByteConversion::to32BitInt(bytes, 10);
  this->fileHeader.setPixelArrayOffsetInBytes(pixelDataOffset);
}