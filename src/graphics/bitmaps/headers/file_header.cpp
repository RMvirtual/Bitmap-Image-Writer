#include <cstdint>

#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/common/byte_array.h"

BitmapFileHeader::BitmapFileHeader(int sizeOfHeaderInBytes, int widthInPixels, int heightInPixels)
: BitmapHeader {sizeOfHeaderInBytes}
{
  this->bitmapSignatureBytes[0] = 'B';
  this->bitmapSignatureBytes[1] = 'M';

  int metadataSize = 54;
  int sizeOfPixels = 3 * widthInPixels * heightInPixels;
  this->sizeOfBitmapFile = metadataSize + sizeOfPixels;
  
  this->reservedBytes = 0;
  this->pixelDataOffset = metadataSize;
}

char* BitmapFileHeader::toBytes()
{
  ByteArrayBuilder byteArrayBuilder;

  byteArrayBuilder.addValue(this->bitmapSignatureBytes[0]);
  byteArrayBuilder.addValue(this->bitmapSignatureBytes[1]);
  byteArrayBuilder.addValue(this->sizeOfBitmapFile);
  byteArrayBuilder.addValue(this->reservedBytes);
  byteArrayBuilder.addValue(this->pixelDataOffset);

  char* byteArray = byteArrayBuilder.toBytes();

  return byteArray;
}