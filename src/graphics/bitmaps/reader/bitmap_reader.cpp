#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/graphics/bitmaps/headers/dib_header.h"
#include "src/common/bytes_conversion.h"
#include "src/common/file_opener.h"

BitmapReader::BitmapReader()
{
  // Pass.
}

BitmapFileHeader BitmapReader::getBitmapFileHeader(std::string filePath)
{
  FileOpener fileOpener;
  std::string bytes = fileOpener.convertFileToString(filePath);

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
  FileOpener fileOpener;
  std::string bytes = fileOpener.convertFileToString(filePath);

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
  FileOpener fileOpener;
  std::string bytes = fileOpener.convertFileToString(filePath);

  int lengthOfPixelArray = this->getLengthOfPixelPayload(filePath);

  // for (int byteNo = 0; byteNo < lengthOfPixelArray; byteNo++)
  vector<Pixel> pixels = {{0, 0, 0}};

  return PixelArray(pixels, 1, 1);
}

int BitmapReader::getLengthOfPixelPayload(std::string filePath)
{
  FileOpener fileOpener;
  int sizeOfFile = fileOpener.getSizeOfFile(filePath);

  return sizeOfFile - 54;
}

