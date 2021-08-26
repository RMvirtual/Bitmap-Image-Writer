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

uint32_t BitmapReader::convert32BitStringToInteger(string bytesString)
{
  return uint32_t (
    (uint8_t) bytesString[0] |
    (uint8_t) bytesString[1] << 8 |
    (uint8_t) bytesString[2] << 16 |
    (uint8_t) bytesString[3] << 24
  );
}

uint16_t BitmapReader::convert16BitStringToInteger(string bytesString)
{
  return uint32_t (
    (uint8_t) bytesString[0] |
    (uint8_t) bytesString[1] << 8
  );
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
  
  // bmpFileHeader.signatureBytes[0] = bytes[0];
  // bmpFileHeader.signatureBytes[1] = bytes[1];

  string sizeOfBitmapFileString = bytes.substr(2, 4);
  uint32_t sizeOfBitmapFile = this->convert32BitStringToInteger(sizeOfBitmapFileString);
  bmpFileHeader.setSizeOfBitmapFile(sizeOfBitmapFile);

  string reservedBytesString = bytes.substr(6, 4);
  uint32_t reservedBytes = this->convert32BitStringToInteger(
    reservedBytesString);

  bmpFileHeader.setReservedBytes(reservedBytes);

  string pixelDataOffsetString = bytes.substr(10, 4);
  uint32_t pixelDataOffset = this->convert32BitStringToInteger(
    pixelDataOffsetString);

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
  uint32_t headerSize = this->convert32BitStringToInteger(headerSizeString);
  bmpInfoHeader.setSizeOfHeaderInBytes(headerSize);

  string widthInPixelsString = bytes.substr(18, 4);
  int32_t widthInPixels = this->convert32BitStringToInteger(
    widthInPixelsString);
  
  bmpInfoHeader.setWidthInPixels(widthInPixels);

  string heightInPixelsAsString = bytes.substr(22, 4);
  int32_t heightInPixels = this->convert32BitStringToInteger(
    heightInPixelsAsString);
  
  bmpInfoHeader.setHeightInPixels(heightInPixels);

  string numberOfColorPlanesAsString = bytes.substr(26, 2);
  uint16_t numberOfColorPlanes = this->convert16BitStringToInteger(
    numberOfColorPlanesAsString);

  bmpInfoHeader.setNumberOfColourPlanes(numberOfColorPlanes);

  string colorDepthAsString = bytes.substr(28, 2);
  uint16_t colorDepth = this->convert16BitStringToInteger(
    colorDepthAsString);

  bmpInfoHeader.setColorDepth(colorDepth);

  string compressionMethodAsString = bytes.substr(30, 4);
  uint32_t compressionMethod = this->convert32BitStringToInteger(
    compressionMethodAsString);

  bmpInfoHeader.setCompressionMethod(compressionMethod);

  string rawBitmapDataSizeAsString = bytes.substr(34, 4);
  uint32_t rawBitmapDataSize = this->convert32BitStringToInteger(
    rawBitmapDataSizeAsString);

  bmpInfoHeader.setRawBitmapDataSize(rawBitmapDataSize);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  string horizontalPixelsPerMetreAsString = bytes.substr(38, 4);
  int32_t horizontalPixelsPerMetre = this->convert32BitStringToInteger(
    horizontalPixelsPerMetreAsString);

  bmpInfoHeader.setHorizontalPixelsPerMetre(horizontalPixelsPerMetre);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  string verticalPixelsPerMetreAsString = bytes.substr(42, 4);
  int32_t verticalPixelsPerMetre = this->convert32BitStringToInteger(
    verticalPixelsPerMetreAsString);

  bmpInfoHeader.setVerticalPixelsPerMetre(verticalPixelsPerMetre);

  string colorTableEntriesAsString = bytes.substr(46, 4);
  uint32_t colorTableEntries = this->convert32BitStringToInteger(
    colorTableEntriesAsString);

  bmpInfoHeader.setColorTableEntries(colorTableEntries);

  string importantColorsAsString = bytes.substr(50, 4);
  uint32_t importantColors = this->convert32BitStringToInteger(
    importantColorsAsString);

  bmpInfoHeader.setImportantColours(importantColors);

  return bmpInfoHeader;
}