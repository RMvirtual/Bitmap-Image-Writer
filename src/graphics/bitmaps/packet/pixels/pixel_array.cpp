#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/common/byte_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array_size_calculator.h"

#include <string>
#include <queue>
#include <vector>
#include <iomanip>
#include <iostream>

Pixels::PixelArray::PixelArray()
{
  this->pixels = std::vector<Pixels::Pixel> {};
  this->initialisePixelArray(0, 0);
}

Pixels::PixelArray::PixelArray(
  std::vector<Pixels::Pixel> pixels, int widthInPixels, int heightInPixels)
{
  if (pixels.size() != widthInPixels * heightInPixels)
    throw std::length_error(
      "Number of pixels does not match given height and width. " \
      "Number of pixels is " + std::to_string(pixels.size()) + " while " \
      "correct size from parameters is " + std::to_string(
        widthInPixels * heightInPixels)
    );

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

char* Pixels::PixelArray::toBytes()
{
  ByteArrayBuilder byteArrayBuilder;

  for (int rowNo = 0; rowNo < this->heightInPixels; rowNo++) {
    char* pixelRowBytes = this->getRowOfPixelsAsBytes(rowNo);
    byteArrayBuilder.addValues(pixelRowBytes, this->rowSizeInBytes);

    delete[] pixelRowBytes;
  }

  return byteArrayBuilder.toBytes();
}

char* Pixels::PixelArray::getRowOfPixelsAsBytes(int rowNo)
{
  ByteArrayBuilder byteArrayBuilder;

  for (int columnNo = 0; columnNo < this->widthInPixels; columnNo++) {
    int index = this->getPixelIndexByRowAndColumn(rowNo, columnNo);
    Pixels::Pixel pixel = this->pixels[index];

    this->addPixelToByteArrayBuilder(pixel, &byteArrayBuilder);
  }

  this->addPaddingBytesToByteArrayBuilder(&byteArrayBuilder);

  return byteArrayBuilder.toBytes();
}

void Pixels::PixelArray::addPixelToByteArrayBuilder(
  Pixels::Pixel pixel, ByteArrayBuilder* byteArrayBuilder)
{
  char* pixelBytes = pixel.toBytes();
  byteArrayBuilder->addValues(pixelBytes, 3);

  delete[] pixelBytes;
}

void Pixels::PixelArray::addPaddingBytesToByteArrayBuilder(
  ByteArrayBuilder* byteArrayBuilder)
{
  for (int byteNo = 0; byteNo < this->rowPadding; byteNo++)
    byteArrayBuilder->addValue(0);
}

int Pixels::PixelArray::getPixelIndexByRowAndColumn(int rowNo, int columnNo)
{
  return rowNo * widthInPixels + columnNo;
}

void Pixels::PixelArray::populateMissingPixels()
{
  int totalExpectedPixels = this->getHeightInPixels() * this->getWidthInPixels();
  int numberOfPopulatedPixels = this->pixels.size();
  bool hasMissingPixels = (numberOfPopulatedPixels < totalExpectedPixels);
  
  if (hasMissingPixels) {
    Pixels::Pixel blankPixel {0, 0, 0};

    while (numberOfPopulatedPixels < totalExpectedPixels) {
      this->pixels.push_back(blankPixel);
      numberOfPopulatedPixels++;
    }
  }
}

void Pixels::PixelArray::setPixel(
  Pixels::Pixel pixel, int rowNo, int columnNo)
{
  bool rowIndexOutOfBounds = (rowNo > this->heightInPixels || rowNo < 0);

  bool columnIndexOutOfBounds = (
    columnNo > this->widthInPixels || columnNo < 0);

  bool indexOutOfBounds = (rowIndexOutOfBounds || columnIndexOutOfBounds);

  if (indexOutOfBounds) {
    throw std::runtime_error(
      "Pixels::PixelArray::setPixel(): Index " + std::to_string(rowNo) + ", "
      + std::to_string(columnNo) + " out of bounds."
    );
  }

  int index = (rowNo * this->widthInPixels) + columnNo;
  this->pixels[index] = pixel;
}

int Pixels::PixelArray::sizeInBytes()
{
  int totalSizeInBytes = this->rowSizeInBytes * this->heightInPixels;

  return totalSizeInBytes;
}

int Pixels::PixelArray::sizeInPixels()
{
  int numberOfPixels = this->widthInPixels * this->heightInPixels;

  return numberOfPixels;
}

void Pixels::PixelArray::setWidthInPixels(int width)
{
  this->widthInPixels = width;
  this->calculateRowStride();
  this->populateMissingPixels();
}

void Pixels::PixelArray::setHeightInPixels(int height)
{
  this->heightInPixels = height;
  this->calculateRowStride();
  this->populateMissingPixels();
}

int Pixels::PixelArray::getRowStride()
{
  return this->rowSizeInBytes;
}

int Pixels::PixelArray::getWidthInPixels()
{
  return this->widthInPixels;
}

int Pixels::PixelArray::getHeightInPixels()
{
  return this->heightInPixels;
}