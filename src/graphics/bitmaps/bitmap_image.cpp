#include <fstream>

#include <iostream> // remove after debug.

#include "src/graphics/bitmaps/bitmap_image.h"
#include "src/common/byte_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/common/filesystem.h"

BitmapImage::BitmapImage()
{
  
}

BitmapImage::BitmapImage(
  BitmapFileHeader fileHeader, BitmapDibHeader dibHeader,
  PixelArray pixelArray)
{
  this->fileHeader = fileHeader;
  this->dibHeader = dibHeader;
  this->pixelArray = pixelArray;
}

BitmapImage BitmapImage::fromFile(std::string filePath)
{
  BitmapFileHeader fileHeader = BitmapReader::getBitmapFileHeader(filePath);
  BitmapDibHeader dibHeader =BitmapReader::getBitmapDibHeader(filePath);
  PixelArray pixelArray = BitmapReader::getPixelArray(filePath);

  BitmapImage newBitmapImage {fileHeader, dibHeader, pixelArray};

  return newBitmapImage;
}

char* BitmapImage::toBytes()
{
  ByteArrayBuilder byteArrayBuilder;

  char* fileHeaderBytes = this->fileHeader.toBytes();
  int fileHeaderSize = this->fileHeader.getSizeOfHeaderInBytes();

  char* dibHeaderBytes = this->dibHeader.toBytes();
  int dibHeaderSize = this->dibHeader.getSizeOfHeaderInBytes();

  char* pixelArrayBytes = this->pixelArray.toBytes();
  int pixelArraySize = this->pixelArray.sizeInBytes();

  std::cout << "Pixel array size: "
    << std::to_string(pixelArraySize)
    << std::endl;

  byteArrayBuilder.addValues(fileHeaderBytes, fileHeaderSize);
  byteArrayBuilder.addValues(dibHeaderBytes, dibHeaderSize);

  // Bug occurs here.
  byteArrayBuilder.addValues(pixelArrayBytes, pixelArraySize);

  char* allBytes = byteArrayBuilder.toBytes();

  std::vector<char*> byteArrays = {
    fileHeaderBytes, dibHeaderBytes, pixelArrayBytes};

  for (auto byteArray : byteArrays)
    delete[] byteArray;

  return allBytes;
}

void BitmapImage::recalculateFileSize()
{
  int widthInPixels = this->getWidthInPixels();
  int heightInPixels = this->getHeightInPixels();

  this->pixelArray.setWidthInPixels(widthInPixels);
  this->pixelArray.setHeightInPixels(heightInPixels);

  this->pixelArray.populateMissingPixels();

  int pixelArraySize = this->pixelArray.sizeInBytes();
  int sizeOfAllHeaders = this->fileHeader.getPixelDataOffset();

  this->fileHeader.setSizeOfBitmapFile(sizeOfAllHeaders + pixelArraySize);
}

void BitmapImage::writeToFile(std::string filePath)
{
  // Bug lies here.
  char* bitmapImageBytes = this->toBytes();
  int bitmapImageSize = this->getSizeOfFile();

  std::ofstream fout(filePath, std::ios::binary);
  fout.write(bitmapImageBytes, bitmapImageSize);  
  fout.close();

  delete[] bitmapImageBytes;
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

BitmapFileHeader BitmapImage::getFileHeader()
{
  return this->fileHeader;
}

BitmapDibHeader BitmapImage::getDibHeader()
{
  return this->dibHeader;
}

PixelArray BitmapImage::getPixelArray()
{
  return this->pixelArray;
}

void BitmapImage::setPixel(int row, int column, Pixel pixel)
{
  this->pixelArray.setPixel(pixel, row, column);
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

void BitmapImage::setFileHeader(BitmapFileHeader fileHeader)
{
  this->fileHeader = fileHeader;
}

void BitmapImage::setDibHeader(BitmapDibHeader dibHeader)
{
  this->dibHeader = dibHeader;
}

void BitmapImage::setPixelArray(PixelArray pixelArray)
{
  this->pixelArray = pixelArray;
}