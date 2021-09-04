#include <cstdint>

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array_size_calculator.h"
#include "src/common/byte_array.h"

BitmapHeaders::FileHeader::FileHeader()
: BitmapHeaders::Header {14}
{
  this->initialiseDefaultValues();
}

BitmapHeaders::FileHeader::FileHeader(int widthInPixels, int heightInPixels)
: BitmapHeaders::Header {14}
{
  this->initialiseDefaultValues();

  int sizeOfPixelArray = this->calculateSizeOfPixelArray(
    widthInPixels, heightInPixels);

  this->sizeOfBitmapFile = this->pixelDataOffset + sizeOfPixelArray;
}

char* BitmapHeaders::FileHeader::toBytes()
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

void BitmapHeaders::FileHeader::initialiseDefaultValues()
{
  this->setSignatureBytes('B', 'M');

  this->sizeOfBitmapFile = 54;
  this->reservedBytes = 0;
  this->pixelDataOffset = 54;
}

int BitmapHeaders::FileHeader::calculateSizeOfPixelArray(
  int widthInPixels, int heightInPixels)
{
  int rowSizeInBytes = Pixels::calculateRowSizeInBytes(widthInPixels);
  int sizeOfPixelArray = rowSizeInBytes * heightInPixels;

  return sizeOfPixelArray;
}

void BitmapHeaders::FileHeader::setSignatureBytes(std::string bytesSignature)
{
  this->signatureBytes[0] = bytesSignature[0];
  this->signatureBytes[1] = bytesSignature[1];
}

void BitmapHeaders::FileHeader::setSignatureBytes(
  char firstSignatureByte, char secondSignatureByte)
{
  this->signatureBytes[0] = firstSignatureByte;
  this->signatureBytes[1] = secondSignatureByte;
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

uint32_t BitmapHeaders::FileHeader::getReservedBytes()
{
  return this->reservedBytes;
}

uint32_t BitmapHeaders::FileHeader::getPixelDataOffset()
{
  return this->pixelDataOffset;
}