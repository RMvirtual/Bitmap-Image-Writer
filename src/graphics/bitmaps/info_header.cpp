#include "src/graphics/bitmaps/info_header.h"
#include <unordered_map>

#include <iostream>
#include <cstdint>

BitmapInfoHeader::BitmapInfoHeader(int sizeOfPixelArray, int widthInPixels, int heightInPixels)
: BitmapHeader {sizeOfPixelArray}
{
  this->sizeOfThisHeader = 40;
  this->widthInPixels = widthInPixels;
  this->heightInPixels = heightInPixels;
  this->numberOfColorPlanes = 1; 
  this->colorDepth = 24; 
  this->compressionMethod = 0;  
  this->rawBitmapDataSize = 0; 
  this->horizontalResolutionPixelPerMeter = 3780; 
  this->verticalResolutionPixelsPerMeter = 3780; 
  this->colorTableEntries = 0; 
  this->importantColors = 0; 
}

char* BitmapInfoHeader::toBytes()
{
  int size = this->getSizeOfHeaderInBytes();
  char* myChars = new char[size];

  /* Initialise empty values in array instead of random uninitialised
  values. */
  for (int i = 0; i < size; i++) {
    myChars[i] = 0;
  }

  std::unordered_map<int, int32_t> fourByteValues = {
    {0, this->sizeOfThisHeader},
    {4, this->widthInPixels},
    {8, this->heightInPixels},
    {16, this->compressionMethod},
    {20, this->rawBitmapDataSize},
    {24, this->horizontalResolutionPixelPerMeter},
    {28, this->verticalResolutionPixelsPerMeter},
    {32, this->colorTableEntries},
    {36, this->importantColors}
  };

  for (std::pair<int, uint32_t> keyAndValue : fourByteValues)
    this->insertFourByteValueToCharArray(myChars, keyAndValue.first, keyAndValue.second);
  
  std::unordered_map<int, int16_t> twoByteValues = {
    {12, this->numberOfColorPlanes},
    {14, this->colorDepth}
  };

  for (std::pair<int, uint32_t> keyAndValue : twoByteValues)
    this->insertTwoByteValueToCharArray(myChars, keyAndValue.first, keyAndValue.second);

  return myChars;
}

int BitmapInfoHeader::getSizeOfHeaderInBytes()
{
  return 40;
}