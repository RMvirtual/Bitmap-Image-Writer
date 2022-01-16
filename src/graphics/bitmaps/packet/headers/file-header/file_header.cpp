#include <cstdint>

#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array_size_calculator.h"
#include "src/common/byte-array/byte_array_builder.h"

BitmapHeaders::FileHeader::FileHeader()
{
  this->initialiseDefaultValues();
}

BitmapHeaders::FileHeader::FileHeader(int widthInPixels, int heightInPixels)
{
  this->initialiseDefaultValues();

  int pixelArraySize = Pixels::calculatePixelArraySizeInBytes(
    widthInPixels, heightInPixels);

  this->sizeOfBitmapFileInBytes = this->pixelDataOffsetInBytes + pixelArraySize;
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

  this->sizeOfBitmapFileInBytes = 54;
  this->reservedBytesValue = 0;
  this->pixelDataOffsetInBytes = 54;
}

void BitmapHeaders::FileHeader::setSignatureBytes(std::string bytesSignature)
{
  this->signatureBytesValue[0] = bytesSignature[0];
  this->signatureBytesValue[1] = bytesSignature[1];
}

void BitmapHeaders::FileHeader::setSignatureBytes(
  char firstByte, char secondByte)
{
  this->signatureBytesValue[0] = firstByte;
  this->signatureBytesValue[1] = secondByte;
}

void BitmapHeaders::FileHeader::setSizeOfBitmapFile(uint32_t sizeOfBitmapFile)
{
  this->sizeOfBitmapFileInBytes = sizeOfBitmapFile;
}

void BitmapHeaders::FileHeader::setReservedBytes(uint32_t reservedBytes)
{
  this->reservedBytesValue = reservedBytes;
}

void BitmapHeaders::FileHeader::setPixelDataOffset(uint32_t offsetInBytes)
{
  this->pixelDataOffsetInBytes = offsetInBytes;
}

std::string BitmapHeaders::FileHeader::signatureBytes() const
{
  std::string signatureBytes = "";
  signatureBytes += this->signatureBytesValue[0];
  signatureBytes += this->signatureBytesValue[1];

  return signatureBytes;
}

uint32_t BitmapHeaders::FileHeader::sizeOfBitmapFile() const
{
  return this->sizeOfBitmapFileInBytes;
}

int BitmapHeaders::FileHeader::pixelArraySizeInBytes() const
{
  return this->sizeOfBitmapFileInBytes - this->pixelDataOffsetInBytes;
}

uint32_t BitmapHeaders::FileHeader::reservedBytes() const
{
  return this->reservedBytesValue;
}

uint32_t BitmapHeaders::FileHeader::pixelDataOffset() const
{
  return this->pixelDataOffsetInBytes;
}