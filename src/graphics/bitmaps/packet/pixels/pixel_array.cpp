#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/common/byte_array_builder.h"
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

unsigned char* Pixels::PixelArray::toBytes()
{
  ByteArrayBuilder byteArrayBuilder;
  this->addAllPixelsToByteArray(&byteArrayBuilder);

  return byteArrayBuilder.toBytes();
}

void Pixels::PixelArray::addAllPixelsToByteArray(
  ByteArrayBuilder* byteArrayBuilder)
{
  for (int rowNo = 0; rowNo < this->heightInPixels; rowNo++) {
    unsigned char* pixelRowBytes = this->getRowOfPixelsAsBytes(rowNo);
    byteArrayBuilder->addValues(pixelRowBytes, this->rowSizeInBytes);

    delete[] pixelRowBytes;
  }
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
  unsigned char* pixelBytes = pixel.toBytes();
  byteArrayBuilder->addValues(pixelBytes, 3);

  delete[] pixelBytes;
}

void Pixels::PixelArray::addPaddingBytesToByteArray(
  ByteArrayBuilder* byteArrayBuilder)
{
  for (int byteNo = 0; byteNo < this->rowPadding; byteNo++)
    byteArrayBuilder->addValue(0);
}

unsigned char* Pixels::PixelArray::getRowOfPixelsAsBytes(int rowNo)
{
  ByteArrayBuilder byteArrayBuilder;

  this->addRowOfPixelsToByteArray(rowNo, &byteArrayBuilder);
  this->addPaddingBytesToByteArray(&byteArrayBuilder);

  return byteArrayBuilder.toBytes();
}

void Pixels::PixelArray::addBlankPixels(int numberOfPixelsToAdd)
{
  for (int pixelNo = 0; pixelNo < numberOfPixelsToAdd; pixelNo++)
    this->addBlankPixel();
}

void Pixels::PixelArray::addBlankPixel()
{
  Colours blackColours = {0, 0, 0};
  Pixels::Pixel blankPixel {blackColours};
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

  // Adding colours here when should be a pixel.
  Pixels::Pixel newPixel = Pixel(pixelData.colours);
  this->pixels[index] = newPixel;
}

void Pixels::PixelArray::setWidthInPixels(int width)
{
  this->initialisePixelArray(width, this->heightInPixels);
}

void Pixels::PixelArray::setHeightInPixels(int height)
{
  this->initialisePixelArray(this->widthInPixels, height);
}

Pixels::Pixel Pixels::PixelArray::getPixel(int rowNo, int columnNo)
{
  int index = this->convertToIndex(rowNo, columnNo);
  
  return this->pixels[index];
}

Pixels::Pixel Pixels::PixelArray::getPixel(int index)
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
