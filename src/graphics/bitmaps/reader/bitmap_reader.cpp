#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/common/bytes_conversion.h"
#include "src/common/filesystem.h"

BitmapFileHeader BitmapReader::getBitmapFileHeader(std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);

  BitmapFileHeader bmpFileHeader;

  bmpFileHeader.setSignatureBytes(bytes[0], bytes[1]);

  uint32_t sizeOfBitmapFile
    = BytesConversion::getFourBytesFromSubstring(bytes, 2);
  
  bmpFileHeader.setSizeOfBitmapFile(sizeOfBitmapFile);

  uint32_t reservedBytes
    = BytesConversion::getFourBytesFromSubstring(bytes, 6);
  
  bmpFileHeader.setReservedBytes(reservedBytes);

  uint32_t pixelDataOffset 
    = BytesConversion::getFourBytesFromSubstring(bytes, 10);
  
  bmpFileHeader.setPixelDataOffset(pixelDataOffset);

  return bmpFileHeader;
}

BitmapDibHeader BitmapReader::getBitmapDibHeader(std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);

  BitmapDibHeader bmpDibHeader;

  uint32_t headerSize = BytesConversion::getFourBytesFromSubstring(bytes, 14);
  bmpDibHeader.setSizeOfHeaderInBytes(headerSize);

  uint32_t widthInPixels
    = BytesConversion::getFourBytesFromSubstring(bytes, 18);
  
  bmpDibHeader.setWidthInPixels(widthInPixels);

  int32_t heightInPixels
    = BytesConversion::getFourBytesFromSubstring(bytes, 22);

  bmpDibHeader.setHeightInPixels(heightInPixels);

  uint16_t numberOfColorPlanes
    = BytesConversion::getTwoBytesFromSubstring(bytes, 26);
  
  bmpDibHeader.setNumberOfColourPlanes(numberOfColorPlanes);

  uint16_t colorDepth = BytesConversion::getTwoBytesFromSubstring(bytes, 28);
  bmpDibHeader.setColorDepth(colorDepth);

  uint32_t compressionMethod
    = BytesConversion::getFourBytesFromSubstring(bytes, 30);
  
  bmpDibHeader.setCompressionMethod(compressionMethod);

  uint32_t rawBitmapDataSize
    = BytesConversion::getFourBytesFromSubstring(bytes, 34);
  
  bmpDibHeader.setRawBitmapDataSize(rawBitmapDataSize);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  int32_t horizontalPixelsPerMetre
    = BytesConversion::getFourBytesFromSubstring(bytes, 38);
  
  bmpDibHeader.setHorizontalPixelsPerMetre(horizontalPixelsPerMetre);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  int32_t verticalPixelsPerMetre
    = BytesConversion::getFourBytesFromSubstring(bytes, 42);
  
  bmpDibHeader.setVerticalPixelsPerMetre(verticalPixelsPerMetre);

  uint32_t colorTableEntries
    = BytesConversion::getFourBytesFromSubstring(bytes, 46);
  
  bmpDibHeader.setColorTableEntries(colorTableEntries);

  uint32_t importantColors
    = BytesConversion::getFourBytesFromSubstring(bytes, 50);
  
  bmpDibHeader.setImportantColours(importantColors);

  return bmpDibHeader;
}

PixelArray BitmapReader::getPixelArray(std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);

  int lengthOfPixelArray = BitmapReader::getPixelArraySizeInBytes(filePath);
  
  std::vector<Pixel> pixels;

  int byteNo = 54;

  for (byteNo = 0; byteNo < 512 * 512 * 3; byteNo += 3) {
    uint8_t blueValue = bytes[byteNo + 54];
    uint8_t greenValue = bytes[byteNo + 1 + 54];
    uint8_t redValue = bytes[byteNo + 2 + 54];

    Pixel pixel {redValue, greenValue, blueValue};
    pixels.push_back(pixel);
  }

  return PixelArray(pixels, 512, 512);
}

int BitmapReader::getPixelArraySizeInBytes(std::string filePath)
{
  BitmapFileHeader bmpFileHeader = BitmapReader::getBitmapFileHeader(filePath);
  int sizeOfFile = bmpFileHeader.getSizeOfBitmapFile();
  int pixelDataOffset = bmpFileHeader.getPixelDataOffset();

  int sizeOfPixelArrayInBytes = sizeOfFile - pixelDataOffset;

  return sizeOfPixelArrayInBytes;
}

