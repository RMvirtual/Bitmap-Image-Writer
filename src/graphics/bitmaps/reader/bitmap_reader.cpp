#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/graphics/bitmaps/headers/dib_header.h"

using namespace std;

BitmapReader::BitmapReader()
{
  // Pass.
}

int BitmapReader::getLengthOfPixelPayload(string filePath)
{
  int sizeOfFile = this->getSizeOfFile(filePath);

  return sizeOfFile - 54;
}

int BitmapReader::getSizeOfFile(string filePath)
{
  filesystem::path pathToFile {filePath};
  int fileSizeInBytes = filesystem::file_size(pathToFile);

  return fileSizeInBytes;
}

uint32_t BitmapReader::convertStringTo32BitInteger(string bytesString)
{
  return uint32_t (
    (uint8_t) bytesString[0] |
    (uint8_t) bytesString[1] << 8 |
    (uint8_t) bytesString[2] << 16 |
    (uint8_t) bytesString[3] << 24
  );
}

uint16_t BitmapReader::convertStringTo16BitInteger(string bytesString)
{
  return uint32_t (
    (uint8_t) bytesString[0] |
    (uint8_t) bytesString[1] << 8
  );
}

uint16_t BitmapReader::getTwoBytesFromString(
  string bytes, int startingByteIndex)
{
  string extractedBytesAsString = bytes.substr(startingByteIndex, 2);
  
  uint16_t extractedBytes = this->convertStringTo16BitInteger(
    extractedBytesAsString);
  
  return extractedBytes;
}

uint32_t BitmapReader::getFourBytesFromString(
  string bytes, int startingByteIndex)
{
  string extractedBytesAsString = bytes.substr(startingByteIndex, 4);
  
  uint32_t extractedBytes = this->convertStringTo32BitInteger(
    extractedBytesAsString);
  
  return extractedBytes;
}

BitmapFileHeader BitmapReader::getBitmapFileHeader(string filePath)
{
  ifstream file(filePath);

  string bytes(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  BitmapFileHeader bmpFileHeader {2};
  
  bmpFileHeader.setSignatureBytes(bytes[0], bytes[1]);

  uint32_t sizeOfBitmapFile = this->getFourBytesFromString(bytes, 2);
  bmpFileHeader.setSizeOfBitmapFile(sizeOfBitmapFile);

  uint32_t reservedBytes = this->getFourBytesFromString(bytes, 6);
  bmpFileHeader.setReservedBytes(reservedBytes);

  uint32_t pixelDataOffset = this->getFourBytesFromString(bytes, 10);
  bmpFileHeader.setPixelDataOffset(pixelDataOffset);

  return bmpFileHeader;
}

BitmapDibHeader BitmapReader::getBitmapInfoHeader(string filePath)
{
  ifstream file(filePath);

  string bytes(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  BitmapDibHeader bmpInfoHeader {2};

  string headerSizeString = bytes.substr(14, 4);
  uint32_t headerSize = this->convertStringTo32BitInteger(headerSizeString);
  bmpInfoHeader.setSizeOfHeaderInBytes(headerSize);

  string widthInPixelsString = bytes.substr(18, 4);
  int32_t widthInPixels = this->convertStringTo32BitInteger(
    widthInPixelsString);
  
  bmpInfoHeader.setWidthInPixels(widthInPixels);

  string heightInPixelsAsString = bytes.substr(22, 4);
  int32_t heightInPixels = this->convertStringTo32BitInteger(
    heightInPixelsAsString);
  
  bmpInfoHeader.setHeightInPixels(heightInPixels);

  string numberOfColorPlanesAsString = bytes.substr(26, 2);
  uint16_t numberOfColorPlanes = this->convertStringTo16BitInteger(
    numberOfColorPlanesAsString);

  bmpInfoHeader.setNumberOfColourPlanes(numberOfColorPlanes);

  string colorDepthAsString = bytes.substr(28, 2);
  uint16_t colorDepth = this->convertStringTo16BitInteger(
    colorDepthAsString);

  bmpInfoHeader.setColorDepth(colorDepth);

  string compressionMethodAsString = bytes.substr(30, 4);
  uint32_t compressionMethod = this->convertStringTo32BitInteger(
    compressionMethodAsString);

  bmpInfoHeader.setCompressionMethod(compressionMethod);

  string rawBitmapDataSizeAsString = bytes.substr(34, 4);
  uint32_t rawBitmapDataSize = this->convertStringTo32BitInteger(
    rawBitmapDataSizeAsString);

  bmpInfoHeader.setRawBitmapDataSize(rawBitmapDataSize);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  string horizontalPixelsPerMetreAsString = bytes.substr(38, 4);
  int32_t horizontalPixelsPerMetre = this->convertStringTo32BitInteger(
    horizontalPixelsPerMetreAsString);

  bmpInfoHeader.setHorizontalPixelsPerMetre(horizontalPixelsPerMetre);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  string verticalPixelsPerMetreAsString = bytes.substr(42, 4);
  int32_t verticalPixelsPerMetre = this->convertStringTo32BitInteger(
    verticalPixelsPerMetreAsString);

  bmpInfoHeader.setVerticalPixelsPerMetre(verticalPixelsPerMetre);

  string colorTableEntriesAsString = bytes.substr(46, 4);
  uint32_t colorTableEntries = this->convertStringTo32BitInteger(
    colorTableEntriesAsString);

  bmpInfoHeader.setColorTableEntries(colorTableEntries);

  string importantColorsAsString = bytes.substr(50, 4);
  uint32_t importantColors = this->convertStringTo32BitInteger(
    importantColorsAsString);

  bmpInfoHeader.setImportantColours(importantColors);

  return bmpInfoHeader;
}