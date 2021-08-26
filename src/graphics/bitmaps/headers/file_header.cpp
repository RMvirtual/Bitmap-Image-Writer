#include <cstdint>
#include <iostream>

#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/common/byte_array.h"

BitmapFileHeader::BitmapFileHeader()
: BitmapHeader {}
{
  this->initialiseDefaultValues();
  this->setSizeOfHeaderInBytes(14);
}

BitmapFileHeader::BitmapFileHeader(int sizeOfHeaderInBytes)
: BitmapHeader {sizeOfHeaderInBytes}
{
  this->initialiseDefaultValues();
}

BitmapFileHeader::BitmapFileHeader(int sizeOfHeaderInBytes, int widthInPixels, int heightInPixels)
: BitmapHeader {sizeOfHeaderInBytes}
{
  this->initialiseDefaultValues();

  int metadataSize = 54;

  int sizeOfPixelArray = this->calculateSizeOfPixelArray(
    widthInPixels, heightInPixels);

  this->sizeOfBitmapFile = metadataSize + sizeOfPixelArray;  
  this->pixelDataOffset = metadataSize;
}

char* BitmapFileHeader::toBytes()
{
  ByteArrayBuilder byteArrayBuilder;

  byteArrayBuilder.addValue(this->signatureBytes[0]);
  byteArrayBuilder.addValue(this->signatureBytes[1]);
  byteArrayBuilder.addValue(this->sizeOfBitmapFile);
  byteArrayBuilder.addValue(this->reservedBytes);
  byteArrayBuilder.addValue(this->pixelDataOffset);

  char* byteArray = byteArrayBuilder.toBytes();

  return byteArray;
}

void BitmapFileHeader::initialiseDefaultValues()
{
  this->setSignatureBytes('B', 'M');

  this->sizeOfBitmapFile = 54;
  this->reservedBytes = 0;
  this->pixelDataOffset = 54;
}

int BitmapFileHeader::calculateSizeOfPixelArray(
  int widthInPixels, int heightInPixels)
{
  int metadataSize = 54;
  int sizeOfPixelArray = 3 * widthInPixels * heightInPixels;

  return sizeOfPixelArray;
}

void BitmapFileHeader::setSignatureBytes(std::string bytesSignature)
{
  this->signatureBytes[0] = bytesSignature[0];
  this->signatureBytes[0] = bytesSignature[1];
}

void BitmapFileHeader::setSignatureBytes(
  char firstSignatureByte, char secondSignatureByte)
{
  this->signatureBytes[0] = firstSignatureByte;
  this->signatureBytes[1] = secondSignatureByte;
}

void BitmapFileHeader::setSizeOfBitmapFile(uint32_t sizeOfBitmapFile)
{
  this->sizeOfBitmapFile = sizeOfBitmapFile;
}

void BitmapFileHeader::setReservedBytes(uint32_t reservedBytes)
{
  this->reservedBytes = reservedBytes;
}

void BitmapFileHeader::setPixelDataOffset(uint32_t pixelDataOffsetInBytes)
{
  this->pixelDataOffset = pixelDataOffsetInBytes;
}

std::string BitmapFileHeader::getSignatureBytes()
{
  std::string signatureBytes = "";
  signatureBytes += this->signatureBytes[0];
  signatureBytes += this->signatureBytes[1];

  return signatureBytes;
}

uint32_t BitmapFileHeader::getSizeOfBitmapFile()
{
  return this->sizeOfBitmapFile;
}

uint32_t BitmapFileHeader::getReservedBytes()
{
  return this->reservedBytes;
}

uint32_t BitmapFileHeader::getPixelDataOffset()
{
  return this->pixelDataOffset;
}