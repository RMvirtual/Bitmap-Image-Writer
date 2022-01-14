#include <cstdint>

#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array_size_calculator.h"
#include "src/common/byte_array_builder.h"

BitmapHeaders::FileHeader::FileHeader()
{
  this->initialiseDefaultValues();
}

BitmapHeaders::FileHeader::FileHeader(int widthInPixels, int heightInPixels)
{
  this->initialiseDefaultValues();

  int pixelArraySize = Pixels::calculatePixelArraySizeInBytes(
    widthInPixels, heightInPixels);

  this->sizeOfBitmapFile = this->pixelDataOffset + pixelArraySize;
}

BitmapHeaders::FileHeader BitmapHeaders::FileHeader::fromValues(
  BitmapHeaders::FileHeaderValues values)
{
  BitmapHeaders::FileHeader header {};

  header.setSignatureBytes(values.signatureBytes);
  header.setSizeOfBitmapFile(values.fileSize);
  header.setReservedBytes(values.reservedBytes);
  header.setPixelDataOffset(values.pixelDataOffsetInBytes);

  return header;
}

void BitmapHeaders::FileHeader::initialiseDefaultValues()
{
  this->setSignatureBytes('B', 'M');

  this->sizeOfBitmapFile = 54;
  this->reservedBytes = 0;
  this->pixelDataOffset = 54;
}

void BitmapHeaders::FileHeader::setSignatureBytes(std::string bytesSignature)
{
  this->signatureBytes[0] = bytesSignature[0];
  this->signatureBytes[1] = bytesSignature[1];
}

void BitmapHeaders::FileHeader::setSignatureBytes(
  char firstByte, char secondByte)
{
  this->signatureBytes[0] = firstByte;
  this->signatureBytes[1] = secondByte;
}

void BitmapHeaders::FileHeader::setSizeOfBitmapFile(uint32_t sizeOfBitmapFile)
{
  this->sizeOfBitmapFile = sizeOfBitmapFile;
}

void BitmapHeaders::FileHeader::setReservedBytes(uint32_t reservedBytes)
{
  this->reservedBytes = reservedBytes;
}

void BitmapHeaders::FileHeader::setPixelDataOffset(
  uint32_t pixelDataOffsetInBytes)
{
  this->pixelDataOffset = pixelDataOffsetInBytes;
}

std::string BitmapHeaders::FileHeader::getSignatureBytes()
{
  std::string signatureBytes = "";
  signatureBytes += this->signatureBytes[0];
  signatureBytes += this->signatureBytes[1];

  return signatureBytes;
}

uint32_t BitmapHeaders::FileHeader::getSizeOfBitmapFile()
{
  return this->sizeOfBitmapFile;
}

int BitmapHeaders::FileHeader::getPixelArraySizeInBytes()
{
  return this->sizeOfBitmapFile - this->pixelDataOffset;
}

uint32_t BitmapHeaders::FileHeader::getReservedBytes()
{
  return this->reservedBytes;
}

uint32_t BitmapHeaders::FileHeader::getPixelDataOffset()
{
  return this->pixelDataOffset;
}