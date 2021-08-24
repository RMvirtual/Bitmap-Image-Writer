#include "src/graphics/bitmaps/file_header.h"
#include "src/common/byte_array.h"

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
  ByteArrayBuilder byteArrayBuilder;

  byteArrayBuilder.addValue(this->bitmapSignatureBytes[0]);
  byteArrayBuilder.addValue(this->bitmapSignatureBytes[1]);
  byteArrayBuilder.addValue(this->sizeOfBitmapFile);
  byteArrayBuilder.addValue(this->reservedBytes);
  byteArrayBuilder.addValue(this->pixelDataOffset);

  char* byteArray = byteArrayBuilder.toArray();

  return byteArray;
}