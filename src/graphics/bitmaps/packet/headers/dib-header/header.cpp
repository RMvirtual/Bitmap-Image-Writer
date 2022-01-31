#include <cstdint>

#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/values.h"

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
  const BitmapHeaders::DibHeaderValues& values)
{
  BitmapHeaders::DibHeader header {};

  header.setWidthInPixels(values.widthInPixels);
  header.setHeightInPixels(values.heightInPixels);
  header.setNumberOfColourPlanes(values.numberOfColorPlanes);
  header.setBitsPerPixel(values.bitsPerPixel);
  header.setCompressionMethod(values.compressionMethod);
  header.setSizeOfPixelArray(values.pixelArraySizeInBytes);
  header.setHorizontalResolution(values.horizontalResolution);
  header.setVerticalResolution(values.verticalResolution);
  header.setColorTableEntries(values.colorTableEntries);
  header.setImportantColours(values.importantColors);

  return header;
}

void BitmapHeaders::DibHeader::initialiseDefaultValues()
{
  this->_widthInPixels = 0;
  this->_heightInPixels = 0;
  this->_numberOfColorPlanes = 1; 
  this->_bitsPerPixel = 32; 
  this->_compressionMethod = 0;  
  this->_sizeOfPixelArray = 0;
  this->_horizontalResolution = 0;
  this->_verticalResolution = 0; 
  this->_colorTableEntries = 0;
  this->_importantColors = 0; 
}

int BitmapHeaders::DibHeader::headerSizeInBytes() const
{
  return 40;
}

void BitmapHeaders::DibHeader::setWidthInPixels(int32_t widthInPixels)
{
  this->_widthInPixels = widthInPixels;
}

void BitmapHeaders::DibHeader::setHeightInPixels(int32_t heightInPixels)
{
  this->_heightInPixels = heightInPixels;
}

void BitmapHeaders::DibHeader::setNumberOfColourPlanes(
  uint16_t numberOfColorPlanes)
{
  this->_numberOfColorPlanes = numberOfColorPlanes;
}

void BitmapHeaders::DibHeader::setBitsPerPixel(uint16_t bitsPerPixel)
{
  this->_bitsPerPixel = bitsPerPixel;
}

void BitmapHeaders::DibHeader::setCompressionMethod(uint32_t compressionMethod)
{
  this->_compressionMethod = compressionMethod;
}

void BitmapHeaders::DibHeader::setSizeOfPixelArray(uint32_t pixelArraySize)
{
  this->_sizeOfPixelArray = pixelArraySize;
}

void BitmapHeaders::DibHeader::setHorizontalResolution(int32_t pixelsPerMetre)
{
  this->_horizontalResolution = pixelsPerMetre;
}

void BitmapHeaders::DibHeader::setVerticalResolution(int32_t pixelsPerMetre)
{
  this->_verticalResolution = pixelsPerMetre;
}

void BitmapHeaders::DibHeader::setColorTableEntries(uint32_t colorTableEntries)
{
  this->_colorTableEntries = colorTableEntries;
}

void BitmapHeaders::DibHeader::setImportantColours(uint32_t importantColors)
{
  this->_importantColors = importantColors;
}

int32_t BitmapHeaders::DibHeader::widthInPixels() const
{
  return this->_widthInPixels;
}

int32_t BitmapHeaders::DibHeader::heightInPixels() const
{
  return this->_heightInPixels;
}

uint16_t BitmapHeaders::DibHeader::numberOfColorPlanes() const
{
  return this->_numberOfColorPlanes;
}

uint16_t BitmapHeaders::DibHeader::bitsPerPixel() const
{
  return this->_bitsPerPixel;
}

uint32_t BitmapHeaders::DibHeader::compressionMethod() const
{
  return this->_compressionMethod;
}

uint32_t BitmapHeaders::DibHeader::sizeOfPixelArray() const
{
  return this->_sizeOfPixelArray;
}

int32_t BitmapHeaders::DibHeader::horizontalResolution() const
{
  return this->_horizontalResolution;
}

int32_t BitmapHeaders::DibHeader::verticalResolution() const
{
  return this->_verticalResolution;
}

uint32_t BitmapHeaders::DibHeader::colorTableEntries() const
{
  return this->_colorTableEntries;
}

uint32_t BitmapHeaders::DibHeader::importantColors() const
{
  return this->_importantColors;
}