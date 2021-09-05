#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/common/filesystem.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/common/bytes_conversion.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array_size_calculator.h"

Pixels::PixelArray BitmapReader::getPixelArray(std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);
  
  BitmapHeaders::FileHeader fileHeader = 
    BitmapReader::getBitmapFileHeader(filePath);

  BitmapHeaders::DibHeader dibHeader = 
    BitmapReader::getBitmapDibHeader(filePath);

  Pixels::PixelArray pixelArray = BitmapReader::parseBytesToVector(
    &bytes, fileHeader, dibHeader);

  return pixelArray;
}

Pixels::PixelArray BitmapReader::parseBytesToVector(
  std::string* bytes, BitmapHeaders::FileHeader fileHeader,
  BitmapHeaders::DibHeader dibHeader)
{
  int pixelDataOffset = fileHeader.getPixelDataOffset();
  int widthInPixels = dibHeader.getWidthInPixels();
  int heightInPixels = dibHeader.getHeightInPixels();
  int rowSizeInBytes = Pixels::calculateRowSizeInBytes(widthInPixels);

  Pixels::PixelArray pixels;
  pixels.setWidthInPixels(widthInPixels);
  pixels.setHeightInPixels(heightInPixels);

  for (int rowNo = 0; rowNo < heightInPixels; rowNo++) {
    int startOfRowByteIndex = rowNo * rowSizeInBytes + pixelDataOffset;

    BitmapReader::parseRowOfBytesToVector(
      bytes, &pixels, rowNo, startOfRowByteIndex);
  }

  return pixels;
}

void BitmapReader::parseRowOfBytesToVector(
  std::string* bytes, Pixels::PixelArray* pixels, 
  int rowNo, int rowStartingByteNo)
{
  int unpaddedRowSizeInBytes = 
    Pixels::calculateUnpaddedRowSize(pixels->getWidthInPixels());

  for (int columnNo = 0; columnNo < unpaddedRowSizeInBytes; columnNo += 3) {
    int byteNo = rowStartingByteNo + columnNo;

    Pixels::Pixel pixel = BitmapReader::parsePixelFromBytes(
      bytes, byteNo);

    pixels->setPixel(pixel, rowNo, columnNo);    
  }
}

void BitmapReader::parsePixelFromBytesToVector(
  std::string* bytes, Pixels::PixelArray* pixels, int startingByteNo)
{
  Pixels::Pixel pixel = BitmapReader::parsePixelFromBytes(
    bytes, startingByteNo);
      
  // pixels->push_back(pixel); 
}

Pixels::Pixel BitmapReader::parsePixelFromBytes(
  std::string* bytes, int startingByteNo)
{
  uint8_t blueValue = (*bytes)[startingByteNo];
  uint8_t greenValue = (*bytes)[startingByteNo + 1];
  uint8_t redValue = (*bytes)[startingByteNo + 2];

  Pixels::Pixel pixel {redValue, greenValue, blueValue};

  return pixel;
}

int BitmapReader::getPixelArraySizeInBytes(std::string filePath)
{
  BitmapHeaders::FileHeader bmpFileHeader =
    BitmapReader::getBitmapFileHeader(filePath);
  
  int sizeOfFile = bmpFileHeader.getSizeOfBitmapFile();
  int pixelDataOffset = bmpFileHeader.getPixelDataOffset();

  int sizeOfPixelArrayInBytes = sizeOfFile - pixelDataOffset;

  return sizeOfPixelArrayInBytes;
}


