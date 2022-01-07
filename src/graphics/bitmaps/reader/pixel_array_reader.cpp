#include <string>
#include <iostream>

#include "src/common/filesystem.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_data.h"
#include "src/common/bytes_conversion.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array_size_calculator.h"
#include "src/graphics/bitmaps/reader/pixel_reader_data.h"

Pixels::PixelArray BitmapReader::getPixelArray(std::string filePath)
{
  std::string bytes = Filesystem::convertFileToString(filePath);
  
  BitmapHeaders::FileHeader fileHeader = BitmapReader::getBitmapFileHeader(
    filePath);

  BitmapHeaders::DibHeader dibHeader = BitmapReader::getBitmapDibHeader(
    filePath);

  PixelReaderData pixelReaderData {};

  pixelReaderData.widthInPixels = dibHeader.getWidthInPixels();
  pixelReaderData.heightInPixels = dibHeader.getHeightInPixels();
  pixelReaderData.rowSizeInBytes = Pixels::calculateRowSizeInBytes(
    pixelReaderData.widthInPixels);

  pixelReaderData.pixelDataOffset = fileHeader.getPixelDataOffset();

  char* bytesAddressPointer = (char *) &bytes;
  std::cout << "address of bytes: " << bytesAddressPointer;
  
  pixelReaderData.pixelPointer = ((char*) &bytes) + pixelReaderData.pixelDataOffset;

  std::cout << "Pixel Pointer values " << (pixelReaderData.pixelPointer);

  return BitmapReader::parseBytesToPixelArray(pixelReaderData);
}

Pixels::PixelArray BitmapReader::parseBytesToPixelArray(
  PixelReaderData pixelReaderData)
{
  Pixels::PixelArray pixels {};

  pixels.setWidthInPixels(pixelReaderData.widthInPixels);
  pixels.setHeightInPixels(pixelReaderData.heightInPixels);

  char* pixelPointer = pixelReaderData.pixelPointer;

  for (int rowNo = 0; rowNo < pixelReaderData.heightInPixels; rowNo++) {
    BitmapReader::parsePixelsFromRow(
      pixelPointer + (rowNo * pixelReaderData.rowSizeInBytes),
      &pixels, rowNo
    );
  }

  return pixels;
}

void BitmapReader::parsePixelsFromRow(
  char* pixelPointer, Pixels::PixelArray* pixelArray, int rowNo)
{
  int widthInPixels = pixelArray->getWidthInPixels();
  int unpaddedRowSizeInBytes = Pixels::calculateUnpaddedRowSize(widthInPixels);

  std::cout << unpaddedRowSizeInBytes << std::endl;

  const int sizeOfPixel = 3;

  for (int columnNo = 0; columnNo < unpaddedRowSizeInBytes; columnNo += sizeOfPixel) {
    Pixels::PixelData pixelData {};

    pixelData.colours = BitmapReader::parsePixelColours(
      pixelPointer + (columnNo * sizeOfPixel));

    pixelData.columnNo = columnNo;
    pixelData.rowNo = rowNo;

    pixelArray->setPixel(pixelData);
  }

  // Does not get here.
}

Colours BitmapReader::parsePixelColours(char* pixelPointer)
{
  Colours colours;

  colours.blue = *pixelPointer;
  colours.green = *(pixelPointer + 1);
  colours.red = *(pixelPointer + 2);

  return colours;
}

int BitmapReader::getPixelArraySizeInBytes(std::string filePath)
{
  BitmapHeaders::FileHeader bmpFileHeader = BitmapReader::getBitmapFileHeader(
    filePath);
  
  int sizeOfFile = bmpFileHeader.getSizeOfBitmapFile();
  int pixelDataOffset = bmpFileHeader.getPixelDataOffset();

  return sizeOfFile - pixelDataOffset;
}