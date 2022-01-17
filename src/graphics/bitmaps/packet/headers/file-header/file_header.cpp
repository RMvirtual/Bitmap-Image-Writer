#include <cstdint>

#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/size-calculator/pixel_array_size_calculator.h"

BitmapHeaders::FileHeader::FileHeader()
{
  this->initialiseDefaultValues();
}

BitmapHeaders::FileHeader::FileHeader(int widthInPixels, int heightInPixels)
{
  this->initialiseDefaultValues();

  int pixelArraySize = Pixels::calculatePixelArraySizeInBytes(
    widthInPixels, heightInPixels);

  this->_fileSizeInBytes = this->_pixelArrayOffsetInBytes + pixelArraySize;
}

BitmapHeaders::FileHeader BitmapHeaders::FileHeader::fromValues(
  BitmapHeaders::FileHeaderValues values)
{
  BitmapHeaders::FileHeader header {};

  header.setSignatureBytes(values.signatureBytes);
  header.setFileSizeInBytes(values.fileSize);
  header.setReservedBytes(values.reservedBytes);
  header.setPixelArrayOffsetInBytes(values.pixelDataOffsetInBytes);

  return header;
}

void BitmapHeaders::FileHeader::initialiseDefaultValues()
{
  this->setSignatureBytes('B', 'M');

  this->_fileSizeInBytes = 54;
  this->_reservedBytes = 0;
  this->_pixelArrayOffsetInBytes = 54;
}

void BitmapHeaders::FileHeader::setSignatureBytes(std::string bytesSignature)
{
  this->_signatureBytes[0] = bytesSignature[0];
  this->_signatureBytes[1] = bytesSignature[1];
}

void BitmapHeaders::FileHeader::setSignatureBytes(
  char firstByte, char secondByte)
{
  this->_signatureBytes[0] = firstByte;
  this->_signatureBytes[1] = secondByte;
}

void BitmapHeaders::FileHeader::setFileSizeInBytes(uint32_t sizeOfBitmapFile)
{
  this->_fileSizeInBytes = sizeOfBitmapFile;
}

void BitmapHeaders::FileHeader::setReservedBytes(uint32_t reservedBytes)
{
  this->_reservedBytes = reservedBytes;
}

void BitmapHeaders::FileHeader::setPixelArrayOffsetInBytes(uint32_t offsetInBytes)
{
  this->_pixelArrayOffsetInBytes = offsetInBytes;
}

std::string BitmapHeaders::FileHeader::signatureBytes() const
{
  std::string signatureBytes = "";
  signatureBytes += this->_signatureBytes[0];
  signatureBytes += this->_signatureBytes[1];

  return signatureBytes;
}

uint32_t BitmapHeaders::FileHeader::fileSizeInBytes() const
{
  return this->_fileSizeInBytes;
}

int BitmapHeaders::FileHeader::pixelArraySizeInBytes() const
{
  return this->_fileSizeInBytes - this->_pixelArrayOffsetInBytes;
}

uint32_t BitmapHeaders::FileHeader::reservedBytes() const
{
  return this->_reservedBytes;
}

uint32_t BitmapHeaders::FileHeader::pixelArrayOffsetInBytes() const
{
  return this->_pixelArrayOffsetInBytes;
}