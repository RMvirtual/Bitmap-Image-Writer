#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/common/byte_array.h"

#include <string>
#include <queue>
#include <vector>
#include <iomanip>
#include <iostream>

PixelArray::PixelArray()
{
  this->pixels = std::vector<Pixel>{};
  this->widthInPixels = 0;
  this->heightInPixels = 0;
  this->calculateRowSizeInBytes();
}

PixelArray::PixelArray(
  std::vector<Pixel> pixels, int widthInPixels, int heightInPixels)
{
  if (pixels.size() != widthInPixels * heightInPixels)
    throw std::length_error(
      "Number of pixels does not match given height and width. " \
      "Number of pixels is " + std::to_string(pixels.size()) + " while " \
      "correct size from parameters is " + std::to_string(
        widthInPixels * heightInPixels)
    );

  this->pixels = pixels;
  this->widthInPixels = widthInPixels;
  this->heightInPixels = heightInPixels;
  this->calculateRowSizeInBytes();

  /*
  queue<Pixel> pixelQueue;

  for (auto pixel : pixels) {
    pixelQueue.push(pixel);
  }

  for (int rowNo = 0; rowNo < heightInPixels; rowNo++) {
    for (int columnNo = 0; columnNo < widthInPixels; columnNo++) {
      Pixel currentPixel = pixelQueue.front();
      pixelQueue.pop();    

      this->pixels.push_back(currentPixel);
    }
  }
  */
}

void PixelArray::calculateRowSizeInBytes()
{
  int padding = 0;
  int unpaddedRowSize = this->widthInPixels * 3;  
  int differenceInAlignment = unpaddedRowSize % 4;

  if (differenceInAlignment)
    padding = 4 - differenceInAlignment;

  this->rowSizeInBytes = unpaddedRowSize + padding;
}

char* PixelArray::toBytes()
{
  ByteArrayBuilder byteArrayBuilder;

  for (int rowNo = 0; rowNo < this->heightInPixels; rowNo++) {
    char* pixelRowBytes = this->getRowOfPixelsAsBytes(rowNo);
    byteArrayBuilder.addValues(pixelRowBytes, this->rowSizeInBytes);

    delete[] pixelRowBytes;
  }

  return byteArrayBuilder.toBytes();
}

char* PixelArray::getRowOfPixelsAsBytes(int rowNo)
{
  ByteArrayBuilder byteArrayBuilder;

  for (int columnNo = 0; columnNo < this->widthInPixels; columnNo++) {
    int index = this->getPixelIndexByRowAndColumn(rowNo, columnNo);
    Pixel pixel = this->pixels[index];

    char* pixelBytes = pixel.toBytes();
    byteArrayBuilder.addValues(pixelBytes, 3);

    delete[] pixelBytes;
  }

  for (int paddingByte = 0; paddingByte < this->rowPadding; paddingByte++) {
    byteArrayBuilder.addValue(0);
  }

  return byteArrayBuilder.toBytes();
}

int PixelArray::getPixelIndexByRowAndColumn(int rowNo, int columnNo)
{
  return rowNo * widthInPixels + columnNo;
}

void PixelArray::populateMissingPixels()
{
  int totalExpectedPixels = this->getHeightInPixels() * this->getWidthInPixels();
  int numberOfPopulatedPixels = this->pixels.size();
  bool hasMissingPixels = (numberOfPopulatedPixels < totalExpectedPixels);
  
  if (hasMissingPixels) {
    Pixel blankPixel {0, 0, 0};

    while (numberOfPopulatedPixels < totalExpectedPixels) {
      this->pixels.push_back(blankPixel);
      numberOfPopulatedPixels++;
    }
  }
}

void PixelArray::setPixel(Pixel pixel, int rowNo, int columnNo)
{
  bool rowIndexOutOfBounds = (rowNo > this->heightInPixels || rowNo < 0);

  bool columnIndexOutOfBounds = (
    columnNo > this->widthInPixels || columnNo < 0);

  bool indexOutOfBounds = (rowIndexOutOfBounds || columnIndexOutOfBounds);

  if (indexOutOfBounds) {
    throw std::runtime_error(
      "PixelArray: setPixel(): Index " + std::to_string(rowNo) + ", "
      + std::to_string(columnNo) + " out of bounds."
    );
  }

  int index = (rowNo * this->widthInPixels) + columnNo;
  this->pixels[index] = pixel;
}

int PixelArray::sizeInBytes()
{
  int numberOfPixels = this->sizeInPixels();
  int numberOfColourChannels = 3;

  int totalSizeInBytes = numberOfPixels * numberOfColourChannels;

  return totalSizeInBytes;
}

int PixelArray::sizeInPixels()
{
  int numberOfPixels = this->widthInPixels * this->heightInPixels;

  return numberOfPixels;
}

void PixelArray::setWidthInPixels(int width)
{
  this->widthInPixels = width;
}

void PixelArray::setHeightInPixels(int height)
{
  this->heightInPixels = height;
}

int PixelArray::getRowStride()
{
  return this->rowSizeInBytes;
}

int PixelArray::getWidthInPixels()
{
  return this->widthInPixels;
}

int PixelArray::getHeightInPixels()
{
  return this->heightInPixels;
}