#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include "bitmap.h"

using namespace std;

char* BitmapFileHeader::toBytes()
{
  char * myChars = new char[14];

  /* Initialise empty values in array instead of random uninitialised
  values. */
  for (int i = 0; i < 14; i++)
    myChars[i] = 0;

  myChars[0] = this->bitmapSignatureBytes[0];
  myChars[1] = this->bitmapSignatureBytes[1];
  myChars[2] = this->sizeOfBitmapFile;
  myChars[6] = this->reservedBytes;
  myChars[10] = this->pixelDataOffset;

  return myChars;
}

int BitmapFileHeader::getSizeOfHeaderInBytes()
{
  return 14;
}

char* BitmapInfoHeader::toBytes()
{
  std::array<unsigned char, sizeof(uint32_t) * 10 + sizeof(uint16_t)> bytes;

  const char * begin = reinterpret_cast<const char *> (std::addressof(this->sizeOfThisHeader));

  int sizeOfPacket = this->getSizeOfHeaderInBytes();
  char * myChars = new char[sizeOfPacket];

  /* Initialise empty values in array instead of random uninitialised
  values. */
  for (int i = 0; i < sizeOfPacket; i++) {
    myChars[i] = 0;
  }

  cout << myChars << endl;

  myChars[0] = this->sizeOfThisHeader;
  cout << myChars << endl;

  myChars[4] = this->widthInPixels;
  cout << myChars << endl;

  myChars[8] = this->heightInPixels;
  myChars[12] = this->numberOfColorPlanes;
  myChars[14] = this->colorDepth;
  myChars[16] = this->compressionMethod;
  myChars[20] = this->rawBitmapDataSize;
  myChars[24] = this->horizontalResolutionPixelPerMeter;
  myChars[28] = this->verticalResolutionPixelsPerMeter;
  myChars[32] = this->colorTableEntries;
  myChars[36] = this->importantColors;


  return myChars;
}

int BitmapInfoHeader::getSizeOfHeaderInBytes()
{
  return 40;
}