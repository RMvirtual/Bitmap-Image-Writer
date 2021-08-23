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
  int size = 4;
  char * myChars = new char[size];

  /* Initialise empty values in array instead of random uninitialised
  values. */
  for (int i = 0; i < size; i++) {
    myChars[i] = 0;
  }

  cout << myChars << endl;
  myChars[0] = this->sizeOfThisHeader;
  cout << myChars << endl;

  return myChars;
}

int BitmapInfoHeader::getSizeOfHeaderInBytes()
{
  return 40;
}