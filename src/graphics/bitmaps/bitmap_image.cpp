#include <fstream>

#include "src/common/byte_array_builder.h"
#include "src/common/filesystem.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

BitmapImage::BitmapImage()
{
  // Pass
}

BitmapImage BitmapImage::fromPacket(BitmapPacket headers)
{
  BitmapImage image;
  image.fileHeader = headers.fileHeader;
  image.dibHeader = headers.dibHeader;
  image.pixelArray = headers.pixelArray;

  return image;
}

BitmapImage BitmapImage::fromFile(std::string filePath)
{
  BitmapPacket packet = BitmapReader::getBitmapPacket(filePath);
  
  return BitmapImage::fromPacket(packet);
}

void BitmapImage::recalculateFileSize()
{
  int widthInPixels = this->getWidthInPixels();
  int heightInPixels = this->getHeightInPixels();

  this->pixelArray.setWidthInPixels(widthInPixels);
  this->pixelArray.setHeightInPixels(heightInPixels);

  int pixelArraySize = this->pixelArray.sizeInBytes();
  int sizeOfAllHeaders = this->fileHeader.getPixelDataOffset();

  this->fileHeader.setSizeOfBitmapFile(sizeOfAllHeaders + pixelArraySize);
}

int32_t BitmapImage::getWidthInPixels()
{
  return this->dibHeader.getWidthInPixels();
}

int32_t BitmapImage::getHeightInPixels()
{
  return this->dibHeader.getHeightInPixels();
}

int BitmapImage::getNumberOfPixels()
{
  return this->pixelArray.sizeInPixels();
}

int BitmapImage::getSizeOfFile()
{
  return this->fileHeader.getSizeOfBitmapFile();
}

BitmapHeaders::FileHeader BitmapImage::getFileHeader()
{
  return this->fileHeader;
}

BitmapHeaders::DibHeader BitmapImage::getDibHeader()
{
  return this->dibHeader;
}

Pixels::PixelArray BitmapImage::getPixelArray()
{
  return this->pixelArray;
}

void BitmapImage::setPixel(Pixels::PixelData pixelData)
{
  this->pixelArray.setPixel(pixelData);
}

void BitmapImage::setWidthInPixels(int32_t widthInPixels)
{
  this->dibHeader.setWidthInPixels(widthInPixels);
  this->recalculateFileSize();
}

void BitmapImage::setHeightInPixels(int32_t heightInPixels)
{
  this->dibHeader.setHeightInPixels(heightInPixels);
  this->recalculateFileSize();
}

void BitmapImage::setSizeOfFile(uint32_t sizeOfFile)
{
  this->fileHeader.setSizeOfBitmapFile(sizeOfFile);
}

void BitmapImage::setFileHeader(BitmapHeaders::FileHeader fileHeader)
{
  this->fileHeader = fileHeader;
}

void BitmapImage::setDibHeader(BitmapHeaders::DibHeader dibHeader)
{
  this->dibHeader = dibHeader;
}

void BitmapImage::setPixelArray(Pixels::PixelArray pixelArray)
{
  this->pixelArray = pixelArray;
}