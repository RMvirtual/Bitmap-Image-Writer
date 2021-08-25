#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/graphics/bitmaps/headers/info_header.h"

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

BitmapFileHeader BitmapReader::getBitmapFileHeader(string filePath)
{
  ifstream file(filePath);

  string string(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  string.c_str();

  BitmapFileHeader bmpFileHeader {2};
  bmpFileHeader.bitmapSignatureBytes[0] = string[0];
  bmpFileHeader.bitmapSignatureBytes[1] = string[1];

  for (int i = 0; i < 54; i++) {
    cout << "Byte no " << i << ": " << (int) string[i] << endl;
  }
  
  bmpFileHeader.sizeOfBitmapFile = uint32_t (
    (uint8_t) string[3] << 24 |
    (uint8_t) string[4] << 16 |
    (uint8_t) string[5] << 8 |
    (uint8_t) string[6]
  );

  bmpFileHeader.reservedBytes = uint32_t (
    (uint8_t) string[6] << 24 |
    (uint8_t) string[7] << 16 |
    (uint8_t) string[8] << 8 |
    (uint8_t) string[9]
  );

  bmpFileHeader.pixelDataOffset = uint32_t (
    (uint8_t) string[10] << 24 |
    (uint8_t) string[11] << 16 |
    (uint8_t) string[12] << 8 |
    (uint8_t) string[13]
  );

  return bmpFileHeader;
}