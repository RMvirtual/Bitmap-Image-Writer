#include <cstdint>
#include <iostream>
#include <unordered_map>

#include "src/graphics/bitmaps/headers/dib_header.h"
#include "src/common/byte_array.h"

using namespace std;

BitmapDibHeader::BitmapDibHeader()
: BitmapHeader {40}
{
  this->initialiseDefaultValues();
}

BitmapDibHeader::BitmapDibHeader(int widthInPixels, int heightInPixels)
: BitmapHeader {40}
{
  this->initialiseDefaultValues();

  this->widthInPixels = widthInPixels;
  this->heightInPixels = heightInPixels;  
}

char* BitmapDibHeader::toBytes()
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

  char* byteArray = byteArrayBuilder.toBytes();

  return byteArray;
}

void BitmapDibHeader::initialiseDefaultValues()
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

void BitmapDibHeader::setWidthInPixels(int32_t widthInPixels)
{
  this->widthInPixels = widthInPixels;
}

void BitmapDibHeader::setHeightInPixels(int32_t heightInPixels)
{
  this->heightInPixels = heightInPixels;
}

void BitmapDibHeader::setNumberOfColourPlanes(uint16_t numberOfColorPlanes)
{
  this->numberOfColorPlanes = numberOfColorPlanes;
}

void BitmapDibHeader::setColorDepth(uint16_t colorDepth)
{
  this->colorDepth = colorDepth;
}

void BitmapDibHeader::setCompressionMethod(uint32_t compressionMethod)
{
  this->compressionMethod = compressionMethod;
}

void BitmapDibHeader::setRawBitmapDataSize(uint32_t rawBitmapDataSize)
{
  this->rawBitmapDataSize = rawBitmapDataSize;
}

void BitmapDibHeader::setHorizontalPixelsPerMetre(int32_t horizontalPixelsPerMetre)
{
  this->horizontalPixelsPerMetre = horizontalPixelsPerMetre;
}

void BitmapDibHeader::setVerticalPixelsPerMetre(int32_t verticalPixelsPerMetre)
{
  this->verticalPixelsPerMetre = verticalPixelsPerMetre;
}

void BitmapDibHeader::setColorTableEntries(uint32_t colorTableEntries)
{
  this->colorTableEntries = colorTableEntries;
}

void BitmapDibHeader::setImportantColours(uint32_t importantColors)
{
  this->importantColors = importantColors;
}

int32_t BitmapDibHeader::getWidthInPixels()
{
  return this->widthInPixels;
}

int32_t BitmapDibHeader::getHeightInPixels()
{
  return this->heightInPixels;
}

uint16_t BitmapDibHeader::getNumberOfColorPlanes()
{
  return this->numberOfColorPlanes;
}

uint16_t BitmapDibHeader::getColorDepth()
{
  return this->colorDepth;
}

uint32_t BitmapDibHeader::getCompressionMethod()
{
  return this->compressionMethod;
}

uint32_t BitmapDibHeader::getRawBitmapDataSize()
{
  return this->rawBitmapDataSize;
}

int32_t BitmapDibHeader::getHorizontalPixelsPerMetre()
{
  return this->horizontalPixelsPerMetre;
}

int32_t BitmapDibHeader::getVerticalPixelsPerMetre()
{
  return this->verticalPixelsPerMetre;
}

uint32_t BitmapDibHeader::getColorTableEntries()
{
  return this->colorTableEntries;
}

uint32_t BitmapDibHeader::getImportantColors()
{
  return this->importantColors;
}