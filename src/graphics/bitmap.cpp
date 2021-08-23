#include <iostream>
#include <string>
#include "bitmap.h"
#include <string.h>
#include <string>
 
#include <cstdint>
#include <fstream>

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
  string packet = "";

  packet += this->bitmapSignatureBytes[0];
  packet += this->bitmapSignatureBytes[1];

  cout << "Packet is now: " << packet << endl;

  return strdup(packet.c_str());
}

int BitmapFileHeader::getSizeOfHeaderInBytes()
{
  return 14;
}