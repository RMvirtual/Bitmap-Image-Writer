#include <string>
#include "src/graphics/bitmaps/formats/format.h"

Pixels::Format::Format()
{
  // pass.
}

std::string Pixels::Format::name() const
{
  return this->_name;
}

int Pixels::Format::bitsPerPixel() const
{
  return this->_bitsPerPixel;
}

int Pixels::Format::pixelSizeInBytes() const
{
  return this->_pixelSizeInBytes;
}

std::vector<std::string> Pixels::Format::colourNames() const
{
  return this->_colourNames;
}

int Pixels::Format::widthInPixels() const
{
  return this->_widthInPixels;
}

int Pixels::Format::heightInPixels() const
{
  return this->_heightInPixels;
}

int Pixels::Format::arraySizeInBytes() const
{  
  return this->_rowSizeInBytes * this->_heightInPixels;
}

int Pixels::Format::rowPaddingInBytes() const
{
  return this->_rowPaddingInBytes;
}

int Pixels::Format::rowSizeInBytes() const
{
  return this->_rowSizeInBytes;
}

void Pixels::Format::setName(std::string name)
{
  this->_name = name;
}

void Pixels::Format::setBitsPerPixel(int bitsPerPixel)
{
  this->_bitsPerPixel = bitsPerPixel;
  this->processPixelSizeInBytes();
}

void Pixels::Format::setColourNames(std::vector<std::string> colourNames)
{
  this->_colourNames = colourNames;
}

void Pixels::Format::setWidthInPixels(int width)
{
  this->_widthInPixels = width;
  this->processRowPaddingInBytes();
  this->processRowSizeInBytes();
}

void Pixels::Format::setHeightInPixels(int height)
{
  this->_heightInPixels = height;
}

void Pixels::Format::processRowPaddingInBytes()
{
  int differenceInAlignment = this->unpaddedRowSize() % 4;

  if (differenceInAlignment)
    this->_rowPaddingInBytes = 4 - differenceInAlignment;
}

int Pixels::Format::unpaddedRowSize() const
{  
  return this->_widthInPixels * this->_pixelSizeInBytes;
}

void Pixels::Format::processRowSizeInBytes()
{  
  this->_rowSizeInBytes = (
    this->_widthInPixels * this->_pixelSizeInBytes + this->_rowPaddingInBytes);
}

void Pixels::Format::processPixelSizeInBytes()
{
  this->_pixelSizeInBytes = this->_bitsPerPixel / 8;
}