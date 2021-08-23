#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include "src/graphics/bitmaps/bitmap.h"

using namespace std;

BitmapHeader::BitmapHeader(int sizeOfHeaderInBytes)
{
  this->sizeOfHeaderInBytes = sizeOfHeaderInBytes;
}

int BitmapHeader::getSizeOfHeaderInBytes()
{
  return this->sizeOfHeaderInBytes;
}

BitmapFileHeader::BitmapFileHeader(int sizeOfPixelArray)
: BitmapHeader {sizeOfPixelArray}
{
  this->bitmapSignatureBytes[0] = 'B';
  this->bitmapSignatureBytes[1] = 'M';
  this->sizeOfBitmapFile = 54 + 786432;
  this->reservedBytes = 0;
  this->pixelDataOffset = 54;
}

char* BitmapFileHeader::toBytes()
{
  int headerSize = this->getSizeOfHeaderInBytes();
  char * myChars = new char[headerSize];

  /* Initialise empty values in array instead of random uninitialised
  values. */
  for (int i = 0; i < headerSize; i++)
    myChars[i] = 0;

  myChars[0] = this->bitmapSignatureBytes[0];
  myChars[1] = this->bitmapSignatureBytes[1];

  myChars[2] = this->sizeOfBitmapFile;
  myChars[3] = this->sizeOfBitmapFile >> 8;
  myChars[4] = this->sizeOfBitmapFile >> 16;
  myChars[5] = this->sizeOfBitmapFile >> 24;
  
  myChars[6] = this->reservedBytes;
  myChars[10] = this->pixelDataOffset;

  return myChars;
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

  myChars[0] = this->sizeOfThisHeader;
  myChars[1] = this->sizeOfThisHeader >> 8;
  myChars[2] = this->sizeOfThisHeader >> 16;
  myChars[3] = this->sizeOfThisHeader >> 24;

  myChars[4] = this->widthInPixels;
  myChars[5] = this->widthInPixels >> 8;
  myChars[6] = this->widthInPixels >> 16;
  myChars[7] = this->widthInPixels >> 24;

  myChars[8] = this->heightInPixels;
  myChars[9] = this->heightInPixels >> 8;
  myChars[10] = this->heightInPixels >> 16;
  myChars[11] = this->heightInPixels >> 24;

  myChars[12] = this->numberOfColorPlanes;
  myChars[13] = this->numberOfColorPlanes >> 8;

  myChars[14] = this->colorDepth;
  myChars[15] = this->colorDepth >> 8;

  myChars[16] = this->compressionMethod;
  myChars[17] = this->compressionMethod >> 8;
  myChars[18] = this->compressionMethod >> 16;
  myChars[19] = this->compressionMethod >> 24;

  myChars[20] = this->rawBitmapDataSize;
  myChars[21] = this->rawBitmapDataSize >> 8;
  myChars[22] = this->rawBitmapDataSize >> 16;
  myChars[23] = this->rawBitmapDataSize >> 24;

  myChars[24] = this->horizontalResolutionPixelPerMeter;
  myChars[25] = this->horizontalResolutionPixelPerMeter >> 8;
  myChars[26] = this->horizontalResolutionPixelPerMeter >> 16;
  myChars[27] = this->horizontalResolutionPixelPerMeter >> 24;

  myChars[28] = this->verticalResolutionPixelsPerMeter;
  myChars[29] = this->verticalResolutionPixelsPerMeter >> 8;
  myChars[30] = this->verticalResolutionPixelsPerMeter >> 16;
  myChars[31] = this->verticalResolutionPixelsPerMeter >> 24;

  myChars[32] = this->colorTableEntries;
  myChars[33] = this->colorTableEntries >> 8;
  myChars[34] = this->colorTableEntries >> 16;
  myChars[35] = this->colorTableEntries >> 24;

  myChars[36] = this->colorTableEntries;
  myChars[37] = this->colorTableEntries >> 8;
  myChars[38] = this->colorTableEntries >> 16;
  myChars[39] = this->colorTableEntries >> 24;

  return myChars;
}

int BitmapInfoHeader::getSizeOfHeaderInBytes()
{
  return 40;
}