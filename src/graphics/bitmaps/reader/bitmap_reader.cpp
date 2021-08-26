#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/graphics/bitmaps/headers/dib_header.h"
#include "src/common/bytes_converter.h"
#include "src/common/file_opener.h"

using namespace std;

BitmapReader::BitmapReader()
{
  // Pass.
}

BitmapFileHeader BitmapReader::getBitmapFileHeader(string filePath)
{
  FileOpener fileOpener;
  string bytes = fileOpener.convertFileToString(filePath);

  BitmapFileHeader bmpFileHeader;
  BytesConverter bytesConverter;

  bmpFileHeader.setSignatureBytes(bytes[0], bytes[1]);

  uint32_t sizeOfBitmapFile
    = bytesConverter.getFourBytesFromSubstring(bytes, 2);
  
  bmpFileHeader.setSizeOfBitmapFile(sizeOfBitmapFile);

  uint32_t reservedBytes
    = bytesConverter.getFourBytesFromSubstring(bytes, 6);
  
  bmpFileHeader.setReservedBytes(reservedBytes);

  uint32_t pixelDataOffset 
    = bytesConverter.getFourBytesFromSubstring(bytes, 10);
  
  bmpFileHeader.setPixelDataOffset(pixelDataOffset);

  return bmpFileHeader;
}

BitmapDibHeader BitmapReader::getBitmapDibHeader(string filePath)
{
  FileOpener fileOpener;
  string bytes = fileOpener.convertFileToString(filePath);

  BitmapDibHeader bmpDibHeader;
  BytesConverter bytesConverter;

  uint32_t headerSize = bytesConverter.getFourBytesFromSubstring(bytes, 14);
  bmpDibHeader.setSizeOfHeaderInBytes(headerSize);

  uint32_t widthInPixels
    = bytesConverter.getFourBytesFromSubstring(bytes, 18);
  
  bmpDibHeader.setWidthInPixels(widthInPixels);

  int32_t heightInPixels
    = bytesConverter.getFourBytesFromSubstring(bytes, 22);

  bmpDibHeader.setHeightInPixels(heightInPixels);

  uint16_t numberOfColorPlanes
    = bytesConverter.getTwoBytesFromSubstring(bytes, 26);
  
  bmpDibHeader.setNumberOfColourPlanes(numberOfColorPlanes);

  uint16_t colorDepth = bytesConverter.getTwoBytesFromSubstring(bytes, 28);
  bmpDibHeader.setColorDepth(colorDepth);

  uint32_t compressionMethod
    = bytesConverter.getFourBytesFromSubstring(bytes, 30);
  
  bmpDibHeader.setCompressionMethod(compressionMethod);

  uint32_t rawBitmapDataSize
    = bytesConverter.getFourBytesFromSubstring(bytes, 34);
  
  bmpDibHeader.setRawBitmapDataSize(rawBitmapDataSize);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  int32_t horizontalPixelsPerMetre
    = bytesConverter.getFourBytesFromSubstring(bytes, 38);
  
  bmpDibHeader.setHorizontalPixelsPerMetre(horizontalPixelsPerMetre);

  /* May be issues here in the future due to conversion between
  unsigned and signed ints with only one function. */
  int32_t verticalPixelsPerMetre
    = bytesConverter.getFourBytesFromSubstring(bytes, 42);
  
  bmpDibHeader.setVerticalPixelsPerMetre(verticalPixelsPerMetre);

  uint32_t colorTableEntries
    = bytesConverter.getFourBytesFromSubstring(bytes, 46);
  
  bmpDibHeader.setColorTableEntries(colorTableEntries);

  uint32_t importantColors
    = bytesConverter.getFourBytesFromSubstring(bytes, 50);
  
  bmpDibHeader.setImportantColours(importantColors);

  return bmpDibHeader;
}

int BitmapReader::getLengthOfPixelPayload(string filePath)
{
  FileOpener fileOpener;
  int sizeOfFile = fileOpener.getSizeOfFile(filePath);

  return sizeOfFile - 54;
}
