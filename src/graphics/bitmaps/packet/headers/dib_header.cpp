#include <cstdint>

#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/common/byte_array.h"

BitmapHeaders::DibHeader::DibHeader()
: BitmapHeaders::Header {40}
{
  this->initialiseDefaultValues();
}

BitmapHeaders::DibHeader::DibHeader(int widthInPixels, int heightInPixels)
: BitmapHeaders::Header {40}
{
  this->initialiseDefaultValues();

  this->widthInPixels = widthInPixels;
  this->heightInPixels = heightInPixels;  
}

void BitmapHeaders::DibHeader::initialiseDefaultValues()
{
  this->widthInPixels = 0;
  this->heightInPixels = 0;
  this->numberOfColorPlanes = 1; 
  this->colorDepth = 24; 
  this->compressionMethod = 0;  
  this->rawBitmapDataSize = 0; 
  this->horizontalPixelsPerMetre = 0;
  this->verticalPixelsPerMetre = 0; 
  this->colorTableEntries = 0;
  this->importantColors = 0; 
}

char* BitmapHeaders::DibHeader::toBytes()
{
  ByteArrayBuilder byteArrayBuilder = this->getByteArrayBuilder();
  char* byteArray = byteArrayBuilder.toBytes();

  return byteArray;
}

ByteArrayBuilder BitmapHeaders::DibHeader::getByteArrayBuilder()
{
  ByteArrayBuilder byteArrayBuilder;

  byteArrayBuilder.addValue(this->getSizeOfHeaderInBytes());
  byteArrayBuilder.addValue(this->widthInPixels);
  byteArrayBuilder.addValue(this->heightInPixels);
  byteArrayBuilder.addValue(this->numberOfColorPlanes);
  byteArrayBuilder.addValue(this->colorDepth);
  byteArrayBuilder.addValue(this->compressionMethod);
  byteArrayBuilder.addValue(this->rawBitmapDataSize);
  byteArrayBuilder.addValue(this->horizontalPixelsPerMetre);
  byteArrayBuilder.addValue(this->verticalPixelsPerMetre);
  byteArrayBuilder.addValue(this->colorTableEntries);
  byteArrayBuilder.addValue(this->importantColors);

  return byteArrayBuilder;
}

void BitmapHeaders::DibHeader::setWidthInPixels(int32_t widthInPixels)
{
  this->widthInPixels = widthInPixels;
}

void BitmapHeaders::DibHeader::setHeightInPixels(int32_t heightInPixels)
{
  this->heightInPixels = heightInPixels;
}

void BitmapHeaders::DibHeader::setNumberOfColourPlanes(
  uint16_t numberOfColorPlanes)
{
  this->numberOfColorPlanes = numberOfColorPlanes;
}

void BitmapHeaders::DibHeader::setColorDepth(uint16_t colorDepth)
{
  this->colorDepth = colorDepth;
}

void BitmapHeaders::DibHeader::setCompressionMethod(
  uint32_t compressionMethod)
{
  this->compressionMethod = compressionMethod;
}

void BitmapHeaders::DibHeader::setRawBitmapDataSize(
  uint32_t rawBitmapDataSize)
{
  this->rawBitmapDataSize = rawBitmapDataSize;
}

void BitmapHeaders::DibHeader::setHorizontalPixelsPerMetre(
  int32_t horizontalPixelsPerMetre)
{
  this->horizontalPixelsPerMetre = horizontalPixelsPerMetre;
}

void BitmapHeaders::DibHeader::setVerticalPixelsPerMetre(
  int32_t verticalPixelsPerMetre)
{
  this->verticalPixelsPerMetre = verticalPixelsPerMetre;
}

void BitmapHeaders::DibHeader::setColorTableEntries(
  uint32_t colorTableEntries)
{
  this->colorTableEntries = colorTableEntries;
}

void BitmapHeaders::DibHeader::setImportantColours(uint32_t importantColors)
{
  this->importantColors = importantColors;
}

int32_t BitmapHeaders::DibHeader::getWidthInPixels()
{
  return this->widthInPixels;
}

int32_t BitmapHeaders::DibHeader::getHeightInPixels()
{
  return this->heightInPixels;
}

uint16_t BitmapHeaders::DibHeader::getNumberOfColorPlanes()
{
  return this->numberOfColorPlanes;
}

uint16_t BitmapHeaders::DibHeader::getColorDepth()
{
  return this->colorDepth;
}

uint32_t BitmapHeaders::DibHeader::getCompressionMethod()
{
  return this->compressionMethod;
}

uint32_t BitmapHeaders::DibHeader::getRawBitmapDataSize()
{
  return this->rawBitmapDataSize;
}

int32_t BitmapHeaders::DibHeader::getHorizontalPixelsPerMetre()
{
  return this->horizontalPixelsPerMetre;
}

int32_t BitmapHeaders::DibHeader::getVerticalPixelsPerMetre()
{
  return this->verticalPixelsPerMetre;
}

uint32_t BitmapHeaders::DibHeader::getColorTableEntries()
{
  return this->colorTableEntries;
}

uint32_t BitmapHeaders::DibHeader::getImportantColors()
{
  return this->importantColors;
}