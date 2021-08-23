#include "src/graphics/bitmaps/file_header.h"

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
  char* myChars = new char[headerSize];

  /* Initialise empty values in array instead of random uninitialised
  values. */
  for (int i = 0; i < headerSize; i++)
    myChars[i] = 0;

  myChars[0] = this->bitmapSignatureBytes[0];
  myChars[1] = this->bitmapSignatureBytes[1];

  this->insertFourByteValueToCharArray(myChars, 2, 5, this->sizeOfBitmapFile);

  /*
  myChars[2] = this->sizeOfBitmapFile;
  myChars[3] = this->sizeOfBitmapFile >> 8;
  myChars[4] = this->sizeOfBitmapFile >> 16;
  myChars[5] = this->sizeOfBitmapFile >> 24;
  */
  myChars[6] = this->reservedBytes;
  myChars[10] = this->pixelDataOffset;

  return myChars;
}