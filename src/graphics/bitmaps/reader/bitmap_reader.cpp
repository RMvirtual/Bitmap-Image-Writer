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

BitmapFileHeader BitmapReader::getBitmapFileHeader(string filePath)
{
  ifstream file(filePath);

  string string(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  BitmapFileHeader bmpFileHeader {2};
  bmpFileHeader.bitmapSignatureBytes[0] = string[0];
  bmpFileHeader.bitmapSignatureBytes[1] = string[1];

  bmpFileHeader.sizeOfBitmapFile = uint32_t (
    (uint8_t) string[2] |
    (uint8_t) string[3] << 8 |
    (uint8_t) string[4] << 16 |
    (uint8_t) string[5] << 24
  );

  bmpFileHeader.reservedBytes = uint32_t (
    (uint8_t) string[6] |
    (uint8_t) string[7] << 8 |
    (uint8_t) string[8] << 16 |
    (uint8_t) string[9] << 24
  );

  bmpFileHeader.pixelDataOffset = uint32_t (
    (uint8_t) string[10] |
    (uint8_t) string[11] << 8 |
    (uint8_t) string[12] << 16 |
    (uint8_t) string[13] << 24
  );

  return bmpFileHeader;
}

BitmapDibHeader BitmapReader::getBitmapInfoHeader(string filePath)
{
  ifstream file(filePath);

  string string(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  BitmapDibHeader bmpInfoHeader {2};

  bmpInfoHeader.setSizeOfHeaderInBytes(uint32_t (
    (uint8_t) string[14] |
    (uint8_t) string[15] << 8 |
    (uint8_t) string[16] << 16 |
    (uint8_t) string[17] << 24
  ));

  bmpInfoHeader.widthInPixels = int32_t (
    (int8_t) string[18] |
    (int8_t) string[19] << 8 |
    (int8_t) string[20] << 16 |
    (int8_t) string[21] << 24
  );

  bmpInfoHeader.heightInPixels = int32_t (
    (int8_t) string[22] |
    (int8_t) string[23] << 8 |
    (int8_t) string[24] << 16 |
    (int8_t) string[25] << 24
  );

  bmpInfoHeader.numberOfColorPlanes = uint16_t (
    (uint8_t) string[26] |
    (uint8_t) string[27] << 8
  );

  bmpInfoHeader.colorDepth = uint16_t (
    (uint8_t) string[28] |
    (uint8_t) string[29] << 8
  );

  bmpInfoHeader.compressionMethod = uint32_t (
    (uint8_t) string[30] |
    (uint8_t) string[31] << 8 |
    (uint8_t) string[32] << 16 |
    (uint8_t) string[33] << 24
  );

  bmpInfoHeader.rawBitmapDataSize = uint32_t (
    (uint8_t) string[34] |
    (uint8_t) string[35] << 8 |
    (uint8_t) string[36] << 16 |
    (uint8_t) string[37] << 24
  );

  bmpInfoHeader.horizontalPixelsPerMetre = int32_t (
    (int8_t) string[38] |
    (int8_t) string[39] << 8 |
    (int8_t) string[40] << 16 |
    (int8_t) string[41] << 24
  );

  bmpInfoHeader.verticalPixelsPerMetre = int32_t (
    (int8_t) string[42] |
    (int8_t) string[43] << 8 |
    (int8_t) string[44] << 16 |
    (int8_t) string[45] << 24
  );

  bmpInfoHeader.colorTableEntries = uint32_t (
    (uint8_t) string[46] |
    (uint8_t) string[47] << 8 |
    (uint8_t) string[48] << 16 |
    (uint8_t) string[49] << 24
  );

  bmpInfoHeader.importantColors = uint32_t (
    (uint8_t) string[50] |
    (uint8_t) string[51] << 8 |
    (uint8_t) string[52] << 16 |
    (uint8_t) string[53] << 24
  );

  return bmpInfoHeader;
}