#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array_size_calculator.h"

#include <string>
#include <queue>
#include <vector>
#include <iomanip>
#include <iostream>

Pixels::PixelArray::PixelArray()
{
  this->pixels = std::vector<Pixels::RGBPixel> {};
  this->initialisePixelArray(0, 0);
}

Pixels::PixelArray::PixelArray(
  std::vector<Pixels::RGBPixel> pixels, int widthInPixels, int heightInPixels)
{
  this->pixels = pixels;
  this->initialisePixelArray(widthInPixels, heightInPixels);
}

void Pixels::PixelArray::initialisePixelArray(
  int widthInPixels, int heightInPixels)
{
  this->widthInPixels = widthInPixels;
  this->heightInPixels = heightInPixels;
  this->populateMissingPixels();
  this->calculateRowStride();
}

void Pixels::PixelArray::calculateRowStride()
{
  this->rowPadding = Pixels::calculateRowPadding(this->widthInPixels);
  this->rowSizeInBytes = Pixels::calculateRowSizeInBytes(this->widthInPixels);
}

void Pixels::PixelArray::populateMissingPixels()
{
  int numberOfMissingPixels = this->getNumberOfMissingPixels();
  bool hasMissingPixels = (numberOfMissingPixels > 0);

  if (hasMissingPixels)
    this->addBlankPixels(numberOfMissingPixels);
}

void Pixels::PixelArray::addBlankPixels(int numberOfPixelsToAdd)
{
  for (int pixelNo = 0; pixelNo < numberOfPixelsToAdd; pixelNo++)
    this->addBlankPixel();
}

void Pixels::PixelArray::addBlankPixel()
{
  Colours blackColours = {0, 0, 0};
  Pixels::RGBPixel blankPixel {blackColours};
  this->pixels.push_back(blankPixel);
}

int Pixels::PixelArray::convertToIndex(int rowNo, int columnNo)
{
  return rowNo * this->widthInPixels + columnNo;
}

void Pixels::PixelArray::setPixel(Pixels::PixelData pixelData)
{
  int index = this->convertToIndex(pixelData.rowNo, pixelData.columnNo);
  bool indexOutOfBounds = (index < 0 || index > this->sizeInPixels());

  if (indexOutOfBounds) {
    throw std::runtime_error(
      "Pixels::PixelArray::setPixel(): Index "
      + std::to_string(pixelData.rowNo) + ", "
      + std::to_string(pixelData.columnNo) + " out of bounds."
    );
  }

  this->pixels[index] = RGBPixel(pixelData.colours);
}

void Pixels::PixelArray::setWidthInPixels(int width)
{
  this->initialisePixelArray(width, this->heightInPixels);
}

void Pixels::PixelArray::setHeightInPixels(int height)
{
  this->initialisePixelArray(this->widthInPixels, height);
}

Pixels::RGBPixel Pixels::PixelArray::getPixel(int rowNo, int columnNo)
{
  int index = this->convertToIndex(rowNo, columnNo);
  
  return this->pixels[index];
}

Pixels::RGBPixel Pixels::PixelArray::getPixel(int index)
{
  return this->pixels[index];
}

int Pixels::PixelArray::getNumberOfMissingPixels()
{
  int totalExpectedPixels = this->sizeInPixels();
  int numberOfActualPixels = this->pixels.size();
  
  return totalExpectedPixels - numberOfActualPixels;
}

int Pixels::PixelArray::getWidthInPixels()
{
  return this->widthInPixels;
}

int Pixels::PixelArray::getHeightInPixels()
{
  return this->heightInPixels;
}

int Pixels::PixelArray::getRowStride()
{
  return this->rowSizeInBytes;
}

int Pixels::PixelArray::sizeInBytes()
{
  return this->rowSizeInBytes * this->heightInPixels;
}

int Pixels::PixelArray::sizeInPixels()
{
  return this->widthInPixels * this->heightInPixels;
}