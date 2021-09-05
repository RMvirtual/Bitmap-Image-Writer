#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/common/bytes_conversion.h"
#include "src/common/filesystem.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array_size_calculator.h"

BitmapHeaders::FileHeader BitmapReader::getBitmapFileHeader(
  std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);
  BitmapHeaders::FileHeader fileHeader = BitmapReader::parseFileHeader(bytes);

  return fileHeader;
}

BitmapHeaders::DibHeader BitmapReader::getBitmapDibHeader(
  std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);
  BitmapHeaders::DibHeader dibHeader = BitmapReader::parseDibHeader(bytes);

  return dibHeader;
}

Pixels::PixelArray BitmapReader::getPixelArray(std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);
  
  BitmapHeaders::FileHeader fileHeader = 
    BitmapReader::getBitmapFileHeader(filePath);

  BitmapHeaders::DibHeader dibHeader = 
    BitmapReader::getBitmapDibHeader(filePath);

  Pixels::PixelArray pixelArray = BitmapReader::parseBytesToVector(
    &bytes, fileHeader, dibHeader);

  return pixelArray;
}

Pixels::PixelArray BitmapReader::parseBytesToVector(
  std::string* bytes, BitmapHeaders::FileHeader fileHeader,
  BitmapHeaders::DibHeader dibHeader)
{
  int pixelDataOffset = fileHeader.getPixelDataOffset();
  int widthInPixels = dibHeader.getWidthInPixels();
  int heightInPixels = dibHeader.getHeightInPixels();
  int rowSizeInBytes = Pixels::calculateRowSizeInBytes(widthInPixels);

  std::vector<Pixels::Pixel> pixels;

  for (int rowNo = 0; rowNo < heightInPixels; rowNo++) {
    int startOfRowByteIndex = rowNo * rowSizeInBytes + pixelDataOffset;

    BitmapReader::parseRowOfBytesToVector(
      bytes, &pixels, widthInPixels, startOfRowByteIndex);
  }

  return Pixels::PixelArray(pixels, widthInPixels, heightInPixels);
}


void BitmapReader::parseRowOfBytesToVector(
  std::string* bytes, std::vector<Pixels::Pixel>* pixels, 
  int widthInPixels, int rowStartingByteNo)
{
  int unpaddedRowSizeInBytes = 
    Pixels::calculateUnpaddedRowSize(widthInPixels);

  for (int byteNo = 0; byteNo < unpaddedRowSizeInBytes; byteNo += 3) {
    int offsetByteNo = rowStartingByteNo + byteNo;
    
    BitmapReader::parsePixelFromBytesToVector(
      bytes, pixels, offsetByteNo);
  }
}

void BitmapReader::parsePixelFromBytesToVector(
  std::string* bytes, std::vector<Pixels::Pixel>* pixels, int startingByteNo)
{
  Pixels::Pixel pixel = BitmapReader::parsePixelFromBytes(
    bytes, startingByteNo);
      
  pixels->push_back(pixel); 
}

Pixels::Pixel BitmapReader::parsePixelFromBytes(
  std::string* bytes, int startingByteNo)
{
  uint8_t blueValue = (*bytes)[startingByteNo];
  uint8_t greenValue = (*bytes)[startingByteNo + 1];
  uint8_t redValue = (*bytes)[startingByteNo + 2];

  Pixels::Pixel pixel {redValue, greenValue, blueValue};

  return pixel;
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

BitmapHeaders::FileHeader BitmapReader::parseFileHeader(std::string bytes)
{
  BitmapHeaders::FileHeader fileHeader;

  BitmapReader::parseSignatureBytes(bytes, &fileHeader);
  BitmapReader::parseSizeOfBitmapFile(bytes, &fileHeader);
  BitmapReader::parseReservedBytes(bytes, &fileHeader);
  BitmapReader::parsePixelDataOffset(bytes, &fileHeader);

  return fileHeader;
}

BitmapHeaders::DibHeader BitmapReader::parseDibHeader(std::string bytes)
{
  BitmapHeaders::DibHeader dibHeader;

  BitmapReader::parseHeaderSize(bytes, &dibHeader);
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


