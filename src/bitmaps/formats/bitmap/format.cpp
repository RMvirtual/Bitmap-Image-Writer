#include <string>
#include "src/bitmaps/formats/bitmap/format.h"

Bitmaps::Format::Format()
{
  // pass.
}

std::string Bitmaps::Format::name() const
{
  return this->_name;
}

Bitmaps::Colours Bitmaps::Format::colours() const
{
  return this->pixelFormat.colours();
}

std::vector<std::string> Bitmaps::Format::colourNames() const
{
  return this->pixelFormat.colourNames();
}

int Bitmaps::Format::widthInPixels() const
{
  return this->_widthInPixels;
}

int Bitmaps::Format::heightInPixels() const
{
  return this->_heightInPixels;
}

int Bitmaps::Format::bitsPerPixel() const
{
  return this->pixelFormat.bitsPerPixel();
}

int Bitmaps::Format::pixelSizeInBytes() const
{
  return this->pixelFormat.pixelSizeInBytes();
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

int Bitmaps::Format::unpaddedRowSizeInBytes() const
{  
  return this->_widthInPixels * this->pixelSizeInBytes();
}

void Bitmaps::Format::setName(std::string name)
{
  this->_name = name;
}

void Bitmaps::Format::setBitsPerPixel(int bitsPerPixel)
{
  this->pixelFormat.setBitsPerPixel(bitsPerPixel);
}

void Bitmaps::Format::setColourNames(std::vector<std::string> colourNames)
{
  this->pixelFormat.setColourNames(colourNames);
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
  int differenceInAlignment = this->unpaddedRowSizeInBytes() % 4;

  this->_rowPaddingInBytes = (
    differenceInAlignment ? 4 - differenceInAlignment : 0);
}

void Bitmaps::Format::processRowSizeInBytes()
{  
  this->_rowSizeInBytes = (
    this->unpaddedRowSizeInBytes() + this->_rowPaddingInBytes);
}