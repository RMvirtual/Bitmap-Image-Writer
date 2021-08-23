#include "src/graphics/bitmaps/info_header.h"
#include <unordered_map>

#include <iostream>
#include <cstdint>

using namespace std;

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
  char* byteArray = this->getEmptyByteArray();

  unordered_map<int, uint32_t> fourByteValues = 
    this->getListOfFourByteHeaderValues();
  
  unordered_map<int, uint16_t> twoByteValues = 
    this->getListOfTwoByteHeaderValues();

  for (pair<int, uint32_t> keyAndValue : fourByteValues)
    this->insertFourByteValueToCharArray(
      byteArray, keyAndValue.first, keyAndValue.second);
  
  for (pair<int, uint32_t> keyAndValue : twoByteValues)
    this->insertTwoByteValueToCharArray(
      byteArray, keyAndValue.first, keyAndValue.second);

  return byteArray;
}

unordered_map<int, uint16_t> BitmapInfoHeader::getListOfTwoByteHeaderValues()
{
  unordered_map<int, uint16_t> twoByteValues = {
    {12, this->numberOfColorPlanes},
    {14, this->colorDepth}
  };

  return twoByteValues;
}

unordered_map<int, uint32_t> BitmapInfoHeader::getListOfFourByteHeaderValues()
{
  unordered_map<int, uint32_t> fourByteValues = {
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

  return fourByteValues;
}