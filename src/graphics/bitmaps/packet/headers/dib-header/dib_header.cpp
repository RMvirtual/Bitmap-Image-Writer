#include <cstdint>

#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header_values.h"

BitmapHeaders::DibHeader::DibHeader()
{
  this->initialiseDefaultValues();
}

BitmapHeaders::DibHeader::DibHeader(int widthInPixels, int heightInPixels)
{
  this->initialiseDefaultValues();
  this->setWidthInPixels(widthInPixels);
  this->setHeightInPixels(heightInPixels);  
}

BitmapHeaders::DibHeader BitmapHeaders::DibHeader::fromValues(
  BitmapHeaders::DibHeaderValues values)
{
  BitmapHeaders::DibHeader header {};

  header.setWidthInPixels(values.widthInPixels);
  header.setHeightInPixels(values.heightInPixels);
  header.setNumberOfColourPlanes(values.numberOfColorPlanes);
  header.setColorDepth(values.colorDepth);
  header.setCompressionMethod(values.compressionMethod);
  header.setRawBitmapDataSize(values.rawBitmapDataSize);
  header.setHorizontalPixelsPerMetre(values.horizontalPixelsPerMetre);
  header.setVerticalPixelsPerMetre(values.verticalPixelsPerMetre);
  header.setColorTableEntries(values.colorTableEntries);
  header.setImportantColours(values.importantColors);

  return header;
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

int BitmapHeaders::DibHeader::getHeaderSizeInBytes() const
{
  return 40;
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

void BitmapHeaders::DibHeader::setCompressionMethod(uint32_t compressionMethod)
{
  this->compressionMethod = compressionMethod;
}

void BitmapHeaders::DibHeader::setRawBitmapDataSize(uint32_t rawBitmapDataSize)
{
  this->rawBitmapDataSize = rawBitmapDataSize;
}

void BitmapHeaders::DibHeader::setHorizontalPixelsPerMetre(
  int32_t pixelsPerMetre)
{
  this->horizontalPixelsPerMetre = pixelsPerMetre;
}

void BitmapHeaders::DibHeader::setVerticalPixelsPerMetre(
  int32_t pixelsPerMetre)
{
  this->verticalPixelsPerMetre = pixelsPerMetre;
}

void BitmapHeaders::DibHeader::setColorTableEntries(uint32_t colorTableEntries)
{
  this->colorTableEntries = colorTableEntries;
}

void BitmapHeaders::DibHeader::setImportantColours(uint32_t importantColors)
{
  this->importantColors = importantColors;
}

int32_t BitmapHeaders::DibHeader::getWidthInPixels() const
{
  return this->widthInPixels;
}

int32_t BitmapHeaders::DibHeader::getHeightInPixels() const
{
  return this->heightInPixels;
}

uint16_t BitmapHeaders::DibHeader::getNumberOfColorPlanes() const
{
  return this->numberOfColorPlanes;
}

uint16_t BitmapHeaders::DibHeader::getColorDepth() const
{
  return this->colorDepth;
}

uint32_t BitmapHeaders::DibHeader::getCompressionMethod() const
{
  return this->compressionMethod;
}

uint32_t BitmapHeaders::DibHeader::getRawBitmapDataSize() const
{
  return this->rawBitmapDataSize;
}

int32_t BitmapHeaders::DibHeader::getHorizontalPixelsPerMetre() const
{
  return this->horizontalPixelsPerMetre;
}

int32_t BitmapHeaders::DibHeader::getVerticalPixelsPerMetre() const
{
  return this->verticalPixelsPerMetre;
}

uint32_t BitmapHeaders::DibHeader::getColorTableEntries() const
{
  return this->colorTableEntries;
}

uint32_t BitmapHeaders::DibHeader::getImportantColors() const
{
  return this->importantColors;
}