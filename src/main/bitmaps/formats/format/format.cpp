#include <string>
#include "src/main/bitmaps/formats/format/format.h"

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

int Bitmaps::Format::bytesPerPixel() const
{
  return this->pixelFormat.bytesPerPixel();
}

int Bitmaps::Format::arraySizeInBytes() const
{  
  return this->_bytesPerRow * this->_heightInPixels;
}

int Bitmaps::Format::bytesPaddingPerRow() const
{
  return this->_bytesPaddingPerRow;
}

int Bitmaps::Format::bytesPerRow() const
{
  return this->_bytesPerRow;
}

int Bitmaps::Format::bytesPerUnpaddedRow() const
{  
  return this->_widthInPixels * this->bytesPerPixel();
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
  this->calculateRowPadding();
  this->calculateBytesPerRow();
}

void Bitmaps::Format::setHeightInPixels(int height)
{
  this->_heightInPixels = height;
}

void Bitmaps::Format::calculateRowPadding()
{
  int differenceInAlignment = this->bytesPerUnpaddedRow() % 4;

  this->_bytesPaddingPerRow = (
    differenceInAlignment ? 4 - differenceInAlignment : 0);
}

void Bitmaps::Format::calculateBytesPerRow()
{
  this->_bytesPerRow = this->bytesPerUnpaddedRow() + this->_bytesPaddingPerRow;
}