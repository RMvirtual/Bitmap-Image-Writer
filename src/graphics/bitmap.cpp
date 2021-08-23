#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "bitmap.h"

using namespace std;

char* BitmapFileHeader::toBytes()
{
  int sizeInBytes = this->getSizeOfHeaderInBytes();
  char fileHeader[] = {
    0,0, // signature
    0,0,0,0, // image file size in bytes
    0,0,0,0, // reserved
    0,0,0,0 // start of pixel array
  };

  cout << sizeof(fileHeader) << endl;

  fileHeader[0] = (char) this->bitmapSignatureBytes[0];
  fileHeader[1] = (char) this->bitmapSignatureBytes[1];
  fileHeader[2] = (char) this->sizeOfBitmapFile;
  fileHeader[3] = (char) this->reservedBytes;
  fileHeader[4] = (char) this->pixelDataOffset;

  return fileHeader;
}

char* BitmapFileHeader::toBytesFromString()
{
  vector<unsigned char> intToBytes = {};
  
  intToBytes.push_back(bitmapSignatureBytes[0]);
  intToBytes.push_back(bitmapSignatureBytes[1]);
  intToBytes.push_back(sizeOfBitmapFile);
  intToBytes.push_back(this->reservedBytes);
  intToBytes.push_back(this->pixelDataOffset);

  char * myChars = new char[14];

  myChars[0] = this->bitmapSignatureBytes[0];
  myChars[1] = this->bitmapSignatureBytes[1];
  myChars[2] = this->sizeOfBitmapFile;

  return myChars;
}

int BitmapFileHeader::getSizeOfHeaderInBytes()
{
  return 14;
}