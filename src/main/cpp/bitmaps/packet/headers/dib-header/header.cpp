#include <cstdint>

#include "src/main/cpp/bitmaps/packet/headers/dib-header/header.h"

Bitmaps::DibHeader::DibHeader()
{
  this->initialiseDefaultValues();
}

Bitmaps::DibHeader::DibHeader(int widthInPixels, int heightInPixels)
{
  this->initialiseDefaultValues();
  this->setWidthInPixels(widthInPixels);
  this->setHeightInPixels(heightInPixels);  
}

Bitmaps::DibHeader::DibHeader(Bitmaps::Format format)
{
  this->initialiseDefaultValues();
  this->setWidthInPixels(format.widthInPixels());
  this->setHeightInPixels(format.heightInPixels());
  this->setBitsPerPixel(format.bitsPerPixel());
  this->setSizeOfPixelArray(format.arraySizeInBytes());
}


Bitmaps::DibHeader Bitmaps::DibHeader::fromValues(
  const Bitmaps::DibHeaderValues& values)
{
  Bitmaps::DibHeader header {};

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

void Bitmaps::DibHeader::initialiseDefaultValues()
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

int Bitmaps::DibHeader::headerSizeInBytes() const
{
  return 40;
}

void Bitmaps::DibHeader::setWidthInPixels(int32_t widthInPixels)
{
  this->_widthInPixels = widthInPixels;
}

void Bitmaps::DibHeader::setHeightInPixels(int32_t heightInPixels)
{
  this->_heightInPixels = heightInPixels;
}

void Bitmaps::DibHeader::setNumberOfColourPlanes(
  uint16_t numberOfColorPlanes)
{
  this->_numberOfColorPlanes = numberOfColorPlanes;
}

void Bitmaps::DibHeader::setBitsPerPixel(uint16_t bitsPerPixel)
{
  this->_bitsPerPixel = bitsPerPixel;
}

void Bitmaps::DibHeader::setCompressionMethod(uint32_t compressionMethod)
{
  this->_compressionMethod = compressionMethod;
}

void Bitmaps::DibHeader::setSizeOfPixelArray(uint32_t pixelArraySize)
{
  this->_sizeOfPixelArray = pixelArraySize;
}

void Bitmaps::DibHeader::setHorizontalResolution(int32_t pixelsPerMetre)
{
  this->_horizontalResolution = pixelsPerMetre;
}

void Bitmaps::DibHeader::setVerticalResolution(int32_t pixelsPerMetre)
{
  this->_verticalResolution = pixelsPerMetre;
}

void Bitmaps::DibHeader::setColorTableEntries(uint32_t colorTableEntries)
{
  this->_colorTableEntries = colorTableEntries;
}

void Bitmaps::DibHeader::setImportantColours(uint32_t importantColors)
{
  this->_importantColors = importantColors;
}

int32_t Bitmaps::DibHeader::widthInPixels() const
{
  return this->_widthInPixels;
}

int32_t Bitmaps::DibHeader::heightInPixels() const
{
  return this->_heightInPixels;
}

uint16_t Bitmaps::DibHeader::numberOfColorPlanes() const
{
  return this->_numberOfColorPlanes;
}

uint16_t Bitmaps::DibHeader::bitsPerPixel() const
{
  return this->_bitsPerPixel;
}

uint32_t Bitmaps::DibHeader::compressionMethod() const
{
  return this->_compressionMethod;
}

uint32_t Bitmaps::DibHeader::sizeOfPixelArray() const
{
  return this->_sizeOfPixelArray;
}

int32_t Bitmaps::DibHeader::horizontalResolution() const
{
  return this->_horizontalResolution;
}

int32_t Bitmaps::DibHeader::verticalResolution() const
{
  return this->_verticalResolution;
}

uint32_t Bitmaps::DibHeader::colorTableEntries() const
{
  return this->_colorTableEntries;
}

uint32_t Bitmaps::DibHeader::importantColors() const
{
  return this->_importantColors;
}