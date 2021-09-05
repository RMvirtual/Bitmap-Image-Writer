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

  this->addRowOfPixelsToByteArray(rowNo, &byteArrayBuilder);
  this->addPaddingBytesToByteArray(&byteArrayBuilder);

  return byteArrayBuilder.toBytes();
}

void Pixels::PixelArray::addRowOfPixelsToByteArray(
  int rowNo, ByteArrayBuilder* byteArrayBuilder)
{
  for (int columnNo = 0; columnNo < this->widthInPixels; columnNo++)
    this->addPixelByIndexToByteArray(rowNo, columnNo, byteArrayBuilder);
}

void Pixels::PixelArray::addPixelByIndexToByteArray(
  int rowNo, int columnNo, ByteArrayBuilder* byteArrayBuilder)
{
  Pixels::Pixel pixel = this->getPixel(rowNo, columnNo);
  this->addPixelToByteArray(pixel, byteArrayBuilder);
}

void Pixels::PixelArray::addPixelToByteArray(
  Pixels::Pixel pixel, ByteArrayBuilder* byteArrayBuilder)
{
  char* pixelBytes = pixel.toBytes();
  byteArrayBuilder->addValues(pixelBytes, 3);

  delete[] pixelBytes;
}

void Pixels::PixelArray::addPaddingBytesToByteArray(
  ByteArrayBuilder* byteArrayBuilder)
{
  for (int byteNo = 0; byteNo < this->rowPadding; byteNo++)
    byteArrayBuilder->addValue(0);
}

Pixels::Pixel Pixels::PixelArray::getPixel(int rowNo, int columnNo)
{
  int index = this->convertRowAndColumnToIndex(rowNo, columnNo);
  Pixels::Pixel pixel = this->pixels[index];

  return pixel;
}

Pixels::Pixel Pixels::PixelArray::getPixel(int index)
{
  return this->pixels[index];
}

int Pixels::PixelArray::convertRowAndColumnToIndex(int rowNo, int columnNo)
{
  return rowNo * widthInPixels + columnNo;
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

int Pixels::PixelArray::getNumberOfMissingPixels()
{
  int totalExpectedPixels = this->getHeightInPixels() * this->getWidthInPixels();
  int numberOfActualPixels = this->pixels.size();
  
  int numberOfMissingPixels = totalExpectedPixels - numberOfActualPixels;
  
  return numberOfMissingPixels;
}

void Pixels::PixelArray::addBlankPixel()
{
  Pixels::Pixel blankPixel {0, 0, 0};
  this->pixels.push_back(blankPixel);
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
  this->initialisePixelArray(width, this->heightInPixels);
}

void Pixels::PixelArray::setHeightInPixels(int height)
{
  this->initialisePixelArray(this->widthInPixels, height);
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