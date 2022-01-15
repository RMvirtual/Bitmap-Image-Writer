#include "src/common/filesystem/filesystem.h"
#include "src/common/byte-array/bytes_conversion.h"
#include "src/graphics/bitmaps/reader/headers/file_header_reader.h"

FileHeaderReader::FileHeaderReader()
{
  // pass.
}

BitmapHeaders::FileHeader FileHeaderReader::convertBytes(ByteArray& bytes)
{
  this->parseSignatureBytes(bytes);
  this->parseSizeOfBitmapFile(bytes);
  this->parseReservedBytes(bytes);
  this->parsePixelDataOffset(bytes);

  return this->fileHeader;
}

void FileHeaderReader::parseSignatureBytes(ByteArray& bytes)
{
  this->fileHeader.setSignatureBytes(bytes[0].value, bytes[1].value);
}

void FileHeaderReader::parseSizeOfBitmapFile(ByteArray& bytes)
{
  uint32_t sizeOfBitmapFile = BytesConversion::get32BitInteger(bytes, 2);
  this->fileHeader.setSizeOfBitmapFile(sizeOfBitmapFile);
}

void FileHeaderReader::parseReservedBytes(ByteArray& bytes)
{
  uint32_t reservedBytes = BytesConversion::get32BitInteger(bytes, 6);
  this->fileHeader.setReservedBytes(reservedBytes);
}

void FileHeaderReader::parsePixelDataOffset(ByteArray& bytes)
{
  uint32_t pixelDataOffset = BytesConversion::get32BitInteger(bytes, 10);
  this->fileHeader.setPixelDataOffset(pixelDataOffset);
}