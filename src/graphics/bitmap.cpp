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
  myChars[3] = this->sizeOfBitmapFile >> 8;
  myChars[4] = this->sizeOfBitmapFile >> 16;
  myChars[5] = this->sizeOfBitmapFile >> 24;
  myChars[6] = this->reservedBytes;
  myChars[10] = this->pixelDataOffset;

  cout << myChars << endl;

  return myChars;
}

int BitmapFileHeader::getSizeOfHeaderInBytes()
{
  return 14;
}

char* BitmapInfoHeader::toBytes()
{
  int size = 12;
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


  cout << (void *) myChars[4] << endl;
  return myChars;
}

int BitmapInfoHeader::getSizeOfHeaderInBytes()
{
  return 40;
}