#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/common/bytes_conversion.h"
#include "src/common/filesystem.h"

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

BitmapHeaders::DibHeader BitmapReader::getBitmapDibHeader(
  std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);
  BitmapHeaders::DibHeader bmpDibHeader = BitmapReader::parseDibHeader(bytes);

  return bmpDibHeader;
}

BitmapHeaders::DibHeader BitmapReader::parseDibHeader(std::string bytes)
{
  BitmapHeaders::DibHeader dibHeader;

  BitmapReader::parseHeaderSize(bytes, &dibHeader);
  BitmapReader::parseWidthInPixels(bytes, &dibHeader);
  BitmapReader::parseHeightInPixels(bytes, &dibHeader);

  uint16_t numberOfColorPlanes
    = BytesConversion::getTwoBytesFromSubstring(bytes, 26);
  
  dibHeader.setNumberOfColourPlanes(numberOfColorPlanes);

  uint16_t colorDepth = BytesConversion::getTwoBytesFromSubstring(bytes, 28);
  dibHeader.setColorDepth(colorDepth);

  uint32_t compressionMethod
    = BytesConversion::getFourBytesFromSubstring(bytes, 30);
  
  dibHeader.setCompressionMethod(compressionMethod);

  uint32_t rawBitmapDataSize
    = BytesConversion::getFourBytesFromSubstring(bytes, 34);
  
  dibHeader.setRawBitmapDataSize(rawBitmapDataSize);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  int32_t horizontalPixelsPerMetre
    = BytesConversion::getFourBytesFromSubstring(bytes, 38);
  
  dibHeader.setHorizontalPixelsPerMetre(horizontalPixelsPerMetre);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  int32_t verticalPixelsPerMetre
    = BytesConversion::getFourBytesFromSubstring(bytes, 42);
  
  dibHeader.setVerticalPixelsPerMetre(verticalPixelsPerMetre);

  uint32_t colorTableEntries
    = BytesConversion::getFourBytesFromSubstring(bytes, 46);
  
  dibHeader.setColorTableEntries(colorTableEntries);

  uint32_t importantColors
    = BytesConversion::getFourBytesFromSubstring(bytes, 50);
  
  dibHeader.setImportantColours(importantColors);

  return dibHeader;
}

void BitmapReader::parseHeaderSize(
  std::string bytes, BitmapHeaders::DibHeader* dibHeader)
{
  uint32_t headerSize = BytesConversion::getFourBytesFromSubstring(bytes, 14);
  dibHeader->setSizeOfHeaderInBytes(headerSize);
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

Pixels::PixelArray BitmapReader::getPixelArray(std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);

  int lengthOfPixelArray = BitmapReader::getPixelArraySizeInBytes(filePath);
  
  std::vector<Pixels::Pixel> pixels;

  int byteNo = 54;

  for (byteNo = 0; byteNo < 512 * 512 * 3; byteNo += 3) {
    uint8_t blueValue = bytes[byteNo + 54];
    uint8_t greenValue = bytes[byteNo + 1 + 54];
    uint8_t redValue = bytes[byteNo + 2 + 54];

    Pixels::Pixel pixel {redValue, greenValue, blueValue};
    pixels.push_back(pixel);
  }

  return Pixels::PixelArray(pixels, 512, 512);
}

int BitmapReader::getPixelArraySizeInBytes(std::string filePath)
{
  BitmapHeaders::FileHeader bmpFileHeader =
    BitmapReader::getBitmapFileHeader(filePath);
  
  int sizeOfFile = bmpFileHeader.getSizeOfBitmapFile();
  int pixelDataOffset = bmpFileHeader.getPixelDataOffset();

  int sizeOfPixelArrayInBytes = sizeOfFile - pixelDataOffset;

  return sizeOfPixelArrayInBytes;
}

