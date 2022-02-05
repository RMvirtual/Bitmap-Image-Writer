#include <string>
#include "src/bitmaps/formats/format.h"

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

Bitmaps::Colours Bitmaps::Format::colours() const
{
  return this->_colours;
}

std::vector<std::string> Bitmaps::Format::colourNames() const
{
  std::vector<std::string> colourNames;

  for (auto colour : this->_colours)
    colourNames.push_back(colour.first);

  return colourNames;
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
  this->_colours = {colourNames};
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

int Bitmaps::Format::unpaddedRowSizeInBytes() const
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