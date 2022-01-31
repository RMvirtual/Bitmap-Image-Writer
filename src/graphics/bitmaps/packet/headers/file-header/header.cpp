#include <cstdint>

#include "src/graphics/bitmaps/packet/headers/file-header/header.h"

Bitmaps::FileHeader::FileHeader()
{
  this->initialiseDefaultValues();
}

Bitmaps::FileHeader::FileHeader(int pixelArraySizeInBytes)
{
  this->initialiseDefaultValues();

  this->_fileSizeInBytes = (
    this->_pixelArrayOffsetInBytes + pixelArraySizeInBytes);
}

Bitmaps::FileHeader Bitmaps::FileHeader::fromValues(
  Bitmaps::FileHeaderValues values)
{
  Bitmaps::FileHeader header {};

  header.setSignatureBytes(values.signatureBytes);
  header.setFileSizeInBytes(values.fileSize);
  header.setReservedBytes(values.reservedBytes);
  header.setPixelArrayOffsetInBytes(values.pixelDataOffsetInBytes);

  return header;
}

void Bitmaps::FileHeader::initialiseDefaultValues()
{
  this->setSignatureBytes('B', 'M');

  this->_fileSizeInBytes = 54;
  this->_reservedBytes = 0;
  this->_pixelArrayOffsetInBytes = 54;
}

void Bitmaps::FileHeader::setSignatureBytes(std::string bytesSignature)
{
  this->_signatureBytes[0] = bytesSignature[0];
  this->_signatureBytes[1] = bytesSignature[1];
}

void Bitmaps::FileHeader::setSignatureBytes(
  char firstByte, char secondByte)
{
  this->_signatureBytes[0] = firstByte;
  this->_signatureBytes[1] = secondByte;
}

void Bitmaps::FileHeader::setFileSizeInBytes(uint32_t sizeOfBitmapFile)
{
  this->_fileSizeInBytes = sizeOfBitmapFile;
}

void Bitmaps::FileHeader::setReservedBytes(uint32_t reservedBytes)
{
  this->_reservedBytes = reservedBytes;
}

void Bitmaps::FileHeader::setPixelArrayOffsetInBytes(uint32_t offsetInBytes)
{
  this->_pixelArrayOffsetInBytes = offsetInBytes;
}

std::string Bitmaps::FileHeader::signatureBytes() const
{
  std::string signatureBytes = "";
  signatureBytes += this->_signatureBytes[0];
  signatureBytes += this->_signatureBytes[1];

  return signatureBytes;
}

uint32_t Bitmaps::FileHeader::fileSizeInBytes() const
{
  return this->_fileSizeInBytes;
}

int Bitmaps::FileHeader::pixelArraySizeInBytes() const
{
  return this->_fileSizeInBytes - this->_pixelArrayOffsetInBytes;
}

uint32_t Bitmaps::FileHeader::reservedBytes() const
{
  return this->_reservedBytes;
}

uint32_t Bitmaps::FileHeader::pixelArrayOffsetInBytes() const
{
  return this->_pixelArrayOffsetInBytes;
}