#ifndef BITMAP_INFO_HEADER_H
#define BITMAP_INFO_HEADER_H

#include <cstdint>

class BitmapInfoHeader
{
public:
  uint32_t sizeOfThisHeader = 40;
  int32_t widthInPixels = 500; 
  int32_t heightInPixels = 512; 
  uint16_t numberOfColorPlanes = 1; 
  uint16_t colorDepth = 24; 
  uint32_t compressionMethod = 0;  
  uint32_t rawBitmapDataSize = 0; 
  int32_t horizontalResolutionPixelPerMeter = 3780; 
  int32_t verticalResolutionPixelsPerMeter = 3780; 
  uint32_t colorTableEntries = 0; 
  uint32_t importantColors = 0; 

  char* toBytes();
  int getSizeOfHeaderInBytes();
};

#endif