#include "src/graphics/bitmaps/info_header.h"

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

  this->insertFourByteValueToCharArray(myChars, 0, this->sizeOfThisHeader);
  this->insertFourByteValueToCharArray(myChars, 4, this->widthInPixels);
  this->insertFourByteValueToCharArray(myChars, 8, this->heightInPixels);

  this->insertTwoByteValueToCharArray(myChars, 12, this->numberOfColorPlanes);
  this->insertTwoByteValueToCharArray(myChars, 14, this->colorDepth);

  this->insertFourByteValueToCharArray(myChars, 16, this->compressionMethod);
  this->insertFourByteValueToCharArray(myChars, 20, this->rawBitmapDataSize);
  this->insertFourByteValueToCharArray(myChars, 24, this->horizontalResolutionPixelPerMeter);
  this->insertFourByteValueToCharArray(myChars, 28, this->verticalResolutionPixelsPerMeter);
  this->insertFourByteValueToCharArray(myChars, 32, this->colorTableEntries);
  this->insertFourByteValueToCharArray(myChars, 36, this->importantColors);

  return myChars;
}

int BitmapInfoHeader::getSizeOfHeaderInBytes()
{
  return 40;
}