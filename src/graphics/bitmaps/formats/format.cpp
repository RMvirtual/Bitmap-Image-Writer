#include <string>
#include "src/graphics/bitmaps/formats/format.h"

Bitmaps::Format::Format()
{
  // pass.
}

std::string Bitmaps::Format::name() const
{
  return this->_name;
}

int Bitmaps::Format::bitsPerPixel() const
{
  return this->_bitsPerPixel;
}

int Bitmaps::Format::pixelSizeInBytes() const
{
  return this->_pixelSizeInBytes;
}

std::vector<std::string> Bitmaps::Format::colourNames() const
{
  return this->_colourNames;
}

int Bitmaps::Format::widthInPixels() const
{
  return this->_widthInPixels;
}

int Bitmaps::Format::heightInPixels() const
{
  return this->_heightInPixels;
}

int Bitmaps::Format::arraySizeInBytes() const
{  
  return this->_rowSizeInBytes * this->_heightInPixels;
}

int Bitmaps::Format::rowPaddingInBytes() const
{
  return this->_rowPaddingInBytes;
}

int Bitmaps::Format::rowSizeInBytes() const
{
  return this->_rowSizeInBytes;
}

void Bitmaps::Format::setName(std::string name)
{
  this->_name = name;
}

void Bitmaps::Format::setBitsPerPixel(int bitsPerPixel)
{
  this->_bitsPerPixel = bitsPerPixel;
  this->processPixelSizeInBytes();
}

void Bitmaps::Format::setColourNames(std::vector<std::string> colourNames)
{
  this->_colourNames = colourNames;
}

void Bitmaps::Format::setWidthInPixels(int width)
{
  this->_widthInPixels = width;
  this->processRowPaddingInBytes();
  this->processRowSizeInBytes();
}

void Bitmaps::Format::setHeightInPixels(int height)
{
  this->_heightInPixels = height;
}

void Bitmaps::Format::processRowPaddingInBytes()
{
  int differenceInAlignment = this->unpaddedRowSize() % 4;

  if (differenceInAlignment)
    this->_rowPaddingInBytes = 4 - differenceInAlignment;
}

int Bitmaps::Format::unpaddedRowSize() const
{  
  return this->_widthInPixels * this->_pixelSizeInBytes;
}

void Bitmaps::Format::processRowSizeInBytes()
{  
  this->_rowSizeInBytes = (
    this->_widthInPixels * this->_pixelSizeInBytes + this->_rowPaddingInBytes);
}

void Bitmaps::Format::processPixelSizeInBytes()
{
  this->_pixelSizeInBytes = this->_bitsPerPixel / 8;
}