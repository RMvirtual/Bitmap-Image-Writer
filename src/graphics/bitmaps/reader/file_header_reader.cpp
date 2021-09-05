#include "src/common/filesystem.h"
#include "src/common/bytes_conversion.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

BitmapHeaders::FileHeader BitmapReader::getBitmapFileHeader(
  std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);
  BitmapHeaders::FileHeader fileHeader = BitmapReader::parseFileHeader(bytes);

  return fileHeader;
}

BitmapHeaders::FileHeader BitmapReader::parseFileHeader(std::string bytes)
{
  BitmapHeaders::FileHeader fileHeader;

  BitmapReader::parseSignatureBytes(bytes, &fileHeader);
  BitmapReader::parseSizeOfBitmapFile(bytes, &fileHeader);
  BitmapReader::parseReservedBytes(bytes, &fileHeader);
  BitmapReader::parsePixelDataOffset(bytes, &fileHeader);

  return fileHeader;
}

void BitmapReader::parseSignatureBytes(
  std::string bytes, BitmapHeaders::FileHeader* fileHeader)
{
  fileHeader->setSignatureBytes(bytes[0], bytes[1]);
}

void BitmapReader::parseSizeOfBitmapFile(
  std::string bytes, BitmapHeaders::FileHeader* fileHeader)
{
  uint32_t sizeOfBitmapFile =
    BytesConversion::getFourBytesFromSubstring(bytes, 2);
  
  fileHeader->setSizeOfBitmapFile(sizeOfBitmapFile);
}

void BitmapReader::parseReservedBytes(
  std::string bytes, BitmapHeaders::FileHeader* fileHeader)
{
  uint32_t reservedBytes
    = BytesConversion::getFourBytesFromSubstring(bytes, 6);
  
  fileHeader->setReservedBytes(reservedBytes);
}

void BitmapReader::parsePixelDataOffset(
  std::string bytes, BitmapHeaders::FileHeader* fileHeader)
{
  uint32_t pixelDataOffset 
    = BytesConversion::getFourBytesFromSubstring(bytes, 10);
  
  fileHeader->setPixelDataOffset(pixelDataOffset);
}
