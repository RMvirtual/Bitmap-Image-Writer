#ifndef BITMAP_INFO_HEADER_H
#define BITMAP_INFO_HEADER_H

#include <cstdint>
#include <unordered_map>
#include "src/graphics/bitmaps/header.h"

class BitmapInfoHeader : public BitmapHeader
{
public:
  BitmapInfoHeader(
    int sizeOfPixelArray, int widthInPixels, int heightInPixels);
  
  char* toBytes();

private:
  uint32_t sizeOfThisHeader;
  int32_t widthInPixels;
  int32_t heightInPixels;
  uint16_t numberOfColorPlanes;
  uint16_t colorDepth;
  uint32_t compressionMethod;
  uint32_t rawBitmapDataSize; 
  int32_t horizontalResolutionPixelPerMeter;
  int32_t verticalResolutionPixelsPerMeter;
  uint32_t colorTableEntries;
  uint32_t importantColors;

  std::unordered_map<int, uint16_t> getListOfTwoByteHeaderValues();
  std::unordered_map<int, uint32_t> getListOfFourByteHeaderValues();

};

#endif