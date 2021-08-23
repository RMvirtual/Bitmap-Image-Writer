#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "bitmap.h"

using namespace std;

char* BitmapFileHeader::toBytes()
{
  char * myChars = new char[14];

  // Initialise empty values in array instead of random values.
  for (int i = 0; i < 14; i++) {
    myChars[i] = 0;
  }

  myChars[0] = this->bitmapSignatureBytes[0];
  std::cout << myChars << endl;

  myChars[1] = this->bitmapSignatureBytes[1];
  std::cout << myChars << endl;

  myChars[2] = this->sizeOfBitmapFile;
  std::cout << myChars << endl;

  myChars[6] = this->reservedBytes;
  std::cout << myChars << endl;

  myChars[10] = this->pixelDataOffset;
  std::cout << myChars << endl;

  return myChars;
}

int BitmapFileHeader::getSizeOfHeaderInBytes()
{
  return 14;
}