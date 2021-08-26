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

BitmapFileHeader BitmapReader::getBitmapFileHeader(string filePath)
{
  string bytes = this->getStringOfBytesFromFile(filePath);
  BitmapFileHeader bmpFileHeader;
  
  bmpFileHeader.setSignatureBytes(bytes[0], bytes[1]);

  uint32_t sizeOfBitmapFile = this->getFourBytesFromString(bytes, 2);
  bmpFileHeader.setSizeOfBitmapFile(sizeOfBitmapFile);

  uint32_t reservedBytes = this->getFourBytesFromString(bytes, 6);
  bmpFileHeader.setReservedBytes(reservedBytes);

  uint32_t pixelDataOffset = this->getFourBytesFromString(bytes, 10);
  bmpFileHeader.setPixelDataOffset(pixelDataOffset);

  return bmpFileHeader;
}

BitmapDibHeader BitmapReader::getBitmapDibHeader(string filePath)
{
  string bytes = this->getStringOfBytesFromFile(filePath);
  BitmapDibHeader bmpDibHeader;

  uint32_t headerSize = this->getFourBytesFromString(bytes, 14);
  bmpDibHeader.setSizeOfHeaderInBytes(headerSize);

  uint32_t widthInPixels = this->getFourBytesFromString(bytes, 18);  
  bmpDibHeader.setWidthInPixels(widthInPixels);

  int32_t heightInPixels = this->getFourBytesFromString(bytes, 22);  
  bmpDibHeader.setHeightInPixels(heightInPixels);

  uint16_t numberOfColorPlanes = this->getTwoBytesFromString(bytes, 26);
  bmpDibHeader.setNumberOfColourPlanes(numberOfColorPlanes);

  uint16_t colorDepth = this->getTwoBytesFromString(bytes, 28);
  bmpDibHeader.setColorDepth(colorDepth);

  uint32_t compressionMethod = this->getFourBytesFromString(bytes, 30);
  bmpDibHeader.setCompressionMethod(compressionMethod);

  uint32_t rawBitmapDataSize = this->getFourBytesFromString(bytes, 34);
  bmpDibHeader.setRawBitmapDataSize(rawBitmapDataSize);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  int32_t horizontalPixelsPerMetre = this->getFourBytesFromString(bytes, 38);
  bmpDibHeader.setHorizontalPixelsPerMetre(horizontalPixelsPerMetre);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  int32_t verticalPixelsPerMetre = this->getFourBytesFromString(bytes, 42);
  bmpDibHeader.setVerticalPixelsPerMetre(verticalPixelsPerMetre);

  uint32_t colorTableEntries = this->getFourBytesFromString(bytes, 46);
  bmpDibHeader.setColorTableEntries(colorTableEntries);

  uint32_t importantColors = this->getFourBytesFromString(bytes, 50);
  bmpDibHeader.setImportantColours(importantColors);

  return bmpDibHeader;
}

int BitmapReader::getSizeOfFile(string filePath)
{
  filesystem::path pathToFile {filePath};
  int fileSizeInBytes = filesystem::file_size(pathToFile);

  return fileSizeInBytes;
}

string BitmapReader::getStringOfBytesFromFile(string filePath)
{
  ifstream file(filePath);

  string bytes(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  file.close();

  return bytes;
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

int BitmapReader::getLengthOfPixelPayload(string filePath)
{
  int sizeOfFile = this->getSizeOfFile(filePath);

  return sizeOfFile - 54;
}
