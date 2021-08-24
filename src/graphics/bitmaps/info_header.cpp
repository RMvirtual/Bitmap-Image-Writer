#include <cstdint>
#include <iostream>
#include <unordered_map>

#include "src/graphics/bitmaps/info_header.h"
#include "src/common/byte_array.h"

using namespace std;

BitmapInfoHeader::BitmapInfoHeader(
  int sizeOfHeaderInBytes, int widthInPixels, int heightInPixels)
: BitmapHeader {sizeOfHeaderInBytes}
{
  this->sizeOfThisHeader = sizeOfHeaderInBytes;
  this->widthInPixels = widthInPixels;
  this->heightInPixels = heightInPixels;
  this->numberOfColorPlanes = 1; 
  this->colorDepth = 24; 
  this->compressionMethod = 0;  
  this->rawBitmapDataSize = 0; 
  this->horizontalResolutionPixelPerMeter = 0;
  this->verticalResolutionPixelsPerMeter = 0; 
  this->colorTableEntries = 0; 
  this->importantColors = 0; 
}

char* BitmapInfoHeader::toBytes()
{
  ByteArrayBuilder byteArrayBuilder;

  byteArrayBuilder.addValue(this->sizeOfThisHeader);
  byteArrayBuilder.addValue(this->widthInPixels);
  byteArrayBuilder.addValue(this->heightInPixels);
  byteArrayBuilder.addValue(this->numberOfColorPlanes);
  byteArrayBuilder.addValue(this->colorDepth);
  byteArrayBuilder.addValue(this->compressionMethod);
  byteArrayBuilder.addValue(this->rawBitmapDataSize);
  byteArrayBuilder.addValue(this->horizontalResolutionPixelPerMeter);
  byteArrayBuilder.addValue(this->verticalResolutionPixelsPerMeter);
  byteArrayBuilder.addValue(this->colorTableEntries);
  byteArrayBuilder.addValue(this->importantColors);

  char* byteArray = byteArrayBuilder.toArray();

  return byteArray;
}
