#include "src/graphics/bitmaps/bitmap_image.h"
#include "src/common/byte_array.h"

BitmapImage::BitmapImage(
  BitmapFileHeader fileHeader, BitmapDibHeader dibHeader,
  PixelArray pixelArray)
{
  this->fileHeader = fileHeader;
  this->dibHeader = dibHeader;
  this->pixelArray = pixelArray;
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

  byteArrayBuilder.addValues(fileHeaderBytes, fileHeaderSize);
  byteArrayBuilder.addValues(dibHeaderBytes, dibHeaderSize);
  byteArrayBuilder.addValues(pixelArrayBytes, pixelArraySize);

  char* allBytes = byteArrayBuilder.toBytes();

  std::vector<char*> byteArrays = {
    fileHeaderBytes, dibHeaderBytes, pixelArrayBytes};

  for (auto byteArray : byteArrays)
    delete[] byteArray;

  return allBytes;
}

int BitmapImage::getSizeOfBytes()
{
  return this->fileHeader.getSizeOfBitmapFile();
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